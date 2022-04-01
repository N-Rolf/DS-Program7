/********************************************************************
***  NAME       :Neil Rolf                                        ***
***  CLASS      :CSc 300                                          ***
***  ASSIGNMENT :Program 7                                        ***
***  DUE DATE   :04/01/2022                                       ***
***  INSTRUCTOR :Kurtenbach                                       ***
*********************************************************************
***  DESCRIPTION : header file for HashPython class               ***
********************************************************************/
#ifndef HashPython_H
#define HashPython_H
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
      SElement userFile;
      int getHashKey(SElement);
      void ingest();

   public:
      HashPython();
      HashPython(SElement);
      bool findWord(const SElement &);
      void printHashTable() const;
      void clearCounts();



};

#endif