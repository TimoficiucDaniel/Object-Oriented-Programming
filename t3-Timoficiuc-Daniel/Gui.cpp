#include "Gui.h"

Gui::Gui() {
    initGui();
    populate();
    connectObjects();
}

void Gui::populate() {
  serv.sortQuestionsByAnswers();
  for(int i =0; i< listOfQuestions.size(); i++)
  {
      listOfQuestions[i]->clear();
      for(auto q:*serv.getQuestions()){
        QString itemInList = QString::fromStdString(q.getUserName()+" : "+q.getText());
        QListWidgetItem* item = new QListWidgetItem(itemInList);
        listOfQuestions[i]->addItem(item);
      }
  }
}

void Gui::connectObjects() {
    for(int i =0; i< listOfQuestions.size();i++)
    {
        QObject::connect(listOfQuestions[i],&QListWidget::itemClicked,this,&Gui::showAnswers);
    }
    QObject::connect(searchEdit,&QLineEdit::textChanged,this,&Gui::findQuestion);
}

void Gui::initGui() {
    ///Users
    for(int i=0;i<serv.getSize();i++)
    {
        QWidget* window = new QWidget();
        window->setWindowTitle(QString::fromStdString((*serv.getUsers())[i].getName()));
        QHBoxLayout* layout = new QHBoxLayout(window);
        QVBoxLayout* questionsLayout = new QVBoxLayout();
        QVBoxLayout* answersLayout = new QVBoxLayout();
        QVBoxLayout* spinBoxLayout = new QVBoxLayout();
        layout->addLayout(questionsLayout);
        layout->addLayout(answersLayout);
        layout->addLayout(spinBoxLayout);
        listOfQuestions.push_back(new QListWidget());
        questionsLayout->addWidget(listOfQuestions[i]);
        questionLines.push_back((new QLineEdit()));
        questionsLayout->addWidget(questionLines[i]);
        addButtons.push_back(new QPushButton("Add question"));
        questionsLayout->addWidget(addButtons[i]);
        listOfQuestionDetails.push_back(new QListWidget());
        answersLayout->addWidget(listOfQuestionDetails[i]);
        answerLines.push_back(new QLineEdit());
        answersLayout->addWidget(answerLines[i]);
        answerButtons.push_back(new QPushButton("Add answer"));
        answersLayout->addWidget(answerButtons[i]);
        QLabel* votes = new QLabel("Votes");
        votesBoxes.push_back(new QSpinBox());
        votes->setBuddy(votesBoxes[i]);
        spinBoxLayout->addWidget(votes);
        spinBoxLayout->addWidget(votesBoxes[i]);
        window->show();
    }

    ///Main window
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    searchEdit =  new QLineEdit();
    mainLayout->addWidget(searchEdit);
    questionEdit = new QLineEdit();
    questionEdit->isReadOnly();
    mainLayout->addWidget(questionEdit);
    tabs = new QTabWidget();
    mainLayout->addWidget(tabs);
    QWidget* tabWidget1 = new QWidget();
    QWidget* tabWidget2 = new QWidget();
    QWidget* tabWidget3 = new QWidget();
    tabs->addTab(tabWidget1,"#1");
    tabs->addTab(tabWidget2,"#2");
    tabs->addTab(tabWidget3,"#3");
    QFormLayout* layout1 = new QFormLayout(tabWidget1);
    QFormLayout* layout2 = new QFormLayout(tabWidget2);
    QFormLayout* layout3 = new QFormLayout(tabWidget3);
    tab1 = new QListWidget();
    tab2 = new QListWidget();
    tab3 = new QListWidget();
    layout1->addRow(tab1);
    layout2->addRow(tab2);
    layout3->addRow(tab3);
}

void Gui::showAnswers() {
    int index = 0;
    for(int i = 0; i < serv.getSize();i++)
    {
        if(sender()==listOfQuestions[i])
        {   index = i;
            break;
        }
    }
    int i = 0;
    QColor color(255,255,0);
    QBrush b(color);
    listOfQuestionDetails[index]->clear();
    int index2 = listOfQuestions[index]->currentRow();
    for( auto q : *serv.getQuestions())
    {
        if(i==index2)
        {
            for(auto a : *serv.getAnswers())
            {
                if(a.getQuestionId()==q.getId()){
                QString itemInList = QString::fromStdString(std::to_string(a.getId())+" "+a.getUserName()+" : "+a.getText()+" , "+std::to_string(a.getVotes()));
                QListWidgetItem* item = new QListWidgetItem(itemInList);
                if(a.getUserName()==(*serv.getUsers())[index].getName())
                    item->setBackground(b);
                listOfQuestionDetails[index]->addItem(item);}
            }
            break;
        }
        i++;
    }
}

void Gui::findQuestion() {
    questionEdit->clear();
    tab1->clear();
    tab2->clear();
    tab3->clear();
    std::string data = searchEdit->text().toStdString();
    int id = serv.findBestMatchingQuestion(data);
    std::vector<Answer> answers;
    for(auto q : *serv.getQuestions())
        if(q.getId()==id) {
            questionEdit->insert(QString::fromStdString(q.getUserName() + " : " + q.getText()));
            answers = serv.getAnswersForQuestion(q);
        }
    serv.sortAnswersByVotes();
    if(answers.size() >0)
    {QString itemInList1 = QString::fromStdString(std::to_string(answers[0].getId())+" "+answers[0].getUserName()+" : "+answers[0].getText()+" , "+std::to_string(answers[0].getVotes()));
    QListWidgetItem* item1 = new QListWidgetItem(itemInList1);
    tab1->addItem(item1);}
    if(answers.size() >1){
    QString itemInList2 = QString::fromStdString(std::to_string(answers[1].getId())+" "+answers[1].getUserName()+" : "+answers[1].getText()+" , "+std::to_string(answers[1].getVotes()));
    QListWidgetItem* item2 = new QListWidgetItem(itemInList2);
    tab2->addItem(item2);}
    if(answers.size() >2){
    QString itemInList3 = QString::fromStdString(std::to_string(answers[2].getId())+" "+answers[2].getUserName()+" : "+answers[2].getText()+" , "+std::to_string(answers[2].getVotes()));
    QListWidgetItem* item3 = new QListWidgetItem(itemInList3);
    tab3->addItem(item3);}
}
