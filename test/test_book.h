#ifndef TEST_BOOK_H
#define TEST_BOOK_H
#include <QtTest>
#include "../book.h"

class TestBook : public QObject
{
    Q_OBJECT

private slots:
    void testSetTitle();
    void testSetISBN();
    void testSetDescription();
    void testSetAuthors();
    void testSetPublishedDate();
    void testSetPageCount();
    void testSetImageLinks();
    void testSetInfoLink();
    void testSetPreviewLink();
};

#endif // TEST_BOOK_H
