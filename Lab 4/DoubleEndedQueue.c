#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct worker{
    char name[10];
    struct worker *right;
}*newptr,*first,*last,*temp,*prev,*next;

int numberOfNodes=0;


int create(){
    char ch;
	while(1)
	{
		newptr=(struct worker*) malloc(sizeof(struct worker));
		if(newptr==NULL){
				printf("Memory allocation error!!");
				return 0;
			}
		printf("\nEnter Name of worker : ");
		scanf("%s",&newptr->name);
		numberOfNodes++;
		newptr->right=NULL;
		if(first==NULL)
		   first=temp=newptr;
		   else
			{
				temp->right=newptr;
				temp=temp->right;
			}
		printf("Want to add more workers(Y/N)?");
		ch=getch();
		if(ch=='n'||ch=='N')
         return(0);	
	temp=first;
	while(temp->right!=NULL)
	{
		temp=temp->right;
		last=temp;
	}	      
  }
}


void peekWorkerQueue(){
    temp= first;
    if(temp==NULL){
        printf("There are no workers!!\n"); 
        return;
    }
    while(temp != NULL) {
        printf("[%s]<---",temp -> name );
        temp = temp-> right ;
    }
}


void enqueueFront(){
	newptr = (struct worker *)malloc( sizeof( struct worker ) );
	if(newptr==NULL){
		printf("Memory allocation error");
		return;
	}
	printf("\nEnter Name of new Worker : ");
	scanf("%s",&newptr->name);
	numberOfNodes++;
	newptr->right=NULL;
	if(first == NULL)
	{
		first=last=newptr;
    }
	else
	{
		newptr->right=first;
		first=newptr;
	}
}

void enqueueRear(){
	newptr=(struct worker*)malloc(sizeof(struct worker));
	if(newptr==NULL){
		printf("Memory allocation error");
		return;
	}
	printf("\nEnter Name of new Worker : ");
	scanf("%s",&newptr->name);
	numberOfNodes++;
	newptr->right=NULL;
	temp= first;
	while(temp!=NULL){
		last=temp;
		temp=temp->right;
	}
	last->right=newptr;
	newptr->right=NULL;
}


void dequeueFront(){
	if(first==NULL){
		printf("\nThere are no Workers");
	}
	else{
		temp = first;
		first = first -> right;
		free(temp);
		numberOfNodes--;
		printf("\nFirst Worker deleted\n");


	}
}

void dequeueRear(){
	if(first==NULL){
		printf("\nThere are no Workers !!");
		return;
	}
	temp=first;
	while(temp->right!=NULL)
	{
		prev=temp;
		temp=temp->right;
		last=temp;
	}	     
	prev->right=NULL;
	last=prev;
    printf("\nLast Worker Queued Out!!\n");
	numberOfNodes--;
	free(temp);
}

void searchWorkerQueue(){
	char search_name[25];
	int pos ,foundFlag=0;pos=0;
	temp = first;
	printf("\nEnter name of the worker you want to find : ");
	scanf("%s",&search_name);
	while(temp!=NULL){
		pos++;
		if(strcmpi(search_name,temp->name)==0){
			foundFlag =1;
			printf("\nWorker Found at %d",pos);
		}
		temp= temp->right;	
	}
	if(foundFlag==0){
		printf("\n\tNo such worker found!");
	}
}

void exit_program(){
    temp = first;
    while (temp != NULL) {
        struct worker* nextNode = temp->right;
        free(temp);
        temp = nextNode;
    }
	exit(0);
}


int main()
{
	int opt;
	opt=0;
	first=temp=NULL;
	while(1)
 {
    printf("\n");
	printf(" +---------Worker-Menu---------+\n");
	printf(" | 1.Create Worker Queue       |\n");
	printf(" | 2.Display Worker Queue      |\n");
	printf(" | 3.Worker Enqueue Front      |\n");
	printf(" | 4.Worker Enqueue Rear       |\n");
	printf(" | 5.Worker Dequeue Front      |\n");
	printf(" | 6.Worker Dequeue Rear       |\n");
	printf(" | 7.Search Worker             |\n");
	printf(" | 8.Exit                      |\n");
    printf(" +-----------------------------+\n");
	printf("enter your option : ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:create();break;
        case 2:peekWorkerQueue();break;
		case 3:enqueueFront();break;
		case 4:enqueueRear();break;
		case 5:dequeueFront();break;
		case 6:dequeueRear();break;
		case 7:searchWorkerQueue();break;
		case 8:exit_program();
	}
	getch();
 }
 return 0;
}

