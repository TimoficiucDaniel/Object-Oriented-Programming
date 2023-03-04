#include "Gui12.h"

Gui12::Gui12(Service &other,Service &otherServ,QWidget *parent): QWidget{parent}, serv{other}, servUser{otherServ} {
    this->chooseRepo();
}

void Gui12::initGui() {

    QHBoxLayout* mainLayout =  new QHBoxLayout(this);
    //tabs
    QTabWidget* tabs = new QTabWidget();
    //admin tab
    QWidget* admin = new QWidget();
    QHBoxLayout* adminLayout = new QHBoxLayout(admin);

    QVBoxLayout* functionsLayout =  new QVBoxLayout();
    //dogs list
    QFormLayout* adminListLayout =  new QFormLayout();

    dogsList =  new QListWidget();
    dogsList->setSelectionMode(QAbstractItemView::SingleSelection);
    //to add dogs to list

    QLabel* adminListLabel = new QLabel("Dogs");

    adminListLayout->addWidget(adminListLabel);
    adminListLayout->addWidget(dogsList);
    // line edit lists
    QFormLayout* descriptionsLayout =  new QFormLayout();

    QLabel* name = new QLabel("Name: ");
    nameWidget = new QLineEdit();
    name->setBuddy(nameWidget);
    QLabel* age =  new QLabel("Age: ");
    ageWidget =  new QLineEdit();
    age->setBuddy(ageWidget);
    QLabel* breed = new QLabel("Breed: ");
    breedWidget = new QLineEdit();
    breed->setBuddy(breedWidget);
    QLabel* link = new QLabel("Link: ");
    linkWidget =  new QLineEdit();
    link->setBuddy(linkWidget);

    descriptionsLayout->addWidget(name);
    descriptionsLayout->addWidget(nameWidget);
    descriptionsLayout->addWidget(breed);
    descriptionsLayout->addWidget(breedWidget);
    descriptionsLayout->addWidget(age);
    descriptionsLayout->addWidget(ageWidget);
    descriptionsLayout->addWidget(link);
    descriptionsLayout->addWidget(linkWidget);

    //buttons
    QGridLayout* buttonsLayout = new QGridLayout();

    addButton = new QPushButton("Add");
    delButton = new QPushButton("Delete");
    updateButton = new QPushButton("Update");
    displayButton = new QPushButton("Open file");
    undoButton =  new QPushButton("Undo");
    redoButton = new QPushButton("Redo");

    QString style = QString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0,")+
            QString("stop:0.000 rgba(%1, %2, %3, 255),").arg(255).arg(0).arg(0) +
            QString("stop:1.000 rgba(%1, %2, %3, 255));").arg(0).arg(100).arg(100);
    addButton->setStyleSheet(style);
    dogsList->setStyleSheet(style);

    buttonsLayout->addWidget(addButton,0,0);
    buttonsLayout->addWidget(delButton,0,1);
    buttonsLayout->addWidget(updateButton,0,2);
    buttonsLayout->addWidget(displayButton,1,1);
    buttonsLayout->addWidget(undoButton,1,0);
    buttonsLayout->addWidget(redoButton,1,2);

    functionsLayout->addLayout(adminListLayout);
    functionsLayout->addLayout(descriptionsLayout);
    functionsLayout->addLayout(buttonsLayout);

    QVBoxLayout* filterLayout = new QVBoxLayout();

    QLabel* filter = new QLabel("Filter: ");
    edit =  new QLineEdit();
    filter->setBuddy(edit);
    filterList =  new QListWidget();

    filterLayout->addWidget(filter);
    filterLayout->addWidget(edit);
    filterLayout->addWidget(filterList);

    adminLayout->addLayout(functionsLayout);
    adminLayout->addLayout(filterLayout);

    QWidget* user = new QWidget();

    QHBoxLayout* userLayout = new QHBoxLayout(user);

    QVBoxLayout* userFunctions = new QVBoxLayout();

    QGridLayout* cycleDogs = new QGridLayout();

    nextDogButton = new QPushButton("Next dog");
    adoptButton = new QPushButton("Adopt dog");
    openPicButton = new QPushButton("Open picture");

    QLabel* dogLabel = new QLabel("Dog: ");
    dog = new QLineEdit();
    dogLabel->setBuddy(dog);

    cycleDogs->addWidget(nextDogButton,0,0);
    cycleDogs->addWidget(adoptButton,0,1);
    cycleDogs->addWidget(openPicButton,0,2);
    cycleDogs->addWidget(dogLabel,1,0);
    cycleDogs->addWidget(dog,1,1,1,2 );

    userFunctions->addLayout(cycleDogs);

    QGridLayout* dogFilterLayout = new QGridLayout();

    QLabel* breedFilterLabel = new QLabel("Breed to filter by: ");
    breedFilterEdit = new QLineEdit();
    breedFilterLabel->setBuddy(breedFilterEdit);

    QLabel* ageFilterLabel = new QLabel("Age to filter by: ");
    ageFilterEdit = new QLineEdit();
    ageFilterLabel->setBuddy(ageFilterEdit);

    filterUserButton = new QPushButton("Start filter");

    dogFilterLayout->addWidget(breedFilterLabel,0,0);
    dogFilterLayout->addWidget(breedFilterEdit,0,1,1,2);
    dogFilterLayout->addWidget(ageFilterLabel,1,0);
    dogFilterLayout->addWidget(ageFilterEdit,1,1,1,2);
    dogFilterLayout->addWidget(filterUserButton,2,0,1,3);

    userFunctions->addLayout(dogFilterLayout);

    openFileUser = new QPushButton("\n\n\n\n\n\n\n\n\n\nOpen file  \n\n\n\n\n\n\n\n\n");
    openFileUser->setStyleSheet(style);

    userFunctions->addWidget(openFileUser);

    showTableView = new QPushButton("Show Table View");

    userFunctions->addWidget(showTableView);

    QFormLayout* adoptionListLayout = new QFormLayout();

    QLabel* adoptListLabel = new QLabel("Adoption list: ");
    adoptionList = new QListWidget();
    adoptListLabel->setBuddy(adoptionList);

    adoptionListLayout->addWidget(adoptListLabel);
    adoptionListLayout->addWidget(adoptionList);

    userLayout->addLayout(userFunctions);
    userLayout->addLayout(adoptionListLayout);

    QWidget* chartWidget = new QWidget();

    QFormLayout* chartLayout = new QFormLayout(chartWidget);

//    QBarSeries* series = new QBarSeries();
//    chart = new QChart();
//    chart->addSeries(series);
//    chart->setTitle("Number of dogs of each breed");
//    chart->setAnimationOptions(QChart::AllAnimations);
//    chart->legend()->setVisible(true);
//    chart->legend()->setAlignment(Qt::AlignBottom);
//
//    chartView = new QChartView(chart);
//    chartView->setRenderHint(QPainter::Antialiasing);
//
//    chartLayout->addWidget(chartView);


    tabs->addTab(admin,"Admin");
    tabs->addTab(user,"User");
    tabs->addTab(chartWidget,"Chart");

    undoKey = new QShortcut(QKeySequence("Ctrl+Z"),this);
    redoKey = new QShortcut(QKeySequence("Ctrl+Y"),this);

    mainLayout->addWidget(tabs);
}

void Gui12::populateGui() {
    serv.database->storeToFileBasic();
    dogsList->clear();
    for(auto d : serv.getDogs())
    {
        QString itemInList = QString::fromStdString(d.getName()+"-"+d.getBreed());
        QListWidgetItem* item = new QListWidgetItem{itemInList};
        this->dogsList->addItem(item);
    }
    this->adoptionList->clear();
    for(auto d : servUser.getDogs())
    {
        QString itemInList = QString::fromStdString(d.getName()+"-"+d.getBreed());
        QListWidgetItem* item = new QListWidgetItem{itemInList};
        this->adoptionList->addItem(item);
    }
    bool ok = false;
    int i=0;
    if(serv.getSize()!=0)
        while(!ok )
            if(i <= serv.getSize())
        {
            if(serv.getDogs()[this->index].getBreed().find(breedToFilterBy)!=-1 &&
            serv.getDogs()[this->index].getAge()<stoi(ageToFilterBy))
            {
                dog->clear();
                dog->insert(QString::fromStdString(serv.getDogs()[this->index].getName() + "-" +
                                           serv.getDogs()[this->index].getBreed()));
                ok=true;
            }
            else{
                i++;
                index++;
                if(index>=serv.getSize())
                    index=0;
            }
        }
        else
            {
                dog->clear();
                break;
            }
    else
        dog->clear();
}

void Gui12::connectObjects() {
    QObject::connect(edit,&QLineEdit::textChanged,this,&Gui12::filter);
    QObject::connect(dogsList,&QListWidget::itemClicked,this,&Gui12::displayData);
    QObject::connect(addButton,&QPushButton::clicked,this,&Gui12::addDog);
    QObject::connect(this,&Gui12::listChanged,this,&Gui12::populateGui);
    QObject::connect(delButton,&QPushButton::clicked,this,&Gui12::deleteDog);
    QObject::connect(updateButton,&QPushButton::clicked,this,&Gui12::updateDog);
    QObject::connect(displayButton,&QPushButton::clicked,this,&Gui12::openFile);
    QObject::connect(openFileUser,&QPushButton::clicked,this,&Gui12::openFileU);
    QObject::connect(nextDogButton,&QPushButton::clicked,this,&Gui12::nextDog);
    QObject::connect(adoptButton,&QPushButton::clicked,this,&Gui12::adoptDog);
    QObject::connect(openPicButton,&QPushButton::clicked,this,&Gui12::openPicFile);
    QObject::connect(filterUserButton,&QPushButton::clicked,this,&Gui12::filterUser);
    QObject::connect(undoButton,&QPushButton::clicked,this,&Gui12::undo);
    QObject::connect(redoButton,&QPushButton::clicked,this,&Gui12::redo);
    QObject::connect(undoKey,&QShortcut::activated,this,&Gui12::undo);
    QObject::connect(redoKey,&QShortcut::activated,this,&Gui12::redo);
    QObject::connect(showTableView,&QPushButton::clicked,this,&Gui12::showView);
}

void Gui12::filter() {
    this->filterList->clear();
    QString filterData = edit->text();
    std::string toFilter = filterData.toStdString();
    for(auto d : serv.getDogs()) {
        std::string dog = d.getName() + "-" + d.getBreed();
        if(toFilter=="")
            break;
        else
        if (dog.find(toFilter) != -1) {
            QString itemInList = QString::fromStdString(d.getName() + "-" + d.getBreed());
            QListWidgetItem *item = new QListWidgetItem{itemInList};
            this->filterList->addItem(item);
        }
    }
}

void Gui12::displayData() {
    nameWidget->clear();
    breedWidget->clear();
    ageWidget->clear();
    linkWidget->clear();
    int index = dogsList->currentRow();
    int i = 0;
    for(auto d : serv.getDogs())
        if(i==index)
        {    nameWidget->insert(QString::fromStdString(d.getName()));
             breedWidget->insert(QString::fromStdString(d.getBreed()));
             ageWidget->insert(QString::fromStdString(std::to_string(d.getAge())));
             linkWidget->insert(QString::fromStdString(d.getLink_to_photo()));
             break;
        }
        else
            i++;
}

void Gui12::addDog() {
    QString name = nameWidget->text();
    QString breed = breedWidget->text();
    QString age = ageWidget->text();
    QString link = linkWidget->text();

    std::string nameString = name.QString::toStdString();
    std::string breedString = breed.QString::toStdString();
    std::string ageString = age.QString::toStdString();
    std::string linkString = link.QString::toStdString();

    try{
        val.checkIfStringEmpty(nameString);
        val.checkIfStringEmpty(breedString);
        val.checkIfStringEmpty(ageString);
        val.checkIfStringEmpty(linkString);
        val.validateInteger(ageString);
    }catch(GuiException& ge){
        return;
    }
    int ageInt = std::stoi(ageString);
    try{
    serv.addDog(nameString,breedString,ageInt,linkString);
    }catch(RepoException& re){
        return;
    }
    nameWidget->clear();
    breedWidget->clear();
    ageWidget->clear();
    linkWidget->clear();
    emit listChanged();
}

void Gui12::deleteDog() {
    QString name = nameWidget->text();
    QString breed = breedWidget->text();
    QString age = ageWidget->text();
    QString link = linkWidget->text();

    std::string nameString = name.QString::toStdString();
    std::string breedString = breed.QString::toStdString();
    std::string ageString = age.QString::toStdString();
    std::string linkString = link.QString::toStdString();
    try{
        val.checkIfStringEmpty(nameString);
        val.checkIfStringEmpty(breedString);
        val.checkIfStringEmpty(ageString);
        val.checkIfStringEmpty(linkString);
        val.validateInteger(ageString);
    }catch(GuiException& ge){
        return;
    }
    int ageInt = std::stoi(ageString);
    Dog dog(breedString,nameString,linkString,ageInt);
    for(auto d: serv.getDogs())
    {
        if(dog==d)
            serv.removeDog(d.getId());
    }
    nameWidget->clear();
    breedWidget->clear();
    ageWidget->clear();
    linkWidget->clear();
    emit listChanged();
}

void Gui12::updateDog() {
    QString name = nameWidget->text();
    QString breed = breedWidget->text();
    QString age = ageWidget->text();
    QString link = linkWidget->text();

    std::string nameString = name.QString::toStdString();
    std::string breedString = breed.QString::toStdString();
    std::string ageString = age.QString::toStdString();
    std::string linkString = link.QString::toStdString();
    try{
        val.checkIfStringEmpty(nameString);
        val.checkIfStringEmpty(breedString);
        val.checkIfStringEmpty(ageString);
        val.checkIfStringEmpty(linkString);
        val.validateInteger(ageString);
    }catch(GuiException& ge){
        return;
    }
    int ageInt = std::stoi(ageString);
    Dog dog(breedString,nameString,linkString,ageInt);
    int index = dogsList->currentRow();
    int i=0;
    for(auto d : serv.getDogs())
        if(i==index)
        {
            try {
                serv.updateDog(d.getId(), dog);
            }catch(RepoException& re)
            {
                return;
            }
            break;
        }
        else
            i++;
    nameWidget->clear();
    breedWidget->clear();
    ageWidget->clear();
    linkWidget->clear();
    emit listChanged();
}

void Gui12::openFile() {
    this->serv.openFile();
}

void Gui12::chooseRepo() {
    Layout = new QHBoxLayout(this);
    csv = new QPushButton("CSV");
    csv->resize(500,500);
    html = new QPushButton("HTML");
    html->resize(500,500);
    Layout->addWidget(csv);
    Layout->addWidget(html);
    QObject::connect(csv,&QPushButton::clicked,this,&Gui12::initCSV);
    QObject::connect(html,&QPushButton::clicked,this,&Gui12::initHTML);
}

void Gui12::initCSV() {
    delete Layout;
    delete csv;
    delete html;
    Database<Dog>* dogb = new CSV;
        dogb->readFromFile();
    dogb->filename ="C:/Users/timod/CLionProjects/QtA11-12/csv.csv";
    Database<Dog>* dogu = new CSV;
    Service userServCSV(dogu);
    dogu->filename ="C:/Users/timod/CLionProjects/QtA11-12/csvUser.csv";
    Service serviceCSV(dogb);
    servUser = userServCSV;
    serv = serviceCSV;
    this->initGui();
    this->populateGui();
    this->connectObjects();

}

void Gui12::initHTML() {
    delete Layout;
    delete csv;
    delete html;
    Database<Dog>* dogb = new HTML;
    dogb->readFromFile();
    dogb->filename ="C:/Users/timod/CLionProjects/QtA11-12/html.html";
    Service serviceHTML(dogb);
    Database<Dog>* dogu = new HTML;
    dogu->filename ="C:/Users/timod/CLionProjects/QtA11-12/htmlUser.html";
    Service userServHTML(dogu);
    servUser = userServHTML;
    serv = serviceHTML;
    this->initGui();
    this->populateGui();
    this->connectObjects();
}

void Gui12::openFileU() {
    this->servUser.openFile();
}

void Gui12::nextDog() {
    this->index++;
    if(index>=this->serv.getSize())
        this->index=0;
    emit listChanged();
}

void Gui12::adoptDog() {
    if(serv.getSize()!=0)
    {
        Dog d = serv.getDogs()[index];
        serv.removeDog(serv.getDogs()[index].getId());
        servUser.database->add(d);
        emit listChanged();
    }
}

void Gui12::openPicFile() {
    serv.getDogs()[index].open();
}

void Gui12::filterUser() {
    QString breed = breedFilterEdit->text();
    QString age = ageFilterEdit->text();

    breedToFilterBy = breed.toStdString();
    ageToFilterBy = age.toStdString();

    if(ageToFilterBy=="")
        ageToFilterBy="99999";

    this->index = 0;
    emit listChanged();
}

void Gui12::undo() {
    serv.undo();
    emit listChanged();
}

void Gui12::redo() {
    serv.redo();
    emit listChanged();
}

void Gui12::showView() {
    tableView = new QTableView;
    model = new MyModel(this->serv.database);
    tableView->setModel(model);
    tableView->show();
}

