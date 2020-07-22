#include "unity.h"

#include "init_stack.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_valid_array(void)
{
    t_stack	*s;
    int		t[3] = {1, 2, 3};
    int		i;

    s = init_stack(t, 3);
    i = 0;
    while (i < 3)
    {
        TEST_ASSERT_EQUAL_INT(t[i++], s->num);
        s = s->next;
    }
    TEST_ASSERT_NULL(s);
}

void test_invalid_array(void)
{
    int		t[3] = {1, -2, 3};

    TEST_ASSERT_NULL(init_stack(t, 3));
}

void test_ptr_null(void)
{
    TEST_ASSERT_NULL(init_stack(NULL, 3));
}

void test_zero_size(void)
{
    int		t[3] = {1, 2, 3};

    TEST_ASSERT_NULL(init_stack(t, 0));
}

void test_negative_size(void)
{
    int		t[3] = {1, 2, 3};

    TEST_ASSERT_NULL(init_stack(t, -1));
}
