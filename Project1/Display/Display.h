#ifndef DISPLAY_H
#define DISPLAY_H
/////////////////////////////////////////////////////////////////////////////
// Display.h - To display DataStore contents and console messages          //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyright © Sai Krishna Bandaru, 2015                                   //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2013                             //
// Platform:    ASUS SonicMaster, Core i3, Windows 8.1                     //
// Application: Project 1, 2015		                                       //
// Author:      Sai Krishna,Syracuse University					           //
//              (832) 940-8083, sbandaru@syr.edu                           //
/////////////////////////////////////////////////////////////////////////////
/*
* Module Operations:
* ==================
* This module is used to display DataStore contents in a reliable format and also some console messages
*
* Public Interface:
* =================
*display() function is used to print the selected contents of file and paths to output console
*
*display_args() function is used to print given argumentson to console
*
*display_text() function is used to print some text to output console
*
*
* Required Files:
* ===============
* DataStore.h ,Display.h and Display.cpp
*
* Build Command:
* ==============
* cl /EHsc /DTEST_DISPLAY Display.cpp ../Project1/DataStore.cpp ../FileMgr/FileMgr.cpp ../FileSystem/FileSystem.cpp ../Catalog/Catalog.cpp
*
* Maintenance History:
* ====================
* ver 1.0 Jan 30 2015
*
*/
#include<iostream>
#include<set>
#include<map>
#include<string>
#include <list>
#include <iomanip>
#include "../Project1/DataStore.h"
#include "../FileMgr/FileMgr.h"

class Display
{
public:
	using filename = std::string;
	using path = std::string;
	using pathset = std::set < path >;
	using itr_pathset = pathset::iterator;
	using reflist = std::list < itr_pathset >;
	using filemap = std::map < filename, reflist>;
	using filemap1 = std::map < filename&, reflist>;

	itr_pathset itr_pathset1;
	reflist::iterator itr_reflist1;

	Display(DataStore& ds) :datastore1(ds){}; //initializing the DataStore object at constructor
	void display(int);
	static void display_text(std::string);
	static void display_args(int argc, char* argv[]);
	void Display::display_filenumber(std::string str, int num);
	
private:
	DataStore& datastore1;
};


#endif
