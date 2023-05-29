#ifndef TEST_APIPARAMETERS_H
#define TEST_APIPARAMETERS_H

#include <QObject>
#include <QtTest>

// Include the header file for the class you want to test
#include "../apiparameters.h"

class TestApiParameters : public QObject
{
    Q_OBJECT

private slots:
    // Add your test functions here
    void testSetQuery();
    void testGetQueryString();
};

#endif // TEST_APIPARAMETERS_H
