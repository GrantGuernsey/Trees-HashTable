#include <iostream>
#include <cstdlib>
#include "Hash.h"
#include "Tree.h"
#include "Test.h"
using namespace std;

int main() {
  int list[100];
	Hash<int> table(500);
	Tree<int> tree;
	int sumTable = 0;
	int sumTree = 0;
	for(int n = 0; n < 100; n++){
		list[n] = rand() % 100000000000;
	}
	for(int x = 0; x < 50; x++){
		tree.insert(list[x]);
		table.addItem(list[x]);
		sumTree += tree.itr;
		sumTable += table.getItr();
	}
	for(int x = 0; x < 50; x++){
		int z;
		if(x % 7 == 0){
			Tree<int>::Node *s;
			s = tree.remove(list[x]);
			z = table.removeItem(list[x]);
			sumTree += tree.itr;
			sumTable += table.getItr();
		}
	}
	for(int x = 50; x < 100; x++){
		tree.insert(list[x]);
		table.addItem(list[x]);
		sumTree += tree.itr;
		sumTable += table.getItr();
	}
	for(int x = 0; x < 100; x++){
		int z;
		if(x%9 == 0){
			Tree<int>::Node *s;
			s = tree.remove(list[x]);
			z = table.removeItem(list[x]);
			sumTree += tree.itr;
			sumTable += table.getItr();
		}
	}
	cout << "Number of comparisons for the tree: " <<sumTree << endl; 
  cout << "Number of comparisons for the hash table: "<< sumTable << endl;
	
	Test::testTree(sumTree);
	Test::testTable(sumTable);
}