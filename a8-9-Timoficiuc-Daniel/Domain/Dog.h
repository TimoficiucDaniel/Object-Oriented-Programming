#ifndef A5_6_DOG_H
#define A5_6_DOG_H
#pragma once
#include <string>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>

static int initialId = 1;

class Dog {
    public:
        int age;
        std::string name;
        std::string link_to_photo;
        std::string breed;
    private:
        int id;

public:
    Dog();
    Dog(const std::string& breed, const std::string& name, const std::string& link_to_photo,int age);

    std::string getName() const;
    std::string getLink_to_photo() const;
    std::string getBreed() const;
    int getAge() const;
    int getId() const;

    void setName(std::string& name);
    void setLink_to_photo(std::string& link_to_photo);
    void setBreed(std::string& breed);
    void setAge(int& age);
    void open();

    void operator=(const Dog& other);
    bool operator==(const Dog& other) const;
    bool operator!=(const Dog& other) const;

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os , const Dog& d);
    friend std::istream& operator>>(std::istream& is , Dog& d);


};


#endif //A5_6_DOG_H
