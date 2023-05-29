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
    int status = 0;

    qDebug() << "";
    status |= QTest::qExec(new TestApiLogic, argc, argv);

    qDebug() << "";
    qDebug() << "";

    status |= QTest::qExec(new TestBook, argc, argv);

    qDebug() << "";
    qDebug() << "";

    status |= QTest::qExec(new TestApiParameters, argc, argv);

    qDebug() << "";
    qDebug() << "";

    // status |= QTest::qExec(new TestBookDetailsWindow, argc, argv);
    // qDebug() << "";
    // qDebug() << "";

    // status |= QTest::qExec(new TestHomePage, argc, argv);
    //
    // qDebug() << "";
    // qDebug() << "";

    status |= QTest::qExec(new TestJsonParse, argc, argv);

    qDebug() << "";
    qDebug() << "";

    // status |= QTest::qExec(new TestSearchResultWindow, argc, argv);
    //
    // qDebug() << "";
    // qDebug() << "";
    return status;
}
