#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int Position;

typedef struct NodeTag {
    ElementType data;
    struct NodeTag *next;
} Node;

typedef Node* List;
typedef Node* PNode;

#define MAX_SIZE 100 

void makeNull(List *L) {
    *L = NULL;
}

int len(List L) {
    int length = 0;
    PNode temp = L;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

int empty(List L) {
    return (L == NULL);
}

int fullList(List L) {
    return (len(L) >= MAX_SIZE);
}

void print(List L) {
    PNode temp = L;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

ElementType getAt(Position p, List L) {
    PNode temp = L;
    for (Position i = 0; i < p; i++) {
        if (temp == NULL) {
            printf("out of position\n");
            exit(1);
        }
        temp = temp->next;
    }
    return temp->data;
}

PNode getPosition(Position p, List L) {
    PNode temp = L;
    for (Position i = 0; i < p; i++) {
        if (temp == NULL) {
            printf("out of position\n");
            exit(1);
        }
        temp = temp->next;
    }
    return temp;
}

PNode first(List L) {
    return L;
}

PNode end(List L) {
    PNode temp = L;
    if (temp == NULL) return NULL;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

void setAt(Position p, ElementType x, List *L) {
    PNode temp = getPosition(p, *L);
    temp->data = x;
}

void insertAt(Position p, ElementType x, List *L) {
    if (p == 0) {
        insertFirst(x, L);
        return;
    }

    if (fullList(*L)) {
        printf("full list\n");
        return;
    }

    PNode newNode = (PNode)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("can't alloctae'\n");
        exit(1);
    }

    newNode->data = x;

    PNode prev = getPosition(p - 1, *L);
    newNode->next = prev->next;
    prev->next = newNode;
}

ElementType popAt(Position p, List *L) {
    if (p == 0) {
        return popFirst(L);
    }

    PNode prev = getPosition(p - 1, *L);
    PNode toDelete = prev->next;
    ElementType value = toDelete->data;
    prev->next = toDelete->next;
    free(toDelete);
    return value;
}

void insertFirst(ElementType x, List *L) {
    if (fullList(*L)) {
        printf("full list\n");
        return;
    }

    PNode newNode = (PNode)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("can't allocate'\n");
        exit(1);
    }

    newNode->data = x;
    newNode->next = *L;
    *L = newNode;
}

ElementType popFirst(List *L) {
    if (*L == NULL) {
        printf("empty list\n");
        exit(1);
    }
    PNode toDelete = *L;
    ElementType value = toDelete->data;
    *L = toDelete->next;
    free(toDelete);
    return value;
}

void append(ElementType x, List *L) {
    if (fullList(*L)) {
        printf("full list\n");
        return;
    }

    if (*L == NULL) {
        insertFirst(x, L);
        return;
    }
    PNode newNode = (PNode)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("can't allocate'\n");
        exit(1);
    }

    newNode->data = x;
    newNode->next = NULL;

    PNode temp = *L;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

ElementType popLast(List *L) {
    if (*L == NULL) {
        printf("empty list\n");
        exit(1);
    }

    if ((*L)->next == NULL) {
        return popFirst(L);
    }

    PNode temp = *L;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    PNode toDelete = temp->next;
    ElementType value = toDelete->data;
    temp->next = NULL;
    free(toDelete);
    return value;
}

Position locate(ElementType x, List L) {
    Position pos = 0;
    PNode temp = L;
    while (temp != NULL) {
        if (temp->data == x) {
            return pos;
        }
        pos++;
        temp = temp->next;
    }
    return -1; 
}

PNode next(Position p, List L) {
    PNode node = getPosition(p, L);
    return node->next;
}

PNode previous(Position p, List L) {
    if (p == 0) return NULL;
    PNode node = L;
    for (Position i = 0; i < p - 1; i++) {
        node = node->next;
    }
    return node;
}
