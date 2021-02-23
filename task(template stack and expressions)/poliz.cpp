#include <iostream>
#include "poliz.h"


void expressionToPoliz(char* expr, string& poliz)
{
	Stack<char> temp;
	for (int i = 0; expr[i] != '\0'; ++i) {
		//  Если этот символ - число, то просто помещаем его в выходную строку.
		if (expr[i] > 47 && expr[i] < 58) {
			poliz += expr[i];
			// пробелы - это своего рода границы числа. Они нужны, чтобы, например,
			// 10*(24+3) переводилось в ОПЗ корректо. Без пробелов будет плохо
			// Например наш пример будет приобразован в 10243+* и не понятно это 102*(4+3) или 10*(2+43)
			// с пробелами будет всё проще и уж точно однозначно 10 24 3 +*
			// вместо пробелов можно использовать любой другой нейтральный символ
			if(expr[i+1] != '\0' && (expr[i+1] <= 47 || expr[i+1] >= 58))
				poliz += " ";
			continue;
		}
		// Если символ - знак операции (+, -, *, / и тд), то проверяем приоритет данной операции.
		else {
			if (temp.stackEmpty() || getPriority(*temp.top()) < getPriority(expr[i]))
				stepA(expr[i], poliz, temp);
			else {
				if (getPriority(*temp.top()) >= getPriority(expr[i])) {
					//temp.push(expr[i]);
					if (expr[i] != '(' && expr[i] != '[' && expr[i] != '{' && expr[i] != ')' && expr[i] != ']' && expr[i] != '}') {
						while (!temp.stackEmpty() && getPriority(*temp.top()) >= getPriority(expr[i])) {
							poliz += *temp.top();
							temp.pop();
						}
						stepA(expr[i], poliz, temp);
						continue;
						//temp.push(expr[i]);
						//continue;
					}
					if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
						temp.push(expr[i]);
					if (expr[i] == ')') {
						while (*temp.top() != '(') {
							poliz += *temp.top();
							temp.pop();
						}
						temp.pop();
					}
					if (expr[i] == ']') {
						while (*temp.top() != '[') {
							poliz += *temp.top();
							temp.pop();
						}
						temp.pop();
					}
					if (expr[i] == '}') {
						while (*temp.top() != '{') {
							poliz += *temp.top();
							temp.pop();
						}
						temp.pop();
					}
				}
			}
		}
	}
	while (!temp.stackEmpty()) {
		poliz += temp.pop();
	}
}

int getPriority(char ch)
{
	switch (ch)
	{
	case '*':
	case '/':
		return 3;
	case '+':
	case '-':
		return 2;
	case '(':
	case '[':
	case '{':
		return 1;
	default:
		return 0;
	}
}

void stepA(char expr, string& poliz, Stack<char>& temp)
{
	if (temp.stackEmpty())
		temp.push(expr);
	else {
		if (getPriority(*temp.top()) < getPriority(expr))
			temp.push(expr);

	}
}

int characterToDigit(char ch) {
	switch (ch) {
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		return 0;
	}
}

int getValue(string& str, int count) {
	int sum = 0;
	int i = 0;
	int n = count;
	int temp = 1;
	while (count != 0) {
		while (n != 1) {
			temp *= 10;
			--n;
		}
		sum += characterToDigit(str[i]) * temp;
		--count;
		++i;
		n = count;
		temp = 1;
	}
	return sum;
}

double sumValue(int x, int y, char ch)
{
	switch (ch)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / double(y);
	default:
		break;
	}
}



double colculatePoliz(const string& poliz)
{
	Stack<double> stack;
	double sum = 0;
	string temp = "";
	int tempNum;
	int count = 0;
	for (int i = 0; i < poliz.size(); ++i) {
		if (poliz[i] > 47 && poliz[i] < 58) {
			temp += poliz[i];
			++count;
		}
		else{
			if (count != 0) {
				tempNum = getValue(temp, count);
				count = 0;
				temp = "";
				stack.push(tempNum);
			}
			if (poliz[i] == '+' || poliz[i] == '-' || poliz[i] == '*' || poliz[i] == '/') {
				sum = sumValue(stack.pop(), stack.pop(), poliz[i]);
				stack.push(sum);
			}
		}
	}
	return sum;
}