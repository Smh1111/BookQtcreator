#ifndef SEARCHRESULTWINDOW_H
#define SEARCHRESULTWINDOW_H

#include <QMainWindow>
#include "book.h"
#include <QGroupBox>
namespace Ui {
class SearchResultWindow;
}

class SearchResultWindow : public QMainWindow
{
    Q_OBJECT

public:
    //explicit SearchResultWindow(QWidget *parent = nullptr);
    SearchResultWindow(QWidget *parent = nullptr, QList<Book> data = QList<Book>());

    ~SearchResultWindow();

    void getData(){
        qDebug() << "Data in search result window" << bookdata.data();
    }
    void handleBookButtonClick(const Book &book);
    void openBookDetailsWindow(const Book &book);
    QGroupBox* createBookGroupBox(const Book& book);
    QPixmap loadImageFromUrl(const QString& imageUrl);
    QWidget *createBookCard(const Book &book);

private slots:
    void goToHomePage();

private:
    Ui::SearchResultWindow *ui;
    QList<Book> bookdata;

};

#endif // SEARCHRESULTWINDOW_H
