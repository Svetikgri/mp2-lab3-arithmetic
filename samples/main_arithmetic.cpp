// реализация пользовательского приложения

#include "arithmetic.h"
#include <cstdlib>
#include <string>

using namespace std;




int main()
{
	bool f = true;
	while (f)
	{
		string s;
		cout << "input string: ";
		cin >> s;
		Arithmetic A(s);
	//	Temp src[1000];
		double res;
		//int k;
		A.DivideToTerms();
		A.OPN();
		res = A.Calculate();
		cout << res << endl;
		cout << "continue?" << endl;
		cin >> f;
	}
}
/*int main()
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
*/

