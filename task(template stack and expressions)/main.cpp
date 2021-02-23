#include <iostream>
#include <string>
#include "stack.h"
#include "poliz.h"


using namespace std;

int main() {
	
	setlocale(LC_ALL, "Rus");
	// ������� 1
	// �������� ����
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
		// ������� ������� �������
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
	
	// ������� 2
	try {
		cout << "������������ ������� � �������� �������� ������ �� ��������� ��������" << endl;
		char test1[8] = "1+2*3";
		string test1Result;
		expressionToPoliz(test1, test1Result);
		cout << "������� ������: " << test1 << " ���������: " << test1Result << " ��������� ���������: 123*+ " 
			<< "� ����� �����: "<< colculatePoliz(test1Result) << endl;

		char test2[12] = "(1+2)/(3-4)";
		string test2Result;
		expressionToPoliz(test2, test2Result);
		cout << "������� ������: " << test2 << " ���������: " << test2Result << " ��������� ���������: 12+34-/" 
			<< "� ����� �����: " << colculatePoliz(test2Result) << endl;

		char test3[20] = "[(1+2)*3+4]/{5+6+7}";
		string test3Result;
		expressionToPoliz(test3, test3Result);
		cout << "������� ������: " << test3 << " ���������: " << test3Result << " ��������� ���������: 12+3*4+56+7+/" 
			<< "� ����� �����: " << colculatePoliz(test3Result) << endl;

		char expression[MAX_SIZE];
		cin.ignore(256, '\n');
		cout << "������� ��������� ��� �������� ����� ���������� � ����������: ";
		std::cin.getline(expression, MAX_SIZE);
		cout << "Your input: " << expression << endl;

		string poliz;
		expressionToPoliz(expression, poliz);
		cout << "��������: " << poliz << endl;
		cout << "��������� ���������. �����: " << colculatePoliz(poliz) << endl;
	}
	catch (int a) {
		cout << "Error" << endl;
	}


	system("pause");
	return 0;
}