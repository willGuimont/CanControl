#include <unity.h>

void test_trivial() {
    TEST_ASSERT_EQUAL(1, 1);
    TEST_ASSERT_EQUAL(2, 2);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_trivial);
    return UNITY_END();
}
