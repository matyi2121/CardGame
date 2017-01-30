
windres resources.rc resources.o
g++ -Wall -Wextra -Weffc++ -c mainwindow.cpp -o mainwindow.o
g++ -Wall -Wextra -Weffc++ -c aboutdlg.cpp -o aboutdlg.o
g++ -mwindows -o cardgame.exe mainwindow.o aboutdlg.o resources.o