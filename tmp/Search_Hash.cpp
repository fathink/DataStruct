#include <iostream>
#include <iomanip>
using namespace std;

#define HASHSIZE 12
#define NULLKEY -32766

typedef struct{
	int* elem;  // data elements' base address 
	int count;  // current elements numbers
}HashTable;

int InitHashTable(HashTable* H);
int Hash(int key);
void InsertHash(HashTable* H, int key);
int SearchHash(HashTable H, int key, int* addr);

int main(){
	int a[5] = { 23, 45, 12, 23, 8 };
	HashTable H;
	InitHashTable(&H);
	InsertHash(&H, a[0]);
	int b = 3;
	int* addr = &b;
    int status = SearchHash(H, a[0], addr);
	cout << status;

	return 0;
}

int InitHashTable(HashTable* H){
	H->count = HASHSIZE;
	H->elem = (int*)malloc(sizeof(int)*HASHSIZE);
	if (!H->elem){
		return -1; //create fail,return -1
	}
	for (int i = 0; i < HASHSIZE; ++i){
		H->elem[i] = NULLKEY;
	}
	return 0;
}

//Division method
int Hash(int key){
	return key%HASHSIZE;
}

void InsertHash(HashTable* H, int key){
	int addr;
	addr = Hash(key);
	while (H->elem[addr] != NULLKEY){
		addr = (addr + 1) % HASHSIZE;
	}
	H->elem[addr] = key;
}

//Search elemts in hash table
int SearchHash(HashTable H, int key, int* addr){
	*addr = Hash(key);
	while (H.elem[*addr] != key){
		*addr = (*addr + 1) % HASHSIZE;
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)){
			return -1; // Search failed
		}
		return 0;
	}
	return 1;
}










