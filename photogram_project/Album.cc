#include "Album.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "Photo.h"

Album::Album(string title, string description){
    this->title = title;
    this->description = description;
    photos = new PhotoArray();
}

Album::Album(const Album &album){
	
    title = album.title;
    description = album.description;
    photos = new PhotoArray(*album.photos);
    
	
}

Album::~Album(){
    //delete photos;

    for (int i = 0; i < photos->size(); i++){
        delete photos->get(i);
    }
    delete photos;
}

string Album::getTitle() const{
    return title;
}

Photo* Album::getPhoto(string title) const{
    return photos->get(title);
}

Photo* Album::getPhoto(int index) const{
    return photos->get(index);
}

bool Album::equals(string t) const{
    if (title == t){
        return true;
    }
    return false;
}

bool Album::lessThan(Album& alb) const{
    if (title < alb.title){
        return true;
    }
    return false;
}

bool Album::addPhoto(Photo* photo){
    return photos->add(photo);
}

bool Album::addPhoto(int index, Photo* photo){
    return photos->add(index, photo);
}

Photo* Album::removePhoto(string title){
    for (int i = 0; i < photos->size(); i++){
        if (photos->get(i)->equals(title)){
            return photos->remove(i);
        }
    }
    return NULL;
}

Photo* Album::removePhoto(int index){
    return photos->remove(index);
}

void Album::print() const{
    cout<<""<<endl;
    cout<<"Album title: "<<title<<", Album description: "<<description<<endl;
    // cout<<"Photos: "<<endl;
    // for (int i = 0; i < photos->size(); i++){
    //     photos->get(i)->print();
    // }
    cout<<""<<endl;

}

void Album::display() const{
    cout<<"Album title: "<<title<<", Album description: "<<description<<endl;
    cout<<"Photos: "<<endl;
    for (int i = 0; i < photos->size(); i++){
        photos->get(i)->display();
    }
}

int Album::size() const{
    return photos->size();
}



