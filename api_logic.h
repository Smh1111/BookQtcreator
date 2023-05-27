#ifndef API_LOGIC_H
#define API_LOGIC_H


#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>


class Api_Logic : public QObject
{
    Q_OBJECT
public:
    explicit Api_Logic(QObject *parent = nullptr);

public slots:
    void makeApiCall(const QString& query);

signals:
    void apiResponseReceived(QString response);

private slots:
    void handleApiReply(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;

};

#endif // API_LOGIC_H
