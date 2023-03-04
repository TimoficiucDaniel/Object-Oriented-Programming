#ifndef A5_6_DATABASE_H
#define A5_6_DATABASE_H

#include "DynamicVectorTemplate.h"
#pragma once

/**
 * template class for Database usign generic TElem
 * @tparam TElem
 */
template <typename TElem> class Database{

    /**
     * private attribute used for getting items in the database
     */
    private:
    int current_element_index;

    public:
    /**
     * default constructor
     */
        Database()= default;

        /**
         * copy constructor for the database
         * @param other
         */
        Database(const Database<TElem>& other){
            this->repo = other.repo;
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
            return repo.getItem(index);
        }
        /**
         * adds the item to the database
         * @param item
         * @return
         */
        bool add(const TElem& item){
            return repo.add(item);
        }
        /**
         * removes tahe item from the database based on a unique identifier id
         * @param id
         * @return
         */
        bool remove(const int id){
            return repo.remove(id);
        }
        /**
         * returns the size of the array holding the data
         * @return
         */
        int getSize(){
            return repo.getSize();
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
        bool next(){
            if(this->getSize() == 0)
                return false;
            this->current_element_index ++;
            return true;
        }
    /**
     * public attribute dynamic vector
     */
    DynamicVector<TElem> repo;
};

#endif //A5_6_DATABASE_H
