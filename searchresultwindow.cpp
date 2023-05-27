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
    QHBoxLayout *hbox = new QHBoxLayout(this);

    QPushButton *pushBut1 = new QPushButton(this);
    pushBut1->setText(bookdata.takeAt(0).getTitle());
    pushBut1->adjustSize();
    hbox->addWidget(pushBut1);

    ui->frame_2->setLineWidth(12);


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

