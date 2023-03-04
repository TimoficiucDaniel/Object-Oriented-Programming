#include "Dog.h"
#include <Windows.h>
#include <shellapi.h>
#include <string>

/**
 * Dog object base constructor
 */
Dog::Dog() {
    this->age = -1;
    this->breed = "";
    this->name = "";
    this->link_to_photo = "";
    this->id = -1;

}
/**
 * Dog object copy constructor
 * @param breed
 * @param name
 * @param link_to_photo
 * @param age
 */
Dog::Dog(const std::string &breed, const std::string &name, const std::string &link_to_photo, const int age) {
    this->age = age;
    this->breed = breed;
    this->name = name;
    this->link_to_photo = link_to_photo;
    this->id = initialId;
    initialId += 1;

}

/**
 * getter for the name attribute
 * @return
 */
std::string Dog::getName() const {
    return this->name;
}
/**
 * getter for the link attribute
 * @return
 */
std::string Dog::getLink_to_photo() const {
    return this->link_to_photo;
}
/**
 * getter for the breed attribute
 * @return
 */
std::string Dog::getBreed() const {
    return this->breed;
}
/**
 * gettter for the id attribute
 * @return
 */
int Dog::getId() const {
    return this->id;
}
/**
 * getter for the age attribute
 * @return
 */
int Dog::getAge() const {
    return this->age;
}
/**
 * setter for the name attribute
 */
void Dog::setName(std::string& new_name) {
    this->name = new_name;
}
/**
 * setter for the link attribute
 * @param new_link_to_photo
 */
void Dog::setLink_to_photo(std::string& new_link_to_photo) {
    this->link_to_photo = new_link_to_photo;
}
/**
 * setter for the breed attribute
 * @param new_breed
 */
void Dog::setBreed(std::string& new_breed) {
    this->breed = new_breed;
}
/**
 * setter for the age attribute
 * @param new_age
 */
void Dog::setAge(int& new_age) {
    this->age = new_age;
}
/**
 *  = operator for basically copying Dog objects
 * @param other
 */
void Dog::operator=(const Dog& other){
    this->link_to_photo = other.link_to_photo;
    this->name = other.name;
    this->breed = other.breed;
    this->age = other.age;
    this->id = other.id;
}

/**
 * == equality operator for Dog objects
 * @param other
 * @return
 */
bool Dog::operator==(const Dog& other) const {
    return ((this->name == other.name)&&(this->breed == other.breed)&&(this->link_to_photo == other.link_to_photo)&&
    (this->age == other.age)&&(this->id == other.id));
}
/**
 * inequality != operator for Dog objects
 * @param other
 * @return
 */
bool Dog::operator!=(const Dog &other) const {
    return !((this->name == other.name)&&(this->breed == other.breed)&&(this->link_to_photo == other.link_to_photo)&&
            (this->age == other.age)&&(this->id == other.id));
}
/**
 * converts the object to a printable string
 * @return
 */
std::string Dog::toString() const
{
    std::string ageStr = std::to_string(this->age);
    std::string idStr = std::to_string(this->id);

    std::string dogStr = "Dog with the breed " + this->breed + ", the name " + this->name
                         + ", age of " + ageStr + ", (id=" + idStr +") and internet link is " +this->link_to_photo+"\n";
    return dogStr;
}
/**
 * function that opens on the web a certain link attached to the object
 */
void Dog::open()
{
    ShellExecuteA(nullptr, nullptr, "chrome.exe", this->link_to_photo.c_str(),
                  nullptr, SW_SHOWMAXIMIZED);
}



