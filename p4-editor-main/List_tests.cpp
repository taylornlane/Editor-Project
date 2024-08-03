#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

//LIST TESTS

TEST(test_empty) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_size) {
    List<int> list1;
    List<int> list2;

    for (int i = 1; i <= 5; i++){
        list1.push_front(i);
    }
    ASSERT_TRUE(list1.size() == 5);
    ASSERT_TRUE(list2.size() == 0);
}

TEST(test_push_front_pop_back) {
    List<int> list1;
    for (int i = 1; i <= 5; i++){
        list1.push_front(i);
    }

    ASSERT_FALSE(list1.empty());

    for (int i = 1; i <= 5; i++){
        ASSERT_TRUE(list1.back() == i);
        list1.pop_back();
    }

    ASSERT_TRUE(list1.empty());
}

TEST(test_push_back_pop_front) {
    List<int> list1;
    for (int i = 1; i <= 5; i++){
        list1.push_back(i);
    }

    for (int i = 1; i <= 5; i++){
        ASSERT_TRUE(list1.front() == i);
        list1.pop_front();
    }
}

TEST(test_clear){
    List<int> list1;
    for (int i = 1; i <= 5; i++){
        list1.push_back(i);
    }
    list1.clear();

    ASSERT_TRUE(list1.empty());    
}

TEST(test_list_default_ctor) {
    List<int> empty_list;
    ASSERT_TRUE(empty_list.empty());
}

TEST(test_copy_ctor) {
    List<int> list1;
    List<int> list2(list1);

    for (int i = 1; i <= 5; i++){
        list1.push_back(i);
    }

    List<int>::Iterator it1 = list1.begin();
    for (List<int>::Iterator it2 = list2.begin(); it2 != list2.end(); ++it2, ++it1) {
        ASSERT_EQUAL(*it2, *it1);

        // Testing deep copy <3
        ASSERT_FALSE(it2 == it1);
    }
}

TEST(test_overloaded_assignment_op){
    List<int> list1;
    List<int> list2;
    list1 = list2;

    for (int i = 1; i <= 5; i++){
        list1.push_back(i);
    }

    List<int>::Iterator it1 = list1.begin();
    for (List<int>::Iterator it2 = list2.begin(); it2 != list2.end(); ++it2, ++it1) {
        ASSERT_EQUAL(*it2, *it1);

        // Testing deep copy <3
        ASSERT_FALSE(it2 == it1);
    }
    List<int> list3;
    list3 = list1;
    List<int>::Iterator it4 = list1.begin();
    for (List<int>::Iterator it3 = list3.begin(); it3 != list3.end(); ++it3, ++it4) {
        ASSERT_EQUAL(*it3, *it4);

        // Testing deep copy <3
        ASSERT_FALSE(it3 == it4);
    }


    list1.clear();
    //ASSERT_FALSE(list2.empty());
}

// ITERATOR TESTS


TEST(test_iterator_insert) {
    List<int> list1;
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
    }
    list1.insert(list1.begin(), 9);
    ASSERT_EQUAL(list1.front(), 9);

    List<int>::Iterator it2 = list1.end();
    --it2;
    it2 = list1.insert(it2, 9);
    ASSERT_EQUAL(list1.back(), 4);

    --it2;
    --it2;
    List<int>::Iterator it3 = list1.insert(it2, 8);

    ASSERT_EQUAL(*it3, 8);
    List<int>::Iterator it4 = list1.end();
    list1.insert(it4, 9);
    ASSERT_EQUAL(list1.back(), 9);
}

TEST(test_iterator_erase) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }

    list.insert(list.begin(), 9);
    List<int>::Iterator it = list.begin();

    list.erase(it);

    ASSERT_EQUAL(list.front(), 0);
    
    List<int>::Iterator it2 = list.end();
    --it2;
    
    list.erase(it2);
    ASSERT_TRUE(3 == list.back());
    List<int>::Iterator it3 = list.end();
    --it3;
    --it3;
    List<int>::Iterator it4 = list.erase(it3);
    ASSERT_EQUAL(*it4, 3);
}


TEST(test_begin_end) {
    List<int> list;
        for (int i = 0; i < 5; ++i) {
            list.push_back(i);
        }
    List<int>::Iterator it = list.begin();
    ASSERT_TRUE(*it == list.front());

    List<int>::Iterator it2 = list.end();
    --it2;
    ASSERT_TRUE(*it2 == list.back());
}

TEST(test_iterator_default) {
    /*List<int> empty_list;
   // List<int>::Iterator it2 = ;
    List<int>::Iterator it = empty_list.end();
    //ASSERT_TRUE(it2 == it);
    ASSERT_NOT_EQUAL(it, nullptr);
    */
    
    List<int>::Iterator it2;
    List<int>::Iterator it3;
    ASSERT_TRUE(it2 == it3);
    
} 

TEST(test_iterator_equals_operators) {
    List<int> list;
        for (int i = 0; i < 5; ++i) {
            list.push_back(i);
        }
    List<int>::Iterator it = list.begin();
    List<int>::Iterator it2 = it;
    ASSERT_TRUE(it == it2);
    ASSERT_FALSE(it != it2);

    List<int> list2;
        for (int i = 0; i < 7; ++i) {
            list.push_back(i);
        }
    List<int>::Iterator it3 = list2.begin();
    ASSERT_TRUE(it != it3);
    ASSERT_FALSE(it == it3);
}

TEST(test_iterator_assignment_operator) {
    List<int> list;
        for (int i = 0; i < 5; ++i) {
            list.push_back(i);
        }
    List<int>::Iterator it = list.begin();
    List<int>::Iterator it2 = it;
    ASSERT_EQUAL(it2, it);

    List<int>::Iterator it3;
    it2 = it3;
    ASSERT_EQUAL(it2, it3);

    List<int>::Iterator it4 = list.end();
    --it4;
    it = it4;
    ASSERT_EQUAL(it, it4);


}

TEST(test_iterator_copy) {
    List<int>::Iterator it2;
    List<int>::Iterator it3(it2);
    ASSERT_EQUAL(it2, it3);


    List<int> list;
        for (int i = 0; i < 5; ++i) {
            list.push_back(i);
        }
    List<int>::Iterator it5 = list.begin();
    List<int>::Iterator it4(it5);
    ASSERT_EQUAL(it5, it4);

}
TEST(test_traversal) {
    List<int> list;
    for (int i = 0; i < 5; ++i) {
        list.push_back(i);
    }
    
    int j = 0;
    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it, ++j) {
        ASSERT_EQUAL(*it, j);
    }
    ASSERT_EQUAL(j, list.size());
}
TEST(test_iterator_operators) {
    List<int> list;
        for (int i = 0; i < 5; ++i) {
            list.push_back(i);
        }
    List<int>::Iterator it = list.begin();
    ++it;
    ASSERT_EQUAL(*it, 1);

    --it;
    ASSERT_EQUAL(*it,0);

    List<int>::Iterator it2(it);
    ASSERT_TRUE(*it2 == 0);

}


TEST_MAIN()