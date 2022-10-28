#include "Hash.h"

int M;
int SIZE = 0;
struct HashNode** T = NULL;

int main(){
    int choice;
    cout << "Menu" << endl;
    cout << "1. Create a list." << endl;
    cout << "2. Show the Hash Table." << endl;
    cout << "3. Insert an element." << endl;
    cout << "4. Search for an element." << endl;
    cout << "5. Delete an element." << endl;
    cout << "0. Quit." << endl;
    label1:
    cout << endl;
    cout << "Your choice:";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Do NOT type letters or words. Try again" << endl;
        goto label1;
    }
    if (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5) {
        switch (choice) {
            case 0:
                return 0;
            case 1:
                if (T == NULL) {
                    label2:
                    cout << "Enter the M: " << endl;
                    cin >> M;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Do NOT type letters or words. Try again" << endl;
                        goto label2;
                    }
                    T = (struct HashNode**)malloc(sizeof(struct HashNode*)* M);
                    for (int i = 0; i < M; i++)
                        T[i] = NULL;
                }
                else{
                    cout << "List has already been created." << endl;
                }
                break;
            case 2:
                if (T != NULL) {
                    label6:
                    int k;
                    cout << "Enter a key:" << endl;
                    cin >> k;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Do NOT type letters or words. Try again" << endl;
                        goto label6;
                    }
                    if (HashSearch(T, k, M)!=-1)
                        cout << "The element has been found: " << HashSearch(T, k, M) << endl;
                    else
                        cout << "The element has not been found" << endl;
                }
                else{
                    cout << "You haven't created a list." << endl;
                }
                break;
            case 3:
                if (SIZE < M) {
                    if (T != NULL) {
                        label3:
                        int key;
                        cout << "Enter the key: " << endl;
                        cin >> key;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(100, '\n');
                            cout << "Do NOT type letters or words. Try again" << endl;
                            goto label3;
                        }
                        SIZE = HashInsert(T, key, M, SIZE);
                    } else {
                        cout << "You haven't created a list." << endl;
                    }
                }
                else {
                    cout << "You have inserted as much elements as you can have right now. Delete some, to insert new ones." << endl;
                }
                break;
            case 4:
                if (T != NULL) {
                    label4:
                    int key;
                    cout << "Enter the key: " << endl;
                    cin >> key;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Do NOT type letters or words. Try again" << endl;
                        goto label4;
                    }
                    if (HashSearch(T, key, M) != NULL)
                        cout << "The element has been found: " << HashSearch(T, key, M) << endl;
                }
                else{
                    cout << "You haven't created a list." << endl;
                }
                break;
            case 5:
                if (T != NULL) {
                    label5:
                    int key;
                    cout << "Enter the key: " << endl;
                    cin >> key;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Do NOT type letters or words. Try again" << endl;
                        goto label5;
                    }
                    if (HashSearch(T, key, M) != -1)
                        SIZE = HashDelete(T, key, M, SIZE);
                    else
                        cout << "The element has not been found" << endl;
                }
                else{
                    cout << "You haven't created a list." << endl;
                }
                break;
        }
        goto label1;
    }
    else {
        cout << "You haven't chosen any of the available options. Please, try again." << endl;
        goto label1;
    }
}