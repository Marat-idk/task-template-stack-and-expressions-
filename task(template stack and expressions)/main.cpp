#include <iostream>
#include <string>
#include "stack.h"
#include "poliz.h"


using namespace std;

int main() {
	
	setlocale(LC_ALL, "Rus");
	// задание 1
	// проверим стек
	try
	{
		Stack<double> mystack;
		for (int i = 0; i < 5; ++i) {
			double x;
			cout << "Input elem: ";
			std::cin >> x;

			mystack.push(x);
		}

		cout << "Top elem in stack " << *mystack.top() << endl;
		cout << "And size of stack is " << mystack.stackSize() << endl;
		// удаляем верхний элемент
		mystack.pop();
		cout << "Top elem in stack " << *mystack.top() << endl;
		cout << "And size of stack is " << mystack.stackSize() << endl;
		mystack.pop();
		mystack.pop();
		mystack.pop();
		mystack.pop();
		cout << "And size of stack is " << mystack.stackSize() << endl;
		cout << "Stack empty? " << mystack.stackEmpty() << endl;
	}
	catch (int a) {
		cout << "Error" << endl;
	}
	
	// задание 2
	try {
		cout << "Протестируем перевод в обратную польскую запись на некоторых примерах" << endl;
		char test1[8] = "1+2*3";
		string test1Result;
		expressionToPoliz(test1, test1Result);
		cout << "Входные данные: " << test1 << " Результат: " << test1Result << " Ожидаемый результат: 123*+ " 
			<< "и сумма равна: "<< colculatePoliz(test1Result) << endl;

		char test2[12] = "(1+2)/(3-4)";
		string test2Result;
		expressionToPoliz(test2, test2Result);
		cout << "Входные данные: " << test2 << " Результат: " << test2Result << " Ожидаемый результат: 12+34-/" 
			<< "и сумма равна: " << colculatePoliz(test2Result) << endl;

		char test3[20] = "[(1+2)*3+4]/{5+6+7}";
		string test3Result;
		expressionToPoliz(test3, test3Result);
		cout << "Входные данные: " << test3 << " Результат: " << test3Result << " Ожидаемый результат: 12+3*4+56+7+/" 
			<< "и сумма равна: " << colculatePoliz(test3Result) << endl;

		char expression[MAX_SIZE];
		cin.ignore(256, '\n');
		cout << "Введите выражение без пробелов между операндами и операциями: ";
		std::cin.getline(expression, MAX_SIZE);
		cout << "Your input: " << expression << endl;

		string poliz;
		expressionToPoliz(expression, poliz);
		cout << "Получено: " << poliz << endl;
		cout << "Вычисляем выражение. Ответ: " << colculatePoliz(poliz) << endl;
	}
	catch (int a) {
		cout << "Error" << endl;
	}


	system("pause");
	return 0;
}