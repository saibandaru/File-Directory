#ifndef DISPLAY_H
#define DISPLAY_H
//display.h...
#include <vector>
#include<iostream>
#include<set>
#include<map>
#include<string>
#include <list>
#include <iomanip>

#include "../Project1/DataStore.h"


using filename = std::string;
using path = std::string;
using pathset = std::set < path >;
using itr_pathset = pathset::iterator;
using reflist = std::list < itr_pathset >;
using filemap = std::map < filename, reflist>;


class Display
{
public:
	itr_pathset itr_pathset1;
	reflist::iterator itr_reflist1;
	Display(DataStore& ds) :datastore1(ds){};
	void display(int);
	
private:
	DataStore& datastore1;
};


#endif
