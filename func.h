#ifndef FUNC_H
#define FUNC_H

#include "line.h"
using namespace std;
bool isNull(int c);
List modify(List* l, int m, int n);
void link_modify(List &l, int m, int n);


void extract(List* l, int m, int n);

void clear(List* l);

template <class T> 
int get(T& a) 
{	
	while(true)
	{
			cin >> a;
			if(cin.good())
			{
				break;
			}			
			if (!cin.good())
			{
				cout << "\nError!\n";
				cin.clear(); 
				cin.ignore(32767, '\n');
			}	
		}	
} 


#endif