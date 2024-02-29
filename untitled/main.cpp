using namespace std;
#include <iostream>
#include <string>
#include <chrono>
#define MAXSIZE 100000

//�궨�����ֵ
typedef struct entry {
    int key;
    string value;
} Entry;

typedef struct list {
    int n;
    Entry *entry = new Entry[MAXSIZE];
} List;

//��ѡ������
void selectSort(List *list) {
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

//ֱ�Ӳ�������
void insertSort(List *list) {
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

//ð������
void bubbleSort(List *list) {
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

//��������
void quickSort(List *list, int low, int high) {
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
                list->entry[i++] = list->entry[j]; //�����
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

//��·�ϲ�����
void merage(List *list, Entry *temp, int low, int n1, int n2) {
    int i = low, j = low + n1;
    while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1) {
        if (list->entry[i].key <= list->entry[j].key)
            *temp++ = list->entry[i++];
        else *temp++ = list->entry[j++];
    }
    while (i <= low + n1 - 1) {
        *temp++ = list->entry[i++];
    }
    while (j <= low + n1 + n2 - 1) {
        *temp++ = list->entry[j++];
    }
}

void merageSort(List *list) {
    auto start = std::chrono::high_resolution_clock::now();
    Entry temp[list->n];
    int low, n1, n2, i, size = 1;
    while (size < list->n) {
        low = 0;
        while (low + size < list->n) {
            n1 = size;
            if (low + size * 2 < list->n)
                n2 = size;
            else
                n2 = list->n - low - size;
            merage(list, temp + low, low, n1, n2);
            low += n1 + n2;
        }
        for (i = 0; i < low; i++) {
            list->entry[i] = temp[i];
        }
        size *= 2;
    };
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(List *list, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && list->entry[left].key > list->entry[largest].key) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && list->entry[right].key > list->entry[largest].key) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(&list->entry[i].key, &list->entry[largest].key);

        // Recursively heapify the affected sub-tree
        heapify(list, n, largest);
    }
}

//������
void heapSort(List *list, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(list, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&list->entry[0].key, &list->entry[i].key);

        // Call max heapify on the reduced heap
        heapify(list, i, 0);
    }
}


//�������
void printList(List *list) {
    int i;
    for (i = 0; i < list->n; i++) {
        cout << list->entry[i].key << " ";
    }
    cout << endl;
}

int main() {
    List list;
    list.n = MAXSIZE;
    for (int i = 0; i < MAXSIZE; i++) {
        Entry entry = {i, "a"};
        list.entry[i] = entry;
    }
    auto start = std::chrono::high_resolution_clock::now();


    selectSort(&list);
    cout << "��ѡ�����������" << endl;
    auto end = std::chrono::high_resolution_clock::now();
    // ���㺯��ִ��ʱ�䣨����Ϊ��λ��
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "����ִ��ʱ��: " << duration.count() << " ����" << std::endl;


    insertSort(&list);
    cout << "ֱ�Ӳ������������" << endl;
    end = std::chrono::high_resolution_clock::now();
    // ���㺯��ִ��ʱ�䣨����Ϊ��λ��
    duration = end - start;
    std::cout << "����ִ��ʱ��: " << duration.count() << " ����" << std::endl;

    bubbleSort(&list);
    cout << "ð�����������" << endl;
    end = std::chrono::high_resolution_clock::now();
    // ���㺯��ִ��ʱ�䣨����Ϊ��λ��
    duration = end - start;
    std::cout << "����ִ��ʱ��: " << duration.count() << " ����" << std::endl;


    quickSort(&list, 0, MAXSIZE / 10);
    cout << "�������������" << endl;
    end = std::chrono::high_resolution_clock::now();
    // ���㺯��ִ��ʱ�䣨����Ϊ��λ��
    duration = end - start;
    std::cout << "����ִ��ʱ��: " << duration.count() << " ����" << std::endl;


    heapSort(&list,MAXSIZE);
    cout << "�����������" << endl;
    end = std::chrono::high_resolution_clock::now(); // ���㺯��ִ��ʱ�䣨����Ϊ��λ��
    duration = end - start;
    std::cout << "����ִ��ʱ��: " << duration.count() << " ����" << std::endl;

    merageSort(&list);
    cout << "�鲢���������" << endl;
    end = std::chrono::high_resolution_clock::now();
    // ���㺯��ִ��ʱ�䣨����Ϊ��λ��
    duration = end - start;
    std::cout << "����ִ��ʱ��: " << duration.count() << " ����" << std::endl;

    return 0;
}
