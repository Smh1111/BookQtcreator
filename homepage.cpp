#include "homepage.h"
#include "./ui_homepage.h"
#include "QDebug"
#include <QLabel>
#include <QBoxLayout>
#include <QGroupBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QPixmap>
#include <QImage>
#include <QStandardPaths>
#include <QRadioButton>


HomePage::HomePage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::HomePage)
{
    ui->setupUi(this);
    this->setWindowTitle("Book Finder App");
    QIcon icon("../BookApp/icons8-book-64.ico");  // Replace with the actual path to your icon file
    setWindowIcon(icon);


    connect(ui->pushButtonSearch, &QPushButton::clicked, this, &HomePage::handleButtonClicked);

    // Inside your class or function where you want to set the background image
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);

    // Connect the finished signal to a slot
    connect(networkManager, &QNetworkAccessManager::finished, this, &HomePage::onImageDownloaded);

    // Start the image download
    QNetworkRequest request;
    request.setUrl(QUrl("https://wallpaperaccess.com/full/124383.jpg"));
    networkManager->get(request);

    // Connect the toggled(bool) signal to a custom slot
    connect(ui->radioButton_5, &QRadioButton::toggled, this, &HomePage::on_radioButton_5_toggled);

    // Connect the toggled(bool) signal to a custom slot
    connect(ui->radioButton_10, &QRadioButton::toggled, this, &HomePage::on_radioButton_10_toggled);

    // Connect the toggled(bool) signal to a custom slot
    connect(ui->radioButton_20, &QRadioButton::toggled, this, &HomePage::on_radioButton_20_toggled);

    // Connect the toggled(bool) signal to a custom slot
    connect(ui->radioButton_30, &QRadioButton::toggled, this, &HomePage::on_radioButton_30_toggled);

    // Connect the toggled(bool) signal to a custom slot
    connect(ui->radioButton_40, &QRadioButton::toggled, this, &HomePage::on_radioButton_40_toggled);



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
    apiparameters->setQuery(query,this->getMaxResult());

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
void HomePage::onImageDownloaded(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        // Read the downloaded image data
        QByteArray imageData = reply->readAll();

        // Create a pixmap from the downloaded image data
        QPixmap pixmap;
        pixmap.loadFromData(imageData);

        // Set the pixmap as the background image of your widget
        QPalette palette;
        palette.setBrush(QPalette::Window, QBrush(pixmap));
        palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        this->setAutoFillBackground(true);
        this->setPalette(palette);

    }

    // Clean up the reply object
    reply->deleteLater();
}




void HomePage::on_radioButton_5_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Radio button 5 toggled";
        this->setMaxResult(5);
    }
}

void HomePage::on_radioButton_10_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Radio button 10 toggled";
         this->setMaxResult(10);
    }
}


void HomePage::on_radioButton_20_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Radio button 20 toggled";
        this->setMaxResult(20);
    }
}


void HomePage::on_radioButton_30_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Radio button 30 toggled";
        this->setMaxResult(30);
    }
}


void HomePage::on_radioButton_40_toggled(bool checked)
{
    if (checked) {
        qDebug() << "Radio button 40 toggled";
         this->setMaxResult(40);
    }
}

void HomePage::setMaxResult(const int& maxResult)
{
    this->maxResult = maxResult;
}

int HomePage::getMaxResult() const
{
    return this->maxResult;
}

