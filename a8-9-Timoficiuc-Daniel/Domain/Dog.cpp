#include "Dog.h"
#include <Windows.h>
#include <shellapi.h>

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
    (this->age == other.age));
}
/**
 * inequality != operator for Dog objects
 * @param other
 * @return
 */
bool Dog::operator!=(const Dog &other) const {
    return !((this->name == other.name)&&(this->breed == other.breed)&&(this->link_to_photo == other.link_to_photo)&&
            (this->age == other.age));
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

/**
 * operator << used to store into a file the dog objects
 * @param os
 * @param d
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Dog &d) {
    os << d.name << "," << d.breed << "," << d.age << ","<< d.id <<","<<d.link_to_photo<<"\n";
    return os;
}

/**
 * operator >> used to read dog objects from a file
 * @param is
 * @param d
 * @return
 */
std::istream &operator>>(std::istream &is, Dog &d) {
    if(is.eof())
        is.setstate(std::ios_base::failbit);
    else
    {
        getline(is,d.name,',');
        if(d.name.empty())
            return is;
        getline(is,d.breed,',');
        std::string age;
        getline(is,age,',');
        int a ;
        a = std::stoi(age);
        d.age = a;
        std::string idS;
        getline(is,idS,',');
        int b;
        b = std::stoi(idS);
        d.id = b;
        getline(is,d.link_to_photo,'\n');
        initialId = b + 1;
    }
    return is;
}



