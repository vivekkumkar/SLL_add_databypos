#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node()
		{
			next=NULL;
		}
		
		Node(int x)
		{
			data=x;
			next=NULL;
		}
};

class SLL
{
	Node *head;;
	public:
		SLL()
		{
			head=NULL;
		}
		
		void createList();
		void show();
		void addbypos(int pos,int x);
		int count();
};

int main()
{
	SLL obj1;
	cout<<"Enter List"<<endl;
	obj1.createList();
	cout<<"\nShowing List: "<<endl;
	obj1.show();  
	                   
	int x,pos;
	cout<<"\n Enter position to add data : ";
	cin>>pos;
	cout<<"\n Enter data to by position : ";
	cin>>x;
	obj1.addbypos(pos,x);
	cout<<"\n List after addbypos : ";
	obj1.show();
	
}


void SLL::createList()
{
	int n,x;
	cout<<"\n Enter number of nodes : ";
	cin>>n;
	if(n==0)
	{
		return;
	}
	cout<<"\n Enter data : ";
	cin>>x;
	
	head=new Node(x);
	Node *p;
	p=head;
	
	for(int i=1;i<=n-1;i++)
	{
		cout<<"\n Enter data : ";
		cin>>x;
		p->next=new Node(x);
		p=p->next;
	}
}

void SLL::show()
{
	if(head==NULL)
	{
		cout<<"\n List is Empty ";
		return;
	}
	Node *p;
	p=head;
	
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
}

int SLL::count()
{
	Node *p;
	p=head;
	int c=0;
	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}

void SLL::addbypos(int pos,int x)
{
	int c;
	c=count();
	if(pos<1 || pos>c+1)
	{
		cout<<"\n Invalid Position ";
		return;
	}
	Node *p;
	p=new Node(x);
	if(pos==1)
	{
		p->next=head;
		head=p;
	}
	else
	{
		Node *q;
		q=head;
		for(int i=1;i<pos-1;i++)
		{
			q=q->next;
		}
		p->next=q->next;
		q->next=p;
	}
}
