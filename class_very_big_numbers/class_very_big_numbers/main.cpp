//
//  main.cpp
//  class_very_big_numbers
//
//  Created by tkvitko on 13.03.2024.
//

#include <iostream>
#include <vector>
#include <string>

class BigInteger {
private:
    unsigned long size;
    std::vector<int> number;

public:
    // конструктор для создания числа, если число передано строкой
    BigInteger(std::string str) {
        this->size = str.length();
        for (auto digit : str) {
            this->number.push_back(digit - 48);
        }
    };
    
    // конструктор для создания пустого числа, если передана его длина
    BigInteger(unsigned long length) {
        this->size = length;
        for (int i = 0; i < length; ++i) {
            this->number.push_back(0);
        }
    };
    
    // неконстантная версия операторв [] для изменения значений
    int& operator[](int index) {
        return this->number[index];
    }
    
    // константная версия операторв [] для получения значений
    const int& operator[](int index) const {
        return this->number[index];
    }
    
    // конструктор перемещения
    BigInteger(BigInteger&& other) {
        this->number = other.number;
        //other.number = nullptr; // no viable overloaded '='
        this->size = other.size;
    }
    
    // перемещающий оператор присваивания
    BigInteger& operator=(BigInteger&& other) {
        if (this == &other) {
            return *this;
        };
        this->number = other.number;
        //other.number = nullptr; // no viable overloaded '='
        this->size = other.size;
        return *this;
    }
    
    BigInteger operator+(BigInteger& other) {
        
        // выравнивание длин чисел
        if (this->size < other.size) {
            unsigned long difference = other.size - this->size;
            for (int i = 0; i < difference; ++i) {
                this->number.insert(this->number.begin(), 0);
                this->size += difference;
            }
        } else if (this->size > other.size) {
            unsigned long difference = this->size - other.size;
            for (int i = 0; i < difference ; ++i) {
                other.number.insert(other.number.begin(), 0);
                other.size += difference;
            }
        }
        
        // число для сохранения суммы
        BigInteger result(other.size);
        
        // идем от последней цифры к первой, не доходя до первой
        for (int i = other.size - 1; i > 0 ; --i) {
            result[i] += this->number[i] + other.number[i];
            if (result[i] > 9) {
                result[i] -= 10;
                result[i - 1] = 1;
            }
        };
        
        // отдельно складываем цифру, и если перешли порядок, увеличиваем его
        result[0] += this->number[0] + other.number[0];
        if (result[0] > 9) {
            result[0] -= 10;
            result.number.insert(result.number.begin(), 1);
        }
        return result;
    };
    
    BigInteger operator*(int other) {
        
        // число для сохранения произведения
        BigInteger result(this->size);
        
        // идем от последней цифры к первой, не доходя до первой
        for (int i = this->size - 1; i > 0 ; --i) {
            int tmp = result[i];    // временное сохранение текущего значения (с предыдущего шага) текушей ячейки
            result[i] = this->number[i] * other;
            if (result[i] > 9) {
                int second_digit = result[i] % 10;
                int first_digit = result[i] / 10;
                result[i] = second_digit;
                result[i] += tmp;   // добавление сохраненного с предыдущего шага значения
                result[i - 1] += first_digit;   // запись превышения в предыдущую ячейку
            }
        };
        
        // отдельно складываем цифру, и если перешли порядок, увеличиваем его
        result[0] += this->number[0] * other;
        if (result[0] > 9) {
            int second_digit = result[0] % 10;
            int first_digit = result[0] / 10;
            result[0] = second_digit;
            result.number.insert(result.number.begin(), first_digit);
        }
        return result;
    };
    
    friend std::ostream& operator<<(std::ostream& stream, BigInteger& number);
};

std::ostream& operator<<(std::ostream& stream, BigInteger& number) {
    
    std::string result;
    for (auto el : number.number) {
        result.push_back(el + 48);
    };
    return stream << result << std::endl;
};

int main(int argc, const char * argv[]) {
    auto number1 = BigInteger("188");
//    std::cout << number1;
    auto number2 = BigInteger("78524");
//    std::cout << number2;
//    auto result = number1 + number2;
    auto result = number1 * 5;
//    std::cout << result; // 193099
    std::cout << result;
    return 0;
}
