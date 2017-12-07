// реализация функций и классов для вычисления арифметических выражений

#include "arithmetic.h"
using namespace std;


Term::Term() 
{ 
	val = 0.0; type = UNKNOWN; 
}
Term & Term::operator=(const Term &p)//конструктор копирования
{
	type=p.type;
	val=p.val;
	return *this;
}
Term::Term(const string & str)
{
	//val=0;
	//type=;
}
Term::Term(char c, TermTypes myType)
{
	type = myType;
	val = allOperators.find(c);
}
Term::Term(char c)
{
	val = allOperators.find(c);
}
Term::Term(double myVal, TermTypes myType)
{
	val = myVal;
	type = myType;
}
bool Term::operator==(const Term &p) const
	{
		if ((val == p.val) && (type == p.type))
			return true;
		else return false;
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
				if (isdigit(c)) //если это цифра, начиная с нее будет число.
				{
			string v;
			int j = i;
			int p=0; //позиция первого символа после числа
			double res;
			/*while (j < inputStr.length() && (inputStr[j] == isdigit(c) || inputStr[j] == '.'))//если равно цифре
			{
				j++;  
			}*/
			v = inputStr.substr(i, j - i);
			//res=stod(v,p);//сконвертировал строку в число например "123+2" => 123.0   //p = 3 (+)
			terms[nTerms] = Term(res, VALUE); // здесь определили тип внутри конструктора
			nTerms++;

			i = j - 1;
				}
				else if (allOperators.find(c) == string::npos) //если символ не нашли в строке allOperators
					throw "no_correct_symbol";
			}
				// либо это - недопуситмый символ allOperators.find(c) == npos
				// see http://www.cplusplus.com/reference/string/string/find/
				// либо это - число. Его надо накопить и создать 1 Term
			
		}
	}
}

void Arithmetic::delspace()//удаление пробелов
{
	int i = 0;
	while (i < inputStr.length())
	{
		if (inputStr[i] == ' ')
			inputStr.erase(i, 1);
		else i++;
	}
}


Arithmetic::Arithmetic(const string & str)//конструктор
{
		terms = new Term[str.length()];
		inputStr = str;
		nTerms = 0;
		DivideToTerms();
}

Arithmetic::~Arithmetic()
{ 
	delete[] terms; 
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

bool Arithmetic::check_symbols() const//проверка на недопустимые символы
{
	bool res=true;
	for (int i=0;i<nTerms;i++)
		if (terms[i].type==UNKNOWN)
		{
			if (res!=0)
			{
				cout << "UNKNOWN symbols:\n";
				cout << terms[i].type << endl;
				res = false;
			}
		}
		else 
return true;
}

bool Arithmetic::check_opers() const
{
	
	bool res = true;
	
	if (terms[0].type == CLOSE_BRACKET)
	{
		cout << "can`t start with CLOSE_BRACKET:\n ";
		cout << terms[0].type << endl;
			res=false;
	}
	else if 
		(terms[0].type == OPERATOR)
	{
		cout << "can`t start with OPERATOR:\n ";
		cout << terms[0].type << endl;
			res=false;
	}
	for (int i=0;i<nTerms-1;i++)
	{
		if (terms[i].type == VALUE)
			if (terms[i+1].type == OPERATOR || OPEN_BRACKET)
				res = true;
			else res = false;
		if (terms[i].type == OPERATOR)
			if (terms[i+1].type == VALUE || OPEN_BRACKET)
				res = true;
			else res = false;
		if (terms[i].type == OPEN_BRACKET)
			if (terms[i+1].type == VALUE || OPEN_BRACKET)
				res = true;
			else res = false;
		if (terms[i].type == CLOSE_BRACKET)
			if (terms[i+1].type == OPERATOR || CLOSE_BRACKET)
				res = true;
			else res = false;
		if 	(terms[i].type == UNKNOWN)
			res=false;
	}
	return res;
}

void Arithmetic::ConvertToPolish()
{
	nPolishTerms=0;
	for (int i=0;i<nTerms-1;i++)
	{
		if (terms[i].type == VALUE)
		{
			polishTerms[i]=terms[i];
			nPolishTerms++;
		}

	}
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