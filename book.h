#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QStringList>
/**
 * @brief A class representing a book in the BookFinder app.
 *
 * This class provides methods for managing book information.
 */
class Book {
public:
    Book() = default;


    // Title
    void setTitle           (QString        Title);
    /**
     * @brief Get the title of the book.
     * @return The book title.
     */
    const QString& getTitle() const;

    // ISBN
    void setISBN            (QStringList&    isbn);
    void setDescription     (QString        description);
    void setAuthors         (QStringList&   authors);
    void setPublishedDate   (QString        publishedDate);
    void setPageCount       (int            pageCount);

    void setImageLinks      (QStringList&       imageLinks);
    void setInfoLink        (QString        infoLink);
    void setPreviewLink     (QString        previewLink);





    const QStringList& getISBNList() const;
    QString getISBN()   const;
    const QString& getDescription() const;
    const QStringList& getAuthors() const;
    const QString& getPublishedDate() const;
    int getPageCount() const;
    const QStringList& getImageLinks() const;
    const QString& getInfoLink() const;
    const QString& getPreviewLink() const;
    QString getInformationLink() const;


    QString getImageUrl() const;

private:
    // Book collections
    QString         title           ;
    QStringList        isbn         ;
    QStringList     authors         ;
    QString         publishedDate   ;


    // For Book Details
    QString         description     ;
    QStringList     imageList       ;
    QString         infoLink        ;
    int             pageCount       ;
    QString         previewLink     ;
    QString         buyLink         ;



};

#endif // BOOK_H
