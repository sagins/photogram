Author: Emrehan Sagin

List of files

README.txt
Makefile
main.cc
Album.h
Album.cc
Date.h
Date.cc
Photo.h
Photo.cc
PhotoArray.h
PhotoArray.cc
AlbumArray.h
AlbumArray.cc
PhotoGram.h
PhotoGram.cc
Client.h
Client.cc
TestControl.h
TestControl.cc
TestView.h
TestView.cc

Program description:
C++ project that mimics a photo viewing application (called PhotoGram). Any Photo on PhotoGram
must belong to an Album. Thus Albums are responsible for the memory management of Photos and PhotoGram is
responsible for the memory management of Albums. Albums have a title and a description and a data structure for
storing Photos. Each Photo will have a title, Date taken, and content (which are the pictures themselves).

Photos may be printed (which is to have their metadata displayed without the content) or displayed, which is to print their metadata and content together to the console.

PhotoGram will consist of 0 or more Albums. A Client class will be able connect to PhotoGram where they can
display Photos from any Album stored on PhotoGram. In addition, the Client will be able to “download” Albums.
This copies the Album to “local storage”, which, in this exercise, is a data structure in the Client class. Users can then display the Album locally, which should work even if the PhotoGram network deletes the original Album. In other words, downloading consists of making a deep copy of the Album.

There is a TestControl class that connects and test the functionality of the PhotoGram and Client classes.
This class and the test functions are written for you. You will then be able to run various tests using the TestControl
and TestView objects.


Running instructions:
1. open terminal in the directory where files are located
2. compile using make or make all
3. use ./a2 to run
4. use clean to clean the executables
