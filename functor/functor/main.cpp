//
//  main.cpp
//  functor
//
//  Created by tkvitko on 02.03.2024.
//

#include <iostream>
#include <vector>

class get_sum {
private:
    std::vector<int> source;
    int sum;
    
public:
    get_sum(std::vector<int> source_) : source(source_), sum(0) {}
    
    int operator()() {
        for (auto elem : source) {
            if (elem % 3 == 0) {
                sum += elem;
            }
        }
        return this->sum;
    }
};

class get_count {
private:
    std::vector<int> source;
    int count;
    
public:
    get_count(std::vector<int> source_) : source(source_), count(0) {}
    
    int operator()() {
        for (auto elem : source) {
            if (elem % 3 == 0) {
                count++;
            }
        }
        return this->count;
    }
};

int main(int argc, const char * argv[]) {
    std::vector<int> test_vector = {4, 1, 3, 6, 25, 54};
    get_sum gs(test_vector);
    int res = gs();
    std::cout << res << std::endl;
    
    get_count gc(test_vector);
    int res2 = gc();
    std::cout << res2 << std::endl;
    return 0;
}
