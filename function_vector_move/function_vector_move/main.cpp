//
//  main.cpp
//  function_vector_move
//
//  Created by tkvitko on 13.03.2024.
//

#include <iostream>
#include <vector>

template <typename VALUE>
void move_vectors(std::vector<VALUE>& src, std::vector<VALUE>& dst) {
    dst = std::move(src);
}

int main(int argc, const char * argv[]) {
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    
    // вывод содержимого до перемещения
    std::cout << "one before move:\n";
    for (auto el : one) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::cout << "two before move:\n";
    for (auto el : two) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    // перемещение
    move_vectors(one, two);
    
    // вывод содержимого после перемещения
    std::cout << "one after move:\n";
    for (auto el : one) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::cout << "two after move:\n";
    for (auto el : two) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
