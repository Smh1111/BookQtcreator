#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QStringList>

class Book {
public:
    Book() = default;

    void setTitle           (QString Title);
    void setDescription     (QString     description);
    void setAuthors         (QStringList& authors);
    void setPublishedDate   (QString     publishedDate);
    void setPageCount       (int         pageCount);

    const QString& getTitle() const;
    const QString& getDescription() const;
    const QStringList& getAuthors() const;
    const QString& getPublishedDate() const;
    int getPageCount() const;
    QString getImageUrl();

private:

    QString     title           ;
    QString     description     ;
    QStringList authors         ;
    QString     publishedDate   ;
    int         pageCount       ;

};

#endif // BOOK_H
