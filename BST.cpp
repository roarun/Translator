/*
 * BST.cpp
 *
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Inspired from our textbook
 *         Arun Paudel(301557420) and Vaishhnav Narendran Meenakshi (301544644)
 * 
 * Date of last modification: March. 2024
 */

#include "BST.h"
#include "WordPair.h"
#include <iostream>

using std::cout;
using std::endl;
using std::nothrow;

// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver
// - the one with which we will mark this assignment -
// will not know about them since, in order to create it, we will have
// used only the public method prototypes below.

/* Constructors and destructor */

// Default constructor
BST::BST() {}

// Copy constructor
BST::BST(const BST &aBST)
{
   elementCount = aBST.elementCount;
   root = nullptr;
   BSTcopy(root, aBST.root);
}


//Description: private Recursive utility method for copying a binary search tree
// Exception: Throws the exception "UnableToInsertException" when srcPtr->element
//            cannot be inserted because the "new" operator failed.
void BST::BSTcopy(BSTNode *&destPtr, const BSTNode *srcPtr)
{
   //checking for recursive case
   if (srcPtr != nullptr)
   {
      destPtr = new (nothrow) BSTNode();
      //checking for proper memory allocation
      if (destPtr == nullptr)
      {
         throw UnableToInsertException("failed to copy nodes");
      }
      destPtr->element = srcPtr->element;//copying the element in the current node
      BSTcopy(destPtr->left, srcPtr->left);//calling left subtree recursively 
      BSTcopy(destPtr->right, srcPtr->right);//calling right subtree recursively
   }
   //base case would be srcPtr == nullptr
}

// Destructor
BST::~BST()
{
   destroyBST(root);
   root = nullptr;
}

//Description: Recursive utility function to free memory/ delete the 
//             binary search tree
void BST::destroyBST(BSTNode *current)
{
   if (current != nullptr)
   {
      destroyBST(current->left);//recursively destroying the left subtree
      destroyBST(current->right);//recursively destroying the left subtree
      delete current;
      elementCount--;
   }
}

/* Getters and setters */

// Description: Returns the number of elements currently stored in the binary search tree.
// Postcondition: This method does not change the binary search tree.
// Time efficiency: O(1)
unsigned int BST::getElementCount() const
{

   return this->elementCount;
}

/* BST Operations */

// Description: Inserts an element into the binary search tree.
//              This is a wrapper method which calls the recursive insertR( ).
// Precondition: "newElement" does not already exist in the binary search tree.
// Exception: Throws the exception "UnableToInsertException" when newElement
//            cannot be inserted because the "new" operator failed.
// Exception: Throws the exception "ElementAlreadyExistsException"
//            if "newElement" already exists in the binary search tree.
// Time efficiency: O(log2 n)
void BST::insert(WordPair &newElement)
{
   BSTNode *newBST = new (nothrow) BSTNode(newElement);
   if (newBST == nullptr)//checking for  memory allocation failure
   {
      throw UnableToInsertException("failed to allocate memory");
   }
   //insertion for the first element
   if (root == nullptr) 
   {
      root = newBST;
      return;
   }

   // calling the wrapper method and using its returning value to check 
   // for exceptions at the same time
   if (!insertR(newBST, root))
   {
      delete newBST;//freeing up the memory if the insertion failed
      throw ElementAlreadyExistsException("element already exists!");
   }
   elementCount++;//increasing the element count
}

// Description: Recursive insertion into a binary search tree.
//              Returns true when "anElement" has been successfully inserted into the
//              binary search tree. Otherwise, returns false.
bool BST::insertR(BSTNode *newBSTNode, BSTNode *current)
{
   // calling the inster function on the left subtree if the
   // insert data is smaller than current's data 
   if (newBSTNode->element < current->element)
   {
      //if we hit nullptr that means we have found the insertion point
      if (current->left == nullptr)
      {
         current->left = newBSTNode;
         elementCount++;
         return true;
      }
      return insertR(newBSTNode, current->left);
   }
   // calling the inster function on the right subtree if the
   // insert data is smaller than current's data 
   else if (newBSTNode->element > current->element)
   {
      //if we hit nullptr that means we have found the insertion point
      if (current->right == nullptr)
      {
         current->right = newBSTNode;
         elementCount++;
         return true;
      }
      return insertR(newBSTNode, current->right);
   }
   else 
   {
   //the code enters here if the element already exists in the binary search tree
   //which in turn triggers the exception
      return false;
   }
}

// Description: Retrieves "targetElement" from the binary search tree.
//              This is a wrapper method which calls the recursive retrieveR( ).
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException"
//            if the binary search tree is empty.
// Exception: Propagates the exception "ElementDoesNotExistException"
//            thrown from the retrieveR(...)
//            if "targetElement" is not found in the binary search tree.
// Postcondition: This method does not change the binary search tree.
// Time efficiency: O(log2 n)
WordPair &BST::retrieve(WordPair &targetElement) const
{

   if (elementCount == 0 || root == nullptr)//condition for empty binary search tree
      throw EmptyDataCollectionException("Binary search tree is empty");

   WordPair &translated = retrieveR(targetElement, root); // calling the wrapper method

   return translated;//returning the updated translated
}

// Description: Recursive retrieval from a binary search tree.
// Exception: Throws the exception "ElementDoesNotExistException"
//            if "targetElement" is not found in the binary search tree.
// Postcondition: This method does not change the binary search tree.
WordPair &BST::retrieveR(WordPair &targetElement, BSTNode *current) const
{
   //base case where the element is not found
   if (current == nullptr)
   {
      throw ElementDoesNotExistException("the element doesn't exist in the BST");
   }
   //we find the element
   else if (targetElement == current->element)
   {
      return current->element;
   }
   // comparing the target and searching in the left subtree if target has smaller value
   else if (targetElement < current->element)
   {
      return retrieveR(targetElement, current->left);
   }
   // comparing the target and searching in the right subtree if target has higher value
   else // tragetElement > current->element
   {
      return retrieveR(targetElement, current->right);
   }
}

// Description: Traverses the binary search tree in order.
//              This is a wrapper method which calls the recursive traverseInOrderR( ).
//              The action to be done on each element during the traverse is the function "visit".
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException"
//            if the binary search tree is empty.
// Postcondition: This method does not change the binary search tree.
// Time efficiency: O(n)
void BST::traverseInOrder(void visit(WordPair &)) const
{

   if (elementCount == 0)
      throw EmptyDataCollectionException("Binary search tree is empty.");

   traverseInOrderR(visit, root); // calling the wrapper method

   return;
}

// Description: Recursive in order traversal of a binary search tree.
// Postcondition: This method does not change the binary search tree.
void BST::traverseInOrderR(void visit(WordPair &), BSTNode *current) const
{
   if (current != nullptr)
   {
      //going left, root, right
      traverseInOrderR(visit, current->left);
      visit(current->element);
      traverseInOrderR(visit, current->right);
   }
   //base case is current == nullptr
}