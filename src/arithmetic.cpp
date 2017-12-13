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
	val = stod(str);
	type = VALUE;
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
bool Term::operator!=(const Term& lop)
	{
		bool res = false;
		if (lop.str != str || lop.type != type)
			res = true;
		return res;
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
					size_t p=0; //позиция первого символа после числа
					double res;
					v = inputStr.substr(i);
					res=stod(v, &p);//сконвертировал строку в число например "123+2" => 123.0   //p = 3 (+)
					terms[nTerms] = Term(res, VALUE); // здесь определили тип внутри конструктора
					nTerms++;

					i += p - 1;
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

bool Arithmetic::check_brackets() const//есть тест
{
	bool res = true;
	int check=0;
	for (int i = 0; i < inputStr.length(); i++)
	{
	if (inputStr[i] == '(')
		check++;
		if (inputStr[i] == ')')
		check--;
		if(check==-1)
			return false;
			break;
	}
	if (check==0)
		return true;
	else return false;

}

bool Arithmetic::check_symbols() const//проверка на недопустимые символы +
{
	bool res=true;
	cout << "UNKNOWN symbols: ";

	for (int i=0;i<nTerms;i++)
		if (terms[i].type==UNKNOWN)
		{
			res = false;
			cout << " term " << i << endl;
		}
	if (res)
		cout << "none\n";

	return res;
}

bool Arithmetic::check_opers() const//+
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
	for (int i=0;i<nTerms - 1;i++)
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

int Arithmetic::OPN(Term* maslex) //перевод в польскую запись
{
	Arithmetic res(*this);
	res.nTerms = 0;
	Stack<Term> a(2*nTerms);	
	int j=0;

	for (int i = 0; i < nTerms; i++)
	{
		if (terms[i].type == VALUE)
			maslex[j++]= terms[i];

		if (terms[i].type == OPEN_BRACKET)
			a.Push(terms[i]);

		if (terms[i].type == CLOSE_BRACKET)
				{
					Term x = a.Pop();
					while (x.type != OPEN_BRACKET)
					{
						maslex[j++]= x;
						x = a.Pop();
					}
				}

		if (terms[i].type == OPERATOR)
		{
			if (a.isempty())
				a.Push(terms[i]);
			else
			{

				 Term x = a.Peek();
				 while ((a.isempty()!= 1) && priority(terms[i],x)) 
				 {
					 x = a.Pop();
					 maslex[j++]= x;
					 x = a.Peek(); 
				 }
				 a.Push(terms[i]);
			}
		}

		
	}

	while (!a.isempty())
	{
		Term x = a.Pop();
		maslex[j++]= x;
	}

	return j;
}

bool Arithmetic::IsCorrect() const//корректно ли
{
	if (inputStr != "")
	{
		bool s, b, o;
		b = check_brackets();
		s = check_symbols();
		if (s)
			o = check_opers();

		return s && b && o;
	}
	else
	{
		cout << "Empty expression!\n";
			return false;
	}
}

bool Arithmetic::priority(Term in, Term top) const
{
	int p1, p2;
	switch (in.str[0])
	{
	case '+': p1 = 0;
		break;
	case '-': p1 = 0;
		break;
	default: p1 = 1;
	}

	switch (top.str[0])
	{
	case '+': p2 = 0;
		break;
	case '-': p2 = 0;
		break;
	default: p2 = 1;
	}
	if (p1<=p2)
		return true;
	else 
return false;
}

double Arithmetic::Calculate() const
{
	Stack<double> a;
	Stack<string> s;
	double res = 0.0;
	string st_now;

	for (int i = 0; i < nTerms; i++)
	{
		if (terms[i].type == VALUE)
		{
			a.Push(stod(terms[i].str));    //stod в double.
		}
			
		if (terms[i].type == OPERATOR)
		{
			double b = a.Pop();
			double c = a.Pop();
			switch (terms[i].str[0])
			{
			case '+': res = b+c; break;
			case '-': res = b-c; break;
			case '*': res = b*c; break;
			case '/': res = b/c; break;
			}
			a.Push(res);
		}
	}
	return a.Peek();
}





// это в Calculate
		/*if (terms[i].type == VARIABLE)
		{
		cout<<"enter value";
		cin>>var;
		a.Push(var);
		st_now=" ";
		st_now+=(terms[i].str + to_string(var));  // to_string ïðåîáðàçóåò ÷èñëî â ñòðîêó
		s.Push(st_now);
		}*/



/*void Arithmetic::ConvertToPolish()
{
	nPolishTerms=0;
	Stack<Term> temp(2*nTerms);
	for (int i=0;i<nTerms-1;i++)
	{
		if (terms[i].type == VALUE)
		{
			polishTerms[i]=terms[i];
			nPolishTerms++;
		}

		if (terms[i].type == OPEN_BRACKET)
		{
		temp.Push(terms[i]);
		}

		/*if (terms[i].type == CLOSE_BRACKET)
		{
			while ((temp.GetTop()).type != OPEN_BRACKET)
				polishTerms[i]=terms[i];
		}*/
		/*if (c.getstr() == ")")
			{
				x = st.pop();
				while (x.getstr() != "(")
				{
					polish[np] = x;
					np+=1;
					x = st.pop();
				}
			}*/
		/*if (terms[i].type == OPERATOR)
		{
			if (temp.isempty())
				temp.Push(terms[i]);
			else
			{
				Term L = temp.GetTop();

			}
		}
	}
}
*/



/*double Arithmetic::Calc(istream& in)
{
	
	Term* Output = new Term[2 * nTerms];
	int fnL = ConvertToPolish(Output);
	Stack<double> res(2*fnL);
	for (int i = 0; i < fnL; i++)
	{
		if (Output[i].type == NUMBER || Output[i].tp == VARIABLE)
			if (Output[i].type == VARIABLE)
			{
				cout<<"Input "<<Output[i].str<<":";
				double val;
				in>>val;
				res.Push(val);
				string cur = "";
				cur+=(" "+Output[i].str+" = "+to_string(val));
				vars.push(cur);
			}
			else
				res.push(stod(Output[i].str));

		if (Output[i].type == OPERATOR)
		{
			double rop = res.Pop(), lop = res.Pop();
			switch (Output[i].str[0])
			{
			case '+': res.Push(lop + rop);
				break;
			case '-': res.push(lop - rop);
				break;
			case '*': res.push(lop * rop);
				break;
			case '/': 
				{
					//if(rop<1e-25)
					res.push(lop / rop);
					//else
						//throw 0;
				}
				break;
			}
		}
	}

	return res.peek();
}
*/
/*double Arithmetic::Calculate() 
{
	double res;
	Stack <double> st;
	double x;
	int nvar=0;
	for (int i = 0; i < nPolishTerms;i++)
	{
		/*if (polish[i].gettypy() == val) 
		{
			x = atof(polish[i].getstr().c_str());
			st.push(x);
		}*/
	
		/*if (polishTerms[i].type == OPERATOR)
		{
			double c, b = st.Pop();
			double a = st.Pop();
			if (polishTerms[i].val == "+")
				c = a + b;
			if (polishTerms[i].getstr() == "-")
				c = a - b;
			if (polishTerms[i].getstr() == "*")
				c = a*b;
			if (polish[i].getstr() == "/")
				c = a/b;
			st.Push(c);
		}
	}
	res = st.Pop();
	if (!st.isempty())
		throw "something went wrong";
	return res;
}*/


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