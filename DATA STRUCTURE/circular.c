#include<stdio.h>
#include<stdlib.h>
struct st
    {
    int roll;
    char name[20];
    float mark;
    struct st *next;
    };
void print(struct st *);
void addend(struct st **);
void rev_print(struct st *,struct st *,int );
int count(struct st *);
int main()
{
    struct st *hptr=0;	
    char ch;
    do
    {
    addend(&hptr);
    printf("Do you want one more data\n");    
    scanf(" %c",&ch);

    }while(ch=='y');

   printf("Printing all Datas\n"); 
   print(hptr);

   printf("After reverse All Data\n");
   rev_print(hptr,hptr,0);

}
void addend(struct st **ptr)
{
   printf("printing all datas\n");	
   struct st *temp=(struct st *)malloc(sizeof(struct st));
   scanf("%d %s %f",&temp->roll,temp->name,&temp->mark);

   if(*ptr==0)
   {
   temp->next=temp;
   *ptr=temp;
   }

   else
   {
    struct st*last=*ptr;
    while(last->next!=*ptr)
    last=last->next;

    temp->next=last->next;
    last->next=temp;   
   }

}
void print(struct st *ptr)
{

   struct st *temp=ptr;	
printf("Printing all datas\n");

   do
   {
   printf("%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
   ptr=ptr->next;
     
   }while(ptr!=temp);
 	

}
void rev_print(struct st *ptr,struct st *ptr1,int i)
{
	if(i!=0 && ptr->roll==ptr1->roll)
	{
		return ;
	}
        rev_print(ptr->next,ptr1,1);
        printf("%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
  	    
  
 // printf("Condition fail\n");
  
}
int count(struct st *ptr)
{
  struct st *temp=ptr;
  int c=0;
  do
  {
   c++;
  }while(temp!=ptr);

  return c;

}
//void rev_data(struct st)
