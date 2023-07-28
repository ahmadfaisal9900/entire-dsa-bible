#include <iostream>
#include <stack>
using namespace std;
struct LinkedList {
	struct node {
		int data;
		node* next = NULL;
	};
	node* head = NULL;
	void Print() {
		node* temp = head;
		while (temp) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	void InsertionAtFront(int x) {
		node* temp = new node;
		temp->data = x;
		if (head == NULL) {
			head = temp;
		}
		else {
			temp->next = head;
			head = temp;
		}
	}
	void InsertAtEnd(int x) {
		node* temp = head;
		node* temp2 = new node;
		temp2->data = x;
		temp2->next = NULL;
		if (head == NULL) {
			head = temp2;
		}
		else {
			while (temp->next != NULL) {
				temp = temp->next;
			}
		}

		temp->next = temp2;
	}
	void InsertAtNth(int x, int place) {
		node* temp = head;
		node* temp2 = new node;
		temp2->data = x;
		temp2->next = NULL;
		for (int i = 0; i < place - 2; i++) {
			temp = temp->next;
		}
		temp2->next = temp->next;
		temp->next = temp2;
	}
	void DeleteFromStart() {
		node* temp = head;
		head = head->next;
		delete temp;
	}
	void DeleteFromEnd() {
		node* current = head;
		node* prev = head;
		while (current->next != NULL) {
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		delete current;
	}
	void DeleteFromNth(int x) {
		node* temp = head;
		node* prev = head;
		for (int i = 0; i < x - 2; i++) {
			prev = temp;
			temp = temp->next;
		}
		prev->next = temp->next;
		delete(temp);
	}
	void Reverse() {
		node* current, * next, * prev;
		current = head;
		prev = NULL;
		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void PrintRecur(node* hea) {
		if (hea == NULL) {
			return;
		}
		cout << hea->data << endl;
		PrintRecur(hea->next);
	}
	void ReverseRecur(node* p) {
		if (p->next == NULL) {
			head = p;
			return;
		}
		ReverseRecur(p->next);
		node* q = p->next; //I do not fully get what's going on here help????
		q->next = p;
		p->next = NULL;
	}
};
struct DoublyLinkedList {
	struct node {
		int data;
		node* next, * prev;
	};
    node* head2 = NULL;
	void Print() {
		node* temp = head2;
		while (head2 != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	void DoublyInsertAtFront(int x) {
		node* temp = new node;
		temp->data = x;
		temp->prev = NULL;
		temp->next = head2;
		head2 = temp;
	}
	void DoublyInsertAtEnd(int x) {
		node* temp = head2;

	}
};
struct Stack {
	int top = -1;
	string num[100];
	void Push(int x) {
		if (top == -1) {
	 		top = 0;
		}
		num[top] = x;
		top++;
	}
	void Pop() {
		top--;
	}
	void Print() {
		for (int i = 0; i < 10; i++) {
			cout << num[i] << endl;
		}
	}

	bool IsEmpty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool ArePair(char start, char end) {
		if (start == '{' && end == '}') {
			return true;
		}
		if (start == '[' && end == ']') {
			return true;
		}
		if (start == '(' && ')') {
			return true;
		}
		else {
			return false;
		}
	}
		bool StackyStacky(string s) {
			stack <char> B;
			for (int i = 0; i < s.size(); i++) {
				if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
					B.push(s[i]);
				}
				if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
					if (B.empty() || ArePair(B.top(), s[i]) == false) {
						cout << "The paranthesis are not balanced." << endl;
						return false;
					}
					else {
						B.pop();
					}

				}
			}
			if (B.empty()) {
				return true;
			}
			else {
				return false;
			}
		}
};
/*struct Queue {
	int num[10];
	int head = -1, tail = -1;
	bool IsFull() {
		if ((tail + 1) % 10 == head) {
			return true;
		}
		else {
			return false;
		}
	}
	bool IsEmpty() {
		if (head == -1 && tail == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void Enqueue(int x) {
		if (IsEmpty()) {
			head = 0;
			tail = 0;
			num[tail] = x;
		}
		else {
			tail = (tail + 1) % 10;
			num[tail] = x;
		}
	}
	void Dequeue() {
		if (IsEmpty() != true) {
			head = (head + 1) % 10;
		}
		else {
			cout << "List is empty.";
			return;
		}
	}
	void Print() {
		for (int i = head; i != tail; i = (i + 1) % 10) {
			cout << num[i] << endl;
		}
		//cout << "End." << endl;
	}
};*/
struct Stack1 {
	int num[10];
	int top = -1;
	bool IsEmpty() {
		if (top == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool IsFull() {
		if (top == 10) {
			return true;
		}
		else {
			return false;
		}
	}
	void Push(int x) {
		if (top == -1) {
			top = 0;
		}
		num[top] = x;
		top++;
	}
	void Pop() {
		top--;
	}
	bool ArePair(char start, char end) {
		if (start == '{' && end == '}') {
			return true;
		}
		if (start == '[' && end == ']') {
			return true;
		}
		if (start == '(' && end == ')') {
			return true;
		}
		else {
			return false;
		}
	}
	bool Para(string s) {
		stack <char> A;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				A.push(s[i]);
			}
			if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
				if (A.empty() || ArePair(A.top(), s[i]) == false) {
					return false;
				}
				else {
					return true;
				}
			}
		}
	}
};
#define N 10
struct QueueCircular{
	int head = -1, tail = -1;
	int num[N];
	bool IsEmpty() {
		if (head == -1 && tail == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	bool IsFull() {
		if (head == (tail + 1) % N) {
			return true;
		}
		else {
			return false;
		}
	}
	void Enqueue(int x) {
		if (IsEmpty()) {
			head = 0; tail = 0;
			num[tail] = x;
			
		}
		else {
			tail = (tail + 1) % N;
			num[tail] = x;
		}
	}
	void Dequeue() {
		if (IsEmpty()) {
			cout << "The list is empty";
			return;
		}
		else if (head == tail) {
			head = -1;
			tail = -1;
			return;
		}
			head = (head + 1) % N;
		
	}
	void Print() {
		for (int i = 0; i <= tail; i++) {
			cout << num[i] << endl;
		}	cout << "End." << endl;
	}
};
struct CircularLinkedList {
	struct node {
		int data;
		struct node* next;
	};
	node* tail = NULL;
	void AddToEmpty(int x) {
		node* temp = new node;
		temp = tail;
		temp->next = tail;
	}
	void InsertAtStart(int x) {
		if (tail == NULL) {
			AddToEmpty(x);
		}
		else {
			node* temp = new node;
			temp->data = x;
			temp->next = tail->next;
			tail->next = temp;
		}
	}
	void InsertAtEnd(int x) {
		if (tail == NULL) {
			AddToEmpty(x);
		}
		else {
			node* temp = new node;
			temp->data = x;
			temp->next = tail->next;
			tail->next = temp;
		}
	}
	
	
};
int main() {
	QueueCircular A;
	A.Enqueue(4);
	A.Enqueue(6);
	A.Dequeue();
	A.Dequeue();
	A.Print();
}