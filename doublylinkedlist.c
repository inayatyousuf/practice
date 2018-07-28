//implementation of doubly linked list
#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next,*prev;
};
struct node *temp,*tail,*head=NULL;
void create()
{
char c;
do
{
	temp=(struct node *)malloc(sizeof(struct node *));
	printf("Enter data element\n");
	scanf("%d\n",&temp->data);
	temp->prev=temp->next=NULL;
	if(head==NULL)
	{
		head=tail=temp;
	}
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
	printf("Do you want to create another\n");
	c=getche();
printf("\n");	
}while(c=='y');
printf("linked list is\n");
display();
}
void display()
{
temp=head;
while(temp!=NULL)
{
	printf("%d\n",temp->data);
	temp=temp->next;
	
}
}
void sort()
{
	struct node *trar1,*trar2;
	int ptr;
	trar1=head;
	while(trar1->next!=NULL)
	{
		trar2=trar1->next;
		while(trar2!=NULL)
		{
			if(trar1->data>trar2->data)
			{
				ptr=trar1->data;
				trar1->data=trar2->data;
				trar2->data=ptr;
			}
			trar2=trar2->next;
		}
		trar1=trar1->next;
	}
	printf("Linked list in sorted form is \n");
	display();
}
void display_links()
{
	printf("linked list links  are\n");
temp=head;
while(temp!=NULL)
{
	printf("%d\n",temp);
	temp=temp->next;
	
}
}
struct node * reverse(struct node *cur)
{
	struct node *trar=NULL,*nextnode=NULL;
	cur=head;
	while(cur!=NULL)
	{
		trar=cur->next;
		cur->next=nextnode;
		nextnode=cur;
		cur=trar;
	}
		printf("linked list in reverse order is\n");
	return nextnode;
}
void main()
{
		int ch;
	while(1)
	{
		printf("Enter\n 1 for create \n 2  for sort\n 3 for reverse\n 4 for display links\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			create();
		}
		else if(ch==2)
		{
			sort();
		}
		else if(ch==3)
		{
		head=reverse(head);
		display();
		}
		else if(ch==4)
		{
			display_links();
		}
	}
}
