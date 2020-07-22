#include "unity.h"

#include "init_stacks.h"

TEST_FILE("init_stack.c")

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
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_INT(1, s->a->num);
    TEST_ASSERT_EQUAL_INT(4, s->b->num);
}

void test_valid2(void)
{
    t_stacks	*s;
    int		t_a[3] = {1, 2, 3};

    s = init_stacks(t_a, 3, NULL, 0);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_EQUAL_INT(1, s->a->num);
    TEST_ASSERT_NULL(s->b);
}

void test_valid3(void)
{
    t_stacks	*s;

    s = init_stacks(NULL, 0, NULL, 0);
    TEST_ASSERT_NOT_NULL(s);
    TEST_ASSERT_NULL(s->a);
    TEST_ASSERT_NULL(s->b);
}
