#include "unity.h"

#include "reverse_rotate.h"

TEST_FILE("init_stack.c")
TEST_FILE("reverse_rotate.c")

void setUp(void)
{
}

void tearDown(void)
{
}

void test_valid1(void)
{
    t_stack	*s;
    int		t_a[3] = {1, 2, 3};

    s = init_stack(t_a, 3);
    TEST_ASSERT_EQUAL_INT(OK, reverse_rotate(&s));
    TEST_ASSERT_EQUAL_INT(3, s->num);
    s = s->next;
    TEST_ASSERT_EQUAL_INT(1, s->num);
    s = s->next;
    TEST_ASSERT_EQUAL_INT(2, s->num);
    TEST_ASSERT_NULL(s->next);
}

void test_valid2(void)
{
    t_stack	*s;
    int		t_a[2] = {4, 5};

    s = init_stack(t_a, 2);
    TEST_ASSERT_EQUAL_INT(OK, reverse_rotate(&s));
    TEST_ASSERT_EQUAL_INT(5, s->num);
    s = s->next;
    TEST_ASSERT_EQUAL_INT(4, s->num);
    TEST_ASSERT_NULL(s->next);
}

/*
** Stack contains single element - no rotation:
*/

void test_invalid1(void)
{
    t_stack	*s;
    int		t_a[1] = {1};

    s = init_stack(t_a, 1);
    TEST_ASSERT_EQUAL_INT(KO, reverse_rotate(&s));
    TEST_ASSERT_EQUAL_INT(1, s->num);
}

/*
** Stack is empty - no rotation:
*/

void test_invalid2(void)
{
    t_stack	*s;

    s = init_stack(NULL, 0);
    TEST_ASSERT_EQUAL_INT(KO, reverse_rotate(&s));
    TEST_ASSERT_NULL(s);
}
