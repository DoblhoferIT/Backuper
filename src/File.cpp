/* File.cpp
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

 #include "File.h"
 #include "Folder.h"
 #include "FileSystemHandler.h"

DoblhoferIT::File::File(string filename, unsigned long filesize, Folder *parentPath, FileSystemHandler *fsys_handler) {
  fsh = fsys_handler;
  setName(filename);
  setFileSize (filesize);
  setParentPath(parentPath);
}

DoblhoferIT::File::File() {
  fsh = 0;
  setName("");
  setFileSize(0);
  setParentPath(0);
}

void
DoblhoferIT::File::setName(string filename) {
  name = filename;
}

string
DoblhoferIT::File::getName() {
  return name;
}

void
DoblhoferIT::File::setFileSize(unsigned long filesize) {
  size = filesize;
}


unsigned long
DoblhoferIT::File::getFileSize() {
  return size;
}

void
DoblhoferIT::File::setParentPath(Folder* parentPath) {
  parent = parentPath;
}

DoblhoferIT::Folder*
DoblhoferIT::File::getParentPath() {
  return parent;
}
