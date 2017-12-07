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

TEST(Arithm, t4)
{
	Arithmetic a("123+22");
	Term t(123.0, VALUE);
	Term t1('+', OPERATOR);
	Term t2(22.0, VALUE);

	Term* at = a.getTerms();
	int nt = a.getNTerms();

	EXPECT_EQ(t, at[0]);
	EXPECT_EQ(t1, at[1]);
	EXPECT_EQ(t2, at[2]);

	EXPECT_EQ(3, nt);
}
TEST(Arithm, t5)
{
	Arithmetic a("123/22+3");
	Term t(123.0, VALUE);
	Term t1('/', OPERATOR);
	Term t2(22.0, VALUE);
	Term t3('+', OPERATOR);
	Term t4(3.0, VALUE);

	Term* at = a.getTerms();
	int nt = a.getNTerms();

	EXPECT_EQ(t, at[0]);
	EXPECT_EQ(t1, at[1]);
	EXPECT_EQ(t2, at[2]);
	EXPECT_EQ(t3, at[3]);
	EXPECT_EQ(t4, at[4]);

	EXPECT_EQ(5, nt);
}
TEST(Arithm, check_symbols)
{
	Arithmetic a("%");
	//Term t(123.0, VALUE);

	EXPECT_EQ(false,a.check_symbols());
}

TEST(Arithm, check_opers)
{
	Arithmetic a("2++");
	//Term t(123.0, VALUE);

	EXPECT_EQ(false,a.check_opers());
}

TEST(Arithm, check_opers1)
{
	Arithmetic a("2+456*7");
	//Term t(123.0, VALUE);

	EXPECT_EQ(true,a.check_opers());
}

TEST(Arithm, check_opers2)
{
	Arithmetic a("()64++");
	//Term t(123.0, VALUE);

	EXPECT_EQ(false,a.check_opers());
}

TEST(Arithm, check_opers3)
{
	Arithmetic a("/*56+");
	//Term t(123.0, VALUE);

	EXPECT_EQ(false,a.check_opers());
}