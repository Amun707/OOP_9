#include <iostream>
#include <string>
#include <vector>

//explicit - запрещает вызывать конструктор (должен стоять перед)

//шаблоны классов
//создание шаблонного связного списка

//связный список - это структура данных в которой каждый элемент хранится
//  в памяти и знает где хранится следующий элемент в структуре списка

//при работе с нодами - геттеры и сеттеры не используются

template <typename Type>
class LinkedList {
public:
	//Задачи связного списка 
	LinkedList();
	LinkedList(int n);//лист с уже созданными n элементами
	LinkedList(const Linkedlist& other);
	LinkedList(Linkedlist && other);//можно не делать но для оптимизации скорости работы программы полезно
								   //тут не будет реализации конструктора от списка инициализации, внесём позже

	~LinkedList();//деструктор(~)

	//присваивание копированием 
	LinkedList& operator = (const LinkedList& other);

	//присваивание переносом
	LinkedList& operator = (const LinkedList&& other);


	Type& operator[](int i);
	const Type& operator[](int i)const;

	Type& at[](int i);
	const Type& at[](int i)const;//метод at - вместо []

	void push_back(const Type& obj);//добавить данные в конец списка
	void push_front(const Type& obj);//добавить данные в начало списка

	void pop_bask();//уничтожить данные в конце списка
	void pop_front();//уничтожить данные в начале списка

	/*
	emplace/insert - методы добавления новых данных в произвольное место коллекции
	erse - метод для уничтожения данных в произвольной точке коллекции

	*/

	int size()const;//метод - сообщить пользователю сколько в коллекции есть элементов

	/*
	методы для прохода по коллекции умными указателями
	мы пока сознательно опустим
	*/
private:
	class Node {
	public:
		Node()
			:Node(Type())//при делигации мы вызываем конструктор по умолчанию хранимого типа данных.
						 //Данный синтаксис корректно отработает даже если прямой вызов такого метода
						 // (например конструктора встроенных типов)
		{ }

		Node(const Type& data, Node* place = nullptr)
			:data_(data),
			next_(place)
		{ }

		typename& Data() {
			return data_;
		}

		const Type& Data()const {
			return data_;
		}

		Node* Next()const {//создали метод о местоположеннии точки следующей в списке
			return next_;
		}

		void Next(Node* next_) {//устанавливаем новое значение о следующей точке
			next_ = next;
		}

	private:
		Type data_;
		Node* next_;
	};
	Node* start_;
	Node* end_;
	int size_;

};


int main() {
	system("chcp 1251>nul");

	int arr[10];
	std::vector<int>vec(10);
	LinkedList<int>list;
	arr[5] = 34;
	vec[5] = 23;
	list[5] = 12;




	return 0;
}