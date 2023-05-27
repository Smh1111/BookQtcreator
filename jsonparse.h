#ifndef JSONPARSE_H
#define JSONPARSE_H
#include <QObject>
#include "book.h"

class JsonParse : public QObject
{
    Q_OBJECT
public:
    explicit JsonParse(QObject* parent = nullptr): QObject(parent) {}

    bool parseJson(const QString& jsonString);

    void printData();

    void populateData(const QJsonArray& jsonArray);

    QList<Book> getBookList();

    // For dynamic binding json values
    void processJson(const QJsonObject& jsonObject);
    void processJsonArray(const QJsonArray& jsonArray);
    void processKeyValue(const QString& key, const QJsonValue& value);



private:
    QList<Book> bookList;




};

#endif // JSONPARSE_H
