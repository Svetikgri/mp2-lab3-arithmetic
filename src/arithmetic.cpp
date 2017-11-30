// реализация функций и классов для вычисления арифметических выражений

#include "arithmetic.h"
using namespace std;


Term & Term::operator=(const Term &p)//конструктор копирования
{
	type=p.type;
	val=p.val;
	return *this;
}
Term::Term(const string& str)
{
	val=0;
	//type=;
}
Term::Term(char c, TermTypes myType)
{
	type = myType;
	val = allOperators.find(c);
}

Term::Term(double myVal, TermTypes myType)
{
	val = myVal;
	type = myType;
}

void Arithmetic::DivideToTerms()
{
	for (int i = 0; i < inputStr.length(); i++)
	{
		char c = inputStr[i];

		switch (c)
		{
		case '(': 
			{
				terms[nTerms] = Term('(', OPEN_BRACKET); // здесь тип определили снаружи конструктора
				nTerms++;
				break;
			}
		case ')': 
			{
				terms[nTerms] = Term(')', CLOSE_BRACKET); // 
				nTerms++;
				break;
			}
    	case '+': case '-': case '*': case '/':  
			{
				terms[nTerms] = Term(c, OPERATOR); // 
				nTerms++;
				break;
			}
		default:
			{
				// либо это - недопуситмый символ allOperators.find(c) == npos
				// see http://www.cplusplus.com/reference/string/string/find/
				// либо это - число. Его надо накопить и создать 1 Term
			}
		}
	}
}

void Arithmetic::delspace()//удаление пробелов
{
}
Arithmetic& Arithmetic::operator=(const Arithmetic& a)
{
	inputStr=a.inputStr;
	nTerms=a.nTerms;
	delete [] terms;
	terms=new Term[nTerms];
	for (int i = 0; i < nTerms; i++)
		terms[i] = a.terms[i];
	return *this;
}

bool Arithmetic::check_brackets() const
{
	bool res = true;
	int check=0;
	for (int i = 0; i < inputStr.length(); i++)
	{
	if (inputStr[i] == '(')
		check++;
	if (inputStr[i] == ')')
		check--;
	}
	if (check==0)
		return true;
	else false;

}
void Arithmetic::ConvertToPolish()
{
}



// способ 1
		/*if (allOperators.find(c) != string::npos) // если символ нашли в строке allOperators
		{
      		terms[nTerms] = Term(c); // здесь определили тип внутри конструктора
			nTerms++;
		}
		else if (isdigit(c)) // это цифра, начиная с нее будет число.
		{
			string v;
			int j = i;
			while (j < inputStr.length() && (inputStr[j] == isdigit(c) || inputStr[j] == '.'))//если равно цифре
			{
				j++;
			}
			v = inputStr.substr(i, j - i);
			terms[nTerms] = Term(v, VALUE); // здесь определили тип внутри конструктора
			nTerms++;

			i = j - 1;
		}*/



/*CheckStatus()
{
	Term[nt].type=0;
	Term[nt].value=;
	nt++;

}

int nt=0;
for (int i=0;i<strlen(str);i++)
{
	if (str[i]=='(')
		{
			Term[nt].type=2;
			nt++;
		}
	else if (str[i]==')' )
		{
			Term[nt].type=3;
			nt++;
		}
	else (str[i]=='+' )
		{
			Term[nt].type=1;
			nt++;
		}

}*/