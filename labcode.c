#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char usn[10];
    char name[10];
    struct Node *next, *prev;
} st;

st *head = NULL, *temp = NULL, *pre = NULL;

void insert(char u[], char sname[]) {
    st *nn = (st *)malloc(sizeof(st));
    if (nn == NULL) {
        printf("Memory allocation failed");
        return;
    }
    strcpy(nn->usn, u);
    strcpy(nn->name, sname);
    nn->next = NULL;
    nn->prev = NULL;
    if (head == NULL) {
        head = nn;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
        nn->prev = temp;
    }
}


void delete(char u[]) {
    if (head == NULL) {
        printf("List is Empty");
        return;
    } else if (head->next == NULL) {
        if (strcmp(head->usn, u) == 0) {
            temp = head;
            free(head);
            head = NULL;
        } else {
            printf("USN %s NOT FOUND", u);
        }
    } else {
        temp = head;
        int f = 0;
        while (temp != NULL) {
            if (strcmp(temp->usn, u) == 0) {
                f = 1;
                break;
            }
            temp = temp->next;
        }
        if (f == 1) {
            if (temp == head) {
                head = temp->next;
                free(temp);
            } else {
                temp->prev->next = temp->next;
                free(temp);
            }
        } else
            printf("USN %s NOT FOUND", u);
    }
}
void deleteNodesStartingWithA() {
    temp = head;
    while (temp != NULL) {
        if (temp->name[0] == 'a' || temp->name[0] == 'A') {
            if (temp == head) {
                head = temp->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
                free(temp);
                temp = head;
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
                st *toDelete = temp;
                temp = temp->next;
                free(toDelete);
            }
        } else {
            temp = temp->next;
        }
    }
}

void display() {
    temp = head;
    while (temp != NULL) {
        printf(" (%s,%s) ", temp->usn, temp->name);
        temp = temp->next;
    }
}

int main() {
    int ch;
    char u[10], sname[10];
    printf("Menu:\n1.Insert\n2.Delete\n3.Display\n4.delete name starting with a\n5.exit");

    while (1) {
        printf("\nEnter Your choice:");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter usn ");
                scanf("%s", u);
                 printf("Enter name ");
                scanf("%s", sname);
                insert(u, sname);
                break;
            case 2:
                printf("Enter USN to delete:");
                scanf("%s", u);
                delete(u);
                break;
            case 3:
                display();
                break;
            case 4: deleteNodesStartingWithA();break;
            case 5:
                exit(0);
        }
    }

    return 0;
}
