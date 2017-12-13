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
TEST(Arithm, check_brackets)
{
	Arithmetic a("((/*56+");

	EXPECT_EQ(false,a.check_brackets());
}

class ParameterizedString : public ::testing::TestWithParam<string>
{
protected:
	string bf1;

public:
	ParameterizedString() : bf1(GetParam())
	{		
	}

	~ParameterizedString() {}
};


/*TEST_P(ParameterizedString, can_determinate_eror)
{
	EXPECT_EQ(0, ChekString(bf1));
}*/

string test_values[] = { "2--", "2++","1+3*()", "(4.4-3)*((6-5)", "(1-arr*)", "(/2+1)" , "()"," (1-3*423.1 )-1+3.4-12 .12.3", "(1-arr/)", "(2+3)(1-3)" };

INSTANTIATE_TEST_CASE_P(Instantiation2,
	ParameterizedString,
	::testing::ValuesIn(test_values));

class ParameterizedString2 : public ParameterizedString
{};

/*TEST_P(ParameterizedString2, can_determinate_true)
{
	EXPECT_EQ(1, ChekString(bf1));
}*/

string test_values2[] = { "-2-1", "8-(-4+7)" };

INSTANTIATE_TEST_CASE_P(Instantiation3,
	ParameterizedString2,
	::testing::ValuesIn(test_values2));

struct T
{
	string s;
	bool isCorrect;
	double val;

	T(string mys = "", bool f = true, double v = 0.0)
	{
		s = mys;
		isCorrect = f;
		val = v;
	}
};

class ParameterizedString3 : public ::testing::TestWithParam<T>
{
protected:
	T testcase;
public:
	ParameterizedString3() : testcase(GetParam())
	{}

	~ParameterizedString3() {}
};


TEST_P(ParameterizedString3, can_calc)
{
	Arithmetic a(GetParam().s);
	a.DivideToTerms();
	//a.OPN();
	//if(ChekString(GetParam().s))
	EXPECT_EQ(GetParam().val, a.Calculate());
	//else EXPECT_EQ(GetParam().IsCorrect, ChekString(GetParam().s));
}

T myarray[] = {T("3-2", true, 1), T("2*3", true, 6), T("-2*3.12+4-1", true , -3.24), T("(-34+4)", true ,-30 ), T("-1+3--23.2", false , 0) };

INSTANTIATE_TEST_CASE_P(Instantiation4,
	ParameterizedString3,
::testing::ValuesIn(myarray));



/*class arithm_check : public ::testing::TestWithParam<check_test>
{
protected: Arithmetic a_test;
public:
	arithm_check(): a_test(GetParam().str)
	{
	}
	~arithm_check() {}
};

class arithm_calc : public ::testing::TestWithParam<calc_test>
{
protected: Arithmetic b_test;
		   istringstream input;
public:
	arithm_calc() : b_test(GetParam().str), input(GetParam().vars)
	{
	}
	~arithm_calc() {}
};


TEST_P(arithm_check, can_check_for_correct)
{
	EXPECT_EQ(GetParam().res,a_test.IsCorrect());
}

TEST_P(arithm_calc, can_calculate_expressions)
{
	EXPECT_GE(EPS, abs(GetParam().res - b_test.Calc(input)));
}
INSTANTIATE_TEST_CASE_P(Inst1,
	arithm_check,
	::testing::Values(
		check_test("22+3.77/4*(-a)", true),
		check_test("5+(1-7*3.7)", true),
		check_test("-7.674*(8+3)", true),
		check_test("(1*4)-(3.65 +6.578)/37", true),
		check_test("-+353", false),
		check_test(")56+7(", false),
		check_test("(15/2)-54)", false),
		check_test("(15/)", false),
		check_test("3.66.+71", false),
		check_test("%65-7", false),
		check_test("(1+6.5)(661)", false),
		check_test("+5/(5+6)", false),
		check_test("xyz", false),
		check_test("+.-", false),
		check_test("1+6(42-3)", false)
	));


TEST(Arithmethic, can_parse_expression)
{
	Arithmetic expr("-2+67*(-3.1/&)");
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
	cmp[9] = Term("&", UNKNOWN);
	cmp[10] = Term(")", OPEN_BRACKET);
	bool res = true;
	for (int i = 0; i < expr.getNTerms(); i++)
		if (cmp[i] != src[i])
			res = false;

	EXPECT_EQ(true,res);
	ASSERT_NO_THROW(expr = Arithmetic(""));
	EXPECT_EQ(0,expr.getNTerms());
}


TEST(arithmetic,can_transform_to_rpn)
{
	Arithmetic expr("- 3 + 4.7 * 2 / (1 - 3)"); //0 3 - 4.7 2 * 1 x - / +
	Term src[11];
	expr.OPN_test(src);
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
}

/*INSTANTIATE_TEST_CASE_P(Inst2, arithm_calc,	::testing::Values(
		calc_test("a+b","15\r3.8",18.8),
		calc_test("(-35-x)/y + 7.1","-5\r6",2.1),
		calc_test("x-s+1-2+3/(-65+64)", "1.8\r-3.2",1.0 ),
		calc_test("18.5+6.16+3.9/x", "3.9",25.66 ),
		calc_test("z*c/(17.9-7.9)", "10\r3.78",3.78 ),
		calc_test("1+2+3+4+5+6-1-3-5-2-4-6+x", "127.789",127.789 ),
		calc_test("17*x-3*y/5", "0.1\r0.5",1.4 )
		*/