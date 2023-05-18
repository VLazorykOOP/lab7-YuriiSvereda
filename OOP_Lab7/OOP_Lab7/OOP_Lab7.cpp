#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

/*Розробити та реалізувати параметризовані функції або класи згідно варіантів.
Передбачити введення початкових даних: з клавіатури, файлу та використовуючи
датчик випадкових чисел.
Задача 1.6. Написати родову функцію у вигляді функції-шаблон. Функція
міняє місцями два аргументи. .*/


template<typename T>
class Swap {
private:
	T a;
	T b;
public:
	Swap() {}
	Swap(T a, T b) {
		this->a = a;
		this->b = b;
	}

	void consolInputAndSwap() {
		cin >> *this;
		cout << *this;
		this->swap();
		cout << *this;
	}
	void fileInputAndSwap(const string& file_name) {
		ifstream fin(file_name);
		if (fin.is_open()) {
			fin >> this->a >> this->b;
			swap();
			fin.close();
		}
		else {
			cout << "file open error" << endl;
		}
	}
	void randInputAndSwap() {
		srand(time(NULL));
		this->a = 97 + rand() % 25;
		srand(time(NULL) / 2 * 3);
		this->b = 97 + rand() % 25;

		cout << "A = " << this->a << endl;
		cout << "B = " << this->b << endl;
		swap();
	}

	void swap() {
		T temp = a;
		a = b;
		b = temp;
		cout << "SWAP" << endl;
	}
	template<typename U>
	friend istream& operator>>(istream& input, Swap<U>& obj);
	template<typename U>
	friend ostream& operator<<(ostream& output, Swap<U>& obj);
};

template<typename T>
istream& operator>>(istream& input, Swap<T>& obj) {
	cout << "enter A: ";
	input >> obj.a;
	cout << "enter B: ";
	input >> obj.b;
	return input;
}
template<typename T>
ostream& operator<<(ostream& output, Swap<T>& obj) {
	output << "A = " << obj.a << endl;
	output << "B = " << obj.b << endl;
	return output;
}

void charSwap(char* a, char* b) {
	const int a_size = strlen(a);
	int b_size = strlen(b);
	char* temp_a;
	temp_a = new char[a_size];
	char* temp_b;
	temp_b = new char[b_size];
	for (int i = 0; i < a_size; i++) {
		temp_a[i] = a[i];
	}
	a = new char[b_size];
	for (int i = 0; i < b_size; i++) {
		a[i] = b[i];
	}
	b = new char[a_size];
	for (int i = 0; i < a_size; i++) {
		b[i] = temp_a[i];
	}

}

int main()
{
	/*int choise = 0;
	cout << "enter number:\n" << "1. Task1;\n" << "2. Task2;\n" << "3. Task3;\n" << "4. Task4\n";
	cin >> choise;
	if (choise == 1) {
		Task1();
	}
	else if (choise == 2) {
		Task2();
	}
	else if (choise == 3) {
		Task3();
	}
	else if (choise == 4) {
		Task4();
	}
	else
		cout << "incorect input";*/
	return 0;
}