#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include <iomanip>
#include "PhotoArray.h"

using namespace std;

class Album {
		
	public:
		//constructors
        	Album(string title, string description);
		// copy constructor
		Album(const Album&);
		// destructors
		~Album();
		
		//setters
		
		//getters
		string getTitle() const;
		Photo* getPhoto(string title) const;
		Photo* getPhoto(int index) const;


		//other
		bool equals(string t) const;
		bool lessThan(Album& alb) const;
		bool addPhoto(Photo* photo);
		bool addPhoto(int index, Photo* photo);
		Photo* removePhoto(string title);
		Photo* removePhoto(int index);
		void print() const;
		void display() const;
		int size() const;
	
	private:
		//functions
	
		//variables
		string title;
		string description;
		PhotoArray* photos;


        
	
	
};
#endif
