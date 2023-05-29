#ifndef SEARCHRESULTWINDOW_H
#define SEARCHRESULTWINDOW_H
/**
 * @file book.cpp
 * @author Soe Moe Htet (65011693), Phyo Thi Khaing (65011466), Myo Pa Pa Kyaw (65011368)
 * @brief   This file handles the search result window. It contains the functions for creating the search result window.
 *          It also contains the necessary variables for the search result window.
 *          It also contains the functions for creating the book card.
 *      
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <QMainWindow>
#include "book.h"
#include <QGroupBox>
namespace Ui {
class SearchResultWindow;
}

/**
 * @brief This class handles the search result window. It contains the functions for creating the search result window.
 * 
 */
class SearchResultWindow : public QMainWindow
{
    Q_OBJECT

public:
    SearchResultWindow(QWidget *parent = nullptr, QList<Book> data = QList<Book>());

    ~SearchResultWindow();

    /**
     * @brief getData
     */
    void getData(){
        qDebug() << "Data in search result window" << bookdata.data();
    }

    /**
     * @brief Handle the book button click
     * @param book
     */
    void handleBookButtonClick(const Book &book);
    /**
     * @brief Open the book details window
     * @param book
     */
    void openBookDetailsWindow(const Book &book);
    /**
     * @brief Create the book group box
     * @param book
     * @return QGroupBox*
     */
    QGroupBox* createBookGroupBox(const Book& book);
    /**
     * @brief Load the image from the url
     * @param imageUrl
     * @return QPixmap
     */
    QPixmap loadImageFromUrl(const QString& imageUrl);

    /**
     * @brief Create the book card
     * @param book
     * @return
     */
    QWidget *createBookCard(const Book &book);

private slots:
    /**
     * @brief When singal recived, go the home page window
     */
    void goToHomePage();

private:
    Ui::SearchResultWindow *ui; // The ui for the search result window
    QList<Book> bookdata;   // The book data

};

#endif // SEARCHRESULTWINDOW_H
