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
		   first=temp=last=newptr;
		   else
			{
				temp->right=newptr;
				temp=temp->right;
			}
		printf("Want to add more workers(Y/N)?");
		ch=getch();
		if(ch=='n'||ch=='N')
         {
			temp=first;
			while(temp->right!=NULL)
			{
				temp=temp->right;
				last=temp;
			}	
			last->right= first; 
			return(0);
		 }
  }
	     
}


void peekWorkerQueue(){
    temp= first;
    if(temp==NULL){
        printf("There are no workers In Queue!!\n"); 
        return;
    }
	do{
		printf("[%s]<---",temp -> name );
        temp = temp-> right ;
	}while(temp!=first);
	printf("(%s)",last->right->name);
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
	last->right=newptr;
    last=newptr;
    last->right=first;

}

void workerDequeue(){
	if(first==NULL){
		printf("\nThere are no Workers in Queue");
	}
	else{
		temp = first;
		first = first -> right;
		last->right=first;
		free(temp);
		printf("\nFirst Worker Queued Out!!\n");


	}
}


void searchWorkerQueue(){
	char search_name[25];
	int pos ,foundFlag=0;pos=0;
	temp = first;
	printf("\nEnter name of the worker you want to find : ");
	scanf("%s",&search_name);

	do{
		pos++;
		if(strcmpi(search_name,temp->name)==0){
			foundFlag =1;
			printf("\nWorker Found at Position %d",pos);
			break;
		}
		temp= temp->right;

	}while(temp!=first);

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
	printf(" +-Worker-Circular--Queue-Menu-+\n");
	printf(" | 1.Create Workers            |\n");
	printf(" | 2.Peek Worker Queue         |\n");
	printf(" | 3.Worker Enqueue            |\n");
	printf(" | 4.Worker Dequeue            |\n");
	printf(" | 5.Search In Worker Queue    |\n");
	printf(" | 6.Exit                      |\n");
    printf(" +-----------------------------+\n");
	printf("Enter your option : ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:create();break;
		case 2:peekWorkerQueue();break;
		case 3:workerEnqueue();break;
		case 4:workerDequeue();break;
		case 5:searchWorkerQueue();break;
		case 6:exit_program();
	}
	getch();
 }
 return 0;
}

