#include <iostream>
#include <queue>
#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>

//using namespace std;

class QueueR {

public:
	QueueR() = default;
	QueueR(const QueueR& data);
	~QueueR();

	QueueR& operator=(const QueueR& data);

	void push(int data);
	void pop();
	bool isEmpty() const;
	int top() const;
	void clear();
	void print(QueueR& q);
	bool isFull() const;

private:

	class Node
	{
	public:
		Node* pNext;
		int data;

		Node(int data, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node* head;
	int size{ 0 };
};


QueueR::~QueueR() {
	clear();
};

QueueR::QueueR(const QueueR& copy) {}
//QueueR& QueueR::operator=(const QueueR& data)
//{
//	return;
//}
void QueueR::push(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* current = this->head;
		Node* current2 = this->head;
		int a;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		};
		if (data < this->head->data) {
			head = new Node(data, head);
		}
		else if (current->data <= data) {
			current->pNext = new Node(data);
		}
		else {
			current = this->head;
			while (current->data <= data)
			{
				current2 = current;
				current = current->pNext;
			};
			current2->pNext = (new Node(data, current));
			/*(new Node(data))->pNext = current;*/
		}

	}
	size++;
}
void QueueR::pop()
{
	if (this->head != nullptr) {
		Node* temp = head;

		head = head->pNext;

		delete temp;

		size--;
	}
	else
		size = 0;

}
bool QueueR::isEmpty() const
{
	if (size == 0)
		return true;
	else
		return false;
}
int QueueR::top() const
{
	Node* current = this->head;
	return current->data;
}
void QueueR::clear()
{
	while (size > 0)
	{
		pop();
	}
}
;

void QueueR::print(QueueR& q) {
	QueueR& copy = q;
	while (size > 0 and this->head != nullptr) {
		std::cout << copy.top() << std::endl;
		copy.pop();
	}
}

int main() {
	QueueR a;


	a.push(10);
	a.push(1000);

	a.push(6);
	a.push(4);
	a.push(7);
	a.push(5);
	std::cout << a.top() << std::endl;
	a.pop();
	std::cout << a.top() << std::endl;
	a.print(a);

	a.push(100);

	std::cout << a.isEmpty() << std::endl;

	a.clear();
	std::cout << a.isEmpty() << std::endl;
};


