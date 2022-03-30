#ifndef BST_H
#define BST_H
#include <string>
typedef std::string SElement;

class HashPython
{
   private:
      enum TableLimit { TABLE_SIZE = 41 };
      struct TableElem
      {
         SElement element;
         unsigned count;
      };
      TableElem hashTable[TABLE_SIZE];
      //prototypes for private member functions go here
   
   public:
      HashPython();  //constructor
      bool findWord(const SElement &);
      void printHashTable() const;
      void clearCounts();
      void ingest(SElement);

};

#endif