#ifndef ADSLAB_4_1_HASH_H
#define ADSLAB_4_1_HASH_H

#include <iostream>
#include <list>
#include <cmath>
using namespace std;

struct HashNode{
    int key;
};


void ChainedHashInsert(list<int> *T, int x, int m);
int ChainedHashSearch(list<int> *T, int k, int m);
void ChainedHashDelete(list<int> *T, int x, int m);
int HashFunctionDivision(int k, int m);
int HashFunctionMultiplication(int k, int m);
void ChainedHashShow(list<int>* T, int m);
int HashInsert(struct HashNode** T, int k, int m, int size);
int HashSearch(struct HashNode** T, int k, int m);
int HashDelete(struct HashNode** T, int k, int m, int size);


#endif //ADSLAB_4_1_HASH_H
