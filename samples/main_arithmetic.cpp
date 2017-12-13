// реализация пользовательского приложения

#include "arithmetic.h"
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string s;
	int f;
    do {
		cout << "Your arithmetic expression:\n";
		getline(cin, s);
		Arithmetic Exp(s);
		f = Exp.IsCorrect();
       } while (f==0);
	Arithmetic Arr(s);
	//Arr.OPN();
	double res = Arr.Calculate();
	cout << res;
  return 0;
}


