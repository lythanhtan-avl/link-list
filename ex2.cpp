#include <stdio.h>
#include "plistlib.h"
void appendList(int a[], int n, List *L) {
    makeNull(L);
    for (int i = 0; i < n; i++) {
        append(a[i], L);
    }
}

void reverseList(int a[], int n, List *L) {
    makeNull(L);
    for (int i = n - 1; i >= 0; i--) {
        insertFirst(a[i], L);
    }
}

void bubbleSort(List *L) {
    int swapped;
    PNode p1, p2;
    if (*L == NULL) return;

    do {
        swapped = 0;
        p1 = *L;
        while (p1->next != NULL) {
            p2 = p1->next;
            if (p1->data > p2->data) {
                ElementType temp = p1->data;
                p1->data = p2->data;
                p2->data = temp;
                swapped = 1;
            }
            p1 = p1->next;
        }
    } while (swapped);
}

int main(int argc, char *argv[]) {
    List L1;
    int a[] = {32, 51, 27, 83, 66, 11, 45, 75};
    appendList(a, sizeof(a) / sizeof(int), &L1);
    print(L1);
    reverseList(a, sizeof(a) / sizeof(int), &L1);
    print(L1);
    insertAt(3, 22, &L1);
    print(L1);
    bubbleSort(&L1);
    print(L1);

    return 0;
}
