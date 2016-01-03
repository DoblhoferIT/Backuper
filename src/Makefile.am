# Our binary is produced here
bin_PROGRAMS = main
main_SOURCES = main.cpp# Folder.cpp File.cpp FileSystemHandler.cpp
main_LDADD = libcommon.a
# main binary will be installed into the default directory for "bin"s (hence we used the bin
# prefix

noinst_LIBRARIES = libcommon.a
libcommon_a_SOURCES = Folder.cpp File.cpp FileSystemHandler.cpp XMLHandler.cpp
libcommon_a_CPPFLAGS = $(XML_CFLAGS)
libcommon_a_LDFLAGS = $(XML_LIBS)
