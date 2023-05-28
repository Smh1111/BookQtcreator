#include "searchresultwindow.h"
#include "ui_searchresultwindow.h"
#include "homepage.h"
#include "bookdetailswindow.h"

#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QScrollArea>
#include <QPropertyAnimation>

#include <QLabel>
#include <QPainter>
#include <QStyleOption>
#include <QStylePainter>
#include <QGraphicsDropShadowEffect>




SearchResultWindow::SearchResultWindow(QWidget *parent, QList<Book> data) :
    QMainWindow(parent),
    ui(new Ui::SearchResultWindow)
{
    bookdata = data;
    //ui->setupUi(this);

    this->setWindowTitle("Book Finder App");
    this->setStyleSheet("QMainWindow {background-color: #303030;}");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
    setMinimumSize(700,600);
    //setMaximumSize(1000,900);
    centralWidget->setStyleSheet("QWidget {background-color: #303030;}");

    // Create the "Home" button
    QPushButton *homeButton = new QPushButton("Home", this);
    homeButton->setStyleSheet("QPushButton { background-color: orange; color: black; font-weight: bold; font-size: 16px; padding: 7px; border-radius: 5px; }"
                              "QPushButton:hover { background-color: lightgreen; }");
    connect(homeButton, &QPushButton::clicked, this, &SearchResultWindow::goToHomePage);

    QLabel *qLabel = new QLabel;

    QString labelText = "<span style='color: white; font-weight: bold; font-size: 18px; font-family: Segoe UI'>BOOK FINDER</span>";
    qLabel->setText(labelText);
    qLabel->setAlignment(Qt::AlignCenter);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(qLabel);
    buttonLayout->addSpacing(1400);
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
                bookCard->setStyleSheet("QWidget { background-color: #424242; border-radius: 10px; border: 1px solid rgba(250, 250, 250, 0.2); }"
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
    groupBox->setStyleSheet( "QGroupBox {"
                            "    border: 2px solid #08F7FE;"
                            "    margin-top: 10px;"
                            "    background-color: #212121;"

                            "}"
                             );
    // Create a QGraphicsDropShadowEffect for the shadow effect
    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setColor(Qt::black);
    shadowEffect->setBlurRadius(20);
    shadowEffect->setOffset(0, 0);

    // Apply the shadow effect to the group box
    groupBox->setGraphicsEffect(shadowEffect);


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

    // Connect the read more button signal to the slot
   // connect(imageLabel, &QLabel::clicked, [this, book]() {
        //openBookDetailsWindow(book);
    //});

    // Add the image label to the layout
    layout->addWidget(imageLabel);

    // Create the book details layout
    QVBoxLayout* detailsLayout = new QVBoxLayout;

    // Create the book details labels
    QLabel* titleLabel = new QLabel("<span style='font-family: Segoe UI; font-weight: bold; font-size: 18px; color: white;'>Title: </span> <span style='font-family: Segoe UI; font-weight: bold; font-size: 18px; color: white;'>"
                                    + book.getTitle()
                                    + " </span>");
    titleLabel->setStyleSheet("QLabel {"
                              "   padding: 10px;"
                              "    border: none;");

    QLabel* isbnLabel = new QLabel("<span style='font-family: Segoe UI; font-weight: bold; font-size: 18px; color: white;'>ISBN: </span> <span style='font-family: Segoe UI; font-weight: bold; font-size: 18px; color: white;'>"
                                   + book.getISBN()
                                   + " </span>");
    isbnLabel->setStyleSheet("QLabel {"
                              "   padding: 10px;"
                             "    border: none;");


    QLabel* authorsLabel = new QLabel("<span style='font-family: Segoe UI; font-weight: bold; font-size: 18px; color: white;'>Authors: </span>  <span style='font-family: Segoe UI; font-weight: bold; font-size: 18px; color: white;'>"
                                      + book.getAuthors().join(", ")
                                      + " </span>");
    authorsLabel->setStyleSheet("QLabel {"
                             "   padding: 10px;"
                             "    border: none;"
                                );


    QLabel* publishedLabel = new QLabel("<span style='font-family: Segoe UI; font-weight: bold; font-size: 18px; color: white;'>Published Date: </span> <span style='font-family: Segoe UI; font-weight: bold; font-size: 18px; color: white;'>("
                                        + book.getPublishedDate()
                                        + ") </span>");
    publishedLabel->setStyleSheet("QLabel {"
                                "   padding: 10px;"
                                "    border: none;"
                                  );


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
    titleLabel->setFixedWidth(300);
    titleLabel->wordWrap();

    isbnLabel->setFixedWidth(300);
    isbnLabel->wordWrap();

    authorsLabel->setFixedWidth(300);
    authorsLabel->wordWrap();

    publishedLabel->setFixedWidth(300);
    publishedLabel->wordWrap();



    titleLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    isbnLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    authorsLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    publishedLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

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

