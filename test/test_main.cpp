#include <QCoreApplication>
#include <QTest>

// Include your test headers here
#include "test_apiLogic.h"
#include "test_book.h"
#include "test_apiParameters.h"
#include "test_bookDetailswindow.h"
#include "test_homePage.h"
#include "test_jsonParse.h"
#include "test_searchResultwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Run all the tests silently



    QTest::qExec(new TestApiLogic, argc, argv);



    QTest::qExec(new TestBook, argc, argv);



    QTest::qExec(new TestApiParameters, argc, argv);



    // status |= QTest::qExec(new TestBookDetailsWindow, argc, argv);
    // qDebug() << "";
    // qDebug() << "";

    // status |= QTest::qExec(new TestHomePage, argc, argv);
    //
    // qDebug() << "";
    // qDebug() << "";

    QTest::qExec(new TestJsonParse, argc, argv);


    // status |= QTest::qExec(new TestSearchResultWindow, argc, argv);
    //
    // qDebug() << "";
    // qDebug() << "";

    system("pause");
    return 0;
}
