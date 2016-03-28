#ifndef CATALOG_H
#define CATALOG_H
//display.h...

#include <iostream>
#include <string>

#include "../FileSystem/FileSystem.h"
#include "../Project1/DataStore.h"

class Catalog
{
	public:
		Catalog(DataStore& ds) :datastore1(ds){};
		void search_text(std::string s_text)
		{
			std::string text;
			int flag = 0;
			std::string filename;
			std::cout << "\n\nTHE SEARCH TEXT IS FOUND IN FOLLOWING FILES:\n\n";
			DataStore datastore2;
			for (datastore1.itr_filemap1 = datastore1.begin_map(); datastore1.itr_filemap1 != datastore1.end_map(); datastore1.itr_filemap1++)
			{
				
				filename = datastore1.itr_filemap1->first;
				datastore1.reflist1 = datastore1.itr_filemap1->second;
				reflist reflist2;
				for (datastore1.itr_reflist1 = datastore1.reflist1.begin(); datastore1.itr_reflist1 != datastore1.reflist1.end(); ++datastore1.itr_reflist1)
				{
					flag = 0;
					FileSystem::Directory::setCurrentDirectory(*(*datastore1.itr_reflist1));
					FileSystem::File fl(filename);
					if (fl.open(FileSystem::File::in, FileSystem::File::text))
					{
						text = fl.readAll(false);
						if (text.find(s_text) != std::string::npos)
						{
							if (flag == 0)
							{
								flag = 1;
								//std::cout << filename<<"\n";
							}
							reflist2.push_back(*datastore1.itr_reflist1);
							break;
						}

					}
				}
				if (reflist2.size() >= 1)
				{
					datastore2.save_map(filename, reflist2);
				}

			}
			Display dis(datastore2);
			dis.display(0);
		}
	private:
		DataStore& datastore1;
		std::string save_text;

};


#endif