#include "unity.h"

#include "print_stack.h"

TEST_FILE("init_stack.c")

void setUp(void)
{
}

void tearDown(void)
{
}

void test_valid(void)
{
    t_stack	*s;
    int		t[3] = {1, 2, 3};

    s = init_stack(t, 3);
    TEST_ASSERT_EQUAL_INT(OK, print_stack(s));
}

void test_invalid(void)
{
    TEST_ASSERT_EQUAL_INT(KO, print_stack(NULL));
}
