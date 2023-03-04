#pragma once
#define CAPACITY 100

typedef void* TElement;
typedef void (*DestroyElementFunctionType)(void*);

typedef struct
{
    TElement* elems;
    int length;			// actual length of the array
    int capacity;		// maximum capacity of the array
    DestroyElementFunctionType destroyElemFct; // function pointer to the function responsible with deallocating the elements stored in the array
} DynamicArray;

/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="capacity">Integer, maximum capacity for the dynamic array.</param>
/// <param name="destroyElemFct">Function pointer, of type DestroyElementFunctionType. The function that deals with deallocating the elements of the array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
DynamicArray* createDynamicArray(int capacity, DestroyElementFunctionType destroyElemFct);

/// <summary>
/// Destroys the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array to be destoyed.</param>
/// <returns>A pointer the the created dynamic array.</returns>
void destroy(DynamicArray* arr);


void add(DynamicArray* arr, TElement t);

void delete(DynamicArray* arr, int pos);

int getLength(DynamicArray* arr);
TElement get(DynamicArray* arr, int pos);