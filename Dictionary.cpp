/*
 * Dictionary.cpp
 *
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *
 * Author: Arun Paudel(301557420) and Vaishhnav Narendran Meenakshi (301544644)
 * 
 * Date of last modification: March. 2024
 */

#include "Dictionary.h"
#include <iostream>

//default constructor
Dictionary::Dictionary()
{
    keyValuePairs = new BST();
}

//destructor
Dictionary::~Dictionary()
{
    delete keyValuePairs;
}

// Dictionary operations

// Description: Returns the number of elements currently stored in the Dictionary.
// Postcondition: This method does not change the Dictionary.
unsigned int Dictionary ::getElementCount() const
{
    //using the getElmenetCount of the BST class to getElementCount for our dictionary
    return (keyValuePairs->getElementCount());
}

// Description: Puts "newElement" (association of key-value) into the Dictionary.
// Precondition: "newElement" does not already exist in the Dictionary.
//               This is to say: no duplication allowed.
// Exception: Throws the exception "UnableToInsertException"
//            when newElement cannot be inserted in the Dictionary.
// Exception: Throws the exception "ElementAlreadyExistsException"
//            if "newElement" already exists in the Dictionary.
void Dictionary ::put(WordPair &newElement)
{
    //using the insert method from BST class to put the new word into our dictionary
    keyValuePairs->insert(newElement);
}

// Description: Gets "newElement" (i.e., the associated value of a given key)
//              from the Dictionary.
// Precondition: Dictionary is not empty.
// Exception: Throws the exception ElementDoesNotExistException
//            if the key is not found in the Dictionary.
// Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
// Postcondition: This method does not change the Dictionary.
WordPair &Dictionary ::get(WordPair &targetElement) const
{
    //using the retrive method from BST class to get the targetElement in our dictionary
    return (keyValuePairs->retrieve(targetElement));
}

// Description: Prints the content of the Dictionary.
// Precondition: Dictionary is not empty.
// Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
// Postcondition: This method does not change the Dictionary.
void Dictionary ::displayContent(void visit(WordPair &)) const
{
    //using inorder traversal of BST class to display the content in the dictionary 
    keyValuePairs->traverseInOrder(visit);
}
