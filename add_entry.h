#ifndef ADD_ENTRY_H
#define ADD_ENTRY_H

#include "oneD.h"





template <typename T>
T* add_entry (T* list, int& size, int& cap, const T& value);


template <typename T>
void shift_left (T* arr, T* position, int& size);

template <typename T>
T* remove (T* list, int& size, int& cap, const T& value);




//=====================================================


template <typename T>
T* add_entry (T* list, int& size, int& cap, const T& value){
    //The function is to add entries (value) to the array, the array will be  automatically reallocated within a double capacity
    // when the size reaches the capacity

    if (size == cap) {

        cap*= 2;

        list = reallocate(list, cap, size);// the array will be reallocated with a double capacity

    }
    // if there is space for adding entry, the value will be added to the first empty space
    *(list + size) = value;
    size++;
    return list;

}



template <typename T>
void shift_left (T* arr, T* position, int& size){
    // This function is used to delete value at a specific address

    T* walker = position;

    // The loop starts checking at the address of the value is found; then the shift left will start at that location
    for (; walker < arr + size; walker ++){
        *(walker) = *(walker + 1);
    }
    --size;
}

template <typename T>
T* remove (T* list, int& size, int& cap, const T& value){
    //The function is for removing entries (value) from the array, the array will be automatically reallocated
    // with a half of current capacity when the size is below 1/4 of capacity

    T* found = find (list, size, value);
    if (found == nullptr) return list;// return the current array if the value cannot be found in the array

    shift_left (list, found, size);

    if (size <= cap/4){
        cap /= 2;
        list = reallocate (list, cap, size);// the array will be reallocated within the new capacity (half of the current one)
    }
    return list;
}
#endif // ADD_ENTRY_H
