#include "test_bookDetailswindow.h"
#include "../book.h"
#include "../bookdetailswindow.h"
#include "QLabel"
void TestBookDetailsWindow::testBookDetailsWindow()
{
    // Create a sample book object
    Book book;

    book.setTitle("Example Title");
    book.setISBN(QStringList() <<"1234567890" << "2233445566");
    book.setAuthors(QStringList() << "Author 1" << "Author 2");
    book.setPublishedDate("2023-05-29");
    book.setDescription("Example Description");
    book.setImageLinks (QStringList() << "http://example.com/book-image.jpg" << "http://example.com/book-image.jpg");
    book.setInfoLink("http://example.com/book-info");

    // Create a book details window and pass the book object
    BookDetailsWindow window(book);

    // Verify the window properties or widget values using assertions
    QCOMPARE(window.windowTitle(), QString("Book Details"));

    // Example assertion for checking the book title
    QLabel* titleLabel = window.findChild<QLabel*>("titleLabel");
    QVERIFY(titleLabel != nullptr);
    QCOMPARE(titleLabel->text(), QString("Title:"));

    QLabel* titleValueLabel = window.findChild<QLabel*>("titleValueLabel");
    QVERIFY(titleValueLabel != nullptr);
    QCOMPARE(titleValueLabel->text(), QString("Example Title"));


    // window.show();

    // QTest::qWait(5000);
}

