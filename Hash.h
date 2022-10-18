#ifndef HASH
#define HASH

#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Hash{
protected:
    /* HASH FUNCTION */
    int hash(T data, int size){
        string str = to_string(data);
        int total = 0;

        for (int i = 0; i < str.size(); i++){
            total += str[i];
        }

		return total % size;
	}

private:
	/* NODE CLASS */
	class Node{
	public:
		bool check;
		T val;

		Node(bool check, T val){
			this->check = check;
			this->val = val;
		}
	};

	/* HASH TABLE ATRRIBUTES */
	int itr;
	int size;
	int length;
	Node** table; //Array of Node pointers
	
public:
	/* CONSTRUCTORS AND DESTRUCTOR */
	Hash(){
		itr = 0;
		size = 500;
		length = 0;

		table = new Node*[size];
		for(int x = 0; x< size; x++){
			table[x] = nullptr;
		}
	}
	Hash(int s){
		itr = 0;
		size = s;
		length = 0;

		table = new Node*[size];
		for(int x = 0; x< size; x++){
			table[x] = nullptr;
		}
	}
	~Hash(){
		for(int x = 0; x < size; x++){
			delete table[x];
		}
		delete table;
	}

	/* UTILITY METHOD */
	int getLen(){
		return length;
	}
	int getItr(){
		return itr;
	}

	/* DISPLAY METHOD */
	void print(){
		for(int x = 0; x < size; x++){
			if(table[x] == nullptr){
				cout << "[] ";
			}
			else{
				if (table[x]->check){
					cout <<  "[] ";
				}
				else{
					cout << "[" << table[x]->val << "] ";
				}
				
			}
			cout << endl;
		}
		cout << endl;
	}

	/* HASH TABLE METHODS */
	void addItem(T data){
		itr = 0; //Reset itr
		
		//Find spot to insert data
		int place = hash(data, size);
		while(table[place] != nullptr && !table[place]->check){
			place = (place + 1) % size;
			itr += 1;
		}

		//Clear any data present
		if (table[place] != nullptr) delete table[place];

		//Insert and return
		table[place] = new Node(false, data);
		length++;
	}
	T getItem(T data){
		itr = 0; //Reset itr
		
		//Find data
		int place = hash(data, size);
		while(table[place] == nullptr || (table[place]->check || table[place]->val != data)){
			place = (place + 1) % size;
			itr += 1;
		}

		//Return
		return table[place]->val;
	}
	T removeItem(T data){
		itr = 0; //Reset itr

		//Find data
		int place = hash(data, size);
		while(table[place] == nullptr && (table[place]->check || table[place]->val != data)){
			place = (place + 1) % size;
			itr += 1;
		}

		//Remove data, then return
		length--;
		table[place]->check = true;
		return table[place]->val;
	}
};

#endif