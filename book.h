#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QStringList>

class Book {
public:
    Book() = default;


    // Title
    void setTitle           (QString        Title);
    const QString& getTitle() const;

    // ISBN

    void setDescription     (QString        description);
    void setAuthors         (QStringList&   authors);
    void setPublishedDate   (QString        publishedDate);
    void setPageCount       (int            pageCount);

    void setImageLinks      (QString        infoLink);



    const QString& getISBN() const;
    const QString& getDescription() const;
    const QStringList& getAuthors() const;
    const QString& getPublishedDate() const;
    int getPageCount() const;

    QString getImageUrl() const;

private:
    // Book collections
    QString         title           ;
    QString         isbn            ;
    QStringList     authors         ;
    QString         publishedDate   ;


    // For Book Details
    QString         description     ;
    QStringList     imageLinks      ;
    QString         infoLink        ;
    int             pageCount       ;


};

#endif // BOOK_H
