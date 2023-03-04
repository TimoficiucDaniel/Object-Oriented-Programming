#include "GUI.h"

void DogsGUI::initGUI() {
    this->layout = new QVBoxLayout{this };

    QWidget* buttonsWidget = new QWidget{};
    buttonsWidget->resize(1000,800);
    QHBoxLayout* hLayout = new QHBoxLayout{buttonsWidget};
    this->adminMode = new QPushButton("Admin Mode");
    this->adminMode->resize(400,400);
    this->userMode = new QPushButton("User Mode");
    this->userMode->resize(400,400);
    QFont f{"Courier", 35};
    this->userMode->setFont(f);
    this->adminMode->setFont(f);
    hLayout->addWidget(this->adminMode);
    hLayout->addWidget( this->userMode);

    QWidget* exit =  new QWidget{};
    exit->resize(1000,400);
    QVBoxLayout* vLayout2 = new QVBoxLayout{exit};
    this->exitApp = new QPushButton("Exit application");
    this->exitApp->resize(400,400);
    this->exitApp->setFont(f);
    vLayout2->addWidget(this->exitApp);

    layout->addWidget(buttonsWidget);
    layout->addWidget(exit);
    QObject::connect(this->adminMode,&QPushButton::clicked,this,&DogsGUI::initAdminMode);
    QObject::connect(this->exitApp,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(this->userMode,&QPushButton::clicked,this,&DogsGUI::initUserMode);
}

DogsGUI::DogsGUI(std::vector<Dog> _dogs, QWidget * parent): QWidget{parent}, dogs{_dogs} {
    this->initGUI();
    this->connectRelations();
}

void DogsGUI::connectRelations() {

}

void DogsGUI::initAdminMode() {
    delete this->layout;
    delete this->adminMode;
    delete this->userMode;
    delete this->exitApp;

    this->layout = new QVBoxLayout{this};

    QFont f{"Courier", 35};

    QWidget* add = new QWidget{};
    add->resize(200,800);
    QHBoxLayout* functionLayout = new QHBoxLayout{add};
    this->addAdmin = new QPushButton{"Add dog"};
    this->updateAdmin = new QPushButton{"Update dog"};
    this->removeAdmin = new QPushButton{"Remove dog"};
    this->fileAdmin = new QPushButton{"Display file"};
    this->addAdmin->resize(200,100);
    this->updateAdmin->resize(200,100);
    this->removeAdmin->resize(200,100);
    this->fileAdmin->resize(200,100);
    this->addAdmin->setFont(f);
    this->updateAdmin->setFont(f);
    this->removeAdmin->setFont(f);
    this->fileAdmin->setFont(f);
    functionLayout->addWidget(this->addAdmin);
    functionLayout->addWidget(this->updateAdmin);
    functionLayout->addWidget(this->removeAdmin);
    functionLayout->addWidget(this->fileAdmin);

    QWidget* list = new QWidget{};
    list->resize(1000,1000);
    QHBoxLayout* show =  new QHBoxLayout{list};
    this->dogsList = new QListWidget{};
    this->dogsList->setSelectionMode(QAbstractItemView::SingleSelection);
    for (auto g : this->dogs)
    {
        QString itemInList = QString::fromStdString(g.getName() + " - " + g.getBreed());
        QFont j{ "Verdana", 15 };
        QListWidgetItem* item = new QListWidgetItem{ itemInList };
        item->setFont(j);
        this->dogsList->addItem(item);
    }
    show->addWidget(this->dogsList);

    QWidget* filter = new QWidget{};
    QHBoxLayout* filterLayout = new QHBoxLayout{filter};
    this->filterButton = new QPushButton{"Filter"};
    QFont j{ "Verdana", 15 };
    filterButton->setFont(j);
    this->input = new QLineEdit{};
    filterLayout->addWidget(filterButton);
    filterLayout->addWidget(input);


    QWidget* last =  new QWidget{};
    last->resize(400,200);
    QHBoxLayout* vLayout =  new QHBoxLayout{last};
    this->exitToInit =  new QPushButton{"Exit admin mode"};
    this->exitToInit->setFont(f);
    this->exitToInit->resize(400,200);
    vLayout->addWidget(this->exitToInit);

    layout->addWidget(add);
    layout->addWidget(filter);
    layout->addWidget(list);
    layout->addWidget(last);
    QObject::connect(this->filterButton,&QPushButton::clicked,this,&DogsGUI::resetDogsList);
    QObject::connect(this->exitToInit,&QPushButton::clicked,this,&DogsGUI::resetInit1);
}

void DogsGUI::initUserMode() {
    delete this->layout;
    delete this->adminMode;
    delete this->userMode;
    delete this->exitApp;
    this->layout = new QVBoxLayout{this};

    QFont f{"Courier", 35};

    QWidget* first = new QWidget{};
    first->resize(400,800);
    QVBoxLayout* vLayout = new QVBoxLayout{first};
    this->showUser = new QPushButton{"Show dogs"};
    this->showCertainUser = new QPushButton{"Show dogs of certain breed and age"};
    this->showAdoptionUser = new QPushButton{"Show adoption list"};
    this->fileUser = new QPushButton{"Display adoption list in file"};
    this->showUser->resize(400,200);
    this->showCertainUser->resize(400,200);
    this->showAdoptionUser->resize(400,200);
    this->fileUser->resize(400,200);
    this->showUser->setFont(f);
    this->showCertainUser->setFont(f);
    this->showAdoptionUser->setFont(f);
    this->fileUser->setFont(f);
    vLayout->addWidget( this->showUser);
    vLayout->addWidget(this->showCertainUser);
    vLayout->addWidget( this->showAdoptionUser);
    vLayout->addWidget(this->fileUser);

    QWidget* last =  new QWidget{};;
    last->resize(400, 200);
    QVBoxLayout* vLayout2 =  new QVBoxLayout{last};
    this->exitToInit =  new QPushButton{"Exit user mode"};
    this->exitToInit->setFont(f);
    this->exitToInit->resize(400,200);
    vLayout2->addWidget(this->exitToInit);

    layout->addWidget(first);
    layout->addWidget(last);
    QObject::connect(this->exitToInit,&QPushButton::clicked,this,&DogsGUI::resetInit2);
}

void DogsGUI::resetInit2(){
    delete this->exitToInit;
    delete this->layout;
    delete this->showUser;
    delete this->showCertainUser;
    delete this->showAdoptionUser;
    delete this->fileUser;
    this->initGUI();
}

void DogsGUI::resetInit1() {
      delete this->input;
      delete this->filterButton;
      delete this->exitToInit;
      delete this->layout;
      delete this->dogsList;
      delete this->addAdmin;
      delete this->updateAdmin;
      delete this->removeAdmin;
      delete this->fileAdmin;
      this->initGUI();
}

void DogsGUI::initAddAdmin() {
    delete this->layout;
    delete this->addAdmin;
    delete this->updateAdmin;
    delete this->fileAdmin;
    delete this->removeAdmin;
    delete this->exitToInit;

    QFont f{"Courier", 35};

    this->layout = new QVBoxLayout{this};

    QWidget* first =  new QWidget{};;
    first->resize(400,800);
    QVBoxLayout* vLayout = new QVBoxLayout{first};

    QWidget* last =  new QWidget{};
    last->resize(400,200);
    QVBoxLayout* vLayout2 =  new QVBoxLayout{last};
    this->exitToAdmin =  new QPushButton{"Exit"};
    this->exitToAdmin->setFont(f);
    this->exitToAdmin->resize(400,200);
    vLayout2->addWidget(this->exitToAdmin);

    this->layout->addWidget(last);

    QObject::connect(this->exitToAdmin,&QPushButton::clicked,this,&DogsGUI::resetInitAdmin);
}

void DogsGUI::resetInitAdmin() {
    delete this->layout;
    delete this->exitApp;
    this->initAdminMode();
}

void DogsGUI::resetDogsList() {
    this->dogsList->clear();
    QString filterData =  this->input->text();
    std::string toFilter = filterData.toStdString();
    for(auto g : this->dogs){
        std::string dog =g.getName() + " - " + g.getBreed();
        if(dog.find(toFilter)!=-1)
        {   QString qs = QString::fromStdString(g.getName() + " - " + g.getBreed());
            QFont j{ "Verdana", 15 };
            QListWidgetItem* item = new QListWidgetItem{qs};
            item->setFont(j);
            this->dogsList->addItem(item);}
    }
}




