#include "book.h"

void Book::setTitle             (QString Title)
{
    this->title = Title;
}
/**
 * @brief set the isbn of the book object to the given isbn.
 * @param isbn
*/
void Book::setISBN          (QStringList&   isbn)
{
    this->isbn = isbn;
}
/**
 * @brief set the description of the book object to the given description.
 * @param description
*/
void Book::setDescription     (QString     description)
{
    this->description = description;
}

/**
 * @brief set the authors of the book object to the given authors.
 * @param authors   the authorlist
 */
void Book::setAuthors         (QStringList& authors)
{
    this->authors = authors;
}
/**
 * @brief set the published date of the book object to the given published date.
 * @param publishedDate
*/
void Book::setPublishedDate   (QString     publishedDate)
{
    this->publishedDate = publishedDate;
}
/**
 * @brief set the page count of the book object to the given page count.
 * @param pageCount
*/
void Book::setPageCount       (int         pageCount)
{
    this->pageCount = pageCount;
}
/**
 * @brief set the image links of the book object to the given image links.
*/
void Book::setImageLinks    (QStringList& imageList)
{
    this->imageList = imageList;
}
/**
 * @brief set the info link of the book object to the given info link.
 * @param infoLink
*/

void Book::setInfoLink     (QString infoLink)
{
    this->infoLink = infoLink;
}
/**
 * @brief set the preview link of the book object to the given preview link.
 * @param previewLink
*/
void Book::setPreviewLink    (QString previewLink)
{
    this->previewLink = previewLink;
}


/**
 * @brief Get the Title object of the book object. 
 * 
 * @return const QString& 
 */
const QString& Book::getTitle() const
{
    return this->title;
}
/**
 * @brief Get the ISBN List object of the book object. 
 * 
 * @return const QStringList& 
 */
const QStringList& Book::getISBNList() const
{
    return this->isbn;
}
/**
 * @brief Get the ISBN object of the book object. 
 * 
 * @return const QString 
 */
QString Book::getISBN() const
{
    QStringList temp = this->getISBNList();
    if (temp.capacity()>0){
        return temp.at(0);  // if there is at lest one ISBN, return the first ISBN
    }
    else{
        return "not registered";    // if there is no ISBN, return "not registered"
    }
}
/**
 * @brief Get the Description object of the book object. 
 * 
 * @return const QString& 
 */
const QString& Book::getDescription() const
{
    return this->description;
}
/**
 * @brief Get the Authors List object of the book object. 
 * 
 * @return const QStringList& 
 */
const QStringList& Book::getAuthors() const
{
    return this->authors;
}
/**
 * @brief Get the Authors object of the book object. 
 * 
 * @return const QString 
 */
const QString& Book::getPublishedDate() const
{
    return this->publishedDate;
}
/**
 * @brief Get the Page Count object of the book object. 
 * 
 * @return int 
 */
int Book::getPageCount() const
{
    return this->pageCount;
}
/**
 * @brief Get the Image Links object of the book object. 
 * 
 * @return const QStringList& 
 */
const QStringList& Book::getImageLinks() const
{
    return this->imageList;
}
/**
 * @brief Get the Info Link object of the book object. 
 * 
 * @return const QString& 
 */
const QString& Book::getInfoLink() const
{
    return this->infoLink;
}
/**
 * @brief Get the Preview Link object of the book object. 
 * 
 * @return const QString& 
 */
const QString& Book::getPreviewLink() const
{
    return this->previewLink;
}
/**
 * @brief Get the Information Link object of the book object.
 * 
 * @return QString The information link of the book object from the google book api. 
 */
QString Book::getInformationLink() const
{
    if (this->getInfoLink().isEmpty()){
        return this->getPreviewLink(); // if there is no info link, return preview link
    }
    else if (this->getPreviewLink().isEmpty()){
        return this->getInfoLink(); // if there is no preview link, return info link
    }
    else
    {
        return "https://lightwidget.com/wp-content/uploads/local-file-not-found.png"; // if there is no info link and preview link, return a default image
    }

}

/**
 * @brief Get the Image Url object of the book object.
 * 
 * @return QString The image url of the book object from the google book api. 
 */
QString Book::getImageUrl() const
{
    if (this->getImageLinks().capacity()>0){
        return this->getImageLinks().at(0); // if there is at least one image link, return the first image link
    }
    else{
        return "https://lightwidget.com/wp-content/uploads/local-file-not-found.png"; // if there is no image link, return a default image
    }


}
