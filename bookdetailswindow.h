#ifndef BOOKDETAILSWINDOW_H
#define BOOKDETAILSWINDOW_H
/**
 * @file book.cpp
 * @author Soe Moe Htet (65011693), Phyo Thi Khaing (65011466), Myo Pa Pa Kyaw (65011368)
 * @brief This file handles the book details window. It contains the necessary widgets for displaying book details.
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <QWidget>
#include "book.h"

/**
 * @brief This class handles the book details window. It contains the necessary widgets for displaying book details.
 * 
 */
class BookDetailsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BookDetailsWindow(const Book &book, QWidget *parent = nullptr);
    ~BookDetailsWindow();
    QByteArray downloadImageData(const QString &url);

};

#endif // BOOKDETAILSWINDOW_H
