#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct worker{
    char name[10];
    struct worker *right;
}*newptr,*first,*last,*temp,*prev,*next;

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
		newptr->right=NULL;
		if(first==NULL)
		   first=temp=newptr;
		   else
			{
				temp->right=newptr;
				temp=temp->right;
			}
		printf("Want to add more workers To Worker Queue(Y/N)");
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
        printf("There are no workers in Queue!!\n"); 
        return;
    }
    while(temp != NULL) {
        printf("[%s]<---",temp -> name );
        temp = temp-> right ;
    }
	
}


void workerEnqueue(){
	newptr=(struct worker*)malloc(sizeof(struct worker));
	if(newptr==NULL){
		printf("Memory allocation error!!");
		return;
	}
	printf("\nEnter Name of new Worker : ");
	scanf("%s",&newptr->name);
	newptr->right=NULL;
	temp= first;
	while(temp!=NULL){
		last=temp;
		temp=temp->right;
	}
	last->right=newptr;
	newptr->right=NULL;

}

void workerDequeue(){
	if(first==NULL){
		printf("\nThere are no Workers in Queue!!");
	}
	else{
		temp = first;
		first = first -> right;
		free(temp);
		printf("\nFirst Worker Queued Out!!\n");
	}
}

void searchInQueue(){
	char search_name[25];
	int pos ,foundFlag=0;pos=0;
	temp = first;
	printf("\nEnter name of the worker you want to find : ");
	scanf("%s",&search_name);
	while(temp!=NULL){
		pos++;
		if(strcmpi(search_name,temp->name)==0){
			foundFlag =1;
			printf("\nWorker Found at Position %d",pos);
		}
		temp= temp->right;	
	}
	if(foundFlag==0){
		printf("\n\tNo such worker found In Queue!!");
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
	printf(" +------Worker-Queue-Menu------+\n");
	printf(" | 1.Create Workers Queue      |\n");
	printf(" | 2.See Worker Queue          |\n");
	printf(" | 3.Worker Enqueue            |\n");
	printf(" | 4.Worker Dequeue            |\n");
	printf(" | 5.Search In Worker Queue    |\n");
	printf(" | 6.Exit                      |\n");
    printf(" +-----------------------------+\n");
	printf("enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:create();break;
		case 2:peekWorkerQueue();break;
		case 3:workerEnqueue();break;
		case 4:workerDequeue();break;
		case 5:searchInQueue();break;
		case 6:exit_program();
	}
	getch();
 }
 return 0;
}



