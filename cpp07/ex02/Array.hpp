#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
    T*           _data;
    unsigned int _size;

public:
    Array() : _data(new T[0]), _size(0) {}
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}
    Array(const Array &other) : _data(NULL), _size(0) {
        *this = other;
    }
    Array &operator=(const Array &other) {
        if (this != &other) {
            if (this->_data)
                delete[] this->_data;
            this->_size = other._size;
            this->_data = new T[this->_size];
            for (unsigned int i = 0; i < this->_size; i++) {
                this->_data[i] = other._data[i];
            }
        }
        return *this;
    }
    ~Array() {
        delete[] _data;
    }
    T &operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return _data[index];
    }
    unsigned int size() const { return _size; }
};


#endif