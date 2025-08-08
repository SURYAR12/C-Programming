#include<stdio.h>
struct st
{
  int roll;
  int mark;
  char n[100];
  struct st *next;
};
void addbegin();
void print();
struct st *hptr=0;
int main()
{
  char ch;	
  do
  {	  	
   addbegin();
   scanf("%c",&ch);
   printf("add one more data");
  }while((ch=='y')||(ch=='Y'));

  print(hptr);   
   

}
void addbegin()
{
   struct st *temp=(struct st*)malloc(sizeof(struct st));	
   scanf("%d %d %s",&(temp)->roll,&(temp)->mark,&(temp)->n);
   temp->next=hptr;
   hptr=temp;   

}
void print()
{
  struct st *ptr=hptr;	
  printf("printing the  data");
  while(ptr!=0)
  {
  printf("%d %d %s",ptr->roll,ptr->mark,ptr->n);
  ptr=ptr->next;
  }
}
