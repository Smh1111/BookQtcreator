#include "api_logic.h"
#include "QDebug"

Api_Logic::Api_Logic(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager(this);
}

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

void Api_Logic::handleApiReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QString response = reply->readAll();
        emit apiResponseReceived(response);
    } else {
        // Handle error

    }
}
