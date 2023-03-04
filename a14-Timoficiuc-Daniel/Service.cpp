#include "Service.h"
/**
 * default constructor for service
 */
Service::Service() = default;
/**
 * copy constructor for service
 * @param other
 */
Service::Service(Database<Dog>* other) {
    this->database = other;
    this->manager = new CommandManager();
}
/**
 * creates a Dog objects and adds it to repo
 * @param name
 * @param breed
 * @param age
 * @param link
 * @return
 */
void Service::addDog(std::string name, std::string breed, int age, std::string link) {
        Dog dog(breed,name,link,age);
        this->database->add(dog);
        manager->RedoStack = std::stack<std::shared_ptr<Command>>();
        std::shared_ptr<Command> c(new AddCommand(dog,this->database));
        manager->UndoStack.push(c);
}
/**
 * removes a dog from the repo given by an id
 * @param id
 * @return
 */
void Service::removeDog(int id) {
        int index = 0;
        for(auto& d: this->database->getElems())
            if(id == d.getId())
                break;
            else
                index++;
        Dog dog = this->database->getItem(index);
        std::shared_ptr<Command> c(new RemoveCommand(dog,this->database));
        this->database->remove(id);
        manager->RedoStack = std::stack<std::shared_ptr<Command>>();
        manager->UndoStack.push(c);

}
/**
 * updates a Dog from repo based on its id and option selected
 * @param id
 * @param dog
 * @return
 */
void Service::updateDog(int id, Dog& d) {
    Dog initDog;
    d.setId(id);
    for(auto doggo: this->database->getElems())
        if(doggo.getId() == id)
            initDog = doggo;
    this->database->update(id,d);
    manager->RedoStack = std::stack<std::shared_ptr<Command>>();
    std::shared_ptr<Command> c(new UpdateCommand(initDog,d,this->database));
    manager->UndoStack.push(c);

}
/**
 * returs a Dog object from repo and advances the iterator by 1;
 * @return
 */
Dog Service::getCurrentDog() {
    this->database->next();
    return this->database->getCurrentDog();

}
/**
 * returns size of the array
 * @return
 */
int Service::getSize() {
    return this->database->getSize();
}

/**
 * returns dog object from repo based on an index
 * @param index
 * @return
 */
Dog Service::getDog(int index) {
    return this->database->getItem(index);
}

/**
 * stores the repo into the file and opens it accordingly
 */
void Service::openFile() {
    this->database->storeToFile();
    this->database->display();
}

std::vector<Dog> Service::getDogs() {
    return this->database->getElems();
}

void Service::undo() {
    manager->undo();
}

void Service::redo() {
    manager->redo();
}


