#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
static int n=0;

struct node{
	int data;
	node* next, *prev;
};

void showList(node* head, node* tail)
{
    node* temp = head;
    int i = 1;
	while (temp)
	{
		cout << i << ".  " << temp->data <<endl;
		temp = temp->prev;
		if (temp == head)
		    temp = NULL;
		i++;
	}	
}

void addLastList(node** head, node** tail, int data)
{
	node* temp = new node;
	temp->data = data;
	
	if (!*head)
	{
		temp->next = temp->prev = temp;
	    *head = *tail = temp;
	}
	else
	{
		temp->data = data;
    	(*tail)->prev = temp;  temp->next = *tail;
    	(*head)->next = temp;  temp->prev = *head;
    	*tail = temp;
	}
}

void searchAmountOfZero(node** head, node** tail, int i, int j){
	node* temp = *head;
	int iterator = 1;
	int amount = 1;
	while (temp)
	{
		if(temp->data != 0 ){
			temp = temp->prev;
			iterator++;
		}
		if(temp->data == 0){	
			cout << "("<< iterator << ", " << temp->data << ")" <<endl;
			temp = temp->prev;
			iterator++;
			if (i<iterator && iterator<j){
				amount++;
			} 
			
		}
		if (temp == *head)
		    temp = NULL;
	}	
	cout << endl;
	cout << "Amount of zero between i(" << i << ") and j(" << j << "): "  << amount; 
}

void deleteList(node **head, node **tail)
{
    node *current = *head;
    node *next;

    while (current)
    {
        next = current->prev;
        delete current;
        current = next;

        if (current == *head)
            break;
    }

    *head = *tail = NULL;
}

int main(){
	int i; 
	int j;
	node* head, *tail;
	head = tail = NULL;
	
	addLastList(&head, &tail, 0);
	addLastList(&head, &tail, 0);
	addLastList(&head, &tail, 1);
	addLastList(&head, &tail, 0);
	addLastList(&head, &tail, 3);
	addLastList(&head, &tail, 0);
	addLastList(&head, &tail, 0);
	addLastList(&head, &tail, 4);
	addLastList(&head, &tail, 0);
	
	showList(head, tail);	
	cout << "All zero: " << endl;

	searchAmountOfZero(&head, &tail, 1, 8);
	deleteList(&head, &tail);
	return 0;
}
