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
#include <vector>
#include "../src/Folder.h"
#include "../src/FileSystemHandler.h"
#include "../src/XMLHandler.h"

using namespace DoblhoferIT;
using namespace std;

#define ASSERT(B, MSG) { if(!(B)) { fputs(MSG, stderr); return 1;}}

class DummyFileSystemHandler : FileSystemHandler {
public:
  vector<Folder> getSubFolders(Folder *cur) {
    vector<Folder> ret;
    if(cur->getName() == "test") {
      for(int i=0;i<5;i++) {
        string s = "";
        s += 'A'+i;
        ret.push_back(Folder(s, cur, this));
      }
    }
    if(cur->getName() == "A") {
      for(int i=0;i<5;i++) {
        string s = "";
        s += '1'+i;
        ret.push_back(Folder(s, cur, this));
      }
    }
    return ret;
  }

  vector<File> getSubFiles(Folder *cur) {
    vector<File> ret;

    if(cur->getName() == "A" || cur->getName() == "B") {
      for(int i=0;i<5;i++) {
        string s = "File_";
        s += '0'+i;
        ret.push_back(File(s, (i+1)*110, cur, this));
      }
    }

    return ret;
  }
};

void printFolder(Folder* f, int indent) {
  vector<Folder> subfolders = f->getSubFolders();
  vector<File> subfiles = f->getSubFiles();
  for(int i=0; i<subfolders.size ();i++) {
    printf(" D %5luB", subfolders[i].getTotalFileSize());
    for(int j=0;j<indent; j++)
      putc(' ', stdout);
    printf("%s\n", subfolders[i].getName ().c_str());
    printFolder(&(subfolders[i]), indent+2);
  }
  for(int i=0; i<subfiles.size ();i++) {
    printf(" F %5luB", subfiles[i].getFileSize());
    for(int j=0;j<indent; j++)
      putc(' ', stdout);
    printf("%s\n", subfiles[i].getName ().c_str());
  }

}

int main() {
  DummyFileSystemHandler dummyhandler;
  Folder f("test", 0, (FileSystemHandler*)&dummyhandler);

  ASSERT(f.getName() == "test", "Foldername is not correct!");
  ASSERT(f.getParentPath () == 0, "Parent path is not correct!");

  // DEBUG Output
  printf(" D %5luB %s\n", f.getTotalFileSize(), f.getName ().c_str());
  printFolder(&f, 2);

  ASSERT(f.getSubFolders().size() == 5, "Wrong count of subfolders");
  ASSERT(f.getSubFolders()[0].getSubFolders().size() == 5, "Wrong count of subfolders");
  ASSERT(f.getSubFolders()[1].getSubFolders().size() == 0, "Wrong count of subfolders");


  File fi("test", 123, 0, 0);
  ASSERT(fi.getName() == "test", "Filename is not correct");
  ASSERT(fi.getParentPath() == 0, "Parent path is not correct");
  ASSERT(fi.getFileSize() == 123, "Filesize is not correct");


  XMLHandler::writeXML("/tmp/my.xml", 0);

  return 0;
}
