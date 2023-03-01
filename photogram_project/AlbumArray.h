#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H

#include "Album.h"
#include "defs.h"

class AlbumArray
{
  public:
    AlbumArray();
    AlbumArray(const AlbumArray&);
    //~AlbumArray();

    // other functions
    bool add(Album*);
    Album* get(string) const;
    Album* get(int) const;
    Album* remove(string);
    Album* remove(int);
    int size() const;

  private:
    Album** albums;
    int numAlbums;
};

#endif
