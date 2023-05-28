#include "book.h"
#include <QDebug>

// Setter
void Book::setTitle             (QString Title)
{
    this->title = Title;
}
void Book::setISBN          (QStringList&   isbn)
{
    this->isbn = isbn;
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
void Book::setImageLinks    (QStringList& imageList)
{
    this->imageList = imageList;
}
void Book::setInfoLink     (QString infoLink)
{
    this->infoLink = infoLink;
}
void Book::setPreviewLink    (QString previewLink)
{
    this->previewLink = previewLink;
}



// Getter

const QString& Book::getTitle() const
{
    return this->title;
}
const QStringList& Book::getISBNList() const
{
    return this->isbn;
}
QString Book::getISBN() const
{
    QStringList temp = this->getISBNList();
    if (temp.capacity()>0){
        return temp.at(0);
    }
    else{
        return "not registered";
    }
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
const QStringList& Book::getImageLinks() const
{
    return this->imageList;
}
const QString& Book::getInfoLink() const
{
    return this->infoLink;
}
const QString& Book::getPreviewLink() const
{
    return this->previewLink;
}
// choose infolink or previewlink
QString Book::getInformationLink() const
{
    if (this->getInfoLink().isEmpty()){
        return this->getPreviewLink();
    }
    else if (this->getPreviewLink().isEmpty()){
        return this->getInfoLink();
    }
    else
    {
        return "https://lightwidget.com/wp-content/uploads/local-file-not-found.png";
    }

}


QString Book::getImageUrl() const
{
    if (this->getImageLinks().capacity()>0){
        return this->getImageLinks().at(0);
    }
    else{
        return "https://lightwidget.com/wp-content/uploads/local-file-not-found.png";
    }


}



