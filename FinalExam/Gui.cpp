#include "Gui.h"

Gui::Gui() {
    initGui();
    populate();
    connect();
}

void Gui::initGui() {
    ///Members
    for(int i = 0; i<(*s.getMembers()).size();i++)
    {
        QWidget* window = new QWidget();
        QVBoxLayout* windowLayout = new QVBoxLayout(window);
        window->setWindowTitle(QString::fromStdString((*s.getMembers())[i].getName()));

        listsOfFiles.push_back(new QListWidget);
        windowLayout->addWidget(listsOfFiles[i]);
        listsOfRevised.push_back((new QLabel()));
        windowLayout->addWidget(listsOfRevised[i]);
        listsOfToRevise.push_back((new QLabel()));
        windowLayout->addWidget(listsOfToRevise[i]);
        edits.push_back(new QLineEdit);
        windowLayout->addWidget(edits[i]);
        add.push_back(new QPushButton("Add file"));
        windowLayout->addWidget(add[i]);
        revise.push_back(new QPushButton("Revise file"));
        windowLayout->addWidget(revise[i]);

        window->show();
    }

    QWidget* listWindow = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(listWindow);
    stats = new QListWidget();
    mainLayout->addWidget(stats);
    listWindow->show();
    repaint();
}

void Gui::populate() {
    s.sortFilesByName();
    QFont f;
    f.setBold(true);
    QColor c(0,255,0);
    QColor d(0,0,255);
    QBrush e(d);
    QBrush b(c);
    for(int i = 0 ; i<(*s.getMembers()).size();i++)
    {
        listsOfFiles[i]->clear();
        int index=0;
        for(auto s: *s.getFiles())
        {
            QString itemInList = QString::fromStdString(s.getName()+" "+s.getStatus()+" "+s.getCreatorName()+" "+s.getReviewerName());
            QListWidgetItem* item = new QListWidgetItem(itemInList);
            if(this->s.notRevised(index))
                item->setFont(f);
            else
                item->setBackground(b);
            listsOfFiles[i]->addItem(item);
            index++;
        }

        listsOfRevised[i]->setText(QString::fromStdString((*s.getMembers())[i].getName()+" has revised "+ std::to_string((*s.getMembers())[i].revised)+" files"));
        listsOfToRevise[i]->setText(QString::fromStdString((*s.getMembers())[i].getName()+" has to revise "+ std::to_string((*s.getMembers())[i].totalRevised)+" files"));
    }
    stats->clear();
    for(auto u:(*s.getMembers()))
    {
        QString itemInList = QString::fromStdString(u.getName());
        QListWidgetItem* item = new QListWidgetItem(itemInList);
        if(u.getTotalRevised()==u.getRevised())
            item->setForeground(e);
        stats->addItem(item);
    }
}

void Gui::connect() {
    for(int i = 0; i<(*s.getMembers()).size();i++)
    {
        QObject::connect(add[i],&QPushButton::clicked,this,&Gui::addFile);
        QObject::connect(revise[i],&QPushButton::clicked,this,&Gui::reviseFile);
    }
    QObject::connect(this,&Gui::listChanged,this,&Gui::populate);
    QObject::connect(this,SIGNAL(listChanged()),this,SLOT(update()));
}

void Gui::addFile() {
    int index = 0;
    for(int i = 0; i<(*s.getMembers()).size();i++)
    {
        if(sender()==add[i])
            index=i;
    }
    std::string data = edits[index]->text().toStdString();
    edits[index]->clear();
    if(s.checkIfValidFile(data)) {
        s.addFile(data, (*s.getMembers())[index].getName());
        emit listChanged();
    }
    else{
        QErrorMessage* msg = new QErrorMessage();
        msg->showMessage("Error in adding file ;\nline edit might be empty or file is already in repo");
    }
}

void Gui::reviseFile() {
    int index = 0;
    for(int i = 0; i<(*s.getMembers()).size();i++)
    {
        if(sender()==revise[i])
            index=i;
    }
    int row = listsOfFiles[index]->currentRow();
    for(int i = 0;i< (*s.getFiles()).size();i++)
    {
        if(row==i)
        {
            if( (*s.getFiles())[i].getStatus()=="revised" || (*s.getMembers())[index].getName()== (*s.getFiles())[i].getCreatorName())
                return;
            else {
                (*s.getMembers())[index].incRevised();
                //(*s.getMembers())[index].decTotalRevised();
                (*s.getFiles())[i].setStatus("revised");
                (*s.getFiles())[i].setReviewer((*s.getMembers())[index].getName());
                if((*s.getMembers())[index].getTotalRevised()==(*s.getMembers())[index].getRevised())
                {
                    QMessageBox* box = new QMessageBox();
                    box->setText("Congratulations !You did it!");
                    box->exec();
                }
                //(*s.getMembers())[index].setEmpty();
                emit listChanged();
                break;
            }
        }
    }
}

void Gui::paintEvent(QPaintEvent *event) {
    for(int i= 0;i<(*s.getMembers()).size();i++) {
        QRectF rectangle(10.0, i*120.0+10, (*s.getMembers())[i].getRevised()*20.0+20, (*s.getMembers())[i].getRevised()*20.0+20);
        int startAngle = 30 * 16;
        int spanAngle = 360 * 16;

        QColor c(0,0,255);
        QBrush b(c);
        QPainter painter(this);
        if((*s.getMembers())[i].getRevised()==(*s.getMembers())[i].getTotalRevised())
            painter.setBrush(b);
        painter.drawPie(rectangle, startAngle, spanAngle);
    }
}


