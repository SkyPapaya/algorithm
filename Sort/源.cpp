
#include <iostream>
#include <string>
using namespace std;
typedef struct entry {
    int key;
    string value;
} Entry;

typedef struct list {
    int n;
    Entry entry[1000];
} List;

//简单选择排序
void selectSort(List* list) {
    int i, j, k;
    Entry temp;
    for (i = 0; i < list->n; i++) {
        k = i;
        for (j = i + 1; j < list->n; j++) {
            if (list->entry[j].key < list->entry[k].key) {
                k = j;
            }
        }
        if (k != i) {
            temp = list->entry[i];
            list->entry[i] = list->entry[k];
            list->entry[k] = temp;
        }
    }
}

//直接插入排序
void insertSort(List* list) {
    int i, j;
    Entry temp;
    for (i = 1; i < list->n; i++) {
        temp = list->entry[i];
        for (j = i - 1; j >= 0 && temp.key < list->entry[j].key; j--) {
            list->entry[j + 1] = list->entry[j];
        }
        list->entry[j + 1] = temp;
    }
}

//冒泡排序
void bubbleSort(List* list) {
    int i, j;
    Entry temp;
    for (i = 0; i < list->n - 1; i++) {
        for (j = 0; j < list->n - i - 1; j++) {
            if (list->entry[j].key > list->entry[j + 1].key) {
                temp = list->entry[j];
                list->entry[j] = list->entry[j + 1];
                list->entry[j + 1] = temp;
            }
        }
    }
}

//快速排序
void quickSort(List* list, int low, int high) {
    int i, j;
    Entry temp;
    if (low < high) {
        i = low;
        j = high;
        temp = list->entry[i];
        while (i < j) {
            while (i < j && list->entry[j].key >= temp.key) {
                j--;
            }
            if (i < j) {
                list->entry[i++] = list->entry[j];
            }
            while (i < j && list->entry[i].key < temp.key) {
                i++;
            }
            if (i < j) {
                list->entry[j--] = list->entry[i];
            }
        }
        list->entry[i] = temp;
        quickSort(list, low, i - 1);
        quickSort(list, i + 1, high);
    }
}

//输出函数
void printList(List* list) {
    int i;
    for (i = 0; i < list->n; i++) {
        cout << list->entry[i].key << " ";
    }
    cout << endl;
}

int main() {
    cout << "999" << endl;
    Entry entry1 = { 1, "a" };;
    Entry entry2 = { 2, "b" };;
    Entry entry3 = { 3, "c" };;
    Entry entry4 = { 4, "d" };;
    Entry entry5 = { 5, "e" };;
    List list;
    quickSort(&list, 0, 4);
    printList(&list);
    return 0;
}
