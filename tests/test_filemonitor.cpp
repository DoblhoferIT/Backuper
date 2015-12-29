/* test_filemonitor.cpp
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

#include <stdio.h>
#include "../src/Folder.h"
#include "../src/FileSystemHandler.h"

using namespace DoblhoferIT;

#define ASSERT(B, MSG) { if(!(B)) { fputs(MSG, stderr); return 1;}}

class DummyFileSystemHandler : FileSystemHandler {
public:
	Folder getNextSubFolder(Folder *cur) {
		return Folder("t", cur->getParentPath() + "/" + cur->getName(), this);
	}
};

int main() {
	DummyFileSystemHandler dummyhandler;
	Folder f("test", "/", (FileSystemHandler*)&dummyhandler);

	ASSERT(f.getName() == "test", "Foldername is not correct!");
	ASSERT(f.getParentPath () == "/", "Parent path is not correct!")


	ASSERT(0, "TEST SUBFOLDER");

	return 0;
}
