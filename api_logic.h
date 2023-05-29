#ifndef API_LOGIC_H
#define API_LOGIC_H

/**
 * @file book.cpp
 * @author Soe Moe Htet (65011693), Phyo Thi Khaing (65011466), Myo Pa Pa Kyaw (65011368)
 * @brief This file handles the api logic. It contains the api call function and the api reply handler function.
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>

/**
 * @brief This class handles the api logic. It contains the api call function and the api reply handler function.
 * 
 */
class Api_Logic : public QObject
{
    Q_OBJECT
public:
    explicit Api_Logic(QObject *parent = nullptr);

public slots:
    void makeApiCall(const QString& query);

signals:
    /**
     * @brief apiResponseReceived Signal when api response is received
     * @param response
     */
    void apiResponseReceived(QString response);

    /**
     * @brief apiErrorOccurred
     * @param networkReply
     * @param replyError
     */
    void apiErrorOccurred(QNetworkReply::NetworkError networkReply, const QString replyError );

private slots:
    /**
     * @brief handleApiReply Slot when handling ApiReply
     * @param reply
     */
    void handleApiReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;

};

#endif // API_LOGIC_H
