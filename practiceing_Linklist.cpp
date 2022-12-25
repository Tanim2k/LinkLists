#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
  	int data;
  	Node *next;

  	Node(int data)
  	{
       this->data=data;
       next=NULL;
  	}
};
Node *head;
void addAtEnd(int data)
{
  Node *temp=new Node(data);
  if(head==NULL)
  {
  	head=temp;
  	return ;
  }
  Node *newnode;
  newnode=head;
  while(newnode->next!=NULL)
  {
  	newnode=newnode->next;
  }
  newnode->next=temp;
}

void addAtBegin(int data)
{
	Node *temp=new Node(data);
	  if(head==NULL)
      {
      	head=temp;
  	    return ;
      }
      temp->next=head;
      head=temp;


}

int length()
{
	Node *temp=head;
	int cnt=0;
	while(temp->next!=NULL)
	{
		++cnt;
		temp=temp->next;
	}
	return cnt+1;
}

void print()
{
	Node *temp=head;

	while(temp->next!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}

void Search(int data)
{
	Node *temp=head;

	while(temp->data!=data && temp->next!=NULL)
	{
		temp=temp->next;
	}
	if(temp->data==data)
		cout<<"Found it"<<endl;
	else
		cout<<"Didnt found"<<endl;
}

void Delete(int data)
{
	Node *temp=head;
     Node *prev=head;
	while(temp->data!=data && temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp->data==data)
	{
		prev->next=temp->next;
	}
}

int cntingN(int n)
{
	int cnt=0;
  Node *temp=head;
	while(temp->next!=NULL)
	{
		if(temp->data==n)
			++cnt;

		temp=temp->next;
	}
	if(temp->data==n)
		++cnt;

	return cnt;
}

int findingmin()
{
	int mini=INT_MAX;
	Node *temp=head;
	while(temp->next!=NULL)
	{
		mini=min(temp->data,mini);
		temp=temp->next;
	}
	mini=min(temp->data,mini);

	return mini;
}

int findingmax()
{
	int maxi=INT_MIN;
	Node *temp=head;
	while(temp->next!=NULL)
	{
		maxi=max(temp->data,maxi);
		temp=temp->next;
	}
	maxi=max(temp->data,maxi);

	return maxi;
}

void convertingCircular()
{
	Node *temp=head;

	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head;
}

void printing()
{
	Node *temp=head;

	while(temp->next!=head)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
}
int main()
{
   addAtEnd(2);
   addAtBegin(1);
   addAtEnd(3);
   addAtEnd(4);
   addAtEnd(3);
   addAtEnd(3);
   addAtEnd(2);
   cout<<length()<<endl;
   print();

   cout<<"3 in linklist ->"<<cntingN(3)<<endl;
   cout<<"2 in linklist ->"<<cntingN(2)<<endl;

   cout<<"Minimum "<<findingmin()<<endl;
   cout<<"Maximum "<<findingmax()<<endl;
   convertingCircular();
   printing();
    

}