#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[10];
    int mark;
    int rollno;
    struct student* right;
} *newptr, *first, *last, *temp, *prev, *next;

int create() {
    char ch;
    while (1) {
        newptr = (struct student*)malloc(sizeof(struct student));
        if (newptr == NULL) {
            printf("Memory allocation error");
            return 0;
        }
        printf("\nEnter Name of student: ");
        scanf("%s", &newptr->name);
        printf("\nEnter the mark (between 0 and 100)of student:");
        scanf("%d",&newptr->mark);
        printf("\nEnter the roll no (positive integer): ");
        scanf("%d",&newptr->rollno);
        newptr->right = NULL;
        if (first == NULL)
            first = temp = last = newptr;
        else {
            temp->right = newptr;
            temp = temp->right;
        }
        printf("Want to add more students? (Y/N): ");
        ch = getch();
        if (ch == 'n' || ch == 'N') {
            temp = first;
            while (temp->right != NULL) {
                temp = temp->right;
                last = temp;
            }
            last->right = first;
            return 0;
        }
    }
}

void display() {
    temp = first;
    if (temp == NULL) {
        printf("There are no students\n");
        return;
    }
    do {
        printf("[Name:%s Mark:%d Rollno:%d ]--->", temp->name,temp->mark,temp->rollno);
        temp = temp->right;
    } while (temp != first);
    printf("[Name:%s Mark:%d Rollno:%d]", last->right->name,last->right->mark,last->right->rollno);
}



void insert_end() {
    newptr = (struct student*)malloc(sizeof(struct student));
    if (newptr == NULL) {
        printf("Memory allocation error");
        return;
    }
  printf("\nEnter Name of student: ");
        scanf("%s", &newptr->name);
        printf("\nEnter the mark (between 0 and 100)of student:");
        scanf("%d",&newptr->mark);
        printf("\nEnter the roll no (positive integer): ");
        scanf("%d",&newptr->rollno);
    newptr->right = NULL;
    last->right = newptr;
    last = newptr;
    last->right = first;
}


void delete_end() {
    if (first == NULL) {
        printf("\nThere are no Students");
        return;
    }
    temp = first;
    while (temp != last) {
        prev = temp;
        temp = temp->right;
    }
    prev->right = NULL;
    last = prev;
    last->right = first;
    printf("\nLast Student deleted\n");
    free(temp);
}

void maxmark() {
	
    int pos;
    int maxmark;
    int rlno;
    pos = 0;
    temp = first;
//    char nm;
//    nm=temp->name;
//    int rlno;
//    rlno=temp->rollno;
    maxmark=temp->mark;
    rlno=temp->rollno;

    do {
        pos++;
        if (maxmark<temp->mark) {
            maxmark=temp->mark;
//            nm=temp->name;
            rlno=temp->rollno;
            
        }
        temp = temp->right;

    } while (temp != first);
    
  printf("Student with roll no:%d got the highest mark %d ", rlno,maxmark);
   
}

void exit_program() {
    temp = first;
    while (temp != NULL) {
        struct student* nextNode = temp->right;
        free(temp);
        temp = nextNode;
    }
    exit(0);
}

int main() {
    int opt;
    opt = 0;
    first = temp = NULL;
    while (1) {
        printf("\n");
        printf(" +----------Menu----------------+\n");
        printf(" | 1. Create Students           |\n");
        printf(" | 2. Display Students          |\n");
        printf(" | 3. Insert Student            |\n");
        printf(" | 4. Delete Student            |\n");
        printf(" | 5. Max mark                  |\n");
        printf(" | 6. Exit                      |\n");
        printf(" +-----------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            maxmark();
            break;       
        case 6:
            exit_program();
        }
      
    }

    return 0;
}
