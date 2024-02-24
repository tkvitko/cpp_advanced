//
//  main.cpp
//  raii_smart_array_copying
//
//  Created by tkvitko on 24.02.2024.
//

#include <iostream>

class NoSuchElement : public std::exception {
public:
    const char* what() const noexcept override {
        return "Нет элемента с таким номером";
    }
};

class AlreadyFull : public std::exception {
public:
    const char* what() const noexcept override {
        return "Массив уже заполнен";
    }
};

class SmartArray {
private:
    int size = 0;
    int* ptr = nullptr;
    int next_free_position = 0;
    
public:

    
    SmartArray(int size_) {
        this->size = size_;
        this->ptr = new int[size];
    }
    
    SmartArray(const SmartArray &obj) {
        // Copy Constructor
        delete[] this->ptr; // очистка памяти от старых данных первого объекта
        this->ptr = new int[obj.size];  // выделение новой памяти для новых данных первого объекта
        
        this->size = obj.size;
        this->next_free_position = obj.next_free_position;
        
        // перенос новых данных (из второго объекта) в первый объект
        for (int i = 0; i < obj.size; ++i) {
            this->ptr[i] = obj.ptr[i];
        }
    }
    
    ~SmartArray() {
        delete[] this->ptr;
    }
    
    void add_element(int elem) {
        if (this->next_free_position < this->size) {
            this->ptr[this->next_free_position] = elem;
            std::cout << "Added " << elem << " to position " << this->next_free_position << std::endl;
            this->next_free_position += 1;
        } else {
            throw AlreadyFull();
        }
    }
    
    int get_element(int idx) {
        if (idx < this->size) {
            return this->ptr[idx];
        } else {
            throw NoSuchElement();
        }
    }
};

int main(int argc, const char * argv[]) {
    
    SmartArray arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    SmartArray new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array;
    return 0;
}
