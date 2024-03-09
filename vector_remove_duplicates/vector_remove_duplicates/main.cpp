//
//  main.cpp
//  vector_remove_duplicates
//
//  Created by tkvitko on 09.03.2024.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    
    std::vector<int> test_vector = {1, 1, 2, 5, 6, 1, 2, 4};
    // сортировка элементов
    std::sort(test_vector.begin(), test_vector.end());
    
    // удаление дубликатов
    auto end_of_uniqs = std::unique(test_vector.begin(), test_vector.end());
    test_vector.erase(end_of_uniqs, test_vector.end());
    
    // вывод результата
    for (auto el : test_vector) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
