
#include "test_apiLogic.h"

void TestApiLogic::testMakeApiCall_data()
{
    QTest::addColumn<QString>("query");

    QTest::newRow("Valid Query") << "q=Harry Potter";
    QTest::newRow("Empty Query") << "";
    QTest::newRow("Invalid Query") << "q=Invalid!@#$%";
}

void TestApiLogic::testMakeApiCall()
{
    QFETCH(QString, query);

    QSignalSpy responseSpy(&apiLogic, &Api_Logic::apiResponseReceived);

    apiLogic.makeApiCall(query);

    QTest::qWait(1000); // Wait for the API call to complete (adjust the delay if needed)

    if (responseSpy.isEmpty()) {
        QFAIL("No API response received");
    }


}
