#include "PhotoArray.h"
#include <iostream>
using namespace std;




PhotoArray::PhotoArray(){
    numPhotos = 0;
    photos = new Photo*[MAX_ARRAY];
}

PhotoArray::PhotoArray(const PhotoArray& photoArray){
    numPhotos = photoArray.numPhotos;
    photos = new Photo*[MAX_ARRAY];
    for (int i = 0; i < numPhotos; i++){
        photos[i] = new Photo(*photoArray.photos[i]);
    }
}

PhotoArray::~PhotoArray(){}
//PhotoArray::~PhotoArray(){
//cout << "HEY22OO" << endl;
 //   for (int i = 0; i < numPhotos; i++){
//        cout << i << endl;
 //       delete photos[i];
  //  }
  //  cout << "HEYOO" << endl;
  //  delete [] photos;
//}

bool PhotoArray::isFull() const{
    return numPhotos == MAX_ARRAY;
}

bool PhotoArray::add(Photo* photo){
    if (isFull()){
        return false;
    }
    photos[numPhotos] = photo;
    numPhotos++;
    return true;
}

bool PhotoArray::add(int index, Photo* photo){
    if (isFull()){
        return false;
    }
    if (index < 0 || index > numPhotos){
        return false;
    }
    for (int i = numPhotos; i > index; i--){
        photos[i] = photos[i-1];
    }
    photos[index] = photo;
    numPhotos++;
    return true;
}

Photo* PhotoArray::get(string title) const{
    for (int i = 0; i < numPhotos; i++){
        if (photos[i]->equals(title)){
            return photos[i];
        }
    }
    return NULL;
}

Photo* PhotoArray::get(int index) const{
    if (index < 0 || index >= numPhotos){
        return NULL;
    }
    return photos[index];
}

Photo* PhotoArray::remove(string title){
     
    if (numPhotos == 0){
        return NULL;
    }

    for (int i = 0; i < numPhotos; i++){
        if (photos[i]->equals(title)){
            Photo* temp = photos[i];
            for (int j = i; j < numPhotos-1; j++){
                photos[j] = photos[j+1];
            }
            numPhotos--;
            return temp;
        }
    }
    return NULL;
}

Photo* PhotoArray::remove(int index){
    if (index < 0 || index >= numPhotos){
        return NULL;
    }
    Photo* temp = photos[index];
    for (int i = index; i < numPhotos-1; i++){
        photos[i] = photos[i+1];
    }
    numPhotos--;
    return temp;
}

int PhotoArray::size() const{
    return numPhotos;
}




