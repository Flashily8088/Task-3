#include <iostream>
using namespace std;

/**
	* @breaf класс очередь
	 */
class queue
{
	/**
	* @breaf размер очереди
	 */
	int size; 
	/**
	* @breaf индекс первого элемента очереди
	 */
	int front; 
	/**
	* @breaf индекс последнего элемента очереди
	 */
	int back;
	/**
	* @breaf массив из элементов очереди
	 */
	int* array;
public:
	/**
	* @breaf конструктор по умолчанию
	 */
	queue();
	/**
	* @breaf конструктор
	* @param s - размер очереди
	* @param list - массив из элементов 
	 */
	queue(const int s, const int* list);
	/**
	* @breaf конструктор копирования
	* @param other - очередь коприования 
	 */
	queue(const queue& other);
	/**
	* @breaf конструктор перемещения
	* @param other - очередь перемещения
	 */
	queue(queue&& other);
	/**
	* @breaf оператор вывода
	* @param os - поток вывода
	* @param Queue - очередь
	* @return поток вывода
	 */

	friend ostream& operator <<(ostream& os, const queue Queue);
	/**
	* @breaf оператор =
	* @param Queue - очередь
	 */
	queue& operator =(queue& Queue);
	/**
	* @breaf вставляет элемент по индексу
	* @param val - значение элемента
	* @param index - индекс 
	 */
	void insert(const int val, const  int index);
	/**
	* @breaf удаляет элемент по значению
	* @param val - значение элемента
	 */
	void remove(const int val);
	/**
	* @breaf вставляет элемент в конец очереди
	* @param val - значение элемента
	 */
	void insert_back(const int val);
	/**
	* @breaf считывает элемент по значению
	* @param index - индекс извлекаемого элемента
	* @return значение элемента
	 */
	int get_val(const int index) const;
	/**
	* @breaf читает первый элемент
	 */
	void read_head() const;
	/**
	* @breaf ищет элемент по значению
	* @param val - значение элемента
	* @return индекс искомого элемента
	 */
	size_t search(const int val) const;
	/**
	* @breaf проверяет есть ли в очереди элементы
	* @return true, если очередь пустая
	* @return false, если в очереди есть хотя бы один элемент
	 */
	bool empty() const;
	/**
	* @breaf считывает размер массива
	* @return размер массива
	 */
	int get_size() const;
	/**
	* @breaf считывает первый элемент
	* @return первый элемент
	 */
	int get_front() const;
	/**
	* @breaf считывает последний элемент
	* @return последний элемент
	 */
	int get_back() const;
};
