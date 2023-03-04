#ifndef TESTPRACTIC_GUI_H
#define TESTPRACTIC_GUI_H
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
#include "qpalette.h"
#include "qspinbox.h"

class Gui:public QWidget{
private:
    Q_OBJECT
    std::vector<QListWidget*> listOfQuestions;
    std::vector<QListWidget*> listOfQuestionDetails;
    std::vector<QPushButton*> addButtons;
    std::vector<QPushButton*> answerButtons;
    std::vector<QLineEdit*> answerLines;
    std::vector<QLineEdit*> questionLines;
    std::vector<QSpinBox*> votesBoxes;
    Service serv;

    QLineEdit* searchEdit;
    QLineEdit* questionEdit;
    QTabWidget* tabs;
    QListWidget* tab1;
    QListWidget* tab2;
    QListWidget* tab3;
public:
    Gui();
    void initGui();
    void connectObjects();
    void populate();

    void showAnswers();
    void findQuestion();

};

#endif //TESTPRACTIC_GUI_H
