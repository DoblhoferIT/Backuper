/* Folder.h
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

#ifndef _FOLDER_H_
#define _FOLDER_H_

#include <string>
#include "FileSystemHandler.h"

using namespace std;

namespace DoblhoferIT {
  class FileSystemHandler;

	class Folder {
	private:
		FileSystemHandler* fsh;

    string name;
    string parent;
    // TODO: Attributes
	public:
	  Folder                (string foldername, string parentPath,
                           FileSystemHandler *fsys_handler);

    void    setName       (string foldername);
    void    setParentPath (string parentPath);
    string  getName       ();
    string  getParentPath ();
	};
}

#endif
