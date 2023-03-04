#ifndef A5_6_DATABASE_H
#define A5_6_DATABASE_H

#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Dogs.h"
#include <cctype>
#include "RepoExceptions.h"
#pragma once

/**
 * template class for Database using generic TElem
 * @tparam TElem
 */
template <typename TElem> class Database{

    /**
     * private attribute used for getting items in the database
     */
    protected:
    std::vector<TElem> elements;
    int current_element_index;

    public:
    std::string filename;
        /**
         * default constructor
         */
        Database()= default;

        /**
         * copy constructor for the database
         * @param other
         */
        Database(const std::vector<TElem>& other){
            this->elements = other;
            this->current_element_index = -1;
        }

        /**
         * resets the attribute used for getting the items in the database to the first position
         */
        void resetIterator(){
            this->current_element_index = -1;
        }

        /**
         * returns an item from the database with a certain index
         * @param index
         * @return
         */
        TElem getItem(const int index)const{
            return this->elements[index];
        }
        /**
         * adds the item to the database
         * @param item
         * @return
         */
        void add(const TElem& item){
            int index = 0;
            for (auto i : this->elements ) {
                if (this->getItem(index) == item) {
                    throw RepoException("Object could not be added.\n");
                }
                index++;
            }
            this->elements.push_back(item);
        }
        /**
         * removes the item from the database based on a unique identifier id
         * @param id
         * @return
         */
        void remove(const int id){
            int index = 0;
            for (auto  i : this->elements) {
                if (this->elements[index].getId() == id) {
                    this->elements.erase(this->elements.begin() + index);
                    return;
                }
                index++;
            }
            throw RepoException("Object to delete not found.\n");
        }
        /**
         * returns the size of the array holding the data
         * @return
         */
        int getSize(){
            return this->elements.size();
        }
        /**
         * returns the item corresponding to the private attribute(current_element_index)
         * @return
         */
        TElem getCurrentDog(){
            if(this->current_element_index >= this->getSize())
                this->current_element_index = 0;
            if(this->getSize()>0)
                return this->getItem(this->current_element_index);
        }
        /**
         * advances the iterator by one
         * @return
         */
        void next(){
            if(this->getSize() == 0)
                throw RepoIteratorException("No objects to parse through.\n");
            this->current_element_index ++;
        }
        /**
         * public attribute dynamic vector
         */

        void update(const int id, const Dog& dog) {
            int index = 0;
            for(auto d: this->elements) {
                if (id == d.getId()) {
                    this->elements[index].setName(dog.getName());
                    this->elements[index].setAge(dog.getAge());
                    this->elements[index].setBreed(dog.getBreed());
                    this->elements[index].setLink_to_photo(dog.getLink_to_photo());
                    return;
                }
                index++;
            }
         throw RepoException("Could not update any object.\n");
        }

        /**
        * Appends an item in the array
        * @param other:
        * @return:
        */
        Database<TElem> &operator+(const TElem &other) {
            int index = 0;
            for (auto i : this->elements) {
                if (this->getItem(index) == other)
                    return *this;
                index++;
            }
            this->add(other);
            return *this;
        }

        /**
      * assignment operator
      * @param v:
      * @return: :
      */
        Database<TElem> &operator=(const Database<TElem> &v) {
            if (this == &v)
                return *this;
            this->elements.clear();
            this->elements = v.elements;
            return *this;
        }

        std::vector<TElem> getElems(){
            return this->elements;
        }

        /**
         * stores the repo into a file located at filename
         */
        virtual void storeToFile() {
            std::ofstream file(filename);
            if(!file.is_open())
                return;
                //throws exception
            for(auto d : this->elements)
            {
                file << d;
            }
            file.close();
        }

        /**
         * stores the repo into a basic textfile used for reading
         */
         void storeToFileBasic() {
        std::ofstream file("C:/Users/timod/CLionProjects/QtA11-12/text.txt");
        if(!file.is_open())
            return;
        //throws exception
        for(auto d : this->elements)
        {
            file << d;
        }
        file.close();
    }
        /**
         * reads the repo from the textfile and adds those objects to the array
         */
        void readFromFile(){
            std::ifstream file("C:/Users/timod/CLionProjects/QtA11-12/text.txt");

            if (!file.is_open())
               return;
                //throw exception

            Dog d;
            while (file >> d)
                this->add(d);

            file.close();
        }

        virtual void display(){
            return;
        }
};



#endif //A5_6_DATABASE_H
