// тесты для вычисления арифметических выражений

#include <gtest.h>
#include "arithmetic.h"


TEST(Arithm, can_create_term)
{
  ASSERT_NO_THROW(Term t(5.0,VALUE));
}

TEST(Arithm, can_create_term1)
{
  ASSERT_NO_THROW(Term t(')',CLOSE_BRACKET));
}

TEST(Arithm, can_create_term2)
{
  ASSERT_NO_THROW(Term t("+"));
}

TEST(Arithm, t1)
{
	Arithmetic a("(");
	Term t(4.0, OPEN_BRACKET);
	Term* at = a.getTerms();
	int nt = a.getNTerms();

	EXPECT_EQ(t, at[0]);
	EXPECT_EQ(1, nt);
}

TEST(Arithm, t2)
{
	Arithmetic a(")");
	Term t(5.0, CLOSE_BRACKET);
	Term* at = a.getTerms();
	int nt = a.getNTerms();

	EXPECT_EQ(t, at[0]);
	EXPECT_EQ(1, nt);
}

TEST(Arithm, t3)
{
	Arithmetic a("123");
	Term t(123.0, VALUE);
	Term* at = a.getTerms();
	int nt = a.getNTerms();

	EXPECT_EQ(t, at[0]);
	EXPECT_EQ(1, nt);
}
