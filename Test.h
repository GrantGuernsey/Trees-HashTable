#ifndef TEST
#define TEST

#include <assert.h>
#include <iostream>
using namespace std;

class Test{
public:
	static void testTree(int sumTree){
		assert(sumTree == 600);
		cout << "Tree assertion passed" << endl;
	}
	static void testTable(int sumTable){
		assert(sumTable == 548);
		cout << "Table assertion passed" << endl;
	}
};

#endif


	