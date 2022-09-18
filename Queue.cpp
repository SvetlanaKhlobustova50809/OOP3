#include <iostream>
#include <queue>
#include <memory>
#include <vector>
#include <algorithm>

//using namespace std;

class QueueR {
public:
	QueueR();
	QueueR(QueueR& copy);
	~QueueR();

	//QueueR& operator=(QueueR& data);

	void push(int data);
	void pop();
	bool isEmpty() const;
	int top();
	void clear();
	void print(QueueR& q);

private:

	class Node
	{
	public:
		Node* pNext;
		int data;

		Node(int data, Node* pNext = nullptr) : data(data)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size{ 0 };
	Node* head;
};

QueueR::QueueR() {
	size = 0;
	head = nullptr;
};

QueueR::~QueueR() {
	clear();
};

QueueR::QueueR(QueueR& copy) {}
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

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(data);

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
int QueueR::top()
{
	Node* current = this->head;
	return current->data;


}
void QueueR::clear()
{
	while (size)
	{
		pop();
	}
}
;

void QueueR::print(QueueR& q) {
	while (size > 1 and this->head != nullptr) {
		std::cout << q.top() << std::endl;
		q.pop();
	}
}

int main() {
	QueueR a;
	a.push(2);
	a.push(1000);
	a.push(6);
	a.push(4);

	a.pop();
	a.print(a);

	QueueR t;
	std::cout << a.top() << std::endl;
	std::cout << a.isEmpty() << std::endl;

	a.clear();
	std::cout << a.isEmpty() << std::endl;
};


