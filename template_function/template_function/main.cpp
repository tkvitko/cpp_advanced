//
//  main.cpp
//  template_function
//
//  Created by tkvitko on 02.03.2024.
//

#include <iostream>
#include <vector>

template <typename INPUT>
INPUT sqrt(INPUT number) {
    return number * number;
}

template <>
std::vector<int> sqrt(std::vector<int> numbers) {
    std::vector<int> result;
    for (int i = 0; i < numbers.size(); ++i) {
        result.push_back(numbers[i] * numbers[i]);
    }
    return result;
}


int main(int argc, const char * argv[]) {
    std::cout << sqrt(4) << std::endl;
    
    std::vector<int> test_vector = {-1, 4, 8};
    std::vector<int> result_vector = sqrt(test_vector);
    for (auto elem : result_vector) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
    
    return 0;
}
