///  addend reverse the data ////


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st
{
	int roll;
	char name[20];
	float mark;
	struct st *next; 
}; 
void print(struct st *);
void add_end(struct st **);
void rev_data(struct st *);
int count(struct st *);
void removeAll_node(struct st **);
void delete_node(struct st **,int);
void sort (struct st *ptr);
int main()
{
	struct st *hptr=0;	
	char ch;
	int i,d;

	for(i=0;i<1;i++)
	{
		printf("+--------+----------------------+\n");
		printf("| A/a	: Add New Record        |\n");
		printf("| D/d	: Delete A Record       |\n");
		printf("| S/s	: Show the List         |\n");
		printf("| M/m	: Modify A record       |\n");
		printf("| V/v	: Save                  |\n");
		printf("| E/e	: Exit                  |\n");
		printf("| T/t	: Sort the List         |\n");
		printf("| L/l	: Delete All the Records|\n");
		printf("| R/r	: Reverse the List	|\n");
		printf("+--------+----------------------+\n");
	}
	char op;
	while(1)
	{

	printf("which operation want you ?\n");
	printf("optional like <-----> a/d/s/e/l/r/t \n");

	scanf(" %c",&op);
		switch(op)
		{
			case'a':
				do {
					add_end(&hptr);
					printf("do you want one more data --> if you want write 'y'\n");
					scanf(" %c",&ch);
				}while((ch=='y')||(ch=='Y'));
				//printf("all Student Records\n");
                               // print(hptr);
				break;

			case'd':
				printf("Enter the particular record num --> \n");
                                scanf("%d",&d); 
				delete_node(&hptr,d);
				printf("After free the space\n");
				print(hptr);
				break;

			case's':
				printf("all Student Records\n");
				print(hptr);
			//	printf("clear The all Data\n");
				break;

				/*   case'm':
				     case'v':
				     case'e':
				     case't':*/

			case'l':

				removeAll_node(&hptr);
				print(hptr);
				break;

			case'r':	
				rev_data(hptr);
				print(hptr);
				break;
			case't':	
				sort(hptr);
				print(hptr);
				break;	
			case'e':
				return 0; 		

		//	default:printf("In valid characters\n");

		}   
	}}
void add_end(struct st **ptr)
{
	struct st *temp=(struct st*)malloc(sizeof(struct st));
	printf("assign the data\n");
	scanf("%d %s %f",&temp->roll,temp->name,&temp->mark);

	if(*ptr==0)
	{
		temp->next=*ptr;
		*ptr=temp;
	}

	else
	{
		struct st*last=*ptr;
		while(last->next!=0)
			last=last->next;

		temp->next=last->next;
		last->next=temp;
	}

}
void print(struct st *ptr)
{
	printf("printing the data\n");

	while(ptr!=0)
	{
		printf("%d %s %f\n ",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;

	}
}
int count(struct st *ptr)
{
	int c=0;	
	while(ptr!=0)
	{
		c++;
		ptr=ptr->next;
	}

	return c; 

}
void rev_data(struct st *ptr)
{
	int c=count(ptr);

        printf("After Reverse the Data\n");
	int size=sizeof(struct st)-8;
	struct st **p=(struct st**)malloc(c*sizeof(struct st*));

	int i,j;

	for(i=0;i<c;i++)
	{
		p[i]=ptr;
		ptr=ptr->next;  
	}

	struct st temp;

	for(i=0,j=c-1;i<j;i++,j--)
	{
		memcpy(&temp,p[i],size);
		memcpy(p[i],p[j],size);
		memcpy(p[j],&temp,size);
	}

}
//        remove all nodes ///////////

void removeAll_node(struct st **ptr)
{
	struct st *temp;
        
        printf("Deleting All Record\n"); 
	while(*ptr!=0)
	{
		temp=*ptr;	  	  
		*ptr=temp->next;
		free(temp);  
	}
}
void delete_node(struct st **ptr,int n)
{
	struct st *temp=*ptr;
	struct st *prev;

        printf("Delete particular Record\n");
	while(temp!=0)
	{

		if(temp->mark==n)
		{
			if(temp==*ptr)
				*ptr=temp->next;

			else
				prev->next=temp->next;

			free(temp);
			return;
		}

		else
		{
			prev=temp;	   
			temp=temp->next;      
		}	   
	} 
	printf("no node are mathching\n");
}

void sort(struct st *ptr)
{
    int c = count(ptr);
    int size = sizeof(struct st);
    struct st **p = (struct st **)malloc(c * sizeof(struct st *));
    int i, j;

    // Store node addresses
    for (i = 0; i < c; i++)
    {
        p[i] = ptr;
        ptr = ptr->next;
    }

    struct st temp;

        for (i = 0; i < c - 1; i++)
    {
        if (p[i]->roll > p[i + 1]->roll)
        {
            memcpy(&temp, p[i], size);
            memcpy(p[i], p[i + 1], size);
            memcpy(p[i + 1], &temp, size);
        }
    }
}
