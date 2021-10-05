#include<iostream>
#include "func.h"
using namespace std;

bool isNull(int c)
{
	return c>0 ? true : false;
}


List modify(List* l, int m, int n)
{
	cout << endl;
	List tmp;
	int minV[m];
	int minX[m];
	Node* ptr = l->head;
	for (int i = 0; i < m; i++)
	{
		minV[i]=0;
		minX[i]=0;
	}
	
	if (l->head)
	{
		while(ptr)
		{
			if (minV[ptr->y] == 0 || ptr->value < minV[ptr->y])
			{
				minV[ptr->y] = ptr->value;
				minX[ptr->y] = ptr->x;
			}
			ptr = ptr->next;
		}


		ptr = l->head;
		while(ptr)
		{
			if (ptr->x >= minX[ptr->y])
			{
				tmp.push_back(ptr->y, ptr->x, ptr->value);
			}
			ptr = ptr->next;
		}
	

	}
	return tmp;
}


void link_modify(List &l, int m, int n)
{
	cout << endl;
	List tmp;
	int minV[m];
	int minX[m];
	Node* ptr = l->head;
	for (int i = 0; i < m; i++)
	{
		minV[i]=0;
		minX[i]=0;
	}
	
	if (l->head)
	{
		while(ptr)
		{
			if (minV[ptr->y] == 0 || ptr->value < minV[ptr->y])
			{
				minV[ptr->y] = ptr->value;
				minX[ptr->y] = ptr->x;
			}
			ptr = ptr->next;
		}


		ptr = l->head;
		while(ptr)
		{
			if (ptr->x >= minX[ptr->y])
			{
				tmp.push_back(ptr->y, ptr->x, ptr->value);
			}
			ptr = ptr->next;
		}
	

	}
	l = tmp;
}



void extract(List* l, int m, int n)
{
	int matr[m][n];
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i) matr[j][i] = 0;
	}
	Node *cur = l->head;
	while(cur != nullptr)
	{
		matr[cur->y][cur->x] = cur->value;
		cur = cur->next;
	}
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i) cout << matr[j][i] << "\t";
		cout << endl;
	}
}


void clear(List* l)
	{
		if (l->head)
			{
				Node* n = l->head;
				Node* ex;
				while(n)
				{
					ex = n;
					delete ex;
					n = n ->next;
				}
			}			
	}



