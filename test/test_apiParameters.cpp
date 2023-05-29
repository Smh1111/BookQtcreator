#include "test_apiParameters.h"

void TestApiParameters::testSetQuery()
{
    ApiParameters apiParameters;

    // Call the setQuery function
    apiParameters.setQuery("Harry Potter", 10);

    // Test the values using QCOMPARE or other assertion functions
    QCOMPARE(apiParameters.getQueryString(), QString("q=Harry Potter&maxResults=10"));
}

void TestApiParameters::testGetQueryString()
{
    ApiParameters apiParameters;

    // Set up the initial state of the object

    // Call the getQueryString function and compare the result
    QCOMPARE(apiParameters.getQueryString(), QString());

    // Make further changes to the object's state

    // Call the getQueryString function again and compare the updated result
    QCOMPARE(apiParameters.getQueryString(), QString());
}

