// объявление функций и классов для вычисления арифметических выражений


#pragma once

#include <string>
#include <iostream>
#include "stack.h" 

using namespace std;

enum TermTypes {OPEN_BRACKET, CLOSE_BRACKET, OPERATOR, VALUE, UNKNOWN} ;

const string allOperators = "+-*/().0123456789";

struct Term
{
	TermTypes type;
	double val;
	string str;

	Term();
	Term(const string& str);
	Term(const string& str, TermTypes myType);
	Term (const Term& s); 
	//Term(char c);
    //Term(const string& str, TermTypes myType);
	Term(char c, TermTypes myType);
	// конструктор копирования
	Term & operator=(const Term &p);// перегрузка =
	Term(double myVal, TermTypes myType);
	Term(double myVal, TermTypes myType, string& str1);
	bool operator==(const Term &p) const;
	bool operator!=(const Term& lop);

};

class Arithmetic
{
	string inputStr; // входная строка
	Term* terms; //массив лексем
	int nTerms; // число термов во входной строке
	Term* polishTerms; // польская запись в виде массива термов
	int nPolishTerms; // число термов в польской записи

	
	//void ConvertToPolish(); // вход - массив terms, nTerms; выход - массив polishTerms, nPolishTerms
	
	

public:
	
	Arithmetic(const string& str);//конструктор
	~Arithmetic(); //деструктор
	Arithmetic& operator=(const Arithmetic& a); // перегрузка =
	void delspace(); //удаление пробелов
	bool check_brackets() const; // проверка на правильность скобок
	bool check_symbols() const;	//Проверка на недопустимые символы
	bool check_opers() const;// проверка на операции чтобы не было ++
	bool IsCorrect() const;
	//int Check(); //возвращает позицию, в которой ошибка
	bool priority(Term in, Term top) const; 
	double Calculate()const; // вычисление по польской записи. Вход - массив polishTerms, nPolishTerms, выход - double ответ
	void DivideToTerms(); // обходим входнуюю строку и разбиваем ее на массив terms, здесь же определяем их кол-во.
	void OPN();

	// это нужно для тестов
	Term* getTerms() const { return terms; }
	int getNTerms() const  { return nTerms; }
    int OPN_test() {return nPolishTerms; }
	Term* getPolishTerms() const { return polishTerms; }
};





// конвертация в double функция stod(): http://www.cplusplus.com/reference/string/stod/


// "(34-5)" ==>  массив из 5 Term 
// если храним поле symbol
// [0] type = OPEN_BRACKET, symbol = "(", val = 0.0;
// [1] type = VALUE, symbol = "34", val = 34.0;
// [2] type = OPERATOR, symbol = "-", val = 0.0;
// [3] type = VALUE, symbol = "5", val = 5.0;
// [2] type = CLOSE_BRACKET, symbol = ")", val = 0.0;

// если НЕ храним поле symbol
// [0] type = OPEN_BRACKET, val = 0.0;
// [1] type = VALUE, symbol = "34", val = 34.0;
// [2] type = OPERATOR, val = 1.0 (это позиция '-' в строке allOperators);
// [3] type = VALUE, val = 5.0;
// [2] type = CLOSE_BRACKET, val = 0.0;


// для этой строки: polishTerms = {"34", "5", "-"}

//Term t = Term("(");
//Term t2 = Term("34");

