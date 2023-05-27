#include "book.h"

// Setter
void Book::setTitle(QString Title)
{
    this->title = Title;
}
void Book::setDescription     (QString     description)
{
    this->description = description;
}
void Book::setAuthors         (QStringList& authors)
{
    this->authors = authors;
}
void Book::setPublishedDate   (QString     publishedDate)
{
    this->publishedDate = publishedDate;
}
void Book::setPageCount       (int         pageCount)
{
    this->pageCount = pageCount;
}

// Getter

const QString& Book::getTitle() const
{
    return this->title;
}
const QString& Book::getDescription() const
{
    return this->description;
}
const QStringList& Book::getAuthors() const
{
    return this->authors;
}
const QString& Book::getPublishedDate() const
{
    return this->publishedDate;
}
int Book::getPageCount() const
{
    return this->pageCount;
}

QString Book::getImageUrl()
{

    return "https://books.google.com/books/content?id=OBM3AAAAIAAJ&printsec=frontcover&img=1&zoom=4&edge=curl&imgtk=AFLRE732jTQFFCRvT_lRHXs2zLcWjeEBEN95EXuYKFhEQbWEdPPvKDcy0fDnXdUWUP2CofuU_hJfwq-AzrCIfA0UkanyP3cEVuzgdeiuhh4of1ke2-PRjRPiVv4xg0JP0RSit4ki-mO2&source=gbs_api";

}

