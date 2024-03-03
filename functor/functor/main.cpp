//
//  main.cpp
//  functor
//
//  Created by tkvitko on 02.03.2024.
//

#include <iostream>
#include <vector>

class analyser {
private:
    int divider;
    int sum;
    int count;
    
public:
    analyser(int divider_) : divider(divider_), sum(0), count(0) {}
    
    void operator()(int elem) {
        if (elem % divider == 0) {
            sum += elem;
            count++;
        }
    }
    
    int get_sum() { return this->sum; }
    int get_count() { return this->count; }
};

int main(int argc, const char * argv[]) {
    std::vector<int> test_vector = {4, 1, 3, 6, 25, 54};
    analyser gs = analyser(3);
    gs = std::for_each(test_vector.begin(), test_vector.end(), gs);
    std::cout << "[OUT]: get_sum() = " << gs.get_sum() << "\n";
    std::cout << "[OUT]: get_count() = " << gs.get_count() << "\n";
    return 0;
}
