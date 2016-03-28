Project 1
=========

This Project is for explorig local filesystem. The application search for files that mach given pattern and search text.

Limitation:
==========

The user search text which the system prompts to enter from keyboard has to be entered first then come "extensions" and "full filenames" in any order, e.g., "FileSystem is good" *.cpp FileMgr.h

For option /f<search_text> there should be a space between /f and <search_text>, e.g., /f FileSystem

Assumption:
==========

As advised, "if there is any path that user wants to feed into the application through command line, then that SHOULD come first before patterns and options". 



Functionality:
=============

The project is about building Catalog that is done upon taking the inputs from command line and search for some text in the files that are there in catalog.

* Initial input can be path, pattern(filename/extension)and also options like
  - /s for building catalog while taking the files in directories into consideration.
  - /d for displaying the duplicates from the catalog.
  - /f <search_text> for searching the given <search_text> in the files stored on catalog.

1) After building the catalog, we display contents of it and when no command line input is given we take current path and build catalog for files that are in there
  (as if there is no "/s" option) and we display information like "M files in N directories" rather than displaying the catalog.

2) Then output console waits for further text searches, if any, the user can by typing in the text also file extensions and full filenames. This search can be done 
   multiple times until user wants to exit by just pressing ENTER.

