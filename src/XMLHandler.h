/* XMLHandler.h
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

#ifndef _XMLHANDLER_H_
#define _XMLHANDLER_H_

#include <libxml/xmlreader.h>
#include <libxml/xmlwriter.h>
#include <libxml/encoding.h>
#include <string>
#include "Folder.h"

using namespace std;

namespace DoblhoferIT {

  class XMLHandler{
  private:
    static xmlChar *convert(const char *in, const char *encoding);
    static bool writeXMLFolder(xmlTextWriterPtr *ptr,
                               Folder      *folder);
    static bool writeXMLFile(xmlTextWriterPtr *ptr,
                               File      *file);
  public:
    // TODO: change to bool
    static bool writeXML(string xmlfilename, Folder *root);
  };
};

#endif
