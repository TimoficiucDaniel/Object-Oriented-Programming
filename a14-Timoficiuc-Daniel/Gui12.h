#include "qwidget.h"
#include "qpushbutton.h"
#include "qboxlayout.h"
#include "qformlayout.h"
#include "qtabwidget.h"
#include "qlistwidget.h"
#include "qlineedit.h"
#include "qtextedit.h"
#include "qlabel.h"
#include "Service.h"
#include "GuiValidator.h"
#include "qpalette.h"
#include "qchart.h"
#include "qbarseries.h"
#include "qlegend.h"
#include "qbarcategoryaxis.h"
#include "qbarset.h"
#include "qchartview.h"
#include "qshortcut.h"
#include "qtableview.h"
#include "QStringListModel"
#include "MyModel.h"
#include "QWindow"



#ifndef QTA11_12_GUI12_H
#define QTA11_12_GUI12_H

class Gui12: public QWidget{
private:
        Q_OBJECT
    QHBoxLayout* Layout;

    QPushButton* csv;
    QPushButton* html;

    QListWidget* dogsList;

    QLineEdit* nameWidget;
    QLineEdit* ageWidget;
    QLineEdit* breedWidget;
    QLineEdit* linkWidget;

    QPushButton* addButton;
    QPushButton* delButton;
    QPushButton* updateButton;
    QPushButton* displayButton;
    QPushButton* undoButton;
    QPushButton* redoButton;

    QLineEdit* edit;
    QListWidget* filterList;

    QPushButton* nextDogButton;
    QPushButton* adoptButton;
    QPushButton* openPicButton;

    QLineEdit* dog;

    QLineEdit* breedFilterEdit;
    QLineEdit* ageFilterEdit;
    QPushButton* filterUserButton;

    QPushButton* openFileUser;

    QListWidget* adoptionList;

    QShortcut* undoKey;
    QShortcut* redoKey;

    QTableView* tableView;
    QPushButton* showTableView;

//    QBarSeries* series;
//    QChart* chart;
//    QChartView* chartView;

    int index=0;
    std::string breedToFilterBy="";
    std::string ageToFilterBy="99999";

    MyModel* model;


public:
    Service &serv;
    GuiValidator val;
    Service &servUser;

    Gui12(Service &other,Service &otherServ,QWidget *parent = 0);


    void initGui();
    void populateGui();
    void connectObjects();
    void chooseRepo();

    void initCSV();
    void initHTML();

    void filter();
    void displayData();
    void addDog();
    void deleteDog();
    void updateDog();
    void openFile();

    void openFileU();
    void nextDog();
    void adoptDog();

    void openPicFile();
    void filterUser();

    void undo();
    void redo();

    void showView();

    signals:
    void listChanged();
};

#endif //QTA11_12_GUI12_H