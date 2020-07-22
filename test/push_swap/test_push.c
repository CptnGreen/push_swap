#include "unity.h"

#include "push.h"

TEST_FILE("init_stack.c")

void setUp(void)
{
}

void tearDown(void)
{
}

void test_notnull_to_notnull1(void)
{
    t_stack	*a;
    t_stack	*b;
    int		t_a[3] = {1, 2, 3};
    int		t_b[2] = {4, 5};

    a = init_stack(t_a, 3);
    b = init_stack(t_b, 2);
    TEST_ASSERT_EQUAL_INT(OK, push(&a, &b));
    TEST_ASSERT_EQUAL_INT(4, a->num);
    TEST_ASSERT_EQUAL_INT(5, b->num);
}

void test_notnull_to_notnull2(void)
{
    t_stack	*a;
    t_stack	*b;
    int		t_a[3] = {1, 2, 3};
    int		t_b[1] = {4};

    a = init_stack(t_a, 3);
    b = init_stack(t_b, 1);
    TEST_ASSERT_EQUAL_INT(OK, push(&a, &b));
    TEST_ASSERT_EQUAL_INT(4, a->num);
    TEST_ASSERT_NULL(b);
}

void test_notnull_to_null(void)
{
    t_stack	*a;
    t_stack	*b;
    int		t_a[3] = {1, 2, 3};

    a = init_stack(t_a, 3);
    b = NULL;
    TEST_ASSERT_EQUAL_INT(OK, push(&b, &a));
    TEST_ASSERT_EQUAL_INT(1, b->num);
    TEST_ASSERT_EQUAL_INT(2, a->num);
}


void test_null_to_null(void)
{
    t_stack	*a;
    t_stack	*b;

    a = NULL;
    b = NULL;
    TEST_ASSERT_EQUAL_INT(KO, push(&a, &b));
    TEST_ASSERT_NULL(a);
    TEST_ASSERT_NULL(b);
}

void test_null_to_notnull(void)
{
    t_stack	*a;
    t_stack	*b;
    int		t_a[3] = {1, 2, 3};

    a = init_stack(t_a, 3);
    b = NULL;
    TEST_ASSERT_EQUAL_INT(KO, push(&a, &b));
    TEST_ASSERT_EQUAL_INT(1, a->num);
    TEST_ASSERT_NULL(b);
}
