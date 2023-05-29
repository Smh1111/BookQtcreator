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
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>


BookDetailsWindow::~BookDetailsWindow()
{

}

/**
 * @brief Construct a new Book Details Window:: Book Details Window object
 * 
 * @param book  The book object to display the details of.
 * @param parent    The parent widget.
 */
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

    QString imageUrl = book.getImageUrl();
    if (!imageUrl.isEmpty()) {
        bookImage.loadFromData(downloadImageData(imageUrl));
    }
    if (bookImage.isNull()) {
        imageLabel->setText("Image not found");
        imageLabel->setAlignment(Qt::AlignCenter);
    } else {
        imageLabel->setPixmap(bookImage.scaledToHeight(300));
        //imageLabel->setPixmap(bookImage.scaledToWidth(300));
        imageLabel->setAlignment(Qt::AlignHCenter);
    }

    QLabel *titleLabel = new QLabel("Title:", this);
    QLabel *isbnLabel = new QLabel("ISBN:", this);
    //QLabel *pageCountLabel = new QLabel("Page Count:", this);
    QLabel *authorsLabel = new QLabel("Authors:", this);
    QLabel *dateLabel = new QLabel("Published Date:", this);
    QLabel *descriptionLabel = new QLabel("Description:", this);


    QLabel *titleValueLabel = new QLabel(book.getTitle(), this);
    QLabel *isbnValueLabel = new QLabel(book.getISBN(), this);
    QLabel *authorsValueLabel = new QLabel(book.getAuthors().join(", "), this);
    QLabel *dateValueLabel = new QLabel(book.getPublishedDate(), this);
    QLabel *pageCountValueLabel = new QLabel(QString::number(book.getPageCount())+" Pages", this);
    pageCountValueLabel->setAlignment(Qt::AlignHCenter);


    //Display Description
    QTextEdit *descriptionValueTextEdit = new QTextEdit(book.getDescription(), this);
    descriptionValueTextEdit->setReadOnly(true);
    descriptionValueTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    descriptionValueTextEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);


    // Create the link label
    QLabel *infoLinkValueLabel = new QLabel("<a href=\"" + book.getInfoLink() + "\">More Info</a>");

    infoLinkValueLabel->setTextFormat(Qt::RichText);
    infoLinkValueLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    infoLinkValueLabel->setOpenExternalLinks(true);
    infoLinkValueLabel->setStyleSheet("QLabel{"
                                      "color: #FF44CC"
                                      "}");

    //Styling bookdetailswindow
    this->setStyleSheet("QWidget{"
                        "background-color: #303030;"
                        "}"
                        "QLabel{"
                        "color: white;"
                        "font-family: Segoe UI;"
                        "font-weight: bold;"
                        "font-size: 14px;"
                        "}"
                        "QTextEdit{"
                        "color: white;"
                        "font-family: Segoe UI;"
                        "font-weight: bold;"
                        "font-size: 14px;"
                        "}"
                        );

    //Book Card creation with QGroupBox
    QGroupBox *groupBox = new QGroupBox;
    groupBox->setStyleSheet( "QGroupBox {"
                            "border: 2px solid #08F7FE;"
                            "margin-top: 10px;"

                            "}"
                            );
    QVBoxLayout *groupBoxLayout = new QVBoxLayout(groupBox);

    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(titleLabel);
    titleLayout->addWidget(titleValueLabel);

    QHBoxLayout *isbnLayout = new QHBoxLayout;
    isbnLayout->addWidget(isbnLabel);
    isbnLayout->addWidget(isbnValueLabel);

    QHBoxLayout *authorsLayout = new QHBoxLayout;
    authorsLayout->addWidget(authorsLabel);
    authorsLayout->addWidget(authorsValueLabel);

    QHBoxLayout *dateLayout = new QHBoxLayout;
    dateLayout->addWidget(dateLabel);
    dateLayout->addWidget(dateValueLabel);

    QHBoxLayout *descriptionLayout = new QHBoxLayout;
    descriptionLayout->addWidget(descriptionLabel);
    descriptionLayout->addWidget(descriptionValueTextEdit);

    groupBoxLayout->addWidget(imageLabel);
    groupBoxLayout->addWidget(pageCountValueLabel);

    groupBoxLayout->addLayout(titleLayout);

    groupBoxLayout->addLayout(isbnLayout);

    groupBoxLayout->addLayout(authorsLayout);

    groupBoxLayout->addLayout(dateLayout);

    groupBoxLayout->addLayout(descriptionLayout);

    groupBoxLayout->addWidget(infoLinkValueLabel);
    groupBoxLayout->addStretch();



    // Add the group box to the main layout
    layout->addWidget(groupBox);

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

/**
 * @brief This function downloads the image data from the url.
 * 
 * @param url The url of the image.
 * @return QByteArray The image data.
 */
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
