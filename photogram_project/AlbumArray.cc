#include "AlbumArray.h"

AlbumArray::AlbumArray(){
    numAlbums = 0;
    albums = new Album*[MAX_ARRAY];
}

AlbumArray::AlbumArray(const AlbumArray& albumArray){
    numAlbums = albumArray.numAlbums;
    albums = new Album*[MAX_ARRAY];

    for (int i = 0; i < numAlbums; i++){
        albums[i] = new Album(*albumArray.albums[i]);
    }
}

//AlbumArray::~AlbumArray(){
//   for (int i = 0; i < numAlbums; i++){
//        delete albums[i];
//    }
//    delete [] albums;
//}

// if there exist an error in this function, 
// check this line: if (album->lessThan(*albums[i])){
bool AlbumArray::add(Album* album){
    if (album == NULL){
        return false;
    }

    int index = 0;
    for (int i = 0; i < numAlbums; i++){
        if (album->lessThan(*albums[i])){
            break;
        }
        ++index;
    }

    for (int i = numAlbums; i > index; i--){
        albums[i] = albums[i - 1];
    }
    
    albums[index] = album;
    numAlbums++;
    return true;
}



Album* AlbumArray::get(string title) const{

    if (numAlbums==0){
    	//cout<<"no albums"<<endl;
    	return NULL;
    }	
	
    for (int i = 0; i < numAlbums; i++){
        //cout<<albums[i] << endl;
        if (albums[i]->equals(title)){
            return albums[i];
        }
    }
    return NULL;
}


Album* AlbumArray::get(int index) const{
    if (index < 0 || index >= numAlbums){
        return NULL;
    }
    return albums[index];
}

Album* AlbumArray::remove(string title){
    if (numAlbums == 0){
        return NULL;
    }

    for (int i = 0; i < numAlbums; i++){
        if (albums[i]->equals(title)){
           Album* output = albums[i];
           for (int j = i; j < numAlbums - 1; j++){
            albums[j] = albums[j +1];
           }
           numAlbums--;
           return output;
        }
    }
    return NULL;
}


Album* AlbumArray::remove(int index){
    if (index < 0 || index >= numAlbums){
        return NULL;
    }
    Album* output = albums[index];

    for (int i = index; i < numAlbums - 1; i++){
        albums[i] = albums[i + 1];
    }

    numAlbums--;
    delete output;
    return output;
}

int AlbumArray::size() const{
    return numAlbums;
}
