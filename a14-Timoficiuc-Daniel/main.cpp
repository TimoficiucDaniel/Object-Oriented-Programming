#include <QApplication>
#include <QPushButton>
#include "GUI.h"
#include "Database.h"
#include "Service.h"
#include "Gui12.h"
#include "qlistview"
#include "qstringlistmodel.h"
#include "qstringlist.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Database<Dog>* dat;
    Database<Dog>* dat2;
    Service serv(dat);
    Service servUser(dat2);
    Gui12 gui{serv,servUser};
    gui.show();
//    QListView idk;
//    QStringListModel list;
//    QStringList list2;
//    list2<<"a"<<"b"<<"c";
//    list.setStringList(list2);
//    idk.setModel(&list);
//    idk.show();
//    Database<Dog>* dat3 = new CSV;
//    //dat3->readFromFile();
//    dat3->filename ="C:/Users/timod/CLionProjects/QtA11-12/csv.csv";
//    QTableView* tableView = new QTableView;
//    MyModel model(dat3);
//    tableView->setModel(&model);
//    tableView->show();
    return a.exec();
}
