/*
 * Translator.cpp
 *
 * Description: Translates the given english word into another language
 *
 * Author: Arun Paudel(301557420) and Vaishhnav Narendran Meenakshi (301544644)
 * Date of last modification: March. 2024
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "Dictionary.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::nothrow;
using std ::ws;

//the display function
void display(WordPair &anElement)
{
    //using overloaded operator to print out a WrodPair
    cout << anElement;
}

int main(int argc, char *argv[])
{
    Dictionary *myDict = new (nothrow) Dictionary();
    if (myDict != nullptr)//checking for proper memory allocation
    {

        string aLine = "";
        string aWord = "";
        string englishW = "";
        string translationW = "";
        string filename = "";
        string delimiter = ":";
        size_t pos = 0;
        WordPair translated;

        // Expecting at least a filename on the command line.
        if ((argc > 1))
        {
            filename = argv[1];
            ifstream myfile(filename);
            if (myfile.is_open())
            {
                while (getline(myfile, aLine))
                {
                    pos = aLine.find(delimiter);
                    englishW = aLine.substr(0, pos);
                    aLine.erase(0, pos + delimiter.length());
                    translationW = aLine;
                    WordPair aWordPair(englishW, translationW);
                    //inserting and catching error
                    try
                    {
                        myDict->put(aWordPair);
                    }
                    catch (const ElementAlreadyExistsException &e1)
                    {
                        cout << "put() unsuccessful because " << e1.what() << endl;
                    }
                    catch (const UnableToInsertException &e2)
                    {
                        cout << "put() unsuccessful because " << e2.what() << endl;
                    }
                }
                myfile.close();
                // myDict->displayContent(display);

                WordPair wordToTranslate(aWord);
                //runnin the loop until user enter display or end of line command
                while (aWord != "display" && !cin.eof())
                {
                    cin >> ws >> aWord;
                    wordToTranslate.setEnglish(aWord);
                    //this if block executes only when display and end of line character is not entered
                    if (aWord != "display" && !cin.eof())
                    {
                        //looking up the word in my Dictionary
                        try
                        {
                            wordToTranslate = myDict->get(wordToTranslate);
                            //printing the word if it is found
                            display(wordToTranslate);
                        }
                        catch (const ElementDoesNotExistException &e1)
                        {
                            //printing not found if not found
                            cout << "***Not Found!***" << endl;
                        }
                        catch (const EmptyDataCollectionException &e2)
                        {
                            //error message to deal with emptry dictionary
                            cout << "the dictionary is empty" << endl;
                        }
                    }
                    //this block executes only when display is entered
                    //using eles if  to avoid end of line command entering into this block
                    else if(aWord == "display")
                    {
                        myDict->displayContent(display);
                    }
                }
            }
            else // !myfile.is_open()
            {
                cout << "Unable to open file" << endl;
            }
        }
        else //user did not enter the data filename in the command line
        {
            cout << "Missing the data filename!" << endl;
        }
    }
    delete myDict; //free up the dict
}

// Translation Algorithm:

// Read in the data filename the user entered at the command line.
// Load its content (all the word pairs) into the Dictionary.
// While not EOF
//   Read the English word the user entered at the command line.
//   Translate this English word using the Dictionary object.
//   Print <English word>:<word in the other language> on the computer monitor screen.
//   If the English word was not found, print ***Not Found!*** instead.