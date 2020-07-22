#include "unity.h"

#include "swap_both.h"

TEST_FILE("swap.c")
TEST_FILE("init_stack.c")
TEST_FILE("init_stacks.c")

void setUp(void)
{
}

void tearDown(void)
{
}

void test_valid1(void)
{
    t_stacks	*s;
    int		t_a[3] = {1, 2, 3};
    int		t_b[2] = {4, 5};

    s = init_stacks(t_a, 3, t_b, 2);
    TEST_ASSERT_EQUAL_INT(OK, swap_both(s));
    TEST_ASSERT_EQUAL_INT(2, s->a->num);
    TEST_ASSERT_EQUAL_INT(5, s->b->num);
}

void test_invalid1(void)
{
    t_stacks	*s;
    int		t_a[1] = {1};

    s = init_stacks(t_a, 1, NULL, 0);
    TEST_ASSERT_EQUAL_INT(KO, swap_both(s));
    TEST_ASSERT_EQUAL_INT(1, s->a->num);
    TEST_ASSERT_NULL(s->b);
}
