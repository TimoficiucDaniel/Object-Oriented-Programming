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
}
/**
 * removes a dog from the repo given by an id
 * @param id
 * @return
 */
void Service::removeDog(int id) {
        this->database->remove(id);

}
/**
 * updates a Dog from repo based on its id and option selected
 * @param option
 * @param id
 * @param item_to_change
 * @return
 */
void Service::updateDog(int option, int id, const std::string& item_to_change) {
    this->database->update(id,option,item_to_change);

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

