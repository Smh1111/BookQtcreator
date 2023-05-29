#ifndef HOMEPAGE_H
#define HOMEPAGE_H
/**
 * @file book.cpp
 * @author Soe Moe Htet (65011693), Phyo Thi Khaing (65011466), Myo Pa Pa Kyaw (65011368)
 * @brief This file handles the homepage. It contains the functions for the homepage.
 *        It also contains the necessary widgets for the homepage. 
 *          - The search button
 *          - The search bar
 *          - The radio buttons for the number of results
 *          - The api logic
 *          - The api parameters
 *          - The json parser
 *          - The search result window
 *          - The max result
 *          - The api response handler
 *          - The image downloader
 *          - The image download handler
 *          - The max result setter and getter
 *          - The radio button handler
 *          - The radio button toggler
 *          - The radio button setter and getter
 * @version 0.1
 * @date 2023-05-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
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

/**
 * @brief This class handles the homepage. It contains the functions for the homepage.
 * 
 */
class HomePage : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief HomePage constructor
     * @param parent
     */
    HomePage(QWidget *parent = nullptr);

    /**
     * @brief HomePage destructor
    */
    ~HomePage();

private slots:
    void handleButtonClicked();                     // Search button handler
    void handleApiResponse(QString response);       // Api response handler
    void onImageDownloaded(QNetworkReply* reply);   // Image download handler

    // Radio button handlers
    void on_radioButton_5_toggled(bool checked);
    void on_radioButton_10_toggled(bool checked);
    void on_radioButton_20_toggled(bool checked);
    void on_radioButton_30_toggled(bool checked);
    void on_radioButton_40_toggled(bool checked);
    
    void setMaxResult(const int& maxResult);
    int getMaxResult() const;
private:
    Ui::HomePage *ui;
    QPushButton *button;
    Api_Logic *api;
    JsonParse *jsonparse;
    ApiParameters *apiparameters;
    SearchResultWindow *searchresultwin;
    int maxResult = 5;
};

#endif // HOMEPAGE_H
