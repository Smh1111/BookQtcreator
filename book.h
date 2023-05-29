#ifndef BOOK_H
#define BOOK_H
#include <QString>
#include <QStringList>
/**
 * @file book.cpp
 * @author Soe Moe Htet (65011693), Phyo Thi Khaing (65011466), Myo Pa Pa Kyaw (65011368)
 * @brief This file handles the data structure of the book object. It contains the setter and getter functions for the book object. 
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/**
 * @brief   This class handles the data structure of the book object. It contains the setter and getter functions for the book object.
 * 
 */
class Book {
public:
    Book() = default;

    /**
     * @brief Set the Title object
     * 
     * @param Title  The title of the book object from the google book api.
     */
    void setTitle           (QString        Title);
    /**
     * @brief Get the title of the book.
     * @return The book title.
     */
    const QString& getTitle() const;
    /**
     * @brief Set the ISBN object
     * @param isbn
     */
    void setISBN            (QStringList&    isbn);
    /**
     * @brief Set the description of the book.
     * @param description
     */
    void setDescription     (QString        description);
    /**
     * @brief Set the authors of the book.
     * @param
     */
    void setAuthors         (QStringList&   authors);
    /**
     * @brief Set the published date of the book.
     * @param publishedDate
     */
    void setPublishedDate   (QString        publishedDate);
    /**
     * @brief Set the page count of the book.
     * @param pageCount
     */
    void setPageCount       (int            pageCount);
    /**
     * @brief Set the image links of the book.
     * @param imageLinks
     */
    void setImageLinks      (QStringList&       imageLinks);
    /**
     * @brief Set the information link of the book.
     * @param infoLink
     */
    void setInfoLink        (QString        infoLink);
    /**
     * @brief Set the preview link link of the book.
     * @param previewLink
     */
    void setPreviewLink     (QString        previewLink);




    /**
     * @brief Get the ISBN lists(eg. isbn10, isbn13) of the book object
     * 
     * @return const QStringList& The book ISBN lists.
     */
    const QStringList& getISBNList() const;
    
    /**
     * @brief Get only one isbn number of the book object.
     * 
     * @return const QString only one ISBN number.
     */
    QString getISBN()   const;

    /**
     * @brief Get the description of the book.
     * 
     * @return const QString&  The book description.
     */
    const QString& getDescription() const;
    /**
     * @brief Get the authors of the book.
     * 
     * @return const QStringList&  The book authors.
     */
    const QStringList& getAuthors() const;
    /**
     * @brief Get the published date of the book.
     * 
     * @return const QString&  The book published date.
     */
    const QString& getPublishedDate() const;
    /**
     * @brief Get the page count of the book.
     * 
     * @return const int The book page count.
     */
    int getPageCount() const;
    /**
     * @brief Get the image links of the book.
     * 
     * @return const QStringList&  The book image links.
     */
    const QStringList& getImageLinks() const;
    /**
     * @brief Get the information link of the book.
     * 
     * @return const QString&  The book information link.
     */
    const QString& getInfoLink() const;
    /**
     * @brief Get the preview link of the book.
     * 
     * @return const QString&  The book preview link.
     */
    const QString& getPreviewLink() const;
    /**
     * @brief Get the info link of the book.
     * 
     * @return const QString  The book info link.
     */
    QString getInformationLink() const;

    /**
     * @brief Get the buy link of the book.
     * 
     * @return const QString  The book buy link.
     */
    QString getImageUrl() const;

private:
    QString         title           ;
    QStringList        isbn         ;
    QStringList     authors         ;
    QString         publishedDate   ;


    QString         description     ;
    QStringList     imageList       ;
    QString         infoLink        ;
    int             pageCount       ;
    QString         previewLink     ;
    QString         buyLink         ;



};

#endif // BOOK_H
