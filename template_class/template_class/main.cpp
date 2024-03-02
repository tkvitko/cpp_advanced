//
//  main.cpp
//  template_class
//
//  Created by tkvitko on 02.03.2024.
//

#include <iostream>

template <typename VALUE>
class Table {
private:
    int rows = 0;
    int cols = 0;
    VALUE **data;
    
public:
    Table(int rows_, int cols_) : rows(rows_), cols(cols_) {
        this->data = new VALUE *[this->rows];
        for (int i = 0; i < this->cols; ++i) {
            this->data[i] = new VALUE[rows]();
        }
    }
    
    VALUE* operator[](int index) {
        return this->data[index];
    }
    
    ~Table() {
        for (int i = 0; i < this->rows; ++i) {
          delete[] this->data[i];
        }
        delete[] this->data;
    }
};

int main(int argc, const char * argv[]) {
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0]; // выводит 4
    return 0;
}
