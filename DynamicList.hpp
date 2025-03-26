#ifndef DYNAMICLIST_HPP
#define DYNAMICLIST_HPP
#include <cstddef>
#include <iostream>

template <typename T>
class DynamicList {
public:
    DynamicList();
    ~DynamicList();
    void setData(T data);
    void setSize(size_t size);
    T getData();
    size_t getSize();
    void push_back(T element);
    void remove(size_t index);
    void operator=(DynamicList& other);
    bool operator==(DynamicList& other);
    bool operator!=(DynamicList& other);
    T operator[](size_t index);

private:
    T* _data;
    size_t _size;
};
//  Default constructor method - Dynamically allocates memory
template <typename T>
DynamicList<T>::DynamicList() : _data(nullptr), _size(0){
}
//  Destructor method - Releases the dynamically allocated memory
template <typename T>
DynamicList<T>::~DynamicList(){
   delete[]_data;
}
// Setter method - Sets the value for the '*_data' attribute
template <typename T>
void DynamicList<T>::setData(T data){
   *_data = data;
}
// Setter method - Sets the value for the '_size' attribute
template <typename T>
void DynamicList<T>::setSize(size_t size){
   _size = size;
}
// Getter method - Returns the value of the '_data' attribute
template <typename T>
T DynamicList<T>::getData(){
   return *_data;
}
// Getter method - Returns the value of the '_size' attribute
template <typename T>
size_t DynamicList<T>::getSize(){
   return _size;
}
//  Method to add items to the end of the main array
template <typename T>
void DynamicList<T>::push_back(T element){
   T *tempArray = new T[_size + 1];
   for (size_t i = 0; i < _size; ++i) {
           tempArray[i] = _data[i];
       }
   tempArray[_size++] = element;
   delete[] _data;
   _data = tempArray;
}
template<typename T>
void DynamicList<T>::remove(size_t index){
   if (index >= _size){
      std::cout << "Error: Index exceeds capacity of array" << std::endl;
       return;
   }
   T *tempArray = new T[_size - 1];
   for (size_t i = 0; i < index; i++){
       tempArray[i] = _data[i];
   }
   for (size_t i = index + 1; i < _size; ++i) {
       tempArray[i - 1] = _data[i];
   }
   delete[] _data;
   _data = tempArray;
   --_size;
}
//  Operator overloading method - Overloads the '=' assignment operator
template <typename T>
void DynamicList<T>::operator=(DynamicList& other){
   if (this != &other){
       delete[] _data;
       _size = other._size;
       _data = new T[_size];
       for (size_t i = 0; i < _size; ++i){
           _data[i] = other._data[i];
       }
   }
   return *this;
}
//  Operator overloading method - Overloads the '==' equality operator
template <typename T>
bool DynamicList<T>::operator==(DynamicList& other){ 
     if (_size != other._size){
       return false;
   }
   for (size_t i = 0; i < _size; ++i) {
       if (_data[i] != other._data[i]) {
           return false;
       }
   }
   return true;
}


//  Operator overloading method - Overloads the '!=' inequality operator
template <typename T>
bool DynamicList<T>::operator!=(DynamicList& other){
   return !(*this != other);
}


//  Operator overloading method - Overloads the '[]' special operator
template <typename T>
T DynamicList<T>::operator[](size_t index){

   return _data[index];
}

#endif
