    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    struct worker {
        char name[10];
        int priority;
        struct worker* next;
    };

    struct worker* front = NULL;

    void workerEnqueue() {
        struct worker* newptr = (struct worker*)malloc(sizeof(struct worker));
        if (newptr == NULL) {
            printf("Memory allocation error!!");
            return;
        }

        printf("\nEnter Name of new Worker: ");
        scanf("%s", newptr->name);

        printf("Enter Priority of new Worker: ");
        scanf("%d", &newptr->priority);

        newptr->next = NULL;

        if (front == NULL || newptr->priority < front->priority) {
            newptr->next = front;
            front = newptr;
        } else {
            struct worker* temp = front;
            while (temp->next != NULL && temp->next->priority <= newptr->priority) {
                temp = temp->next;
            }
            newptr->next = temp->next;
            temp->next = newptr;
        }

        printf("\nWorker Enqueued with Priority %d!\n", newptr->priority);
    }

    void workerDequeue() {
        if (front == NULL) {
            printf("\nThere are no Workers in the Priority Queue!\n");
        } else {
            struct worker* temp = front;
            front = front->next;
            free(temp);
            printf("\nHighest Priority Worker Dequeued!\n");
        }
    }

    void peekPriorityQueue() {
        struct worker* temp = front;

        if (temp == NULL) {
            printf("Priority Queue is Empty!\n");
            return;
        }

        printf("Priority Queue: ");
        while (temp != NULL) {
            printf("[%s, Priority: %d] <-- ", temp->name, temp->priority);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    int main() {
        int opt;

        while (1) {
            printf("\n");
            printf(" +-------Priority-Queue-Menu-------+\n");
            printf(" | 1. Enqueue Worker with Priority |\n");
            printf(" | 2. Dequeue Highest Priority     |\n");
            printf(" | 3. Display Priority Queue       |\n");
            printf(" | 4. Exit                         |\n");
            printf(" +---------------------------------+\n");
            printf("Enter your option : ");
            scanf("%d", &opt);

            switch (opt) {
                case 1:
                    workerEnqueue();
                    break;
                case 2:
                    workerDequeue();
                    break;
                case 3:
                    peekPriorityQueue();
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Invalid Option! Please try again.\n");
            }
        }

        return 0;
    }
