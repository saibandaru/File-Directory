/////////////////////////////////////////////////////////////////////////////
// Display.cpp - To print the datastore contents onto output console and   //
//					also title texts									   //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyright © Sai Krishna Bandaru, 2015                                   //
// All rights granted provided that this notice is retained                //
// ----------------------------------------------------------------------- //
// Language:    Visual C++, Visual Studio 2013                             //
// Platform:    ASUS SonicMaster, Core i3, Windows 8.1                     //
// Application: Project 1, 2015		                                       //
// Author:      Sai Krishna,Syracuse University					           //
//              (832) 940-8083, sbandaru@syr.edu			               //
/////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<set>
#include<map>
#include<string>
#include <list>
#include <iomanip>
#include "Display.h"

//----< To display text to console like a header or title >-----------------------------------------------------------------------------------

void Display::display_text(std::string str){
	std::cout << "==========================================================================================\n";
	std::cout << str<<"\n"; 
	std::cout << "==========================================================================================\n";
}
void Display::display_filenumber(std::string str,int num){
	std::cout << str << num<<"\n";
	}

//----< To display command line arguments to console so that the catalog is more readable >---------------------------------------------------

void Display::display_args(int argc, char* argv[]){
	std::cout << "Command Line Arguments :";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << "  ";
	std::cout << "\n\n";
}

//----< To display file and corresponding paths stored in datastore based on the given option(display whole darastore or duplicates >----------

void Display::display(int i)  //parameter i=0 for whole datastore, i=1 forduplicates and i=3 for no command line i/p is given
{
	filemap::iterator itr_filemap1;
	int no_f = 0, no_d = 1;
	if (i == 1) Display::display_text("\t\t\t\t Duplicate Files"); 
	if (i != 3)	Display::display_text("FILE					PATH");
	pathset::iterator itr_pathset1 = (datastore1.begin_path());
	for (itr_filemap1 = datastore1.begin_map(); itr_filemap1 != datastore1.end_map(); itr_filemap1++){
		reflist reflist_display = itr_filemap1->second;
		reflist::iterator itr_reflist_display;
		if (i == 0 || (i == 1 && reflist_display.size() > 1))
			std::cout << itr_filemap1->first << "\n";
		for (itr_reflist_display = reflist_display.begin(); itr_reflist_display != reflist_display.end(); itr_reflist_display++){
			if (i == 0){ std::cout << std::left << std::setw(18) << "   " << (*(*itr_reflist_display)) << "\n"; ++no_f; }
			else if (i == 1){ 
				if (reflist_display.size() > 1){++no_f;			//count for duplicates
					std::cout << std::left << std::setw(18) << "   " << (*(*itr_reflist_display)) << "\n";
				}
			}
			else{ ++no_f; }				//count for no command line input
		}
	}
	if (i == 3){						// when no command line input is given
		std::cout << no_f << " files found in " << no_d << " directories\n";
		
	}
	else{
		Display::display_filenumber("Number of files      :", no_f);
	}
}


//----< test stub >---------------------------------------------------------------------------------------------------------------------------

#ifdef TEST_DISPLAY

int main(int argc, char* argv[])
{
	DataStore ds;
	Display::display_args(argc, argv);
	Display::display_text("THIS IS TO TEST DISPLAY TEST FUNCTION");
	FileMgr fm(".", ds);
	fm.initilize(argc, argv);
}
#endif
