// ���������� ������� � ������� ��� ���������� �������������� ���������


#pragma once

#include <string>
#include <iostream>

using namespace std;

enum TermTypes {OPEN_BRACKET, CLOSE_BRACKET, OPERATOR, VALUE, UNKNOWN} ;

const string allOperators = "+-*/()";

struct Term
{
	TermTypes type;
	//string symbol; // ����� ��� ����
	double val;

	Term();
	Term(const string& str);
	Term(char c);
	Term(const string& str, TermTypes myType);
	Term(char c, TermTypes myType);
	// ����������� �����������
	Term & operator=(const Term &p);// ���������� =
};

// ����������� � double ������� stod(): http://www.cplusplus.com/reference/string/stod/


// "(34-5)" ==>  ������ �� 5 Term 
// ���� ������ ���� symbol
// [0] type = OPEN_BRACKET, symbol = "(", val = 0.0;
// [1] type = VALUE, symbol = "34", val = 34.0;
// [2] type = OPERATOR, symbol = "-", val = 0.0;
// [3] type = VALUE, symbol = "5", val = 5.0;
// [2] type = CLOSE_BRACKET, symbol = ")", val = 0.0;

// ���� �� ������ ���� symbol
// [0] type = OPEN_BRACKET, val = 0.0;
// [1] type = VALUE, symbol = "34", val = 34.0;
// [2] type = OPERATOR, val = 1.0 (��� ������� '-' � ������ allOperators);
// [3] type = VALUE, val = 5.0;
// [2] type = CLOSE_BRACKET, val = 0.0;


// ��� ���� ������: polishTerms = {"34", "5", "-"}

//Term t = Term("(");
//Term t2 = Term("34");

class Arithmetic
{
	string inputStr; // ������� ������
	Term* terms; //������ ������
	int nTerms; // ����� ������ �� ������� ������

	Term* polishTerms; // �������� ������ � ���� ������� ������
	int nPolishTerms; // ����� ������ � �������� ������


	void DivideToTerms(); // ������� �������� ������ � ��������� �� �� ������ terms, ����� �� ���������� �� ���-��.
	void ConvertToPolish(); // ���� - ������ terms, nTerms; ����� - ������ polishTerms, nPolishTerms
	double Calculate(); // ���������� �� �������� ������. ���� - ������ polishTerms, nPolishTerms, ����� - double �����

public:
	Arithmetic& operator=(const Arithmetic& a); 
	Arithmetic(const string& str)
	{
		terms = new Term[str.length()];
		inputStr = str;
		nTerms = 0;
	}
	~Arithmetic() { delete[] terms; } 
	bool check_brackets() const;
	int Check(); //���������� �������, � ������� ������
};




/*#include <iostream>

using namespace std;

enum LexType {VAL, OPER, OP_BR, CL_BR, QU}; //�����, ��������, ( , ) , = 

struct Lexem
{
	char str[10];
	LexType type;
	Lexem(char *s, LexType t);
	Lexem(const Lexem &p);
	Lexem & operator=(const Lexem &p);
	bool operator==(const Lexem &p) const;
};



class Arithmetic
{

};*/