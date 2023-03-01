#include "Photo.h"

Photo::Photo(const string& title, const Date& date, const string& content)
   : title(title), date(date), content(content)
{}


Photo::Photo(const Photo& otherPhoto)
   : title(otherPhoto.title), date(otherPhoto.date), content(otherPhoto.content)
{

}


Photo::Photo()
   : title(""), date(Date()), content("")
{}

bool Photo::equals(const string& title) const{
    return this->title == title;
}

Photo::~Photo(){
    cout<<"-- Photo dtor:  "<< title <<endl;
}

void Photo::print() const{
	cout<<"Title: "<<title<<endl;
	//cout<<"Date: "<<endl;
	date.print();
}

void Photo::display() const{
	print();
	cout<<"Content: "<<content<<endl;
}



