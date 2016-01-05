/* DefaultFileSystemHandler.cpp
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

#include "DefaultFileSystemHandler.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

vector<DoblhoferIT::Folder> DoblhoferIT::DefaultFileSystemHandler::getSubFolders(Folder *cur) {
  vector<Folder> ret;

  string path = cur->getAbsolutePath();
  struct dirent *cur_dir;
  DIR* d  = opendir(path.c_str());

  while((cur_dir = readdir(d)) != NULL) {
    if(cur_dir->d_type == DT_DIR) {
      string name = cur_dir->d_name;
      if(name == "." || name == "..")
        continue;
      ret.push_back(Folder(name, cur, this));
    }
  }

  closedir(d);

  return ret;
}

vector<DoblhoferIT::File> DoblhoferIT::DefaultFileSystemHandler::getSubFiles(Folder *cur) {
  vector<File> ret;

  string path = cur->getAbsolutePath();
  struct dirent *cur_dir;
  DIR* d  = opendir(path.c_str());

  while((cur_dir = readdir(d)) != NULL) {
    // TODO: Support other types (link, socket, chardev, ...)
    if(cur_dir->d_type == DT_REG) {
      string name = cur_dir->d_name;

      string absFN = path + "/" + name;
      struct stat st;
      st.st_size = 0;
      if(stat(absFN.c_str(), &st)<0) {
        st.st_size=-1; // show error
      }

      ret.push_back(File(name, st.st_size, cur, this));
    }
  }
  closedir(d);

  return ret;
}
