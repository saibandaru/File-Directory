:run.bat

cd Project1/debug 


@echo OFF
@echo:
echo Requirment 3 Case 1:When relative path is given:
Exec.exe ../../Root 

@echo:
echo Requirment 3 Case 2:When a pattern is given:
Exec.exe ../../Root *.cpp *.h *.obj

echo Requirment 3 Case 3:When /s swith is given path is given:
Exec.exe ../../Root /s 

@echo:
echo Requirment 5:To display the duplicate files when /d option is given:
Exec.exe ../../Root /s /d 

@echo:
echo Requirment 6:When /f <search_text> is given :
Exec.exe ../../Root /s /f File  

@echo:
echo Requirment 7:When no command line agruments are given path is given:
Exec.exe 


cd ../..