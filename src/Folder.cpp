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

DoblhoferIT::Folder::Folder(string foldername, string parentPath, FileSystemHandler *fsys_handler) {
	fsh = fsys_handler;
	setName(foldername);
	setParentPath(parentPath);
}

void
DoblhoferIT::Folder::setName(string foldername) {
	name = foldername;
}

string
DoblhoferIT::Folder::getName() {
	return name;
}

void DoblhoferIT::Folder::setParentPath(string parentPath) {
	parent = parentPath;
}

string
DoblhoferIT::Folder::getParentPath() {
	return parent;
}
