#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "add_entry.h"
using namespace std;


template <class T>
class Vector {
public:

    Vector(unsigned int capacity = 100);

    // big three:
    Vector(const Vector& other);
    Vector& operator =(const Vector& other);
    ~Vector();


    //member access functions:
    const T operator [](unsigned int index) const;
    T& operator [](unsigned int index);
    T& at (int index);             //return reference to item at position index
    const T at(int index) const;  //return a const item at position index
    T& front() const;             //return item at position 0.
    T& back() const;              //return item at the last position


    //Push and Pop functions:
    Vector& operator +=(const T& item); //push_back
    void push_back(const T& item);      //append to the end
    T pop_back();                       //remove last item and return it


    //Insert and Erase:
    void insert(int insert_here, const T& insert_this); //insert at pos
    void erase(int erase_index);        //erase item at position
    int index_of(const T& item);        //search for item. return index.

    //size and capacity:
    //void set_size(int size);            //enlarge the vector to this size
    void set_capacity(int capacity);    //allocate this space
    int size() const {return _size;} //return _size
    int capacity() const {return _capacity;} //return _capacity

    bool empty() const;                 //return true if vector is empty

    //OUTPUT:
    template <class U>
    friend ostream& operator <<(ostream& outs, const Vector<U>& _a);
private:
    int _size;
    int _capacity;
    T* _v;

};

template <typename T>
T& Vector<T>::operator []( unsigned int index){
    return at(index);
}

template <typename T>
const T Vector<T>:: operator []( unsigned int index) const{
    return at(index);
}



template<typename T>
Vector<T>:: Vector (unsigned int capacity){
    //initialize the vector
    _size = 0;
    _capacity = capacity;
    _v = allocate <T>(_capacity);
}

template<typename T>
Vector<T>::Vector(const Vector& other){
    //1. copy all the variables:
    _size = other._size;
    _capacity = other._capacity;
    //2. allocate space
    _v = allocate <T>(other._capacity);

    //3. copy all elements from other to me.
    copy_list(other._v, _v, other._size);

}


template<typename T>
Vector<T>& Vector<T>::operator =(const Vector& other){
    //1. check for self reference
    if (this == &other){

        return *this; //return this object (me!)
    }
    //2. release existing dynamic space
    deallocate(_v);
    //3. copy all the variables:
    _size = other._size;
    _capacity = other._capacity;
    //4. allocate space
    _v = allocate <T> (other._capacity);
    //5. copy all elements from other to me.
    copy_list(other._v, _v, other._size);
    return *this;

}
template<typename T>
Vector<T>::~Vector (){
    //destructor to clean up anything goes out of scope
   deallocate(_v);
}

template<typename T>
Vector<T>& Vector<T>::operator +=(const T& item){
    _v[_size]=item;
    _size++;

    return *this;
}
template<typename U>
ostream& operator <<(ostream& outs, const Vector<U>& print_me){
    for (int i=0; i< print_me._size; i++){
        outs<<print_me._v[i] <<" ";
    }
    return outs;
}

template<typename T>
T& Vector<T>:: at(int index){

    if(!empty())
        return get_value(_v, index);//return variable at index

}

template<typename T>
const T Vector<T>:: at(int index) const{

    if(!empty())
        return get_value(_v, index);//return the const value at index

}

template<typename T>
T& Vector<T>:: front() const{
    if(!empty())
        return get_value (_v, 0);// the first number has index = 0
}

template<typename T>
T& Vector<T>:: back() const{
    if(!empty())
        return get_value (_v,_size - 1);// the last number has index size -1

}
template<typename T>
void Vector<T>::push_back(const T& item){
    _v = add_entry(_v, _size, _capacity, item);
}

template<typename T>
T Vector<T>::pop_back(){

    if(!empty()) {
        _size--;
        return _v[_size];// return the element we just delete after reducing size
    }

}

template<typename T>
void Vector<T>::insert(int insert_here, const T& insert_this){
   at(insert_here) = insert_this;
}

template<typename T>
void Vector<T>::erase(int erase_index){
    if(!empty())
        _v = remove (_v, _size, _capacity, at(erase_index));
}

template<typename T>
int Vector<T>::index_of(const T& item){
    T* found = find (_v, _size, item); // we already checked the case of empty array in the find function
    return (found - _v); //the difference of two pointer will give us the index at current position
}

//template<typename T>
//void Vector<T>::set_size(int size){

//    set_capacity(size + 1 );// setting a new capacity for the new size
//    init(_v + _size , _capacity, T());// initialize for the rest of spaces.
//    _size = size;


//}
template<typename T>
void Vector<T>::set_capacity(int capacity) {

    _v = reallocate(_v, capacity, _capacity);
    _capacity = capacity;

}

template<typename T>
bool Vector<T>::empty() const{
    //check if the array is empty
    if (_size == 0)
        return true;
    return false;
}

#endif // VECTOR_H
