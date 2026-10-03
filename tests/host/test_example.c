#include "unity.h"

void setUp(void) {
}
void tearDown(void) {
}

static int add(int a, int b) {
    return a + b;
}

void test_add_two_positive_numbers(void) {
    TEST_ASSERT_EQUAL_INT(5, add(2, 3));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_two_positive_numbers);
    return UNITY_END();
}