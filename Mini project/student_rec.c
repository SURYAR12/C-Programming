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
void file(struct st *ptr);
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
		printf("| f/f	: Save FILE             |\n");
		printf("| E/e	: Exit                  |\n");
		printf("| T/t	: Sort the List         |\n");
		printf("| L/l	: Delete All the Records|\n");
		printf("| R/r	: Reverse the List	|\n");
		printf("+--------+----------------------+\n");
	}
	char op,u;
	while(1)
	{

	printf("which operation want you ?\n");
	printf("optional like <-----> a/d/s/e/l/r/t/f \n");

	scanf(" %c",&op);
		switch(op)
		{
			case'a':
				do {
					add_end(&hptr);
					printf("do you want one more data --> if you want write 'y'\n");
					scanf(" %c",&ch);
				}while((ch=='y')||(ch=='Y'));
			
				break;

			case'd':
					printf("+-------------------------------+\n");
					printf("|                               |\n");
		            printf("| Delete Particular A Record    |\n");
        	        printf("+-------------------------------+\n");
                scanf("%d",&d); 
				delete_node(&hptr,d);
				printf("After free the space\n");
				print(hptr);
				break;
			    

			case's':
			    	printf("+-------------------------------+\n");
					printf("|                               |\n");
		            printf("|         Student  List         |\n");
        	        printf("+-------------------------------+\n\n");
	             
				print(hptr);
			    break;
			    			
			case'l':
				    printf("+-------------------------------+\n");
					printf("|                               |\n");
		            printf("|     Delete All List           |\n");
        	        printf("+-------------------------------+\n");
		 		    
            	removeAll_node(&hptr);
				print(hptr);
				break;
			   

			case'r':
			        printf("+-------------------------------+\n");
					printf("|                               |\n");
		            printf("|       Reverse The data        |\n");
        	        printf("+-------------------------------+\n\n");
				rev_data(hptr);
				print(hptr);
				break;
			case't':
			    	printf("+-------------------------------+\n");
					printf("|                               |\n");
		            printf("|     Sort with percentage      |\n");
        	        printf("+-------------------------------+\n");
			   
			   
			    sort(hptr);
				print(hptr);
				break;
			   
			case'f':
				    printf("+-------------------------------+\n");
					printf("|                               |\n");
		            printf("|  Successfully saved Into File |\n");
        	        printf("+-------------------------------+\n");
				file(hptr);
				break;
				
			case'e':
			        printf("+-------------------------------+\n");
					printf("|                               |\n");
		            printf("|         Exit                  |\n");
        	        printf("+-------------------------------+\n");
				return 0; 		

		//	default:printf("In valid characters\n");

}		}   
	}
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

        printf("+---------------------+\n");
        printf("| R.No | Name | Mark  |\n");
        printf("+---------------------+\n"); 
				
	while(ptr!=0)
	{
		
		printf("|  %d     %s     %2.f   |\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;

	}
	    printf("+---------------------+\n");
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

  
	while(temp!=0)
	{

		if(temp->roll==n)
		{
			if(temp==*ptr)
				*ptr=temp->next;

			else
				prev->next=temp->next;

			free(temp);
			return;
			printf("Deleted successfully\n");
		}

		else
		{
			prev=temp;	   
			temp=temp->next;      
		}	   
	} 
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
void file(struct st *ptr)
{
	FILE *fp=fopen("student record","w");

	while(ptr!=0)
	{
	fprintf(fp,"%d %s %f\n",ptr->roll,ptr->name,ptr->mark);
		ptr=ptr->next;
	}

}
