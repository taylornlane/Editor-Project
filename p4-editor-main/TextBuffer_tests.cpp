#include "TextBuffer.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    TextBuffer buffer;
    buffer.insert('\n');
    buffer.insert('\n');
    buffer.insert('\n');
    ASSERT_EQUAL(buffer.get_column(), 0);
    ASSERT_EQUAL(buffer.get_row(), 4);
    ASSERT_EQUAL(buffer.stringify(), "\n\n\n");

    buffer.up();
    ASSERT_EQUAL(buffer.get_column(), 0);
    ASSERT_EQUAL(buffer.get_row(), 3);

    buffer.up();
    ASSERT_EQUAL(buffer.get_column(), 0);
    ASSERT_EQUAL(buffer.get_row(), 2);

    buffer.up();
    ASSERT_EQUAL(buffer.get_column(), 0);
    ASSERT_EQUAL(buffer.get_row(), 1);
}

TEST_MAIN()
