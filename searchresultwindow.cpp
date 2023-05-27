#include "searchresultwindow.h"
#include "ui_searchresultwindow.h"
#include "homepage.h"
#include "bookdetailswindow.h"

#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QScrollArea>

SearchResultWindow::SearchResultWindow(QWidget *parent, QList<Book> data) :
    QMainWindow(parent),
    ui(new Ui::SearchResultWindow)
{
    bookdata = data;
    //ui->setupUi(this);

    this->setWindowTitle("Book Finder App");

    setMinimumSize(800, 600);  // Set a minimum size for the window

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *scrollContent = new QWidget(scrollArea);
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);
    scrollContent->setLayout(scrollLayout);
    scrollLayout->setAlignment(Qt::AlignTop);  // Align the content to the top
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);

    mainLayout->addWidget(scrollArea);

    int booksPerRow = 2;
    int bookCount = bookdata.size();
    int rowCount = (bookCount + booksPerRow - 1) / booksPerRow;

    for (int row = 0; row < rowCount; row++) {
        QHBoxLayout *rowLayout = new QHBoxLayout();
        rowLayout->setSpacing(20);
        scrollLayout->addLayout(rowLayout);

        for (int col = 0; col < booksPerRow; col++) {
            int index = row * booksPerRow + col;
            if (index < bookCount) {
                Book book = bookdata[index];

                QWidget *bookContainer = new QWidget(scrollContent);
                QVBoxLayout *bookLayout = new QVBoxLayout(bookContainer);
                bookLayout->setAlignment(Qt::AlignTop);  // Align the content to the top
                bookContainer->setLayout(bookLayout);

                QLabel *imageLabel = new QLabel(bookContainer);
                QPixmap bookImage = loadImageFromUrl(book.getImageUrl());
                imageLabel->setPixmap(bookImage.scaledToHeight(200));
                imageLabel->setAlignment(Qt::AlignCenter);  // Align the image to the center

                QGroupBox *bookGroup = createBookGroupBox(book);

                bookLayout->addWidget(imageLabel);
                bookLayout->addWidget(bookGroup);

                rowLayout->addWidget(bookContainer);
            }
        }
    }
}

QPixmap SearchResultWindow::loadImageFromUrl(const QString& imageUrl)
{
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(imageUrl)));

    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QByteArray imageData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(imageData);

    reply->deleteLater();

    return pixmap;
}

QGroupBox* SearchResultWindow::createBookGroupBox(const Book& book)
{
    QGroupBox *bookGroup = new QGroupBox(this);
    QVBoxLayout *bookLayout = new QVBoxLayout(bookGroup);
    bookGroup->setLayout(bookLayout);

    QLabel *titleLabel = new QLabel(book.getTitle(), bookGroup);
    QLabel *isbnLabel = new QLabel("ISBN: " + book.getTitle(), bookGroup);
    QLabel *authorsLabel = new QLabel("Authors: " + book.getAuthors().join(", "), bookGroup);
    QLabel *dateLabel = new QLabel("Published Date: " + book.getPublishedDate(), bookGroup);

    QPushButton *readMoreButton = new QPushButton("Read More", bookGroup);
    connect(readMoreButton, &QPushButton::clicked, [this, book]() {
        openBookDetailsWindow(book);
    });

    bookLayout->addWidget(titleLabel);
    bookLayout->addWidget(isbnLabel);
    bookLayout->addWidget(authorsLabel);
    bookLayout->addWidget(dateLabel);
    bookLayout->addWidget(readMoreButton);

    return bookGroup;
}


void SearchResultWindow::handleBookButtonClick(const Book &book)
{
    // Handle the book button click here
    this->hide();
    HomePage *homepage= new HomePage();
    homepage->show();
}
SearchResultWindow::~SearchResultWindow()
{
    delete ui;
}

void SearchResultWindow::on_pushButton_clicked()
{
    this->hide();
    HomePage *homepage= new HomePage();
    homepage->show();
}

void SearchResultWindow::openBookDetailsWindow(const Book &book)
{
    //this->hide();
    BookDetailsWindow *bookpage= new BookDetailsWindow(book, this);
    bookpage->show();
}
