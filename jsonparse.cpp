#include "jsonparse.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QDebug>

void JsonParse::populateData(const QJsonArray& jsonArray)
{
    for (const QJsonValue& value : jsonArray) {
        if (value.isObject()) {
            QJsonObject bookObject = value.toObject();

            // Create a new Book object
            Book book;

            // Set values from the bookObject to the Book object
            QJsonObject volumeInfo = bookObject.value("volumeInfo").toObject();
            book.setTitle(volumeInfo.value("title").toString());
            book.setDescription(volumeInfo.value("description").toString());

            // Handle authors array
            QJsonArray authorsArray = volumeInfo.value("authors").toArray();
            QStringList authors;
            for (const QJsonValue& authorValue : authorsArray) {
                authors.append(authorValue.toString());
            }
            book.setAuthors(authors);

            book.setPublishedDate(volumeInfo.value("publishedDate").toString());
            book.setPageCount(volumeInfo.value("pageCount").toInt());

            // Add the book to the bookList
            bookList.append(book);
        }
    }
}
bool JsonParse::parseJson(const QString& jsonData)
{
    //qDebug() << "\n Jsonstring = " << jsonString;
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData.trimmed().toUtf8(), &error);

    if (error.error != QJsonParseError::NoError) {
        // JSON parsing error occurred
        qDebug() << error.errorString();
        return false;
    }

    if (jsonDocument.isNull() || !jsonDocument.isObject()) {
        // Invalid JSON data

        qDebug() << "Invalid JSON data";
        return false;
    }

    QJsonObject jsonObject = jsonDocument.object();

    qDebug() << "Keys = " << jsonObject.keys();


    //processJson(jsonObject);

    QString kind = jsonObject.value("kind").toString();
    int totalItems = jsonObject.value("totalItems").toInt();
    QJsonArray itemsArray = jsonObject.value("items").toArray();


    populateData(itemsArray);

    return true;
}

void JsonParse::processJson(const QJsonObject& jsonObject)
{

    for (auto it = jsonObject.begin(); it != jsonObject.end(); ++it) {
        const QString& key = it.key();
        const QJsonValue& value = it.value();

        // Process key-value pair dynamically
        if (value.isObject()) {
            processJson(value.toObject());  // Handle nested JSON object
        } else if (value.isArray()) {
            processJsonArray(value.toArray());  // Handle JSON array
        }
    }
}

void JsonParse::processJsonArray(const QJsonArray& jsonArray)
{
    for (const QJsonValue& value : jsonArray) {
        if (value.isObject()) {
            processJson(value.toObject());  // Handle nested JSON object
        } else if (value.isArray()) {
            processJsonArray(value.toArray());  // Handle JSON array
        }
    }
}

// void JsonParse::processKeyValue(const QString& key, const QJsonValue& value)
// {
//     // Perform desired operations on the key-value pair dynamically
//     if (key == "title") {
//         title = value.toString();
//         // Process the title
//     }
//     else if (key == "description")
//     {
//         description = value.toString();
//         // Process the description
//     }
//     else if (key == "authors")
//     {
//
//         if (value.isArray()) {
//             QJsonArray authorsArray = value.toArray();
//             for (const QJsonValue& authorValue : authorsArray) {
//                 authors.append(authorValue.toString());
//             }
//         }
//         // Process the list of authors
//     }
//     else if (key == "publishedDate")
//     {
//          publishedDate = value.toString();
//         // Process the published date
//     }
//     else if (key == "pageCount")
//     {
//         pageCount  = value.toInt();
//         // Process the page count
//     }
//
// }
//
void JsonParse::printData()
{
    /*
     * title
description
authors
publishedDate
pageCount
*/
    qDebug().noquote() << "\n\n";
    for (Book& book : bookList)
    {

        QString result = "Book(title = " + book.getTitle() + ",\n" +
                         "description = " + book.getDescription() + ",\n" +
                         "authors = " + book.getAuthors().join(", ") + ",\n" +
                         "publishedDate = " + book.getPublishedDate() + ",\n" +

                         "pageCount = " + QString::number(book.getPageCount()) + "')";
        qDebug().noquote() << result << "\n\n";

    }


}

QList<Book> JsonParse::getBookList()
{
    return bookList;
}
