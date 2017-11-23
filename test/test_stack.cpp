// тесты для стека

#include "stack.h"
#include <gtest.h>

TEST(Stack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(Stack<int> v(5));
}
TEST(Stack, throws_when_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(Stack<int> v(-5));
}
TEST(Stack, can_create_copied_stack)
{
  Stack<int> v(10);

  ASSERT_NO_THROW(Stack<int> v1(v));
}
TEST(Stack, can_get_top)
{
  Stack<int> s1(25);
  s1.Push(1);
  s1.Push(2);
  
  EXPECT_EQ(1, s1.GetTop());
}

TEST(Stack, can_get_element_Pop)
{
  Stack<int> s1(10);
  s1.Push(1);
  s1.Push(2);
  s1.Push(3);
  s1.Push(30);

  EXPECT_EQ(30, s1.Pop());
}

TEST(Stack, can_not_delete_if_stack_is_empty)
{
	 Stack<int> s1(10);
	 s1.Push(1);
	 s1.Pop();
	 s1.isempty();
	  ASSERT_ANY_THROW(s1.Pop());
}
TEST(Stack, compare_equal_stack_return_true)
{
	Stack<int> v1(10);
	Stack<int> v2(v1);
	EXPECT_EQ(true, v1 == v2); 
}
TEST(Stack, copied_stack_is_equal_to_source_one) 
{
	Stack<int> st1(4);
	for(int i=0; i<4; i++)
		st1.Push(i);
	Stack<int> st2(st1);
	EXPECT_EQ(st1, st2);
} 
/*class Stacktest : public ::testing::Test {
protected:
	Stack s1;
	Stack s2;

public:
  Stack() : s1(25), s2(25) {
    s1.Push(1);
    s1.Push(2);
    s1.Push(3);

    s2.Push(1);
    s2.Push(3);
   s2.Push(5);
  }

  ~Stack() {}
};
TEST_F(Stack, copied_vector_is_equal_to_source_one)
{
 Stack<int> s2(s1);
  EXPECT_EQ(s1, s2);
}*/

TEST(Stack, can_compare_stacks_of_different_sizes_but_with_different_numbers)
{
	Stack<int> st1(2), st2(2);
	st1.Push(1);
	st1.Push(3);
	st2.Push(1);
	st2.Push(2);

	EXPECT_NE(true, st1 == st2);
}

TEST(Stack, can_return_the_number_of_elements)
{
	Stack<int> st(4);
	st.Push(1);
	st.Push(3);
	st.Push(1);
	st.Push(2);
	st.Clean();

	EXPECT_EQ(true, st.isempty());
}

TEST(Stack, can_equate_stacks_of_different_sizes)
{
	Stack<int> st(3), st1(2);
	st1.Push(1);
	st1.Push(2);
	st.Push(1);
	st.Push(2);
	st.Push(3);

	st = st1;

	EXPECT_EQ(st1, st);
}

TEST(Stack, can_equate_equal_stacks)
{
	Stack<int> st1(2);
	st1.Push(1);
	st1.Push(2);

	st1 = st1;
	EXPECT_EQ(st1, st1);
}
