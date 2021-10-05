#ifndef LINE_H
#define LINE_H
using namespace std;


struct Node
{
	int x;
	int y;
	int value;

	Node* next;
	Node(int row, int col, int val) : y(row), x(col), value(val), next() {}
};


struct List
{
	int m;
	int n;
	Node *head;
	
	List() {head = nullptr;}
	void push_back(int y, int x, int val);
	void print();
};



#endif