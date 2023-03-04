#ifndef A5_6_DYNAMICVECTORTEMPLATE_H
#define A5_6_DYNAMICVECTORTEMPLATE_H
#pragma once

#include <iterator>
#include <iostream>
#include <string>

template< typename TElem>
class DynamicVector
{
public:
    TElem* elements;
private:
    int capacity;
    int size;

public:

    /**
     * default constructor for arrray
     */
    DynamicVector()
    {
        this->size = 0;
        this->capacity = 1;
        this->elements =         new TElem[this->capacity];
    }
    /**
     * assignment operator
     * @param v:
     * @return: :
     */
    DynamicVector<TElem>& operator= (const DynamicVector<TElem>& v)
    {
        if (this == &v)
            return *this;

        this->size = v.size;
        this->capacity = v.capacity;
        delete[] this->elements;
        this->elements = new TElem[this->capacity];
        for(int i = 0; i < this->size; i++)
            this->elements[i] = v.elements[i];

        return *this;
    }

    /**
     * copy constructor for array
     * @param other:
     */
    DynamicVector(const DynamicVector<TElem>& other)
    {
        this->size = other.size;
        this->capacity = other.capacity;
        this->elements = new TElem[this->capacity];
        for(int i=0; i<this->size; i++)
            this->elements[i] = other.elements[i];
    }

    /**
     * a destructor
     */
    ~DynamicVector()
    {
        delete[] this->elements;
    }

    /**
     * Returns the size of the array
     * @return: int
     */
    int getSize() const
    {
        return this->size;
    }

    /**
     * returns the item at index
     * @param index: int
     * @return: T
     */
    TElem getItem(const int index) const
    {
        //throw exception if there's nothing at index
        return this->elements[index];
    }

    /**
     * appends an item in the array
     * @param item:
     */
    bool add(const TElem& item)
    {
        for(int i = 0; i < this->size; i++)
        {
            if (this->getItem(i) == item) {
                return false;
            }
        if (this->size == this->capacity)
            this->resize();
        }
            this->elements[this->size] = item;
            this->size += 1;
            return true;
        }


    /**
     * Removes the item with id from the array
     * @param id:
     * @return:
     *
     */
    bool remove(const int id)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->elements[i].getId() == id)
            {
                this->size --;
                for (int j = i; j < this->size; j++)
                {
                    this->elements[j] = this->elements[j + 1];
                }
                return true;
            }
        }
        return false;
    }

    /**
     * updates the an object given by its id according to certain options
     * @param id
     * @param option
     * @param string
     * @return
     */
    bool update(const int id, const int option , std::string string) {
        for (int i = 0; i < this->size; i++) {
            if (this->elements[i].getId() == id) {
                if (option == 1)
                    this->elements[i].setName(string);
                if (option == 2)
                    this->elements[i].setBreed(string);
                if (option == 4)
                    this->elements[i].setLink_to_photo(string);
                if (option == 3) {
                    for (char const &c: string) {
                        if (std::isdigit(c) == 0)
                            return false;
                    }
                    int age = stoi(string);
                    this->elements[i].setAge(age);

                }
                return true;
            }
        }
            return false;
    }

    /**
     * Appends an item in the array
     * @param other:
     * @return:
     */
    DynamicVector<TElem>& operator+ (const TElem& other)
    {
        for(int i = 0; i < this->size; i++)
        {
            if (this->getItem(i) == other)
                return *this;
        }
        this->add(other);
        return *this;
    }


private:
    /**
     * doubles the array's capacity once it is full
     */
    void resize()
    {
        this->capacity *= 2;
        TElem* newElements = new TElem[capacity];
        for (int i = 0; i < this->size; i++)
            newElements[i] = this->elements[i];

        delete[] this->elements;
        this->elements = newElements;
    }
};
#endif //A5_6_DYNAMICVECTORTEMPLATE_H
