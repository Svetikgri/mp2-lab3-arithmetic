// реализация пользовательского приложения

#include "arithmetic.h"
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;




int main()
{
		string s;
		cout << "input string: ";
		cin >> s;
		Arithmetic A(s);
		double res;
		if (A.IsCorrect())
		{		
		A.DivideToTerms();
		A.OPN();
		res = A.Calculate();
		cout << res << endl;
		}
		else cout << "no correct input string: ";
		_getch();
		
}


