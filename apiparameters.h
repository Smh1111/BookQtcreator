#ifndef APIPARAMETERS_H
#define APIPARAMETERS_H

#include <QObject>
#include <QString>
#include <QUrlQuery>
#include <QMap>

class ApiParameters: public QObject
{
public:
    explicit ApiParameters(QObject *parent = nullptr);

    void setQuery(const QString& query, int maxResult);

    QString getQueryString() const;

    // Dynamic parameter handling

    void setParameter(const QString& key, const QString& value);
    void removeParameter(const QString& key);
    QUrl buildRequestUrl(const QUrl& baseUrl) const;


private:
    QUrlQuery urlQuery;


};

#endif // APIPARAMETERS_H
