//
//  test-main.cpp
//  testing_catch2_linked_list_01
//
//  Created by tkvitko on 24.02.2024.
//

#include <iostream>
#include "List.cpp"
#include "Catch2/src/catch2/catch_test_macros.hpp"
#include "Catch2/src/catch2/catch_session.hpp"


TEST_CASE("test List", "[List]") {
    
    List test_list = List();
    
    SECTION("Empty list") {
        CHECK(test_list.Empty() == 1);
        CHECK(test_list.Size() == 0);
    }
    
    SECTION("Filling list") {
        test_list.PushFront(1);
        CHECK(test_list.Empty() == 0);
        CHECK(test_list.Size() == 1);
    }
    
    SECTION("Clearing list") {
        test_list.Clear();
        CHECK(test_list.Empty() == 1);
        CHECK(test_list.Size() == 0);
    }
    
    SECTION("Push and Pop functions of list") {
        CHECK_THROWS_AS(test_list.PopBack(), std::runtime_error);
        CHECK_THROWS_AS(test_list.PopFront(), std::runtime_error);
        
        test_list.PushBack(2);
        CHECK(test_list.PopBack() == 2);
        test_list.PushFront(3);
        CHECK(test_list.PopFront() == 3);
    }
}

int main() {
    return Catch::Session().run();
}
