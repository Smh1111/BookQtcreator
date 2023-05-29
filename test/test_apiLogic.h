#ifndef TEST_APILOGIC_H
#define TEST_APILOGIC_H
#include <QtTest>
#include "../api_logic.h"


class TestApiLogic : public QObject
{
    Q_OBJECT

private slots:
    void testMakeApiCall_data();
    void testMakeApiCall();

private:
    Api_Logic apiLogic;
};

#endif // TEST_APILOGIC_H
