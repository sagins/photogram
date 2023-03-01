#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include "PhotoGram.h"
#include <random>
#include <unordered_set>

using namespace std;

class TestControl {
		
	public:
		void launch();
	
	private:
		int  photoTest();
		int  albumTest();
		int  albumArrayTest();
		int  photoGramTest();
		int  clientTest();

		//initialize with some Songs and Albums
		void initialize(PhotoGram*);

		// generate a set (no duplicates) of "count" random integers
		// from 0 to "range"
		void ran(unordered_set<int>& s, int count, int range);
		// generate a random integer in the given range
		int ran(int range_from, int range_to);

		// Some initial data
		const static string albumTitles[5];
		const static string descriptions[5];
		const static string photoTitles[5][5];
		const static string photoContent[5][5];
	
};
#endif
