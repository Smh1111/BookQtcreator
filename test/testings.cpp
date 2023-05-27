#include "testings.h"
#include "../book.h"
#include "../jsonparse.h"


void BookTest::testTitle() {
    Book book;
    book.setTitle("The Great Gatsby");
    QCOMPARE(book.getTitle(), QString("The Great Gatsby"));
}

void BookTest::testDescription() {
    Book book;
    book.setDescription("A novel by F. Scott Fitzgerald");
    QCOMPARE(book.getDescription(), QString("A novel by F. Scott Fitzgerald"));
}

void BookTest::testAuthors() {
    Book book;
    QStringList authors = {"F. Scott Fitzgerald"};
    book.setAuthors(authors);
    QCOMPARE(book.getAuthors(), authors);
}

void BookTest::testPublishedDate() {
    Book book;
    book.setPublishedDate("April 10, 1925");
    QCOMPARE(book.getPublishedDate(), QString("April 10, 1925"));
}

void BookTest::testPageCount() {
    Book book;
    book.setPageCount(180);
    QCOMPARE(book.getPageCount(), 180);
}


void JsonParseTest::testParseJson() {
    JsonParse jsonParse;

    // Prepare test JSON data
    QString jsonData = "{\"kind\":\"books#volumes\",\"totalItems\":1,\"items\":[{\"volumeInfo\":{\"title\":\"Book Title\",\"description\":\"Book Description\",\"authors\":[\"Author 1\",\"Author 2\"],\"publishedDate\":\"2023-01-01\",\"pageCount\":200}}]}";

    // Perform JSON parsing
    bool success = jsonParse.parseJson(jsonData);

    // Assert the parsing was successful
    QVERIFY(success);

    // Retrieve the list of parsed books
    QList<Book>& bookList = jsonParse.getBookList();

    // Assert the number of parsed books
    QCOMPARE(bookList.size(), 1);

    // Retrieve the first book from the list
    Book& book = bookList[0];

    // Assert the book properties
    QCOMPARE(book.getTitle(), QString("Book Title"));
    QCOMPARE(book.getDescription(), QString("Book Description"));

    QStringList expectedAuthors = {"Author 1", "Author 2"};
    QCOMPARE(book.getAuthors(), expectedAuthors);

    QCOMPARE(book.getPublishedDate(), QString("2023-01-01"));
    QCOMPARE(book.getPageCount(), 200);
}
