#include<iostream>

using namespace std;

class Node{
	int data;
	Node *prev;
	Node *next;
public:
	Node(int data) {
		this->data = data;
		prev = nullptr;
		next = nullptr;
	}
	int getData() {
		return data;
	}
	void setData(int data) {
		this->data = data;
	}
	Node* getPrev() {
		return prev;
	}
	Node* getNext() {
		return next;
	}
	void setPrev(Node*prev) {
		this->prev = prev;
	}
	void setNext(Node*next) {
		this->next = next;
	}
};

class DoubleCircularLinkedList
{
	Node* head;
	int size = 0;
public:
	DoubleCircularLinkedList() {
		head = nullptr;
		size = 0;
	}

	bool insertByPos(int pos, int val) {
		if ((head == nullptr&&pos > 0 )|| pos < 0||pos>size) {
			return false;
		}
		Node *newNode = new Node(val);
		if (newNode == nullptr) {
			return false;
		}
		if (pos == 0) {
			if (head == nullptr) {
				head = newNode;
				newNode->setNext(newNode);
				newNode->setPrev(newNode);
				size++;
				return true;
			}
			else {
				Node*last = head->getPrev();
				newNode->setNext(head);
				newNode->setPrev(last);
				head->setPrev(newNode);
				last->setNext(newNode);
				head = newNode;
				size++;
				return true;
			}
		}
		Node*prev = head;
		for (int i = 0; i < pos-1; i++) {
			prev = prev->getNext();
			if (prev == head) {
				delete newNode;
				return false;
			}
		}
		newNode->setPrev(prev);
		newNode->setNext(prev->getNext());
		prev->getNext()->setPrev(newNode);
		prev->setNext(newNode);
		size++;
		return true;
	}

	bool insertByVal( int val) {
		Node *newNode = new Node(val);
		if (newNode == nullptr) {
			return false;
		}
		
		if (head == nullptr) {
			head = newNode;
			head->setNext(head);
			head->setPrev(head);
			return true;
		}

		Node* last = head->getPrev();
		newNode->setNext(head);
		newNode->setPrev(last);
		last->setNext(newNode);
		head->setPrev(newNode);
		size++;
		return true;
	}

	bool deleteByVal(int val) {
		if (head == nullptr)
			return false;

		if (head->getData() == val) {
			if (head->getNext() == head) {
				delete head;
				head = nullptr;
				size--;
				return true;
			}
			Node* last = head->getPrev();
			Node* del = head;
			head = head->getNext();
			last->setNext(head);
			head->setPrev(last);
			delete del;
			size--;
			return true;
		}

		Node*prev = head;
		while (prev->getNext()->getData() != val) {
			if (prev->getNext() == head)
				return false;
			prev = prev->getNext();
		};
		Node*del = prev->getNext();
		prev->setNext(del->getNext());
		del->getNext()->setPrev(prev);
		delete del;
		size--;
		return true;
	}

	int findMiddle() {
		if (size == 0)
			return -999;
		Node*middle = head;
		for (int i = 0; i < size / 2; i++) {
			middle = middle->getNext();
		}
		return middle->getData();
	}

	bool searchByVal(int val) {
		Node*temp = head;
		do{
			if (temp->getData() == val)
				return true;
			temp = temp->getNext();
		} while (temp != head);
		return false;
	}

	bool reverse() {
		if (head == nullptr||head->getNext()==head)
			return false;

		Node * curr, *next, *temp;
		curr = head;
		do {
			next = curr->getNext();
			temp = curr->getPrev();
			curr->setPrev(next);
			curr->setNext(temp);
			curr = next;
		} while (curr != head);
		head = head->getNext();
		return true;
 	}
	void display() {
		if (head == nullptr) {
			return;
		}
		Node*temp = head;
		do {
			cout << temp->getData()<<" ";
			temp = temp->getNext();
		} while (temp!=head);
	}
	bool checkPalindrome() {
		Node*rev = head->getPrev();
		Node*forward = head;
		for(int i=0;i<size/2;i++) {
			if (forward->getData() != rev->getData())
				return false;
			forward = forward->getNext();
			rev = rev->getPrev();
		}
		return true;
	}
};

