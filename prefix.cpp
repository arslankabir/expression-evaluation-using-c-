#include<iostream>
#include<stack>
#include<string>
using namespace std;
int evaluationprefix(string exp);
bool isNumericDigit(char c);
bool isOperator(char c);
int operation(char op,int op1,int op2);
int main()
{
	string exp;
	cout<<" input expression: ";
	getline(cin,exp);
	int result = evaluationprefix(exp);
	cout<<" Output: "<<result;
}
int evaluationprefix(string exp)
{
	stack<int> s;	 
	for(int i=(exp.length());i>0;i--)
	{
		
		int p=0;
			if(isNumericDigit(exp[i]))
		{
			while(i>0 && isNumericDigit(exp[i])){
			
			p = (exp[i]+(exp.length()-'1'));
			i--;
			
		}
		i++;
			s.push(p);
				//s.push(exp[i] + (exp.length()-'1'));
		
		}
		else if(isOperator(exp[i]))
		{
			int op1=s.top();s.pop();
			int op2=s.top();s.pop();
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
