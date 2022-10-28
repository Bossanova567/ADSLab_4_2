#include "Hash.h"
const int C1 = 2;
const int C2 = 3;
const float A = (sqrt(5) - 1)/2;
const int DELETED = INT_MAX;

struct HashNode* dummy
        = (struct HashNode*)malloc(sizeof(struct HashNode));

void ChainedHashInsert(list<int>* T, int x, int m){
    int index = HashFunctionMultiplication(x, m);
    T[index].push_front(x);
}

int ChainedHashSearch(list<int>* T, int k, int m){
    int index = HashFunctionMultiplication(k, m);
    for(auto ii=T[index].begin(); ii != T[index].end(); ii++)
        if (*ii == k)
            return *ii;
    cout << "No such item in the list" << endl;
    return NULL;
}

void ChainedHashDelete(list<int>* T, int x, int m){
    int index = HashFunctionMultiplication(x, m);
    for(auto ii=T[index].begin(); ii != T[index].end(); ii++)
        if (*ii == x) {
            T[index].erase(ii);
            break;
        }
}

void ChainedHashShow(list<int>* T, int m){
    for (int i = 0; i < m; i++) {
        cout << i;
        for (auto x : T[i])
            cout << " -> " << x;
        cout << endl;
    }
}

int HashFunctionDivision(int k, int m){
    return (k % m);
}

int HashFunctionMultiplication(int k, int m){
    double key = k, intPart;
    return floor(m * modf(key*A, &intPart));
}

int HashInsert(struct HashNode** T, int k, int m){
    int i = 0;
    int j;
    while (i != m) {
        j = HashFunctionQuadratic(k, i, m);
        if (T[j] == NULL || T[j]->key == DELETED) {
            T[j]->key = k;
            return j;
        }
        i++;
    }
    cout << "Error. The table is overflown";
}

int HashSearch(struct HashNode** T, int k, int m){
    int i = 0;
    int j;
    while (T[j] != NULL || i != m) {
        j = HashFunctionQuadratic(k, i, m);
        if (T[j]->key == k)
            return j;
        i++;
    }
    return NULL;
}

int HashDelete(struct HashNode** T, int k, int m){
    int i = 0;
    int j;
    while (T[j] != NULL || i != m) {
        j = HashFunctionQuadratic(k, i, m);
        if (T[j]->key == k) {
            T[j]->key = DELETED;
            return j;
        }
        i++;
    }
    cout << "No such element in the list." << endl;
    return NULL;
}

int HashFunctionLinear(int k, int i, int m){
    return (HashFunctionDivision(k ,m)+i)%m;
}

int HashFunctionQuadratic(int k, int i, int m){
    return (HashFunctionDivision(k ,m)+C1*i+C2*i*i)%m;
}

int HashFunctionDouble(int k, int i, int m){
    return (HashFunctionDivision(k ,m)+ i * (1+HashFunctionDivision(k, m-1)))%m;
}
