#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node* start = NULL;

void insert_at_beginning(int value)
{
	struct node* ptr = start;
	struct node* newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	if(start==NULL)
	{
		start = newnode;
		return;
	}
	newnode->next = start;
	start = newnode;
	return;
}

void insert_at_end(int value)
{
	struct node* ptr = start;
	struct node* newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	if(start==NULL)
	{
		start = newnode;
		return;
	}
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = newnode;
	return;
}

void insert_at_position(int value,int position)
{
	struct node* ptr = start;
	struct node* newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	if(position<0)
	{
		cout<<"Invalid Position"<<endl;
		return;
	}
	if(start==NULL)
	{
		start = newnode;
		return;
	}
	if(position==0)
	{
		newnode->next = ptr;
		start = newnode;
		return;
	}
	for(int i=1;i<position;i++)
	{
		ptr=ptr->next;
		if(ptr==NULL)
		{
			cout<<"Invalid Position"<<endl;
			return;
		}
	}
	newnode->next = ptr->next;
	ptr->next = newnode;
}

//Only for Sorted Linked List
void insert_by_value(int value)
{
	struct node* ptr = start;
	struct node* newnode = new node;
	newnode->data = value;
	newnode->next = NULL;
	
	if(start==NULL)
	{
		start = newnode;
		return;
	}
	
	if(ptr->data>=newnode->data)
	{
		newnode->next = ptr;
		start = newnode;
		return;
	}
	while(ptr->next->data<newnode->data)
	{
		ptr = ptr->next;
		if(ptr->next == NULL)
		{
			break;
		}
	}
	newnode->next = ptr->next;
	ptr->next = newnode;
	return;
}

void delete_at_beginning()
{
	struct node* ptr = start;
	if(start==NULL)
	{
		cout<<"List is already Empty"<<endl;
		return;
	}
	
	start = ptr->next;
	delete ptr;
	return;
}

void delete_at_end()
{
	struct node* ptr = start;
	if(start==NULL)
	{
		cout<<"List is already Empty"<<endl;
		return;
	}
	if(ptr->next==NULL)
	{
		start = NULL;
		delete ptr;
		return;
	}
	while(ptr->next->next!=NULL)
	{
		ptr = ptr->next; 
	}
	struct node* temp = ptr->next;
	ptr->next = NULL;
	delete temp;
	return;
}

void delete_at_position(int position)
{
	struct node* ptr = start;
	if(position<0)
	{
		cout<<"Invalid Position Entered"<<endl;
		return;
	}
	if(start==NULL)
	{
		cout<<"List is already empty"<<endl;
		return;
	}
	if(position==0 && ptr->next==NULL)
	{
		start = NULL;
		delete ptr;
		return;
	}
	if(position==0)
	{
		start = ptr->next;
		delete ptr;
		return;
	}
	
	for(int i=1;i<position;i++)
	{
		ptr = ptr->next;
		if(ptr==NULL)
		{
			cout<<"Invalid Position"<<endl;
		}
	}
	struct node *temp = ptr->next;
	ptr->next = temp->next;
	delete temp;
	return;
}

void delete_by_value(int value)
{
	struct node *ptr = start;
	if(start==NULL)
	{
		cout<<"List is already empty"<<endl;
		return;
	}
	if(ptr->next==NULL && ptr->data!=value)
	{
		cout<<"No such value exists"<<endl;
		return;
	}
	if(ptr->next == NULL)
	{
		start = NULL;
		delete ptr;
		return;
	}
	if(ptr->data == value)
	{
		start = ptr->next;
		delete ptr;
		return;
	}
	while(ptr->next->data!=value)
	{
		ptr = ptr->next;
		if(ptr->next == NULL)
		{
			cout<<"No such value exists"<<endl;
			return;
		}
	}
	struct node *temp = ptr->next;
	ptr->next = temp->next;
	delete temp;
	return;
}

bool searchRecursive(struct node* start,int key)
{
	if(start==NULL)
	{
		return false;
	}
	if(start->data == key)
	{
		return true;
	}
	else
	{
		return searchRecursive(start->next,key);
	}
	
}

bool searchIterative(int key)
{
	struct node* ptr = start;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			return true;
		}
		ptr = ptr->next;	
	}
	return false;	
}

void searching_value(int value)
{
	struct node *ptr = start;
	int position=0,flag=0;
	if(start==NULL)
	{
		cout<<"List is empty so no such value exist"<<endl;
		return;
	}
	while(ptr->next!=NULL)
	{
		if(flag == 1)
		{
			ptr=ptr->next;
			position++;
		}
		while(ptr->data!=value)
		{
			position++;
			if(ptr->next==NULL && flag==0)
			{
				cout<<"No such value exist"<<endl;
				return;
			}
			ptr=ptr->next;
			
		}
		flag=1;
		cout<<position<<" ";
	}
	return;
}

void buildlist()
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insert_at_end(data);
		cin>>data;
	}
}

void display()
{
	struct node *ptr;
	if(start==NULL)
	{
		cout<<"List is Empty!"<<endl;
		return;
	}
	ptr = start;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	return;
}

void reverse()
{
	struct node* ptr = start;
	struct node* current;
	struct node* prev = NULL;
	while(ptr!=NULL)
	{
		current = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = current;
	}
	start = prev;
}

node* midValue(node* head)
{
	if(head	==NULL || head->next==NULL)
	{
		return NULL;
	}
	struct node* slow = head;
	struct node* fast = head->next;
	
	while(fast!=NULL and fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	
	return slow;
}

void kNodeFromEnd(int k)
{
	struct node* slow = start;
	struct node* fast = start;
	int n = k;
	while(n--)
	{
		if(fast==NULL)
		{
			cout<<k<<" nodes does not exist"<<endl;
			return;
		}
		fast = fast->next;
	}
	while(fast!=NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	cout<<slow->data<<" ";
	cout<<endl;
	return;
}

node* merge(node* a,node* b)
{
	if(a==NULL)
	{
		return b;
	}
	else if(b==NULL)
	{
		return a;
	}
	node* c;
	if(a->data<b->data)
	{
		c = a;
		c->next = merge(a->next,b);
	}
	else
	{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}

struct node* mergeSort(struct node* head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	
	node* mid = midValue(head);
	node* a = head;
	node* b = mid->next;
	mid->next = NULL;
	
	a = mergeSort(a);
	b = mergeSort(b);
	
	node* c = merge(a,b);
	return c;
}

bool detectCycle(node* head)
{
	node* slow = head;
	node* fast = head;
	
	while(fast!=NULL and fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow)
		{
			return true;
		}
	}
	return false;
}

void removeCycle(node* head)
{
	if(!detectCycle)
	{
		return;
	}
	node* slow = head;
	node* fast = head;
	while(fast!=NULL and fast->next!=NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast==slow)
		{
			break;
		}
	}
	node* fastPos = fast;
	slow = head;
	int ds = 0;
	int df = 0;
	while(slow!=fast)
	{
		slow = slow->next;
		fast = fast->next;
		ds++;
		df++;
	}
	while(df--)
	{
		fastPos = fastPos->next;
	}
	fastPos->next = NULL;
	return;
}

int main()
{
	insert_at_beginning(3);
	display();
	cout<<endl;
	insert_at_beginning(2);
	display();
	cout<<endl;
	insert_at_beginning(1);
	display();
	cout<<endl;
	insert_at_position(4,3);
	display();
	cout<<endl;
	insert_at_position(6,4);
	display();
	cout<<endl;
	insert_at_position(1,1);
	display();
	cout<<endl;
	insert_by_value(7);
	display();
	cout<<endl;
	insert_by_value(0);
	display();
	cout<<endl;
	delete_at_beginning();
	display();
	cout<<endl;
	delete_at_end();
	display();
	cout<<endl;
	delete_at_position(2);
    display();
	cout<<endl;
	delete_at_position(0);
    display();
	cout<<endl;
	delete_at_position(3);
    display();
	cout<<endl;
	delete_by_value(4);
	display();
	cout<<endl;
	delete_by_value(3);
	display();
	cout<<endl;
	cout<<endl;
	cout<<endl;
	insert_at_beginning(3);
	insert_at_beginning(2);
	delete_by_value(1);
	insert_at_beginning(1);
	insert_at_end(4);
	insert_at_position(5,4);
	insert_at_end(6);
	insert_at_end(7);
	reverse();
	display();
	cout<<endl;
	node* midVal = midValue(start);
	cout<<midVal->data;
    cout<<endl;
    kNodeFromEnd(8);
//	display();
//	cout<<endl;
//	searching_value(1);
//	cout<<endl<<endl<<endl;
//	while(start!=NULL)
//	{
//		delete_at_end();
//	}
//	
//	buildlist();
	cout<<endl;
	start = mergeSort(start);
	display();
	return 0;
}
