// ���������� ������� � ������� ��� ���������� �������������� ���������

#include "arithmetic.h"
using namespace std;

void Arithmetic::DivideToTerms()
{
	for (int i = 0; i < inputStr.length(); i++)
	{
		char c = inputStr[i];

		// ������ 1
		/*if (allOperators.find(c) != string::npos) // ���� ������ ����� � ������ allOperators
		{
      		terms[nTerms] = Term(c); // ����� ���������� ��� ������ ������������
			nTerms++;
		}
		else if (isdigit(c)) // ��� �����, ������� � ��� ����� �����.
		{
			string v;
			int j = i;
			while (j < inputStr.length() && (inputStr[j] == isdigit(c) || inputStr[j] == '.'))//���� ����� �����
			{
				j++;
			}
			v = inputStr.substr(i, j - i);
			terms[nTerms] = Term(v, VALUE); // ����� ���������� ��� ������ ������������
			nTerms++;

			i = j - 1;
		}*/

		// ������ 2
		switch (c)
		{
		case '(': 
			{
				terms[nTerms] = Term('(', OPEN_BRACKET); // ����� ��� ���������� ������� ������������
				nTerms++;
			}
		case ')': 
			{
				terms[nTerms] = Term(')', CLOSE_BRACKET); // 
				nTerms++;
			}
		case '+': 
			{
				terms[nTerms] = Term('+', OPERATOR); // 
				nTerms++;
			}
		case '-': 
			{
				terms[nTerms] = Term('-', OPERATOR); // 
				nTerms++;
			}
		case '*': 
			{
				terms[nTerms] = Term('*', OPERATOR); // 
				nTerms++;
			}
		case '/': 
			{
				terms[nTerms] = Term('/', OPERATOR); // 
				nTerms++;
			}
		case '0': 
			{
				terms[nTerms] = Term('0', VALUE); // 
				nTerms++;
			}
		}
	}
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
		return true
	else false;

{
void Arithmetic::ConvertToPolish()
{
}


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