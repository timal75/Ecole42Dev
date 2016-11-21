#include <stdio.h>
#include <stdlib.h>
double ParseSummands(char  *expr);
double ParseAtom(char  *expr)
{
	 	int		_paren_count;
		while(*expr == ' ')
			expr++;
		int negative = 0;
		if (*expr == '-') {
				negative = 1;
				expr++;
		}
		if(*expr == '+') {
					expr++;
	}
	if(*expr == '(') {
		expr++;
		_paren_count++;
		double res = ParseSummands(expr);
		if(*expr != ')') {
			return 1;
		}
		expr++;
		_paren_count--;
		return (negative == 0) ? -res : res;
	}
	char* end_ptr;
	double res = strtod(expr, &end_ptr);
	expr = end_ptr;
	printf("res : :%lf\n",res);
	return res;
}
double ParseFactors(char *expr)
{
	double num1 = ParseAtom(expr);
	for(;;) 
	{
		char op = *expr;
		if(op != '/' && op != '*')
			return num1;
		expr++;
		double num2 = ParseAtom(expr);
		if(op == '/')
			num1 /= num2;
		else
			num1 *= num2;
	}
}
double ParseSummands(char *expr) 
{
	double num1 = ParseFactors(expr);
	for(;;) 
	{
		while(*expr == ' ')
			expr++;
		char op = *expr;
	printf("ds for parsesummonds   %c\n",*expr);
	printf("op %c\n",op);
		if(op != '-' && op != '+')
			return num1;
		expr++;
		double num2 = ParseFactors(expr);
		if(op == '-')
			num1 -= num2;
		else
			num1 += num2;
	}
}
double EvaluateTheExpression(char *expr) 
{
	return ParseSummands(expr);
}
int	main (int agc, char **agv)
{
	int		res;
	res = EvaluateTheExpression(agv[1]);
	printf("resultat : %d\n", res);
}

