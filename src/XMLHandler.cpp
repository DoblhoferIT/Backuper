/* XMLHandler.cpp
 *
 * Copyright (C) 2016 Doblhofer Philipp <philipp@doblhofer.it>
 *
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "XMLHandler.h"
#include <string.h>

#define ENCODING  "ISO-8859-1"

xmlChar *
DoblhoferIT::XMLHandler::convert(const char *in, const char *encoding) {
    xmlChar *out;
    int ret;
    int size;
    int out_size;
    int temp;
    xmlCharEncodingHandlerPtr handler;

    if (in == 0)
        return 0;

    handler = xmlFindCharEncodingHandler(encoding);

    if (!handler) {
        return 0;
    }

    size = (int) strlen(in) + 1;
    out_size = size * 2 - 1;
    out = (unsigned char *) xmlMalloc((size_t) out_size);

    if (out != 0) {
        temp = size - 1;
        ret = handler->input(out, &out_size, (const xmlChar *) in, &temp);
        if ((ret < 0) || (temp - size + 1)) {
            xmlFree(out);
            out = 0;
        } else {
            out = (unsigned char *) xmlRealloc(out, out_size + 1);
            out[out_size] = 0;  /*null terminating out */
        }
    }
    return out;
}



bool
DoblhoferIT::XMLHandler::writeXMLFile(xmlTextWriterPtr *ptr,
                               File *file) {

  if(xmlTextWriterStartElement(*ptr, BAD_CAST "File") < 0)
      return false;

  if(xmlTextWriterWriteAttribute(*ptr, BAD_CAST "name", convert(file->getName().c_str(), ENCODING)) < 0)
    return false;
  if(xmlTextWriterWriteAttribute(*ptr, BAD_CAST "size", convert(std::to_string(file->getFileSize()).c_str(), ENCODING)) < 0)
    return false;


  /* Close <folder> */
  if (xmlTextWriterEndElement(*ptr) < 0)
    return false;
  return true;
}

bool
DoblhoferIT::XMLHandler::writeXMLFolder(xmlTextWriterPtr *ptr,
                               Folder *folder) {

  if(xmlTextWriterStartElement(*ptr, BAD_CAST "Folder") < 0)
      return false;

  if(xmlTextWriterWriteAttribute(*ptr, BAD_CAST "name", convert(folder->getName().c_str(), ENCODING)) < 0)
    return false;
  if(xmlTextWriterWriteAttribute(*ptr, BAD_CAST "totalsize", convert(std::to_string(folder->getTotalFileSize()).c_str(), ENCODING)) < 0)
    return false;


  vector<Folder> sfo = folder->getSubFolders();
  vector<File> sfi = folder->getSubFiles();
  if(xmlTextWriterWriteAttribute(*ptr, BAD_CAST "subfolders", convert(std::to_string(sfo.size()).c_str(), ENCODING)) < 0)
    return false;
  if(xmlTextWriterWriteAttribute(*ptr, BAD_CAST "subfiles", convert(std::to_string(sfi.size()).c_str(), ENCODING)) < 0)
    return false;

  vector<Folder>::iterator it;
  vector<File>::iterator it2;

  for(it=sfo.begin(); it < sfo.end(); it++) {
      writeXMLFolder(ptr, &(*it));
  }

  for(it2=sfi.begin(); it2 < sfi.end(); it2++) {
      writeXMLFile(ptr, &(*it2));
  }


  /* Close <folder> */
  if (xmlTextWriterEndElement(*ptr) < 0)
    return false;
  return true;
}

bool
DoblhoferIT::XMLHandler::writeXML (string xmlfilename, DoblhoferIT::Folder *root) {
    xmlTextWriterPtr writer = xmlNewTextWriterFilename(xmlfilename.c_str(), 0);
    if(!writer)
      return false;

    if(xmlTextWriterStartDocument(writer, NULL, ENCODING, NULL) < 0)
      return false;

    if(xmlTextWriterStartElement(writer, BAD_CAST "Backup") < 0)
      return false;

    if(!writeXMLFolder(&writer, root))
      return false;

    /* Close <Backup> */
    if (xmlTextWriterEndElement(writer) < 0)
      return false;

    if (xmlTextWriterEndDocument(writer) < 0)
      return false;

    xmlFreeTextWriter(writer);

    return true;
}
