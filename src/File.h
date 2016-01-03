/* File.h
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

#ifndef _FILE_H_
#define _FILE_H_

#include <string>
#include "FileSystemHandler.h"
#include "Folder.h"

using namespace std;

namespace DoblhoferIT {
  class FileSystemHandler;
  class Folder;

  class File {
  private:
      FileSystemHandler* fsh;

      string name;
      Folder* parent;

      unsigned long size;
      // TODO: Attributes

  public:
    File                    ();
    File                    (string             filename,
                             unsigned long      filesize,
                             Folder            *parentPath,
                             FileSystemHandler *fsys_handler);

    void    setName         (string filename);
    void    setParentPath   (Folder* parentPath);

    void    setFileSize     (unsigned long filesize);
    unsigned long
            getFileSize     ();


    string  getName();
    Folder* getParentPath   ();
  };
};
#endif
