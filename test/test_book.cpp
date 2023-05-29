#include <QtTest>
#include "../book.h"
#include "test_book.h"

void TestBook::testSetTitle()
    {
        Book book;
        book.setTitle("Sample Title");
        QCOMPARE(book.getTitle(), QString("Sample Title"));
    }

void TestBook::testSetISBN()
    {
        Book book;
        QStringList isbnList;
        isbnList << "ISBN1" << "ISBN2";
        book.setISBN(isbnList);
        QCOMPARE(book.getISBNList(), isbnList);
    }

void TestBook::testSetDescription()
    {
        Book book;
        book.setDescription("Sample Description");
        QCOMPARE(book.getDescription(), QString("Sample Description"));
    }

void TestBook::testSetAuthors()
    {
        Book book;
        QStringList authors;
        authors << "Author1" << "Author2";
        book.setAuthors(authors);
        QCOMPARE(book.getAuthors(), authors);
    }

void TestBook::testSetPublishedDate()
    {
        Book book;
        book.setPublishedDate("2023-05-29");
        QCOMPARE(book.getPublishedDate(), QString("2023-05-29"));
    }

void TestBook::testSetPageCount()
    {
        Book book;
        book.setPageCount(100);
        QCOMPARE(book.getPageCount(), 100);
    }

void TestBook::testSetImageLinks()
    {
        Book book;
        QStringList imageLinks;
        imageLinks << "link1" << "link2";
        book.setImageLinks(imageLinks);
        QCOMPARE(book.getImageLinks(), imageLinks);
    }

void TestBook::testSetInfoLink()
    {
        Book book;
        book.setInfoLink("infoLink");
        QCOMPARE(book.getInfoLink(), QString("infoLink"));
    }

void TestBook::testSetPreviewLink()
    {
        Book book;
        book.setPreviewLink("previewLink");
        QCOMPARE(book.getPreviewLink(), QString("previewLink"));
    }

