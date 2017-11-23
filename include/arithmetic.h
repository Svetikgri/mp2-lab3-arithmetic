// объ€вление функций и классов дл€ вычислени€ арифметических выражений


#include <iostream>

using namespace std;

enum LexType {VAL, OPER, OP_BR, CL_BR, QU}; //число, операци€, ( , ) , = 

struct Lexem
{
	char str[10];
	LexType type;
	Lexem(char *s, LexType t);
	Lexem(const Lexem &p);
	Lexem & operator=(const Lexem &p);
	bool operator==(const Lexem &p) const;
};

struct Term
{
	int type;
	double value;
};

class Arithmetic
{

};