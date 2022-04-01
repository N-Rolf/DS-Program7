/********************************************************************
***  NAME       :Neil Rolf                                        ***
***  CLASS      :CSc 300                                          ***
***  ASSIGNMENT :Program 7                                        ***
***  DUE DATE   :04/01/2022                                       ***
***  INSTRUCTOR :Kurtenbach                                       ***
*********************************************************************
***  DESCRIPTION : implementation file for HashPython class       ***
********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "HashPython.h"
using namespace std;

/********************************************************************
***  FUNCTION HashPython                                          ***
*********************************************************************
***  DESCRIPTION   : default constructor for the hash table       ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
HashPython::HashPython()
{
    clearCounts();
    ingest();
}

/********************************************************************
***  FUNCTION HashPython()                                        ***
*********************************************************************
***  DESCRIPTION   : parameterized constructor for the hash table ***
***  INPUT ARGS    : string with file name                        ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
HashPython::HashPython(SElement file)
{
    clearCounts();
    userFile = file;
    ingest();
}

/********************************************************************
***  FUNCTION clearCounts                                         ***
*********************************************************************
***  DESCRIPTION   : sets all hash table cells to 0 or NULL       ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
void HashPython::clearCounts()
{
    for(int i =0; i<TABLE_SIZE; i++)
    {
        hashTable[i].element = "";
        hashTable[i].count = 0;
    }
}

/********************************************************************
***  FUNCTION ingest                                              ***
*********************************************************************
***  DESCRIPTION   : reads string elements from file into hash    ***
***                  table, prints table contents                 ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
void HashPython::ingest()
{
    SElement word;
    int wall = 0;
    //check for file
    ifstream infile;
    infile.open(userFile);
        if(!infile)
        {
            cout << "Error opening file." << endl;
            exit(102);
        }
    //read from file
    while(getline(infile, word))
        {
            int key = getHashKey(word);
            int found = findWord(word);
            if(found == 0)
            {
                //overflow protection
                if(wall <= TABLE_SIZE)
                {
                    hashTable[key].element = word;
                    hashTable[key].count = 1;
                    wall++;
                }
                else
                {
                    cout << "\n\nError: Hash table is full. Rehashing unavailable." << endl;
                    cout << "\nPrinting last table instance..." << endl;
                    printHashTable();
                    cout << "\n\nExiting..." << endl;
                    exit(201);
                }
            }
        }

   infile.close();
   
   printHashTable();
}

/********************************************************************
***  FUNCTION getHashKey                                          ***
*********************************************************************
***  DESCRIPTION   : calculates a hash key using the ascii values ***
***                  of the first and last character % the table  ***
***                  size, uses quadratic collision prevention    ***
***  INPUT ARGS    : string value to hash                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : hashed key (int)                             ***
********************************************************************/
int HashPython::getHashKey(SElement word)
{
    int hashLoc,key;
    int count = 0;
    //calculate hash key
    hashLoc = (word.front() + word.back()) % TABLE_SIZE;
    
    //quadratic collision prevention
    while(hashTable[(hashLoc + count*count) % TABLE_SIZE].element != "")
        count++;

    key = (hashLoc + count*count)%TABLE_SIZE;
    return key;
}

/********************************************************************
***  FUNCTION printHashTable                                      ***
*********************************************************************
***  DESCRIPTION   : prints contents of the hash table            ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
void HashPython::printHashTable() const
{
    cout << "\n\nHash Location |" << " Reserved Word |" << " Count " << endl;
    cout << "_________________________________________________________" << endl;
    for(int i=0; i<TABLE_SIZE; i++)
    {
        cout << setw(16) << std::left << i;
        cout << setw(16) << std::left << hashTable[i].element;
        cout << setw(2) << std::left << hashTable[i].count <<endl;
    }
}

/********************************************************************
***  FUNCTION findWord                                            ***
*********************************************************************
***  DESCRIPTION   : searches for existing instances of string in ***
***                  table, returns true or false                 ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : true if found, false if not                  ***
********************************************************************/
bool HashPython::findWord(const SElement & word)
{
    int counter = 0;
    int hashLoc = getHashKey(word);

    for(int i=0; i<TABLE_SIZE; i++)     //unsure if TABLE_SIZE is correct search cap but seems to work
    {
        if(hashTable[(hashLoc + i*i)%TABLE_SIZE].element == word)
        {
            hashTable[(hashLoc + i*i)%TABLE_SIZE].count += 1;
            return 1;
        }
    }
    
    return 0;
}

