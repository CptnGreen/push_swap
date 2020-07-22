#include "unity.h"

#include "reverse_rotate_both.h"

TEST_FILE("init_stack.c")
TEST_FILE("init_stacks.c")
TEST_FILE("reverse_rotate.c")

void setUp(void)
{
}

void tearDown(void)
{
}

/*
** Rotation in both stacks:
*/

void test_valid1(void)
{
    t_stacks	*s;
    int		t_a[3] = {1, 2, 3};
    int		t_b[2] = {4, 5};

    s = init_stacks(t_a, 3, t_b, 2);
    TEST_ASSERT_EQUAL_INT(OK, reverse_rotate_both(s));
    TEST_ASSERT_EQUAL_INT(3, s->a->num);
    TEST_ASSERT_EQUAL_INT(5, s->b->num);
}

/*
** Second stack has just one element, so
** rotation happens only in the first stack:
*/

void test_valid2(void)
{
    t_stacks	*s;
    int		t_a[3] = {1, 2, 3};
    int		t_b[1] = {4};

    s = init_stacks(t_a, 3, t_b, 1);
    TEST_ASSERT_EQUAL_INT(OK, reverse_rotate_both(s));
    TEST_ASSERT_EQUAL_INT(3, s->a->num);
    TEST_ASSERT_EQUAL_INT(4, s->b->num);
}

/*
** Both stacks have just one element - no rotation:
*/

void test_invalid1(void)
{
    t_stacks	*s;
    int		t_a[1] = {1};
    int		t_b[1] = {2};

    s = init_stacks(t_a, 1, t_b, 1);
    TEST_ASSERT_EQUAL_INT(KO, reverse_rotate_both(s));
    TEST_ASSERT_EQUAL_INT(1, s->a->num);
    TEST_ASSERT_EQUAL_INT(2, s->b->num);
}

/*
** One stack is empty, another has just one element - no rotation:
*/

void test_invalid2(void)
{
    t_stacks	*s;
    int		t_a[1] = {1};

    s = init_stacks(t_a, 1, NULL, 0);
    TEST_ASSERT_EQUAL_INT(KO, reverse_rotate_both(s));
    TEST_ASSERT_EQUAL_INT(1, s->a->num);
    TEST_ASSERT_NULL(s->b);
}
