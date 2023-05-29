#ifndef APIPARAMETERS_H
#define APIPARAMETERS_H
/**
 * @file book.cpp
 * @author Soe Moe Htet (65011693), Phyo Thi Khaing (65011466), Myo Pa Pa Kyaw (65011368)
 * @brief This file handles the api parameters. It contains the setter and getter functions for the api parameters.
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <QObject>
#include <QString>
#include <QUrlQuery>
#include <QMap>

/**
 * @brief This class handles logic about the api parameters. It contains the setter and getter functions for the api parameters.
 * 
 */
class ApiParameters: public QObject
{
public:
    /**
     * @brief ApiParameters constructor
     *
     */
    explicit ApiParameters(QObject *parent = nullptr);

    void setQuery(const QString& query, int maxResult); // Set the query string and the max result

    /**
     * @brief getQueryString
     * @return QString
     */
    QString getQueryString() const; // Get the query string

    // Dynamic parameter handling
    /**
     * @brief setParameter
     * @param key
     * @param value
     */
    void setParameter(const QString& key, const QString& value);
    /**
     * @brief removeParameter
     * @param key
     */
    void removeParameter(const QString& key);
    /**
     * @brief buildRequestUrl
     * @param baseUrl
     * @return QUrl
     */
    QUrl buildRequestUrl(const QUrl& baseUrl) const; // Build the request url with the base url and the query string


private:
    QUrlQuery urlQuery;


};

#endif // APIPARAMETERS_H
