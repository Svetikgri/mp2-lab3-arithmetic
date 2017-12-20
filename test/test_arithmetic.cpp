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
  ASSERT_NO_THROW(Term t('+',OPERATOR));
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
	Arithmetic a("!45!");

	EXPECT_EQ(false,a.check_symbols());
}

TEST(Arithm, check_symbols3)
{
	Arithmetic a("3%");

	EXPECT_EQ(false,a.check_symbols());
}

TEST(Arithm, check_symbols5)
{
	Arithmetic a("83%2");

	EXPECT_EQ(false,a.check_symbols());
}

TEST(Arithm, check_symbols4)
{
	Arithmetic a("8.2");

	EXPECT_EQ(true,a.check_symbols());
}

TEST(Arithm, check_symbols1)
{
	Arithmetic a("12");

	EXPECT_EQ(true,a.check_symbols());
}

TEST(Arithm, check_symbols2)
{
	Arithmetic a("12+75/2");

	EXPECT_EQ(true,a.check_symbols());
}

TEST(Arithm, check_opers)
{
	Arithmetic a("2++");

	EXPECT_EQ(false, a.check_opers());
}

TEST(Arithm, check_opers1)
{
	Arithmetic a("2+456*7");

	EXPECT_EQ(true,a.check_opers());
}

TEST(Arithm, check_opers2)
{
	Arithmetic a("()64++");
	
	EXPECT_EQ(false,a.check_opers());
}

TEST(Arithm, check_opers3)
{
	Arithmetic a("/*56+");

	EXPECT_EQ(false,a.check_opers());
}

TEST(Arithm, check_brackets)
{
	Arithmetic a("((/*56+");

	EXPECT_EQ(false,a.check_brackets());
}
TEST(Arithm, check_brackets1)
{
	Arithmetic a("()()/*56+");

	EXPECT_EQ(true,a.check_brackets());
}
TEST(Arithm, check_brackets2)
{
	Arithmetic a(")((");

	EXPECT_EQ(false,a.check_brackets());
}
TEST(Arithm, check_brackets3)
{
	Arithmetic a("(()))/*56+");

	EXPECT_EQ(false,a.check_brackets());
}

TEST(Arithm, can_calculate_expressions0)
{
	Arithmetic b_test("(-3)+4");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(1, x);
}

TEST(Arithm, can_calculate_expressions01)
{
	Arithmetic b_test("((-3)+4)/5");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(0.2, x);
}


TEST(Arithm, can_calculate_expressions)
{
	Arithmetic b_test("1+1");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(2, x);
}

TEST(Arithm, can_calculate_expressions1)
{
	Arithmetic b_test("13+1");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(14, x);
}

TEST(Arithm, can_calculate_expressions3)
{
	Arithmetic b_test("1*3+1");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(4, x);
}

TEST(Arithm, can_calculate_expressions4)
{
	Arithmetic b_test("113+5");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(118, x);
}

TEST(Arithm, can_calculate_expressions2)
{
	Arithmetic b_test("13+1-2");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(12, x);
}
TEST(Arithm, can_calculate_expressions5)
{
	Arithmetic b_test("14/2");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(7, x);
}
TEST(Arithm, can_calculate_expressions6)
{
	Arithmetic b_test("(1+3)*4/2");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(8, x);
}

TEST(Arithm, can_calculate_expressions7)
{
	Arithmetic b_test("4/(1+3)*4/2");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(2, x);
}

TEST(Arithm, can_calculate_expressions8)
{
	Arithmetic b_test("(1*5)-(3.5 +6.5)/2");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(0, x);
}

TEST(Arithm, can_calculate_expressions9)
{
	Arithmetic b_test("((6/3)+(3.35 +6.54))/2");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ(5.945, x);
}

TEST(Arithm, can_calculate_expressions10)
{
	Arithmetic b_test("1-2");
	b_test.DivideToTerms();
	b_test.OPN();
	double x = b_test.Calculate();
	EXPECT_EQ((-1), x);
}





//struct check_test
//{
//	string str;
//	bool isCorrect;
//};
//
//struct calc_test
//{
//	string str;
//	double res;
//};
//
//
//class arithm_check : public ::testing::TestWithParam<check_test>
//{
//protected: Arithmetic a_test;
//public:
//	arithm_check(): a_test(GetParam().str)
//	{
//	}
//	~arithm_check() {}
//};
//
//class arithm_calc : public ::testing::TestWithParam<calc_test>
//{
//protected: Arithmetic b_test;
//public:
//	arithm_calc() : b_test(GetParam().str)
//	{
//	}
//	~arithm_calc() {}
//};
//
//
//TEST_P(arithm_check, can_check_for_correct)
//{
//	EXPECT_EQ(GetParam().isCorrect,a_test.IsCorrect());
//}
//
//TEST_P(arithm_calc, can_calculate_expressions)
//{
//	b_test.DivideToTerms();
//	b_test.OPN();
//	double x = b_test.Calculate();
//	EXPECT_EQ(GetParam().res, x);
//}

//INSTANTIATE_TEST_CASE_P(Inst2, arithm_calc,	::testing::Values(calc_test("1+1", 2.0)));


//INSTANTIATE_TEST_CASE_P(Inst1,
//	arithm_check,
//	::testing::Values(
//		check_test("22+3.77/4*(-a)", true),
//		check_test("5+(1-7*3.7)", true),
//		check_test("-7.674*(8+3)", true),
//		check_test("(1*4)-(3.65 +6.578)/37", true),
//		check_test("-+353", false),
//		check_test(")56+7(", false),
//		check_test("(15/2)-54)", false),
//		check_test("(15/)", false),
//		check_test("3.66.+71", false),
//		check_test("%65-7", false),
//		check_test("(1+6.5)(661)", false),
//		check_test("+5/(5+6)", false),
//		check_test("xyz", false),
//		check_test("+.-", false),
//		check_test("1+6(42-3)", false)
//	));


/*TEST(Arithmethic, can_parse_expression)
{
	Arithmetic expr("-2+67*(-3.1/1)");
	Term cmp[11];
	Term* src = expr.getTerms();
	cmp[0] = Term("-",OPERATOR);
	cmp[1] = Term("2", VALUE);
	cmp[2] = Term("+", OPERATOR);
	cmp[3] = Term("67", VALUE);
	cmp[4] = Term("*", OPERATOR);
	cmp[5] = Term("(", CLOSE_BRACKET);
	cmp[6] = Term("-", OPERATOR);
	cmp[7] = Term("3.1", VALUE);
	cmp[8] = Term("/", OPERATOR);
	cmp[9] = Term("1", VALUE);
	cmp[10] = Term(")", OPEN_BRACKET);
	bool res = true;
	for (int i = 0; i < expr.getNTerms(); i++)
		if (cmp[i] != src[i])
			res = false;

	EXPECT_EQ(true,res);
	ASSERT_NO_THROW(expr = Arithmetic(""));
	EXPECT_EQ(0,expr.getNTerms());
}*/


/*TEST(arithmetic,can_transform_to_rpn)
{
	Arithmetic expr("0 3 + 4.7 * 2 / (1 - 3)"); //0 3 - 4.7 2 * 1 x - / +
	Term src[11];
	expr.OPN_test();
	Term cmp[11];
	cmp[0] = Term("0", VALUE);
	cmp[1] = Term("3", VALUE);
	cmp[2] = Term("-", OPERATOR);
	cmp[3] = Term("4.7", VALUE);
	cmp[4] = Term("2", VALUE);
	cmp[5] = Term("*", OPERATOR);
	cmp[6] = Term("1", VALUE);
	cmp[7] = Term("3", VALUE);
	cmp[8] = Term("-", OPERATOR);
	cmp[9] = Term("/", OPERATOR);
	cmp[10] = Term("+", OPERATOR);
	bool res = true;
	for (int i = 0; i < 11; i++)
		if (cmp[i] != src[i])
		{
			cout << src[i].str << "   " << cmp[i].str << endl;
			res = false;
		}
	EXPECT_EQ(true,res);
}*/

//INSTANTIATE_TEST_CASE_P(Inst2, arithm_calc,	::testing::Values());

		