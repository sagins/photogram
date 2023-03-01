#ifndef CLIENT_H
#define CLIENT_H

#include "PhotoGram.h"
#include "Album.h"

class Client{
    public:
        Client();
        ~Client();

        bool downloadAlbum(PhotoGram* pg, string albumTitle);
        bool displayOnlinePhoto(PhotoGram* pg, string albumTitle, string photoTitle) const;
        bool displayLocalPhoto(string albumTitle, string photoTitle) const;
        void printLocalAlbums() const;
        void displayLocalAlbums() const;



    private:
        AlbumArray* array;


};

#endif
