#include "apiparameters.h"
#include "QDebug"

ApiParameters::ApiParameters(QObject *parent) : QObject(parent)
{

}

/*
 * Set the query for the APi parameter
 *
 *
 */
void ApiParameters::setQuery(const QString& query)
{
    qDebug() << "Query in api param = " << query;
    urlQuery.clear();
    urlQuery.addQueryItem("q", query);
    urlQuery.addQueryItem("maxResults", "5");




    auto apiKey = "AIzaSyBEu08wHao57QatWkgO4DmyhLX00CRYQag";
    urlQuery.addQueryItem("key", apiKey);


    qDebug() << "urlQuery = " << urlQuery.toString();


}

QString ApiParameters::getQueryString() const
{

    return urlQuery.query();
}


