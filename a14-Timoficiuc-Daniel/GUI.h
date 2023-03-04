#include <qwidget.h>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include "Dogs.h"
#include "GuiValidator.h"

#ifndef QTA11_12_GUI_H
#define QTA11_12_GUI_H

class DogsGUI : public QWidget{
    Q_OBJECT
public:
    DogsGUI(std::vector<Dog> dogs,QWidget *parent = 0);

private:
    std::vector<Dog> dogs;
    QListWidget* dogsList;

    QPushButton* exitApp;
    QPushButton* userMode;
    QPushButton* adminMode;
    QVBoxLayout* layout;

    QPushButton* exitToInit;

    QPushButton* addAdmin;
    QPushButton* removeAdmin;
    QPushButton* updateAdmin;
    QPushButton* fileAdmin;
    QPushButton* filterButton;
    QLineEdit* input;

    QPushButton* exitToAdmin;

    QPushButton* showUser;
    QPushButton* showCertainUser;
    QPushButton* showAdoptionUser;
    QPushButton* fileUser;

    void initGUI();
    void connectRelations();
    void initAdminMode();
    void resetInit1();
    void resetInit2();
    void initUserMode();
    void initAddAdmin();
    void resetInitAdmin();
    void resetDogsList();

    signals:
    void adminModeSignal();
    void userModeSignal();
};

#endif //QTA11_12_GUI_H
