#include "searchresultwindow.h"
#include "ui_searchresultwindow.h"
#include "homepage.h"
#include <QGroupBox>


SearchResultWindow::SearchResultWindow(QWidget *parent, QList<Book> data) :
    QMainWindow(parent),
    ui(new Ui::SearchResultWindow)
{
    bookdata = data;
    ui->setupUi(this);

    this->setWindowTitle("Book Finder App");
    QHBoxLayout *hbox = new QHBoxLayout;

    foreach (const Book &book, bookdata) {
        QPushButton *pushButton = new QPushButton(this);
        pushButton->setText(book.getTitle());
        pushButton->adjustSize();
        hbox->addWidget(pushButton);

        connect(pushButton, &QPushButton::clicked, [this, book]() {
            handleBookButtonClick(book);
        });
    }

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(hbox);
    setCentralWidget(centralWidget);

}


void SearchResultWindow::handleBookButtonClick(const Book &book)
{
    // Handle the book button click here
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

