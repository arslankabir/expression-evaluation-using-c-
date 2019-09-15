#include<iostream>
#include<stack>
#include<string>
using namespace std;
int evaluationpostfix(string exp);
bool isNumericDigit(char c);
bool isOperator(char c);
int operation(char op,int op1,int op2);
int main()
{
	string exp;
	cout<<" input expression: ";
	getline(cin,exp);
	int result = evaluationpostfix(exp);
	cout<<" Output: "<<result;
}
int evaluationpostfix(string exp)
{
	stack<int> s;
	for(int i=0;i<exp.length();i++)
	{
		if(isNumericDigit(exp[i]))
		{
			s.push(exp[i]-'0');
		}
		else if(isOperator(exp[i]))
		{
			int op2=s.top();s.pop();
			int op1=s.top();s.pop();
			int result = operation(exp[i], op1, op2);
			s.push(result);
		}	
	}
	return s.top();	
}
bool isNumericDigit(char c)
{
	if(c >= '0' && c <= '9')
	return true;
	return false;
}
bool isOperator(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
	return true;
	return false;
}
int operation(char op, int op1, int op2)
{
	if(op == '+')return op1+op2;
	else if(op == '-') return op1-op2;
	else if(op == '*')return op1*op2;
	else if(op == '/')return op1/op2;
}
