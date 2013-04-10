#include <iostream>
#include <fstream>
#include <locale>
#include "WindowSettings.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	//TEMP::SettingsManager mgr("myfile.xml");

    QApplication a(argc, argv);
    Ui::MainWindow w;
    w.show();
    
    return a.exec();
}