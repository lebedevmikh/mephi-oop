#include<iostream>

#include "line.h"

using namespace std;


void List::push_back(int y, int x, int val)
	{
		Node *ptr = new Node(y,x,val);

		ptr->next = nullptr;

		if(List::head == nullptr)
		{
			List::head = ptr;
		}
		else          
		{
			Node *cur = List::head;
			while(cur->next != nullptr) cur = cur->next;
			cur->next = ptr;
		}
	}


void  List::print()
	{
		cout << endl;
		if (List::head)
			{
				Node* n = List::head;
				Node* ex = List::head;
				while(n)
				{
					
					if (n->y == ex->y)
					{
						cout << n->value << "—";	
					}
					if (n->y != ex->y)
					{
						cout << endl;
						cout << n->value << "—";	
						ex = n;
					}

					n = n->next;
				}
			}
			cout << endl;
	}