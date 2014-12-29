// Written by Zack Rosales
// Advanced C++ Programming ITSE 2431 1001
// Program from page #, # #

#include <fstream> // for using files
#include <iomanip> // for formatting
#include <string> // for strings
#include <cstdlib> // for rand and srand
#include <vector> // for vectors
#include <cctype> // for character functions
#include <cstring> // for C-strings
#include <ctime> // for using time/date functions
#include <algorithm> // for STL algorithms
#include "conio.h" 
#include "BinaryTree.h"
using namespace std;

// global constants
static const int EXIT = 0;

// method prototypes
int menu();
int submenu(int);

// template prototypes
template <class T>
void manipulateTree(BinaryTree<T>);

int main() // main method start
{
	// local variable
	int choice;

	// BinaryTree objects
	BinaryTree<int> intTree;
	BinaryTree<double> doubleTree; // like the hotel :)
	BinaryTree<string> stringTree;

	do
	{
		choice = menu();
		switch (choice)
		{
		case 1: manipulateTree(intTree);
			break;
		case 2: manipulateTree(doubleTree);
			break;
		case 3: manipulateTree(stringTree);
			break;
		} // end switch
	} while (choice != EXIT);


	cout << "Have a good day.";
	_getch();
	return 0;
} // main method end

// menu method displays the menu options and returns user selection
int menu() // menu method start
{
	// local variable
	int choice;

	// displaying menu choices and getting input
	cout << "Please choose what type of tree to work with:\n";
	cout << "1. Integer tree\n";
	cout << "2. Double tree\n";
	cout << "3. String tree\n";
	cout << "0. Exit the program\n";
	cout << "Enter selection: ";
	cin >> choice;

	// input validation
	while (choice < EXIT || choice > 3)
	{
		cout << "You did not enter a valid selection. Please try again.\n";
		cout << "Enter selection (0 - 3): ";
		cin >> choice;
	} // end while

	cout << "\n";

	return choice;
} // menu method end

// manipulateTree method displays options for working with the tree
template <class T>
void manipulateTree(BinaryTree<T> tree) // manipulateTree method start
{
	// local variable
	int choice;
	T value;

	do
	{
		choice = submenu(tree.countNodes());
		switch (choice)
		{
		case 1: cout << "\nEnter a value to add: ";
			cin >> value;
			tree.insertNode(value);
			break;
		case 2: cout << "\nEnter a value to remove: ";
			cin >> value;
			try
			{
				tree.remove(value);
			} // end try
			catch (BinaryTree<T>::EmptyNode)
			{
				cout << "\nThe value you entered was not in the tree.\n";
			} // end catch
			break;
		case 3: tree.displayInOrder();
			break;
		case 4: tree.displayPreOrder();
			break;
		case 5: tree.displayPostOrder();
			break;
		case 6: cout << "\nThere are " << tree.countLeaves() << " leaves in the tree.\n";
			break;
		} // end switch
	} while (choice != EXIT);
} // manipulateTree method end

// submenu method displays submenu options and returns user choice
int submenu(int size) // submenu method start
{
	// local variable
	int choice,
		max;

	// warning that not all menu options will appear when tree is empty
	if (size == 0)
	{
		max = 1;
		cout << "This tree is empty.\nYou must add a value before seeing more menu options.\n\n";
	} // end if
	else
	{
		max = 5;
	} // end else

	// displaying menu options
	cout << "Select an operation to perform:\n";
	cout << "1. Add a chosen value\n";
	if (size != 0) // menu options only appear if tree is not empty
	{
		cout << "2. Delete a value\n";
		cout << "3. Display tree in order\n";
		cout << "4. Display tree in preorder\n";
		cout << "5. Display tree in postorder\n";
		cout << "6. Display number of leaves in tree\n";
	} // end if
	cout << "0. Return to previous menu\n";
	cout << "Enter selection: ";
	cin >> choice;

	// input validation
	while (choice < EXIT || choice > max)
	{
		cout << "You did not enter a valid selection. Please try again.\n";
		cout << "Enter selection (0 - " << max << "): ";
		cin >> choice;
	} // end while

	cout << "\n";

	return choice;
} // submenu method end