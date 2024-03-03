//
//  main.cpp
//  no_duplicates_and_sorting
//
//  Created by tkvitko on 03.03.2024.
//

#include <iostream>
#include <set>

int main(int argc, const char * argv[]) {
    
    // сбор данных
    std::cout << "[IN]:" << std::endl;
    int count = 0;
    std::cin >> count;
    
    // ordere set для того, чтобы сраз хранить упорядоченно уникальные значения
    std::set<int, std::greater<int>> data;
    for (int i = 0; i < count; ++i) {
        int el = 0;
        std::cin >> el;
        data.insert(el);
    }
    
    std::cout << "[OUT]:" << std::endl;
    for (auto& el : data) {
        std::cout << el << std::endl;
    }
    
    return 0;
}
