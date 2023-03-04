#ifndef QTA11_12_UNDOREDO_H
#define QTA11_12_UNDOREDO_H
#include "memory"
#include "Database.h"
#include "stack"

class Command{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual void redo() = 0;
};

class AddCommand:public Command{
    Database<Dog>* data;
    Dog d;
public:
    explicit AddCommand(Dog& d,Database<Dog>* data){
        this->data = data;
        this->d = d;
    };
    void execute() override{
        data->add(d);
    };

    void undo() override{
        data->remove(d.getId());
    };

    void redo() override{
        data->add(d);
    }
};

class RemoveCommand:public Command{
    Database<Dog>* data;
    Dog d;
public:
    explicit RemoveCommand(Dog& d,Database<Dog>* data){
        this->data = data;
        this->d = d;
    };
    void execute() override{
      data->remove(d.getId());
    };
    void undo() override{
      data->add(d);
    };
    void redo() override{
      data->remove(d.getId());
    };
};

class UpdateCommand:public Command{
    Database<Dog>* data;
    Dog d1;
    Dog d2;
public:
    explicit UpdateCommand(Dog d1,Dog d2,Database<Dog>* data){
        this->data = data;
        this->d1 = d1;
        this->d2 = d2;
    };
    void execute() override{
        data->update(d1.getId(),d2);
    };
    void undo() override{
        data->update(d1.getId(),d1);
    };
    void redo() override{
        data->update(d1.getId(),d2);
    };
};

class CommandManager{
public:
    std::stack<std::shared_ptr<Command>> UndoStack;
    std::stack<std::shared_ptr<Command>> RedoStack;

    void undo(){
      if(UndoStack.empty()){
          return;
      }
      UndoStack.top()->undo();
      RedoStack.push(UndoStack.top());
      UndoStack.pop();
    };

    void redo(){
      if(RedoStack.empty())
      {
          return;
      }
      RedoStack.top()->redo();
      UndoStack.push(RedoStack.top());
      RedoStack.pop();
    };
};
#endif //QTA11_12_UNDOREDO_H
