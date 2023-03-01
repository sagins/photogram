#include "PhotoGram.h"

PhotoGram::PhotoGram(){
    albumArray = new AlbumArray();
}

PhotoGram::~PhotoGram(){
    for (int i = 0; i < albumArray->size(); i++){
        delete albumArray->get(i);
    }
    delete albumArray;
}

bool PhotoGram::addAlbum(string title, string description){
    Album* album = new Album(title, description);
    
    if (albumArray->add(album)){
        return true;
    }
    else {
        cout<<"Failed to add album!"<<endl;
        return false;
    }
}


bool PhotoGram::removeAlbum(string title){
    for (int i = 0; i < albumArray->size(); i++){
        if (albumArray->get(i)->equals(title)){
            albumArray->remove(i);
            return true;
        }
    }
    cout<<"Failed to remove album!"<<endl;
    return false;
}


bool PhotoGram::addPhoto(string albumTitle, const Photo& photo){
    Album* album = albumArray->get(albumTitle);
    if (album == NULL){
        return false;
    }

    Photo* newPhoto = new Photo(photo);

    return album->addPhoto(newPhoto);
}


bool PhotoGram::removePhoto(string albumTitle, string photoTitle){
    
    Album* album = albumArray->get(albumTitle);
    if (album == NULL){
        return false;
    }
    
    Photo* photo = album->removePhoto(photoTitle);
    if (photo == NULL){
        return false;
    }
    delete photo;
    return true;

}

   
Album* PhotoGram::downloadAlbum(string album) const{
    return albumArray->get(album);
}

Photo* PhotoGram::downloadPhoto(const string albumName, const string photoName) const{
   
   Album* album = downloadAlbum(albumName);
   //return album->getPhoto(photoName);
   

   
   //cout << "IN photogram" << endl;
    if (album == NULL){
    	cout<<"The album is null"<<endl;
        return NULL;
    }

    Photo* photo = album->getPhoto(photoName);
    if (photo == NULL){
    	cout<<"The photo is null"<<endl;
        return NULL;
    }
    
    return photo;
   
    
    

}


void PhotoGram::printAlbums() const{
    cout<<"Printing all albums stored in the PhotoGram: "<<endl;
    cout<<""<<endl;

    for (int i = 0; i < albumArray->size(); i++){
        albumArray->get(i)->print();
        cout<<""<<endl;
    }

}


void PhotoGram::displayAlbums() const{
    cout<<"Displaying all albums stored in the PhotoGram: "<<endl;
    cout<<""<<endl;

    for (int i = 0; i < albumArray->size(); i++){
        albumArray->get(i)->display();
        cout<<""<<endl;
    }
}
