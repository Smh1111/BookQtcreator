#include "bookdetailswindow.h"
#include <QFormLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QUrl>
#include <QMessageBox>
#include <QSizePolicy>

BookDetailsWindow::~BookDetailsWindow()
{

}

BookDetailsWindow::BookDetailsWindow(const Book &book, QWidget *parent) : QWidget(parent)
{
    // Set up the window properties
    setWindowTitle("Book Details");
    // Set the appropriate size, layout, or other properties as desired

    // Create QLabel or QTextEdit widgets to display the book details

    QIcon icon("../BookApp/icons8-book-64.ico");  // Replace with the actual path to your icon file
    setWindowIcon(icon);

    QFormLayout *layout = new QFormLayout(this);
    layout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);

    QLabel *imageLabel = new QLabel(this);
    QPixmap bookImage;

    QString imageUrl = "https://books.google.com/books/content?id=OBM3AAAAIAAJ&printsec=frontcover&img=1&zoom=4&edge=curl&imgtk=AFLRE732jTQFFCRvT_lRHXs2zLcWjeEBEN95EXuYKFhEQbWEdPPvKDcy0fDnXdUWUP2CofuU_hJfwq-AzrCIfA0UkanyP3cEVuzgdeiuhh4of1ke2-PRjRPiVv4xg0JP0RSit4ki-mO2&source=gbs_api";
    if (!imageUrl.isEmpty()) {
        bookImage.loadFromData(downloadImageData(imageUrl));
    }
    if (bookImage.isNull()) {
        imageLabel->setText("Image not found");
        imageLabel->setAlignment(Qt::AlignCenter);
    } else {
        imageLabel->setPixmap(bookImage.scaledToHeight(300));
        imageLabel->setAlignment(Qt::AlignHCenter);
    }

    QLabel *titleLabel = new QLabel("Title:", this);
    QLabel *isbnLabel = new QLabel("ISBN:", this);
    QLabel *authorsLabel = new QLabel("Authors:", this);
    QLabel *dateLabel = new QLabel("Published Date:", this);

    QLabel *titleValueLabel = new QLabel(book.getTitle(), this);
    QLabel *isbnValueLabel = new QLabel(book.getTitle(), this);
    QLabel *authorsValueLabel = new QLabel(book.getAuthors().join(", "), this);
    QLabel *dateValueLabel = new QLabel(book.getPublishedDate(), this);

    layout->addRow(imageLabel);
    layout->addRow(titleLabel, titleValueLabel);
    layout->addRow(isbnLabel, isbnValueLabel);
    layout->addRow(authorsLabel, authorsValueLabel);
    layout->addRow(dateLabel, dateValueLabel);

    titleValueLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    isbnValueLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    authorsValueLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    dateValueLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    adjustSize();
    setFixedWidth(qMin(600, width()));
    setFixedHeight(qMin(400, height()));
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    layout->setSizeConstraint(QLayout::SetFixedSize);

}


QByteArray BookDetailsWindow::downloadImageData(const QString &url)
{
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray imageData;
    if (reply->error() == QNetworkReply::NoError) {
        imageData = reply->readAll();
    } else {
        QMessageBox::warning(this, "Error", "Failed to download image: " + reply->errorString());
    }

    reply->deleteLater();
    return imageData;
}
