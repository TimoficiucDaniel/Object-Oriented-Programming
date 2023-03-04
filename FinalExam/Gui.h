
#ifndef EXAMFINAL_GUI_H
#define EXAMFINAL_GUI_H
#include "Service.h"
#include "QWidget"
#include "QListWidget"
#include "QLabel"
#include "QBoxLayout"
#include "QLineEdit"
#include "QPushButton"
#include "QErrorMessage"
#include "QColor"
#include "QBrush"
#include "QMessageBox"
#include "QFont"
#include "QPainter"
#include "QPicture"

class Gui:public QWidget{
private:
    Q_OBJECT
    std::vector<QListWidget*> listsOfFiles;
    std::vector<QLabel*> listsOfToRevise;
    std::vector<QLabel*> listsOfRevised;
    std::vector<QLineEdit*> edits;
    std::vector<QPushButton*> add;
    std::vector<QPushButton*> revise;

    QListWidget* stats;
    Service s;
public:
    Gui();
    void initGui();
    void connect();
    void populate();

    void addFile();
    void paintEvent(QPaintEvent* event);
    void reviseFile();
    signals:
    void listChanged();
    void paint();
};

#endif //EXAMFINAL_GUI_H
