#ifndef BOOKDETAILSWINDOW_H
#define BOOKDETAILSWINDOW_H

#include <QWidget>
#include "book.h"

class BookDetailsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit BookDetailsWindow(const Book &book, QWidget *parent = nullptr);
    ~BookDetailsWindow();
    QByteArray downloadImageData(const QString &url);

private:
         // Declare the necessary widgets for displaying book details

};

#endif // BOOKDETAILSWINDOW_H
