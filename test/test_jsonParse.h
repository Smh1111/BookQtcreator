#ifndef TESTJSONPARSE_H
#define TESTJSONPARSE_H

#include <QTest>
// Test class for JsonParse
#include "../book.h"
#include "../jsonparse.h"
class TestJsonParse : public QObject
{
    Q_OBJECT

private slots:
    void testParseJson();
    // Add more test functions for other member functions if needed
};

#endif // TESTJSONPARSE_H
