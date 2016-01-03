# Our binary is produced here
check_PROGRAMS = test-filemonitor
test_filemonitor_SOURCES = test_filemonitor.cpp# ../src/Folder.cpp ../src/File.cpp ../src/FileSystemHandler.cpp
test_filemonitor_CPPFLAGS = $(XML_CFLAGS)
test_filemonitor_LDADD = ../src/libcommon.a $(XML_LIBS)
# main binary will be installed into the default directory for "bin"s (hence we used the bin
# prefix

TESTS = test-filemonitor

