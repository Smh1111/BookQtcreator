#include "homepage.h"
#include "./ui_homepage.h"
#include "QDebug"
#include <QLabel>
#include <QBoxLayout>
#include <QGroupBox>

HomePage::HomePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);
    this->setWindowTitle("Book Finder App");
    QIcon icon("../BookApp/icons8-book-64.ico");  // Replace with the actual path to your icon file
    setWindowIcon(icon);

    connect(ui->pushButtonSearch, &QPushButton::clicked, this, &HomePage::handleButtonClicked);


}

HomePage::~HomePage()
{
    delete ui;
}

void HomePage::handleButtonClicked()
{
    QString query = ui->lineEditQuery->text();

    qDebug() << "Query from Ui = " << query;

    api = new class Api_Logic(this);
    connect(api, &Api_Logic::apiResponseReceived, this, &HomePage::handleApiResponse);

    apiparameters = new class ApiParameters(this);
    apiparameters->setQuery(query);

    //apiCall.makeApiCall(parameters.getQueryString());
    api->makeApiCall(apiparameters->getQueryString());
}

void HomePage::handleApiResponse(QString response)
{
    // Process the API response
    jsonparse = new class JsonParse(this);
    jsonparse->parseJson(response);
    //jsonparse->printData();

    qDebug() << "First author= " << jsonparse->getBookList().takeFirst().getAuthors();


    searchresultwin = new SearchResultWindow(this, jsonparse->getBookList());

    searchresultwin->getData();
    this->hide();
    searchresultwin->show();

}


