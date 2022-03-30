// Implementation file for the HashPython class
#include <iostream>
#include <fstream>
#include <iomanip>
#include "HashPython.h"
using namespace std;


HashPython::HashPython()
{
    clearCounts();
    ingest();
}

void HashPython::clearCounts()
{
    for(int i =0; i<TABLE_SIZE; i++)
    {
        hashTable[i].count = NULL;
    }
}

void HashPython::ingest()
{
    string word;
 
    //check for file
    string userFile = "keywords.txt";
    ifstream infile;
    infile.open(userFile);
        if(!infile)
        {
            cout << "Error opening file." << endl;
            exit(102);
        }
        
    while(infile >> word)
        {
            int hashLoc;
            int count = 0;
            hashLoc = (word.front() + word.back()) % TABLE_SIZE;

            while(hashTable[(hashLoc + count*count) % TABLE_SIZE].element == "")
                count++;

            hashTable[hashLoc + count*count].element = word;
        }

   infile.close();
   printHashTable();
}

void HashPython::printHashTable() const
{
    cout << "\n\nHash Location" << "Reserved Word" << "Count" << endl;
    cout << "_________________________________________________________" << endl;
    for(int i=0; i<TABLE_SIZE; i++)
    {
        cout << i << hashTable[i].element << hashTable[i].count <<endl;
    }
}

bool HashPython::findWord(const SElement &)
{
    //find hash location using getHashKey
    //use similar quadratic probing loop, but
    //counter = 0
    //while (hashTable[(hashLoc + counter*counter)%TABLE_SIZE] != word)
    //  counter++
    //increment the count at location: hashLoc + counter*counter
    //hashTable[hashLoc + counter*counter].count++;
}

// unsigned int HashPython::hash(const string & key, int tableSize)     //this function pg213
// {
        // unsigned int hashVal = 0;

        // for(char ch : key)
        //     hashVal = 37 * hashVal + ch;
        
        // return hashVal % tableSize;
// }

