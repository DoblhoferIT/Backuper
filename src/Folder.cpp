/* Folder.cpp
 *
 * Copyright (C) 2015 Doblhofer Philipp <philipp@doblhofer.it>
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

#include "Folder.h"
#include "FileSystemHandler.h"

DoblhoferIT::Folder::Folder(string foldername, Folder* parentPath, FileSystemHandler *fsys_handler) {
  fsh = fsys_handler;
  setName(foldername);
  setParentPath(parentPath);
}

DoblhoferIT::Folder::Folder() {
  fsh = 0;
  setName("");
  setParentPath(0);
}

void
DoblhoferIT::Folder::setName(string foldername) {
  name = foldername;
}

string
DoblhoferIT::Folder::getName() {
  return name;
}

void DoblhoferIT::Folder::setParentPath(Folder* parentPath) {
  parent = parentPath;
}

DoblhoferIT::Folder*
DoblhoferIT::Folder::getParentPath() {
  return parent;
}

unsigned long
DoblhoferIT::Folder::getTotalFileSize() {
  unsigned long ret = 0;
  vector<Folder> sfolder = getSubFolders();
  for(int i=0; i<sfolder.size(); i++)
    ret += sfolder[i].getTotalFileSize();

  vector<File> files = getSubFiles();
  for(int i=0; i<files.size(); i++)
    ret += files[i].getFileSize();

  return ret;
}

vector<DoblhoferIT::Folder>
DoblhoferIT::Folder::getSubFolders() {
  if(!fsh)
    return vector<DoblhoferIT::Folder>();
  return fsh->getSubFolders(this);
}

vector<DoblhoferIT::File>
DoblhoferIT::Folder::getSubFiles() {
  if(!fsh)
    return vector<DoblhoferIT::File>();
  return fsh->getSubFiles(this);
}
