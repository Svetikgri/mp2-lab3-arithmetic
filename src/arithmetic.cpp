// реализация функций и классов для вычисления арифметических выражений

/*CheckStatus()
{
	Term[nt].type=0;
	Term[nt].value=;
	nt++;

}*/

int nt=0;
for (i=0;i<strlen(str);i++)
{
	if (str[i]=='(')
		{
			Term[nt].type=2;
			nt++;
		}
	else (str[i]==')' )
		{
			Term[nt].type=3;
			nt++;
		}
	else (str[i]=='+' )
		{
			Term[nt].type=1;
			nt++;
		}

}