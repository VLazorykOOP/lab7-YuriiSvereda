#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

/*��������� �� ���������� ��������������� ������� ��� ����� ����� �������.
����������� �������� ���������� �����: � ���������, ����� �� ��������������
������ ���������� �����.
������ 1.6. �������� ������ ������� � ������ �������-������. �������
���� ������ ��� ���������. .*/


namespace swaping {
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
}

/*������ 2.3. �������� �������-������ ������� ������������� �������
��������.*/

namespace sorting
{
	template <typename T>
	void insertionSort(T arr[], int size) {
		for (int i = 1; i < size; ++i) {
			T key = arr[i];
			int j = i - 1;

			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				--j;
			}

			arr[j + 1] = key;
		}
	}

	void charInsertionSort(char** arr, int size) {

		for (int i = 1; i < size; ++i) {
			char* key = arr[i];
			int j = i - 1;

			while (j >= 0 && *arr[j] > *key) {
				arr[j + 1] = arr[j];
				--j;
			}

			arr[j + 1] = key;
		}
	}

	template <typename T>
	void inputFromConsole(T arr[], int size) {
		for (int i = 0; i < size; ++i) {
			cout << "Enter element at index " << i << ": ";
			cin >> arr[i];
		}
	}
	template <typename T>
	void inputFromFile(T arr[], int size, const string& filename) {
		ifstream file(filename);

		if (!file.is_open()) {
			cout << "Failed to open file: " << filename << std::endl;
			return;
		}

		for (int i = 0; i < size; ++i) {
			if (!(file >> arr[i])) {
				cout << "Error reading element at index " << i << " from file." << std::endl;
				break;
			}
		}

		file.close();
	}
	template <typename T>
	void inputRandom(T* arr, int size, int limit) {
		for (int i = 0; i < size; ++i) {
			arr[i] = rand() % limit;
		}
	}
}



using namespace swaping;
void Task1()
{
	Swap<int> test;
	cout << "consol input:\n";
	test.consolInputAndSwap();
	cout << "\nfile input:\n";
	test.fileInputAndSwap("textFile.txt");
	cout << test;
	cout << "\nrand input\n";
	test.randInputAndSwap();
	cout << test;
}

using namespace sorting;
void Task2()
{
	const int size = 5;
	int arr[size];

	inputRandom(arr, size, 100);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << '\t';
	}
	insertionSort(arr, size);

	cout << "\nSorted\n";

	for (int i = 0; i < size; i++) {
		cout << arr[i] << '\t';
	}

	//const int size = 5;
	//char arr[size][9] = { "qwerty__", "apple___", "dinosaur", "banana__", "traktor_" };
	//char** dinamic_arr;
	//dinamic_arr = new char* [size];
	//for (int i = 0; i < size; i++) {
	//	dinamic_arr[i] = new char[9];
	//}
	////dinamic_arr[][] = {"qwerty__", "apple___", "dinosaur", "banana__", "traktor_"};
	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		dinamic_arr[i][j] = arr[i][j];
	//	}
	//}
	//for (int i = 0; i < size; i++) {
	//	cout << dinamic_arr[i] << '\t';
	//}
	//charInsertionSort(dinamic_arr, size);
	//
	//cout << "\nSorted\n";
	//
	//for (int i = 0; i < size; i++) {
	//	cout << dinamic_arr[i] << '\t';
	//}
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