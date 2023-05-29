#include "apiparameters.h"
#include "QDebug"

ApiParameters::ApiParameters(QObject *parent) : QObject(parent)
{

}
/**
 * @brief This function sets the query string and the max result. 
 *      It also sets the order by and the api key. 
 *     The query string is the search term.
 *    The max result is the number of results to be shown.
 *      The order by is showing the newest books first.
 * @param query  
 * @param maxResult     
 */
void ApiParameters::setQuery(const QString& query, int maxResult)
{
    qDebug() << "Query in api param = " << query;
    urlQuery.clear();
    urlQuery.addQueryItem("q", query);
    urlQuery.addQueryItem("maxResults", QString::number(maxResult));


    urlQuery.addQueryItem("orderBy", "newest");

    auto apiKey = "AIzaSyBEu08wHao57QatWkgO4DmyhLX00CRYQag";
    urlQuery.addQueryItem("key", apiKey);


    qDebug() << "urlQuery = " << urlQuery.toString();


}


QString ApiParameters::getQueryString() const
{

    return urlQuery.query();
}


