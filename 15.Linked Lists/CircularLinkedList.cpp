#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int data){
			this->data = data;
		}
};

void push(node *&head,int data)
{
	node* ptr = new node(data);
	node* temp = head;
	ptr->next = head;
	if(head==NULL)
	{
		ptr->next = ptr;
		head = ptr;
		return;
	}
	
	while(temp->next!=head)
	{
		temp = temp->next;
	}
	temp->next = ptr;
	head = ptr;
	return;
}

node* getNode(node* head,int data)
{
	if(head==NULL)
	{
		return NULL;
	}
	node* temp = head;
	while(temp->next!=head)
	{
		if(temp->data==data)
		{
			return temp;
		}
		temp = temp->next;
	}
	if(temp->data==data)
	{
		return temp;
	}
	return NULL;
}

void deleteNode(node *&head,int data)
{
	node* del = getNode(head,data);
	if(del==NULL)
	{
		cout<<"Node is not present in the linked list"<<endl;
		return;
	}
	
	if(del==head)
	{
		head = del->next;
	}	
	node* temp = head;
	while(temp->next!=del)
	{
		temp = temp->next;
	}
	temp->next = del->next;
	delete del;
	return;
	
}

void printList(node *head)
{
	node* temp = head;
	while(temp->next!=head)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<" ";
	cout<<endl;
	return;
}

int main()
{
	node* head = NULL;
	push(head,6);
	push(head,5);
	push(head,4);
	push(head,3);
	push(head,2);
	push(head,1);
	printList(head);
	deleteNode(head,1);
	printList(head);
	return 0;
}
