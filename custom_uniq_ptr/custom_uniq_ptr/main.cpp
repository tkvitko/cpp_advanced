//
//  main.cpp
//  custom_uniq_ptr
//
//  Created by tkvitko on 09.03.2024.
//

#include <iostream>

template <typename T>
class SharedPtr {
    
private:
    T* ptr;
    
public:
    
    // Конструктор, принимающий сырой указатель
    SharedPtr(T* raw_ptr) : ptr(raw_ptr) {}
    
    // перегруженный оператор * для получения объекта
    T operator*() { return *(this->ptr); };
    
    // запрет копирования
    SharedPtr(const SharedPtr&) = delete;
    
    // запрет присваивания
    SharedPtr& operator= (const SharedPtr&) = delete;
    
    // метод release, который освобождает владение и возвращает сырой указатель
    T* release() {
        T* temp_storage = this->ptr;
        this->ptr = nullptr;
        return temp_storage;
    }
    
    // метод получения данных для теста
    T get_data() {
        return *(this->ptr);
    }
    
    // деструктор
    ~SharedPtr() {
        delete this->ptr;
    }
};

int main(int argc, const char * argv[]) {
    
    int* my_raw_ptr = new int(5);
    SharedPtr<int> my_shared_ptr(my_raw_ptr);
    std::cout << my_shared_ptr.get_data() << std::endl; // 5
    return 0;
}
