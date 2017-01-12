#include "Doubly_LinkedList.h"

Doubly_LinkedList::Doubly_LinkedList() : LinkedList(0)
{
	root = new node;
	root -> number = 1200;
	root -> previous_item = nullptr;
	root -> next_item = tail;

	tail = new node;
	tail -> number = 1300;
	tail -> previous_item = root;
	tail -> next_item = nullptr;
}


/****************************************************************************
* Function: insert_node(node * NewNode, int position)
*****************************************************************************
*
* Inserts node at the specified location
* 
*
****************************************************************************/ 
bool Doubly_LinkedList::insert_node(node * NewNode, int position)
{

/*****************************************************************************
 * Protect the root and the tail nodes
*****************************************************************************/
	if (position <= 0 || position > LinkedList+1)
	{
		std::cout << "Error!!! Out of range." << std::endl;
		return(false);
	}

/*****************************************************************************
 * If first node in the list
*****************************************************************************/	
	if (!root -> next_item || !tail -> previous_item)
	{
		std::cout << "First item in the list." << std::endl;
		root -> next_item = NewNode;
		tail -> previous_item = NewNode;
		NewNode -> previous_item = root;
		NewNode -> next_item = tail;
		++LinkedList;
		return(true);
	}

	int count = 1;
	previous_node = root;
	current_node = root -> next_item;
	while(true)
	{
		if(count == position)
		{
			NewNode -> previous_item = previous_node;
			NewNode -> next_item = current_node;
			previous_node -> next_item = NewNode;			
			current_node -> previous_item = NewNode;
			++LinkedList;
			break;
		}
		else
		{
			previous_node = current_node;
			current_node = current_node -> next_item;
			++count;
		}
	}
	return(true);
}


/****************************************************************************
* Function: push_front(node * NewNode)
*****************************************************************************
*
* Push a new node at the front of the list
* 
*
****************************************************************************/ 
void Doubly_LinkedList::push_front(node * NewNode)
{
	NewNode -> next_item = root -> next_item;
	NewNode -> previous_item = root;
	next_node = root -> next_item;
	next_node -> previous_item = NewNode;
	root -> next_item = NewNode;
	++LinkedList;
}


/****************************************************************************
* Function: push_back(node * NewNode)
*****************************************************************************
*
* Push a new node at the end of the list
* 
*
****************************************************************************/ 
void Doubly_LinkedList::push_back(node * NewNode)
{
	NewNode -> next_item = tail;
	NewNode -> previous_item = tail -> 	previous_item;
	previous_node = tail -> previous_item;
	previous_node -> next_item = NewNode;
	tail -> previous_item = NewNode;
	++LinkedList;
}


/****************************************************************************
* Function: remove(int position)
*****************************************************************************
*
* Removes the node at the specified location
* 
*
****************************************************************************/ 
bool Doubly_LinkedList::remove(int position)
{
/*****************************************************************************
 * Protect the root and the tail nodes
*****************************************************************************/
	if (position <= 0 || position > LinkedList+1)
	{
		std::cout << "Error!!! Out of range." << std::endl;
		return(false);
	}
	previous_node = root;
	current_node = root -> next_item;
	next_node = current_node -> next_item;
	int count = 1;
	while (true)
	{
		if (count == position)
		{
			previous_node -> next_item = next_node;
			next_node -> previous_item = previous_node;
			delete current_node;
			--LinkedList;
			break;
		}
		else
		{
			previous_node = current_node;
			current_node = next_node;
			next_node = next_node -> next_item;
			++count;
		}
	}
	return(true);
}


/****************************************************************************
* Function: get_node(int position, node * vertex_number)
*****************************************************************************
*
* Gets the contents of the targetted node "vertex_number"
* 
*
****************************************************************************/ 
bool Doubly_LinkedList::get_node(int position, int & vertex_number)
{
	if (position <= 0 || position > LinkedList)
	{
		std::cout << "Error: Index out of range!!!" << std::endl;
		return(false);
	}
	node_to_display = root -> next_item;
	int count = 1;
	while(true)
	{
		if(count == position)
		{
			vertex_number = node_to_display -> number;
			break;
		}
		else
		{
			node_to_display = node_to_display -> next_item;
			++count;
		}
	}
	return (true);
}


/****************************************************************************
* Function: get_length()
*****************************************************************************
*
* Function returns length of the list
* 
*
****************************************************************************/
int Doubly_LinkedList::get_length()
{
	return (LinkedList);
}


/****************************************************************************
* Function: printout()
*****************************************************************************
*
* Prints out the contents of the linked list
* 
*
****************************************************************************/ 
void Doubly_LinkedList::printout()
{
	previous_node = root;
	current_node = root -> next_item;
	next_node = current_node -> next_item;
	for (int i = 1; i <= LinkedList; ++i)
	{
		std::cout << " ---> " << current_node -> number;
		previous_node = current_node;
		current_node = current_node -> next_item;
		next_node = next_node -> next_item;
	}
	std::cout << endl;
}


Doubly_LinkedList::~Doubly_LinkedList()
{
	node * next = root -> next_item;
	node * current = root;
	for (int i = 0; i < LinkedList+1; ++i)
	{
		delete current;
		current = next;
		next = next -> next_item;
	}
	delete current;	
}

