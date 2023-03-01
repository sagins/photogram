#ifndef PHOTOARRAY_H
#define PHOTOARRAY_H

#include "Photo.h"
#include "defs.h"

class PhotoArray
{
  public:
    PhotoArray();
    PhotoArray(const PhotoArray&);
    ~PhotoArray();

    // other functions
    bool isFull() const;
    bool add(Photo*);
    bool add(int index, Photo*);
    Photo* get(string) const;
    Photo* get(int index) const;
    Photo* remove(string title);
    Photo* remove(int index);
    int size() const;


    

  private:
    Photo** photos;
    int numPhotos;

    
   
};

#endif
