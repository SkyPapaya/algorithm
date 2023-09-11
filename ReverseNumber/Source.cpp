#include<stdio.h>
#include<stdlib.h>

int sum = -2;

int spaceOfNum(int target) {
    int sum = 0;
    while (target >= 1) {
        target /= 10;
        sum++;
    }
    return sum;
}

int* transformNum(int target, int* cap) {
    int summary = 0;
    int index = spaceOfNum(target) - 1;
    while (target >= 1) {
        cap[index - summary] = target % 10;
        target /= 10;
        summary++;
    }
    cap = (int*)malloc(sizeof(int) * summary);
    return cap;
}

void reverseNumber(int* source, int* tem, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    reverseNumber(source, tem, left, mid);
    reverseNumber(source, tem, mid + 1, right);

    int begin1 = left, end1 = mid;
    int begin2 = mid + 1, end2 = right;
    int index = begin1;

    while (begin1 <= end1 && begin2 <= end2) {
        if (source[begin1] <= source[begin2]) {
            tem[index] = source[begin1];
            begin1++;
            sum++;
            index++;
        }
        else {
            tem[index] = source[begin2];
            begin2++;
            index++;
            sum++;
        }
    }

    while (begin1 <= end1) {
        tem[index] = source[begin1];
        begin1++;
        index++;
        sum++;
    }

    while (begin2 <= end2) {
        tem[index] = source[begin2];
        begin2++;
        index++;
        sum++;
    }

    for (int i = left; i <= right; i++) {
        source[i] = tem[i];
    }
}

int main() {
    int target;
    printf("请输入要判断的数据\n");
    scanf_s("%d", &target);
    int* source = (int*)malloc(sizeof(int) * spaceOfNum(target));
    int* temp = (int*)malloc(sizeof(int) * spaceOfNum(target));

    transformNum(target, source);

    reverseNumber(source, temp, 0, spaceOfNum(target) - 1);

    if (sum == -2) {
        return 0;
    }
    printf("逆序数对对数为：%d\n", sum);
    for (int i = 0; i < spaceOfNum(target); i++) {
        printf("%d", source[i]);
    }

    

    return 0;
}