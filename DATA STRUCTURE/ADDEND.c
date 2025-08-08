#include<stdio.h>
#include<stdlib.h>
struct st
  {
    int roll;
    char name[20];
    float mark;
   struct st*next; 
  };
void add_end(struct st **);
void print(struct st *);
void rev(struct st *);
int main()
{
  struct st *hptr=0;

  char ch;
  do
  {
   add_end(&hptr);
   printf("Do You want another one node :\n");
   scanf(" %c",&ch);
  }while((ch=='y')||(ch=='Y'));


  print(hptr);

  rev(hptr);
}
void add_end(struct st **ptr)
{
  struct st *temp=(struct st *)malloc(sizeof(struct st));

  printf("data are assigned \n");
  scanf("%d %s %f",&temp->roll,temp->name,&temp->mark);

  if(*ptr==0)
  {
    temp->next=*ptr;	  
    *ptr=temp;	  
  }
  else
  {
     struct st *last=*ptr;

  while(last->next!=0)
  last =last->next;

  temp->next=last->next;
  last->next=temp;      
  }
}
void print(struct st *ptr)
{
   printf("printing the data\n ");
   
   while(ptr!=0)
   {
   printf("%d %s %f\n",ptr->roll,ptr->name,ptr->mark);

   ptr=ptr->next;     
   }
}
void rev(struct st *ptr)
{
   if(ptr!=0)
   {
   rev(ptr->next);
   printf("this is reverse order\n");
   printf("%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
   }

}
