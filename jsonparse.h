#ifndef JSONPARSE_H
#define JSONPARSE_H
/**
 * @file book.cpp
 * @author Soe Moe Htet (65011693), Phyo Thi Khaing (65011466), Myo Pa Pa Kyaw (65011368)
 * @brief This file handles the json parser. It contains the functions for parsing json.
 *       It also contains the necessary variables for the json parser. 
 * @version 0.1
 * @date 2023-05-29
 * @copyright Copyright (c) 2023
 * 
 */
#include <QObject>
#include "book.h"

/**
 * @brief This class handles the json parser. It contains the functions for parsing json.
 * 
 */
class JsonParse : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief JsonParse explicit constructor
     * @param parent
     */
    explicit JsonParse(QObject* parent = nullptr): QObject(parent) {}

    bool parseJson(const QString& jsonString);      // Parse the json string

    void printData();                               // Print the data

    void populateData(const QJsonArray& jsonArray); // Populate the data

    QList<Book> getBookList();                      // Get the book list

    // For dynamic binding json values
    void processJson(const QJsonObject& jsonObject); 
    void processJsonArray(const QJsonArray& jsonArray);

    /**
     * @brief processKeyValue
     * @param key
     * @param value
     */
    void processKeyValue(const QString& key, const QJsonValue& value);

private:
    QList<Book> bookList;
};

#endif // JSONPARSE_H
