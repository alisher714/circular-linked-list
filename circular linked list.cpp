#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int data;
	Node *link;
};

Node *head = NULL;

void insertAtBeg(int val)
{
	Node *newnode = new Node();
	newnode->data = val;
	newnode->link = NULL;

	if (head == NULL)
	{
		head = newnode;
		newnode->link = head;
	}
	else
	{
		Node *temp = new Node();
		temp = head;
		while (temp->link != head)
		{
			temp = temp->link;
		}
		temp->link = newnode;
		newnode->link = head;
		head = newnode;
	}
}
void insertAtEnd(int val)
{
	Node *newnode = new Node;
	newnode->data = val;
	newnode->link = NULL;
	Node *temp = head;
	while (temp->link != head)
	{
		temp = temp->link;
	}
	temp->link = newnode;
	newnode->link = head;
}

void printlist()
{
	Node *temp = head;
	if (temp != NULL)
	{
		cout << "the list contain ";
		while (true)
		{
			cout << temp->data << " ";
			temp = temp->link;
			if (temp == head)
			{
				break;
			}
		}
		cout << endl;
	}
	else
	{
		cout << "the list is empty";
	}
}

void insertAtSpecificPos(int pos, int val)
{
	Node *newnode = new Node;
	newnode->data = val;
	newnode->link = NULL;

	Node *temp = head;
	if (pos < 1)
	{
		cout << "---Invalid position---";
	}
	else
	{
		for (int i = 1; i < pos - 1; i++)
		{
			temp = temp->link;
		}
		newnode->link = temp->link;
		temp->link = newnode;
	}
}

void DelFromStart()
{
	if (head == NULL)
	{
		cout << "list is empty\n";
	}
	else
	{
		Node *temp = head;
		Node *temp1 = head;
		while (temp->link != head)
		{
			temp = temp->link;
		}
		temp->link = head->link;
		head = head->link;
		delete (temp1);
	}
}

void DelFromEnd()
{
	if (head == NULL)
	{
		cout << "list is empty\n";
	}
	else
	{
		Node *temp = head;
		while (temp->link->link != head)
		{
			temp = temp->link;
		}
		Node *last = temp->link;
		temp->link = head;
		delete (last);
	}
}

void DelFromSpecPos(int pos)
{
	if (head == NULL)
	{
		cout << "list is empty\n";
	}
	else
	{
		Node *temp = head;
		for (int i = 1; i < pos-1; i++)
		{
			temp = temp->link;
		}
		Node *del = new Node;
		del = temp->link;
		temp->link = temp->link->link;
		delete (del);
	}
}

void search(int elem)
{
	int count=0;
	if (head == NULL)
	{
		cout << "list is empty\n";
	}
	else
	{
		Node *temp = head;
		while(temp->data != elem)
		{
			temp = temp->link;
			count++;
		}
		cout<<elem<<"is found at "<<count;
	}
}

int main()
{
	int choice, val, pos;
do_:
	cout << "1. insert at beginning\n";
	cout << "2. insert at ending\n";
	cout << "3. insert at a specific postion\n";
	cout << "4. display list\n";
	cout << "5. delete from end\n";
	cout << "6. delete from start\n";
	cout << "7. delete from specific position\n";
	cout << "8. search element\n";
	cout << "9. exit \n";
	cout << "ENTER YOUR CHOICE : \n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "enter value : ";
		cin >> val;
		insertAtBeg(val);
		getch();
		system("cls");
		break;

	case 2:
		cout << "enter value : ";
		cin >> val;
		insertAtEnd(val);
		getch();
		system("cls");
		break;

	case 3:
		cout << "enter value : ";
		cin >> val;
		cout << "enter position : ";
		cin >> pos;
		insertAtSpecificPos(pos, val);
		getch();
		system("cls");
		break;

	case 4:
		printlist();
		getch();
		system("cls");
		break;

	case 5:
		DelFromEnd();
		system("cls");
		break;

	case 6:
		DelFromStart();
		system("cls");
		break;

	case 7:
		int del;
		cout << "enter position to be deleted : ";
		cin >> del;
		DelFromSpecPos(del);
		system("cls");
		break;

	case 8:
		int val;
		cout << "enter element to be search : ";
		cin >> val;
		search(val);
		getch();
		system("cls");
		break;

	case 9:
		exit(0);
		break;

	default:
		cout << "\nINVALID INPUT";
		break;
	}
	goto do_;

	return 0;
}
