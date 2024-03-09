//
//  main.cpp
//  template_func_to_print_any_container
//
//  Created by tkvitko on 09.03.2024.
//

#include <iostream>
#include <vector>
#include <set>
#include <list>


template <typename CONT>
void print_container(CONT& cont) {
    auto current = cont.begin();
    auto end = cont.end();
    for (; current != end; ++current) {
        std::cout << *current << " ";
    }
    std::cout << std::endl;
}


int main(int argc, const char * argv[]) {
    
    
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set); // four one three two - по алфавиту, т.к. set упорядочен

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list); // one, two, three, four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector); // one, two, three, four
    return 0;
}
