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

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *scrollContent = new QWidget(scrollArea);
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);
    scrollLayout->setAlignment(Qt::AlignTop);
    scrollContent->setLayout(scrollLayout);
    scrollArea->setWidget(scrollContent);
    scrollArea->setWidgetResizable(true);

    mainLayout->addWidget(scrollArea);

    for (const Book& book : bookdata) {
        QGroupBox *bookGroup = new QGroupBox(scrollContent);
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

        scrollLayout->addWidget(bookGroup);
    }

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
