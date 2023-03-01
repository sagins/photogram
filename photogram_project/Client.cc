#include "Client.h"

Client::Client(){
    array = new AlbumArray();
}

Client::~Client(){
    for (int i = 0; i < array->size(); i++){
        delete array->get(i);
    }
    delete array;
}

bool Client::downloadAlbum(PhotoGram* pg, string albumTitle){
    Album* album = pg->downloadAlbum(albumTitle);

    if (album == NULL || array->size() == MAX_ARRAY){
        cout<<"Could not download album."<<endl;
        return false;
    }

    // make a deep copy of the album and add it to the array
    Album* newAlbum = new Album(*album);
    return array->add(newAlbum);

}

bool Client::displayOnlinePhoto(PhotoGram* pg, string albumTitle, string photoTitle) const{
    
    Album* album = pg->downloadAlbum(albumTitle);

    if (album == NULL){
        cout<<"Album does not exist."<<endl;
        return false;
    }

    Photo* photo = album->getPhoto(photoTitle);

    if (photo == NULL){
        cout<<"Photo does not exist."<<endl;
        return false;
    }

    photo->display();
    return true;
}

bool Client::displayLocalPhoto(string albumTitle, string photoTitle) const{

    Album* album = array->get(albumTitle);
    if (album == NULL){
        cout<<"The album does not exist"<<endl;
        return false;
    }

    Photo* photo = album->getPhoto(photoTitle);

    if (photo == NULL){
        cout<<"The photo does not exist"<<endl;
        return false;
    }

    photo->display();
    return true;
}


void Client::printLocalAlbums() const{
    cout<<"Printing local albums: "<<endl;
    for (int i = 0; i < array->size(); i++){
        array->get(i)->print();
    }
}



void Client::displayLocalAlbums() const{
    cout<<"Displaying local albums: "<<endl;
    for (int i = 0; i < array->size(); i++){
        array->get(i)->display();
    }
}
