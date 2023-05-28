#include "searchresultwindow.h"
#include "ui_searchresultwindow.h"
#include "homepage.h"
#include "bookdetailswindow.h"

#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QScrollArea>
#include <QPropertyAnimation>

SearchResultWindow::SearchResultWindow(QWidget *parent, QList<Book> data) :
    QMainWindow(parent),
    ui(new Ui::SearchResultWindow)
{
    bookdata = data;
    //ui->setupUi(this);

    this->setWindowTitle("Book Finder App");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
    setMinimumSize(400, 600);

    // Create the "Home" button
    QPushButton *homeButton = new QPushButton("Home", this);
    homeButton->setStyleSheet("QPushButton { background-color: #007BFF; color: white; font-weight: bold; padding: 20px 20px; border-radius: 5px; }"
                              "QPushButton:hover { background-color: #0056b3; }");
    connect(homeButton, &QPushButton::clicked, this, &SearchResultWindow::goToHomePage);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(homeButton);

    // Create the scroll area
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *scrollContent = new QWidget(scrollArea);
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);
    scrollContent->setLayout(scrollLayout);
    scrollLayout->setAlignment(Qt::AlignTop);  // Align the content to the top
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);

    mainLayout->addLayout(buttonLayout);
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

                // Create the book card container
                QWidget *bookCard = new QWidget(scrollContent);
                QVBoxLayout *cardLayout = new QVBoxLayout(bookCard);
                cardLayout->setContentsMargins(20, 20, 20, 20);

                // Set the background color and add border effect to the card
                bookCard->setStyleSheet("QWidget { background-color: #F5F5F5; border-radius: 10px; border: 1px solid rgba(0, 0, 0, 0.2); }"
                                        "QWidget:hover { background-color: #E0E0E0; }");




                // Create the book details group box
                QGroupBox *bookDetailsGroupBox = createBookGroupBox(book);
                cardLayout->addWidget(bookDetailsGroupBox);

                rowLayout->addWidget(bookCard);
            } else {
                // Add an empty widget to maintain the layout for the right section of the last row
                QWidget *emptyWidget = new QWidget(scrollContent);
                rowLayout->addWidget(emptyWidget);
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
    // Create the group box for the book
    QGroupBox* groupBox = new QGroupBox;
    groupBox->setStyleSheet("QGroupBox {"
                            "    border: 2px solid black;"
                            "    margin-top: 10px;"
                            "    background-color: #f0f0f0;"
                            "}");

    // Create the layout for the group box
    QHBoxLayout* layout = new QHBoxLayout(groupBox);
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(10);

    // Create the book image
    QPixmap bookImage = loadImageFromUrl(book.getImageUrl());

    // Create the label to display the book image
    QLabel* imageLabel = new QLabel;
    imageLabel->setPixmap(bookImage.scaledToWidth(200));

    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setStyleSheet("QLabel { border: none; }"); // Remove the stylesheet for the image label

    // Add the image label to the layout
    layout->addWidget(imageLabel);

    // Create the book details layout
    QVBoxLayout* detailsLayout = new QVBoxLayout;

    // Create the book details labels
    QLabel* titleLabel = new QLabel("<span style='font-weight: bold; font-size: 16px; color: #007BFF;'>Title-></span> <span style='font-size: 22px;'>"
                                    + book.getTitle()
                                    + " </span>");

    QLabel* isbnLabel = new QLabel("<span style='font-weight: bold; font-size: 16px; color: #007BFF;'>ISBN-></span> <span style='font-size: 22px;'>"
                                   + book.getTitle()
                                   + " </span>");
    QLabel* authorsLabel = new QLabel("<span style='font-weight: bold; font-size: 16px; color: #007BFF;'>Authors-></span>  <span style='font-size: 22px;'>"
                                      + book.getAuthors().join(", ")
                                      + " </span>");

    QLabel* publishedLabel = new QLabel("<span style='font-weight: bold; font-size: 16px; color: #007BFF;'>Published Date-></span> <span style='font-size: 22px;'>("
                                        + book.getPublishedDate()
                                        + ") </span>");


    QPushButton* readMoreButton = new QPushButton("Read More");
    readMoreButton->setFixedSize(100, 30);

    // Set the button's style using CSS
    readMoreButton->setStyleSheet("QPushButton {"
                                  "    background-color: orange;"  // White background
                                  "    color: #000000;"  // Black text color
                                  "    font-weight: bold;"
                                  "    padding: 10px 10px;"
                                  "    border-radius: 13px;"
                                  "    border: none;"
                                  "    outline: none;"
                                  "    text-transform: uppercase;"
                                  "}"
                                  "QPushButton:hover {"
                                  "    background-color: lightgreen;"  // Lighter background on hover
                                  "}"
                                  "QPushButton:pressed {"
                                  "    background-color: #d3d3d3;"  // Even darker background when pressed
                                  "}");


    // Connect the read more button signal to the slot
    connect(readMoreButton, &QPushButton::clicked, [this, book]() {
        openBookDetailsWindow(book);
    });

    titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    isbnLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    authorsLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    publishedLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    // Add the book details labels and read more button to the details layout
    detailsLayout->addWidget(titleLabel);
    detailsLayout->addWidget(isbnLabel);
    detailsLayout->addWidget(authorsLabel);
    detailsLayout->addWidget(publishedLabel);
    detailsLayout->addWidget(readMoreButton);

    // Add the details layout to the main layout
    layout->addLayout(detailsLayout);

    return groupBox;
}



SearchResultWindow::~SearchResultWindow()
{
    delete ui;
}

void SearchResultWindow::goToHomePage()
{
    hide();
    HomePage *homepage = new HomePage();
    homepage->show();
}

void SearchResultWindow::openBookDetailsWindow(const Book &book)
{
    //this->hide();
    BookDetailsWindow *bookpage= new BookDetailsWindow(book, this);
    bookpage->show();
}

