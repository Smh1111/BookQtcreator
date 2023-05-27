#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include "api_logic.h"
#include "apiparameters.h"
#include "searchresultwindow.h"
#include "jsonparse.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HomePage; }
QT_END_NAMESPACE

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    HomePage(QWidget *parent = nullptr);
    ~HomePage();

private slots:
    void handleButtonClicked();
    void handleApiResponse(QString response);


private:
    Ui::HomePage *ui;
    QPushButton *button;
    Api_Logic *api;
    JsonParse *jsonparse;
    ApiParameters *apiparameters;
    SearchResultWindow *searchresultwin;

};
#endif // HOMEPAGE_H
