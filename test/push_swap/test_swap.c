#include "unity.h"

#include "swap.h"

TEST_FILE("init_stack.c")

void setUp(void)
{
}

void tearDown(void)
{
}

void test_valid1(void)
{
    t_stack	*s;
    int		t[3] = {1, 2, 3};

    s = init_stack(t, 3);
    TEST_ASSERT_EQUAL_INT(OK, swap(s));
    TEST_ASSERT_EQUAL_INT(2, s->num);
    TEST_ASSERT_EQUAL_INT(1, s->next->num);
}

void test_invalid1(void)
{
    t_stack	*s;
    int		t[1] = {1};

    s = init_stack(t, 1);
    TEST_ASSERT_EQUAL_INT(KO, swap(s));
}

void test_invalid2(void)
{
    t_stack	*s;

    s = NULL;
    TEST_ASSERT_EQUAL_INT(KO, swap(s));
}
