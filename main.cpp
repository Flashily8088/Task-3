#include "../Solver/queue.h"
#include "iostream"
using namespace std;
/**
* @breaf создаёт массив из целыйх чисел, из этого массива создаёт очередь, выводит очередь на эран,
* добавляет запись по индексу, добавляет запись в конец очереди, считывет данные из головы очереди,
* получает элемент очереди по значению, удаляет заданный элемент из очереди
	* @param s - размер очереди
	* @param list - массив элементов
	* @param Queue - очередь
	* @param v - элемент очереди для добавления, получения и удаления из очереди
	* @param index - индекс элемента для вставки в очередь
*  * return 0
*/
int main() {
	int s = 0;
	cout << "Size: ";
	cin >> s;
	if (s <= 0) return 0;
	int* list = new int[s];
	for (size_t i(0); i < s; i++) {
		int val;
		cin >> list[i];
	}
	queue Queue(s, list);
	cout << Queue;
	int index = 0, v = 0;
	cout << "Insert: ";
	cin >> v;
	cout << "Index: ";
	cin >> index;
	Queue.insert(v, index);
	cout << Queue << endl;
	cout << "Insert back: ";
	cin >> v;
	Queue.insert_back(v);
	cout << Queue << endl;
	cout << "Head: ";
	Queue.read_head();
	cout << endl;
	cout << "Get: ";
	cin >> index;
	cout << Queue.get_val(index) << endl;
	cout << "Remove: ";
	cin >> v;
	Queue.remove(v);
	cout << Queue;
	return 0;
}
