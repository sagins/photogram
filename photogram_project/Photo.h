#ifndef PHOTO_H
#define PHOTO_H

#include <iomanip>
#include <iostream>
#include <string>
#include "Date.h"

class Photo
{
  public:
    // constructors
    Photo(const string& title, const Date& date, const string& content);
    Photo(const Photo& otherPhoto);
    Photo();

    // destructors
    ~Photo();

    // other functions
    bool equals(const string& title) const;
    void print() const;
    void display() const;


  private:
    const string title;
    const string content;
    const Date date;


};

#endif

