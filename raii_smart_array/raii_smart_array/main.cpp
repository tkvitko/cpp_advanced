//
//  main.cpp
//  raii_smart_array
//
//  Created by tkvitko on 24.02.2024.
//

// Реализация умного массива, очищающего занятую собой память в деструкторе


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
    
    try {
        SmartArray arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
