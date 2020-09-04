#ifndef ONED_H
#define ONED_H

#include <iostream>
using namespace std;

template <typename T>
T* allocate (int cap);

template <typename T>
void copy_list(T* old_array, T* new_array, int size);

template <typename T>
T* reallocate (T* arr1, int new_cap, int old_cap);

template <typename T>
void init (T* arr, int size, T value);

template <typename T>
T* find (T* arr, int size, const T& value);

template <typename T>
void print1  (T* arr, int size);

template <typename T>
T& get_value (T* arr, int index);

template <typename T>
void deallocate (T*arr);



template <typename T>
T* allocate (int cap){
//    const bool DEBUG = true;
    // a debug boolean is to print of a  message that the space is being allocated whenever the capacity is increased or decreased
    //if (DEBUG)  cout<<"************allocate(): capacity: "<<cap<<endl;
    return new T [cap];
}

template <typename T>
void copy_list(T* old_arr, T* new_arr, int size){
    //this function is for copying all the elements from the onw array to another

    for (int i =0; i < size; i++){

        *new_arr = *old_arr;
        old_arr++;
        new_arr++;
    }
}

template <typename T>
T* reallocate (T* arr1, int new_cap, int old_cap){
    //This function is to allocate a new array with a new capacity containing elements from the old one

    T* arr2 = allocate <T> (new_cap);
    copy_list (arr1, arr2, old_cap);

    delete [] arr1;
    return arr2;
}

template <typename T>
void init (T* arr, int size, T value){
    //initialize 1d array
    T* walker = arr;
    for (int i = 0; i < size; i++){
        *walker = value;
        walker ++;
    }
}

template <typename T>
T* find (T* arr, int size, const T& value) {
    //The function is looking for the address of a specific value and return the pointer

    T* walker = arr;
    if (size == 0) return nullptr;// this is for the empty array

    for (int i = 0; i < size; i++, walker++){
        if (*walker == value)
            return walker; // return the address if the value is found
    }
    return nullptr;// if the value cannot be found
}
template <typename T>
void print1  (T* arr, int size){

    T* walker = arr;

    // The loop is used to print all the elements in the array
    for ( int i =0; i < size; i++){

        cout << *walker << " ";
        walker++;
    }

}
template <typename T>
T& get_value (T* arr, int index){
    //getting value at given index

    T* walker = arr + index;
    return *walker;
}

template <typename T>
void deallocate (T*arr){
    //deleting the dynamic space
    delete [] arr;
}

#endif // ONED_H
