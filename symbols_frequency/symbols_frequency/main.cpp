//
//  main.cpp
//  symbols_frequency
//
//  Created by tkvitko on 03.03.2024.
//

#include <iostream>
#include <string>
#include <map>

int main(int argc, const char * argv[]) {
    
    std::string input = "Hello world!";
    
    // перегон символов в map и подсчет их количества
    std::map<char, int> data;
    for (auto& el : input) {
        if (data.find(el) == data.end()) {
            data[el] = 1;
        } else {
            data[el]++;
        }
    }
    
    // перегон map в новую, меняя местами ключи и значения, чтобы упорядочить по значениям
    std::multimap<int, char, std::greater<int>> sorted_data;
    for (auto& elem : data) {
        sorted_data.insert(std::pair(elem.second, elem.first));
    }
    
    // вывод результата
    std::cout << "[OUT]:" << std::endl;
    for (auto& el : sorted_data) {
        std::cout << el.second << ": " << el.first << std::endl;
    }
    
    return 0;
}
