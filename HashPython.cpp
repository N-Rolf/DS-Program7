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
        hashTable[i].count = 0;
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
            //cout << "read: " << word << endl;
            int hashLoc,key;
            int count = 0;
            hashLoc = (word.front() + word.back()) % TABLE_SIZE;
            
            while(hashTable[(hashLoc + count*count) % TABLE_SIZE].element != "")
                count++;

            key = (hashLoc + count*count)%TABLE_SIZE;
            //cout << "word: " << setw(8) << std::left << word << ", key: " << setw(4) << std::left << key << "count: " << count << endl;
            hashTable[key].element = word;
        }

   infile.close();
   for(int i=0; i<TABLE_SIZE; i++)
   {
       if (hashTable[i].element != "")
            findWord(hashTable[i].element);
   }
   
   printHashTable();
}

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

//bool HashPython::findWord(const SElement &)
//{
    //find hash location using getHashKey
    //use similar quadratic probing loop, but
    //counter = 0
    //while (hashTable[(hashLoc + counter*counter)%TABLE_SIZE] != word)
    //  counter++
    //increment the count at location: hashLoc + counter*counter
    //hashTable[hashLoc + counter*counter].count++;
//}


