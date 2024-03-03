//
//  main.cpp
//  template_class
//
//  Created by tkvitko on 02.03.2024.
//

#include <iostream>


class BadIndex : public std::exception {
public:
    const char* what() const noexcept override {
        return "Неверный индекс";
    }
};


template <typename VALUE>
class Table {
private:
    int rows = 0;
    int cols = 0;
    VALUE **data;
    
public:
    Table(int rows_, int cols_) : rows(rows_), cols(cols_) {
        // создание двумерного массива в динамической памяти
        this->data = new VALUE *[this->rows];
        for (int i = 0; i < this->cols; ++i) {
            this->data[i] = new VALUE[rows]();
        }
    }
    
    // неконстантная версия операторв [] для изменения значений таблицы
    VALUE* operator[](int index) {
        if (index >= 0 && index < this->rows) {
            return this->data[index];
        } else {
            throw BadIndex();
        }
    }
    
    // константная версия операторв [] для получения значений таблицы
    const VALUE* operator[](int index) const {
        if (index >= 0 && index < this->rows) {
            return this->data[index];
        } else {
            throw BadIndex();
        }
    }
    
    // запрет копирования
    Table(const Table&) = delete;
    // запрет присваивания
    Table& operator= (const Table&) = delete;
    
    ~Table() {
        // удаление двумерного массива в динамической памяти
        for (int i = 0; i < this->rows; ++i) {
          delete[] this->data[i];
        }
        delete[] this->data;
    }
};

int main(int argc, const char * argv[]) {
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl; // выводит 4
    return 0;
}
