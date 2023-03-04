#include "Service.h"
/**
 * default constructor for service
 */
Service::Service() = default;
/**
 * copy constructor for service
 * @param other
 */
Service::Service(Database<Dog> &other) {
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
bool Service::addDog(std::string name, std::string breed, int age, std::string link) {
        Dog dog(breed,name,link,age);
        return this->database.add(dog);
}
/**
 * removes a dog from the repo given by an id
 * @param id
 * @return
 */
bool Service::removeDog(int id) {
        return this->database.remove(id);

}
/**
 * updates a Dog from repo based on its id and option selected
 * @param option
 * @param id
 * @param item_to_change
 * @return
 */
bool Service::updateDog(int option, int id, const std::string& item_to_change) {
    return this->database.repo.update(id,option,item_to_change);

}
/**
 * returs a Dog object from repo and advances the iterator by 1;
 * @return
 */
Dog Service::getCurrentDog() {
    bool x = this->database.next();
    return this->database.getCurrentDog();

}

