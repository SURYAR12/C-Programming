#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st
{
	struct st *prev;
	int roll;
	char name[20];
	float mark;
	struct st *next; 
};
void addend(struct st **);
void print(struct st *);
void rev_print(struct st *);
int count(struct st *);
void rev_data(struct st *);
void rev_link(struct st **);
int main()
{
	struct st * hptr=0;
	char ch;
	do
	{
		addend(&hptr);
		printf("Do you want one more \n");
		scanf(" %c",&ch);   
	}while((ch=='y')||(ch=='Y'));

	printf("all data\n");
	print(hptr);

	rev_print(hptr);

	rev_data(hptr);
	print(hptr);

	rev_link(&hptr);
	print(hptr);


}
void addend(struct st **ptr)
{	
	struct st *temp=(struct st*)malloc(sizeof(struct st));
	printf("Assign one more data\n");
	scanf("%d %s %f",&temp->roll,temp->name,&temp->mark);

	if(*ptr == 0)
	{
		temp->prev = 0;
		temp->next = 0;
		*ptr = temp;
	}
	else
	{
		struct st *last = *ptr;
		while(last->next != 0)
			last = last->next;

		temp->prev = last;
		temp->next = last->next;
		last->next = temp;	
	}
}
void print(struct st *ptr)
{
	while(ptr!=0)
	{
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;
	}

}
void rev_print(struct st *ptr)
{
	printf("Reverse Printing\n");	
	while(ptr->next!=0)	  
		ptr=ptr->next;

	while(ptr!=0)
	{
		printf("%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->prev;
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

	int i,c=count(ptr);
	int size=sizeof(struct st)-16;
	struct st temp;

	struct st *p1,*p2;
	p1=ptr;
	p2=ptr;

	printf("reverse data printing\n");  
	for(i=0;i<c;i++)
	{
		p2=ptr->next; 
	}


	for(i=0;i<c/2;i++)
	{
		memcpy(&temp.roll,&p1->roll,size);
		memcpy(&p1->roll,&p2->roll,size);
		memcpy(&p2->roll,&temp.roll,size);

		p1=p1->next;
		p2=p2->next;
	}


}
void rev_link(struct st **ptr)
{
	struct st *temp;
 
	printf("reverse link data\n");
	while(*ptr!=0)
	{
		temp=(*ptr)->prev;
		(*ptr)->prev=(*ptr)->next;
		(*ptr)->next=temp;

		(*ptr)=(*ptr)->prev;
	}
	(*ptr)=temp->prev; 

}
