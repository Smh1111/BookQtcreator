#include "api_logic.h"
#include "QDebug"

/**
 * @brief Construct a new Api_Logic::Api_Logic object
 * 
 * @param parent 
 */
Api_Logic::Api_Logic(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
}

/**
 * @brief This function makes the api call to the google book api.
 * 
 * @param query The query string for the api call.
 */
void Api_Logic::makeApiCall(const QString& query)
{

    qDebug() << "query = " << query;


    QUrl apiUrl("https://www.googleapis.com/books/v1/volumes");
    apiUrl.setQuery(query);


    qDebug() << "Full path = " << apiUrl;

    QNetworkRequest request(apiUrl);
    QNetworkReply *reply = networkManager->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        handleApiReply(reply);
        reply->deleteLater();
    });
}

/**
 * @brief This function handles the api reply.
 * 
 * @param reply The reply from the api call.
 */
void Api_Logic::handleApiReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QString response = reply->readAll();
        emit apiResponseReceived(response);
    } else {
        // Handle error
        emit apiErrorOccurred(reply->error(), reply->errorString());


    }
}
