#ifndef TESTBOOKDETAILSWINDOW_H
#define TESTBOOKDETAILSWINDOW_H

#include <QtTest>
#include "../bookdetailswindow.h"
#include "../book.h"

class TestBookDetailsWindow : public QObject
{
    Q_OBJECT

private slots:
    void testBookDetailsWindow();
};

#endif // TESTBOOKDETAILSWINDOW_H
