#include "queue.h"
#include<iostream>
using namespace std;

int queue::get_size() const
{
    return size;
}

int queue::get_front() const
{
    return front;
}

int queue::get_back() const
{
    return back;
}
int queue::get_val(const int index) const
{
    return array[index];
}

queue::queue() : size(0), front(0), back(-1), array(nullptr) {}
queue::queue(const int s, const int* list) : size(s), front(0), back(s - 1) {
    array = new int[size];
    for (size_t i(0); i < s; i++) {
        int val(list[i]);
        array[i] = val;
    }
}
queue::queue(const queue& other) {
    size = other.size;
    front = other.front;
    back = other.back;
    array = new int[size];
    for (size_t i(0); i < size; i++) {
        array[i] = other.get_val(i);
    }
}
queue::queue(queue&& other) :
    array(other.array),
    size(other.size),
    front(other.front),
    back(other.back)
{
    other.array = nullptr;
    other.size = 0;
    other.front = 0;
    other.back = -1;
}
queue& queue::operator=(const queue& other)
{
    delete[] array;
    size = other.size;
    back = other.back;
    array = new int[size];
    for (size_t i(0); i < size; i++) {
        array[i] = other.array[i];
    }
    return *this;
}

void queue::insert(const int val, const int index)
{
    if (index < 0 || index > back + 1) {
        cout << "Index error";
        return;
    }
    int* new_array = new int[size + 1];
    for (size_t i(0); i < index; i++) {
        new_array[i] = array[i];
    }
    new_array[index] = val;
    for (size_t i(index); i < size; i++) {
        new_array[i + 1] = array[i];
    }
    swap(new_array, array);
    delete[]new_array;
    back = size;
    size += 1;
}

void queue::remove(const int val)
{
    int* new_array = new int[size - 1];
    int index(search(val));
    if (index == -1) {
        cout << "Does not exist" << endl;
        return;
    }
    for (size_t i(0); i < index; i++) {
        new_array[i] = array[i];
    }
    for (size_t i(index); i < size - 1; i++) {
        new_array[i] = array[i + 1];
    }
    swap(new_array, array);
    delete[]new_array;
    size--;
    back = size - 1;
}

void queue::insert_back(const int val)
{
    int* new_array = new int[size + 1];
    for (size_t i(0); i < size; i++) {
        new_array[i] = array[i];;
    }
    new_array[back + 1] = val;
    swap(new_array, array);
    delete[]new_array;
    size++;
    back = size - 1;
}
void queue::read_head() const
{
    cout << array[front];
}

size_t queue::search(const int val) const
{
    for (size_t i(0); i < size; i++) {
        if (array[i] == val) return i;
    }
    cout << "Error" << endl;
    return -1;
}
bool queue::empty() const{
    return size == 0;
}
ostream& operator <<(ostream& os, const queue Queue) {
    cout << "[";
    for (size_t i(0); i < Queue.size; i++) {
        cout << Queue.array[i] << " ";
    }
    cout << "]" << endl;
    return os;
}
