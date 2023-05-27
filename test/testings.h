#ifndef TESTINGS_H
#define TESTINGS_H



#include <QtTest/QtTest>

class BookTest : public QObject {
    Q_OBJECT

private slots:
    // Declare test functions as slots

    void testTitle();
    void testDescription();
    void testAuthors();
    void testPublishedDate();
    void testPageCount();
};

class JsonParseTest : public QObject {
    Q_OBJECT

private slots:
    void testParseJson();
};



#endif // TESTINGS_H
