#include "homepage.h"

#include <QApplication>
/**
*@mainpage BookFinderApp Documentation
 * @section Book Finder App Introduction
 * This is the documentation
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomePage w;

    w.show();
    return a.exec();
}
