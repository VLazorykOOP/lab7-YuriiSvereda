#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;


/*Розробити та реалізувати параметризовані функції або класи згідно варіантів.
Передбачити введення початкових даних: з клавіатури, файлу та використовуючи
датчик випадкових чисел.*/


/*Задача 1.6.Написати родову функцію у вигляді функції - шаблон.Функція
міняє місцями два аргументи. .*/

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


/*Задача 2.3. Написати функцію-шаблон функцію впорядкування методом
«Вставки».*/

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
			cout << "Failed to open file: " << filename << endl;
			return;
		}

		for (int i = 0; i < size; ++i) {
			if (!(file >> arr[i])) {
				cout << "Error reading element at index " << i << " from file." << endl;
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


/*Задача 3.6.Створити параметризованний клас бінарного дерева.З методами
- додати елемент у дерево, проходження по дереву в спадному й у
висхідному порядку.Здійснити пошук по дереву.*/

template<typename T>
class BinaryTree {
private:
	struct Node {
		T data;
		Node* left;
		Node* right;

		Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
	};

	Node* root;

	void addElement(Node*& node, const T& value) {
		if (node == nullptr) {
			node = new Node(value);
		}
		else if (value < node->data) {
			addElement(node->left, value);
		}
		else {
			addElement(node->right, value);
		}
	}

	void fromSmallerTraversal(Node* node) {
		if (node != nullptr) {
			fromSmallerTraversal(node->left);
			cout << node->data << " ";
			fromSmallerTraversal(node->right);
		}
	}

	void fromBiggerTraversal(Node* node) {
		if (node != nullptr) {
			fromBiggerTraversal(node->right);
			cout << node->data << " ";
			fromBiggerTraversal(node->left);
		}
	}

	Node* search(Node* node, const T& value) {
		if (node == nullptr || node->data == value) {
			return node;
		}
		else if (value < node->data) {
			return search(node->left, value);
		}
		else {
			return search(node->right, value);
		}
	}

public:
	BinaryTree() : root(nullptr) {}

	void add(const T& value) {
		addElement(root, value);
	}

	void traverseFromSmaller() {
		fromSmallerTraversal(root);
	}

	void traverseFromBigger() {
		fromBiggerTraversal(root);
	}

	bool contains(const T& value) {
		return search(root, value) != nullptr;
	}
};

/*Задача 4.3. Побудувати клас, що описує лінійний двох зв’язний список.
Побудувати клас ітератор, що дозволяє проходити список.*/

namespace linkedList
{
	template <typename T>
	class Node {
	public:
		T data;
		Node<T>* prev;
		Node<T>* next;

		Node(T value) : data(value), prev(nullptr), next(nullptr) {}
	};

	template <typename T>
	class LinkedList {
	private:
		Node<T>* head;
		Node<T>* tail;
		int size;

	public:
		LinkedList() : head(nullptr), tail(nullptr), size(0) {}

		Node<T>* getHead() {
			return this->head;
		}

		void pushBack(T value) {
			Node<T>* newNode = new Node<T>(value);
			if (isEmpty()) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
			size++;
		}

		void pushFront(T value) {
			Node<T>* newNode = new Node<T>(value);
			if (isEmpty()) {
				head = newNode;
				tail = newNode;
			}
			else {
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
			size++;
		}

		void popBack() {
			if (isEmpty()) {
				cout << "List is empty." << endl;
				return;
			}

			Node<T>* nodeToRemove = tail;

			if (head == tail) {
				head = nullptr;
				tail = nullptr;
			}
			else {
				tail = tail->prev;
				tail->next = nullptr;
			}

			delete nodeToRemove;
			size--;
		}

		void popFront() {
			if (isEmpty()) {
				std::cout << "List is empty." << std::endl;
				return;
			}

			Node<T>* nodeToRemove = head;

			if (head == tail) {
				head = nullptr;
				tail = nullptr;
			}
			else {
				head = head->next;
				head->prev = nullptr;
			}

			delete nodeToRemove;
			size--;
		}

		bool isEmpty() const {
			return (size == 0);
		}

		int getSize() const {
			return size;
		}

		void printList() const {
			Node<T>* current = head;
			while (current != nullptr) {
				std::cout << current->data << " ";
				current = current->next;
			}
			std::cout << std::endl;
		}
	};

	template <typename T>
	class LinkedListIterator {
	private:
		Node<T>* currentNode;

	public:
		LinkedListIterator(Node<T>* node) : currentNode(node) {}

		T& operator*() const {
			return currentNode->data;
		}

		LinkedListIterator<T>& operator++() {
			currentNode = currentNode->next;
			return *this;
		}

		bool operator!=(const LinkedListIterator<T>& other) const {
			return (currentNode != other.currentNode);
		}
	};

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

void Task3()
{
	BinaryTree<int> binaryTree;

	binaryTree.add(5);
	binaryTree.add(3);
	binaryTree.add(7);
	binaryTree.add(2);
	binaryTree.add(4);
	binaryTree.add(6);
	binaryTree.add(8);

	cout << "Going through the tree in ascending order ";
	binaryTree.traverseFromSmaller();
	cout << endl;

	cout << "Going through the tree in descending order: ";
	binaryTree.traverseFromBigger();
	cout << endl;

	int searchValue = 4;
	cout << "Tree contains " << searchValue << ": " << (binaryTree.contains(searchValue) ? "true" : "false") << endl;

	searchValue = 9;
	cout << "Tree contains " << searchValue << ": " << (binaryTree.contains(searchValue) ? "true" : "false") << endl;


}

using namespace linkedList;
void Task4()
{
	LinkedList<int> list;
	list.pushBack(1);
	list.pushBack(2);
	list.pushBack(3);

	cout << "List: ";
	list.printList();

	cout << "Using Iterator: ";
	for (LinkedListIterator<int> it = LinkedListIterator<int>(list.getHead()); it != nullptr; ++it) {
		cout << *it << " ";
	}
	cout << endl;

}


int main()
{
	int choise = 0;
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
		cout << "incorect input";
	return 0;
}