#include "test_jsonParse.h"
void TestJsonParse::testParseJson()
{
    // Create a test JSON string
    QString jsonString = R"(
        {
            "kind": "books#volumes",
            "totalItems": 2,
            "items": [
                {
                    "volumeInfo": {
                        "title": "Book 1",
                        "description": "Description 1",
                        "authors": ["Author 1"],
                        "publishedDate": "2023-01-01",
                        "pageCount": 100
                    }
                },
                {
                    "volumeInfo": {
                        "title": "Book 2",
                        "description": "Description 2",
                        "authors": ["Author 2"],
                        "publishedDate": "2023-02-01",
                        "pageCount": 200
                    }
                }
            ]
        }
    )";

    // Create an instance of JsonParse
    JsonParse jsonParse;

    // Parse the JSON string
    bool parseResult = jsonParse.parseJson(jsonString);

    // Verify that parsing was successful
    QVERIFY(parseResult);

    // Get the book list
    QList<Book> bookList = jsonParse.getBookList();

    // Verify the size of the book list
    QCOMPARE(bookList.size(), 2);

    // Verify the values of the first book
    QCOMPARE(bookList[0].getTitle(), QString("Book 1"));
    QCOMPARE(bookList[0].getDescription(), QString("Description 1"));
    QCOMPARE(bookList[0].getAuthors(), QStringList() << "Author 1");
    QCOMPARE(bookList[0].getPublishedDate(), QString("2023-01-01"));
    QCOMPARE(bookList[0].getPageCount(), 100);

    // Verify the values of the second book
    QCOMPARE(bookList[1].getTitle(), QString("Book 2"));
    QCOMPARE(bookList[1].getDescription(), QString("Description 2"));
    QCOMPARE(bookList[1].getAuthors(), QStringList() << "Author 2");
    QCOMPARE(bookList[1].getPublishedDate(), QString("2023-02-01"));
    QCOMPARE(bookList[1].getPageCount(), 200);
}

