#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include "AlbumArray.h"
#include "Photo.h"
#include "Album.h"

class PhotoGram{
    public:
        PhotoGram();
        ~PhotoGram();
        bool addAlbum(string, string);
        bool removeAlbum(string);
        bool removePhoto(string, string);
        bool addPhoto(string, const Photo&);
        Album* downloadAlbum(string) const;
        Photo* downloadPhoto(const string, const string) const;
        void printAlbums() const;
        void displayAlbums() const;



    private:
        AlbumArray* albumArray;

};

#endif
