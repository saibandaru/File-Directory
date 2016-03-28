//display.h...
#include <vector>
#include<iostream>
#include<set>
#include<map>
#include<string>
#include <list>
#include <iomanip>

#include "../Project1/DataStore.h"
#include "Display.h"

void Display::display(int i)
{
	filemap::iterator itr_filemap1;
	int no_f = 0, no_d = 0;
	if (i == 1)
	{
		std::cout << "PRINTING DUPLICATE FILES:\n";
	}
	for (itr_filemap1 = datastore1.begin_map(); itr_filemap1 != datastore1.end_map(); itr_filemap1++)
	{
		reflist reflist_display = itr_filemap1->second;
		reflist::iterator itr_reflist_display;
		if (i == 0 || (i == 1 && reflist_display.size() > 1))
			std::cout << itr_filemap1->first << "\n";

		for (itr_reflist_display = reflist_display.begin(); itr_reflist_display != reflist_display.end(); itr_reflist_display++)
		{
			if (i == 0)
			{
				std::cout << std::left << std::setw(18) << "   " << (*(*itr_reflist_display)) << "\n";
			}
			else if (i == 1)
			{
				if (reflist_display.size() > 1)
				{
					std::cout << std::left << std::setw(18) << "   " << (*(*itr_reflist_display)) << "\n";
				}
			}
			else
			{
				++no_f;
			}
		}
	}
	if (i == 3)
	{
		std::cout << "Number of files      :" << no_f << "\n";
		std::cout << "Number of directories: 1" << "\n";
	}
}