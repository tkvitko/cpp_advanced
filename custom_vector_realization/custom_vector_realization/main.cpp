//
//  main.cpp
//  custom_vector_realization
//
//  Created by tkvitko on 03.03.2024.
//

#include <iostream>

class BadIndex : public std::exception {
public:
    const char* what() const noexcept override {
        return "Неверный индекс";
    }
};

template <typename ELEM_TYPE>
class Vector {

private:
    ELEM_TYPE* ptr = nullptr;
    int _capacity = 0;
    int _size = 0;
  
public:
    Vector(int capacity_) : _capacity(capacity_), _size(0) {
        this->ptr = new ELEM_TYPE[capacity_];
    }
    
    ELEM_TYPE at(int index) {
        // получение значения по индексу
        if (index < _size) {
            return this->ptr[index];
        } else {
            throw BadIndex();
        }
    }
    
    void push_back(ELEM_TYPE value) {
        // добавление нового элемента
        if (this->_size == this->_capacity) {
            // если места уже нет, переносим данные в новую память объемом в 2 раза  больше
            _capacity *= 2;
            ELEM_TYPE* new_ptr = new ELEM_TYPE[_capacity];
            for (int i = 0; i < this->_size; ++i) {
                new_ptr[i] = this->ptr[i];
            }
            delete[] this->ptr;
            this->ptr = new_ptr;
        }
        // добавляем новый элемент
        this->ptr[_size] = value;
        this->_size++;
    }
    
    int size() { return this->_size; }
    int capacity() { return this->_capacity; }
    
    ~Vector() { delete[] this->ptr; }
    
};

int main(int argc, const char * argv[]) {
    
    // тестирование
    Vector my_vector = Vector<bool>(2);
    std::cout << "size is "<< my_vector.size() << std::endl;
    std::cout << "capacity is "<< my_vector.capacity() << std::endl;
    my_vector.push_back(1);
    std::cout << "size is "<< my_vector.size() << std::endl;
    std::cout << "capacity is "<< my_vector.capacity() << std::endl;
    my_vector.push_back(0);
    std::cout << "size is "<< my_vector.size() << std::endl;
    std::cout << "capacity is "<< my_vector.capacity() << std::endl;
    my_vector.push_back(1);
    std::cout << "size is "<< my_vector.size() << std::endl;
    std::cout << "capacity is "<< my_vector.capacity() << std::endl;
    my_vector.push_back(0);
    std::cout << "size is "<< my_vector.size() << std::endl;
    std::cout << "capacity is "<< my_vector.capacity() << std::endl;
    
    return 0;
}
