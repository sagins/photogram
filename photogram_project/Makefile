TARGETS = a2
OBJECTS	 = main.o Album.o Date.o Photo.o PhotoArray.o AlbumArray.o PhotoGram.o Client.o TestControl.o TestView.o

all: $(TARGETS)

a2: $(OBJECTS)
	g++ -o a2 $(OBJECTS)
	
main.o:	main.cc TestControl.h
	g++ -c main.cc

TestControl.o:	TestControl.cc TestControl.h
	g++ -c TestControl.cc
	
TestView.o:  TestView.cc TestView.h
	g++ -c TestView.cc
	
Client.o:  Client.cc Client.h
	g++ -c Client.cc
	
PhotoGram.o:  PhotoGram.cc PhotoGram.h
	g++ -c PhotoGram.cc
	
AlbumArray.o:  AlbumArray.cc AlbumArray.h
	g++ -c AlbumArray.cc

Album.o: Album.cc Album.h
	g++ -c Album.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Photo.o: Photo.cc Photo.h
	g++ -c Photo.cc

PhotoArray.o: PhotoArray.cc PhotoArray.h
	g++ -c PhotoArray.cc

clean:
	rm -f *.o a2   






















