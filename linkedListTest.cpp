/**
 * Author: Luis Ángel.
 * HW9 Q2.
 * March 13, 2020.
 */

#include <iostream>

using namespace std;

// Node struct.
struct Node
{
	int data;
	Node *next;
};
typedef Node* NodePtr;

/**
 * Retrieve the length of a singly linked list pointed to by 'head'.
 * @param head A reference to the pointer pointing to the beginning of the list.
 * @return Number of nodes in the list.
 */
int getListLength( const NodePtr& head )
{
	int count = 0;
	for( const Node *p = head; p != nullptr; p = p->next )
		count++;
	return count;
}

/**
 * Insert a value in the list and keep it sorted in ascending order.
 */
void insert( NodePtr& head, int value )
{
	Node* prior = nullptr;
	Node* current = head;

	while( current && value > current->data )
	{
		prior = current;
		current = current->next;
	}

	Node* tmp = new Node;			// Allocate the incoming new node.
	tmp->data = value;

	if( !prior )					// Head node's data (if any) is larger than incoming value.
	{
		tmp->next = head;
		head = tmp;
	}
	else
	{
		tmp->next = prior->next;	// Link to the first value in the list that is larger than incoming node's data.
		prior->next = tmp;
	}
}

/**
 * Get a dynamic array of size <= 'length' with the data values of the listed pointed to by 'head'. 
 */
int* linkedListToArray( const NodePtr& head, int length )
{
	int *array = nullptr;

	// Define the current length of the list.
	int count = getListLength( head );

	if( length < 1 || count == 0 )		// Invalid input length or empty list?
		return array;

	const int LEN = min( length, count );
	array = new int[LEN];			// Allocate new array with a valid length.

	// Dump list into dynamic array.
	const Node *p;
	int i;
	for( i = 0, p = head; i < LEN && p != nullptr; i++, p = p->next )
		array[i] = p->data;

	return array;
}

int main( int argc, char *argv[] )
{
	Node* head = nullptr;
	insert( head, 30 );
	insert( head, 20 );
	insert( head, 40 );
	insert( head, 10 );

	///////////////////////// Evaluation /////////////////////////

	cout << "Requesting fewer elements than list length: " << endl;
	cout << "  Expected: 10 20 30" << endl;
	cout << "  Obtained: ";
	int L = 3;
	int* array = linkedListToArray( head, L );
	if( array )
	{
		for( int i = 0; i < L; i++ )
			cout << array[i] << " ";
		delete [] array;
	}
	else
		cout << "nullptr";
	cout << endl;

	cout << "Requesting more elements than list length: " << endl;
	cout << "  Expected: 10 20 30 40 X Y" << endl;
	cout << "  Obtained: ";
	L = 6;
	array = linkedListToArray( head, L );
	if( array )
	{
		for( int i = 0; i < L; i++ )
			cout << array[i] << " ";
		delete [] array;
	}
	else
		cout << "nullptr";
	cout << endl;

	cout << "Requesting invalid number of elements: " << endl;
	cout << "  Expected: nullptr" << endl;
	cout << "  Obtained: ";
	L = -1;
	array = linkedListToArray( head, L );
	if( array )
	{
		cout << "Well, this is an error! ";
		delete [] array;
	}
	else
		cout << "nullptr";
	cout << endl;

	cout << "Requesting some elements from an empty list: " << endl;
	cout << "  Expected: nullptr" << endl;
	cout << "  Obtained: ";
	L = 3;
	NodePtr empty = nullptr;
	array = linkedListToArray( empty, L );
	if( array )
	{
		cout << "Well, this is an error! ";
		delete [] array;
	}
	else
		cout << "nullptr";
	cout << endl;

    return 0;
}