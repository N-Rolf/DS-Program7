/********************************************************************
***  NAME       :Neil Rolf                                        ***
***  CLASS      :CSc 300                                          ***
***  ASSIGNMENT :Program 7                                        ***
***  DUE DATE   :04/01/2022                                       ***
***  INSTRUCTOR :Kurtenbach                                       ***
*********************************************************************
***  DESCRIPTION : Hash table structure                           ***
********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "HashPython.h"
using namespace std;

enum Menu {ENTER_FILENAME=1, EXIT};

struct TempStruct
    {
        string element;
        unsigned count;
    };

int ingestData();

int main()
{

    //initial data ingest and user file name prompt
    int itemCount = ingestData();
   
    //USER MENU
    int selection = 0;
    do{
        cout << "\nChoose an Option...\n";
        cout << "1: Enter a new file name.\n";
        cout << "4: Exit. \n";
        cin.clear();
        cin >> selection;
        switch(selection){
            case ENTER_FILENAME:{
                //user prompt here
                break;
                }
            case EXIT:{
                cout << "\nExiting...\n";
                break;
                }
        }
    }while(selection != 4);
   
   return 0;
}

/********************************************************************
*** FUNCTION ingestData                                           ***
*********************************************************************
*** DESCRIPTION : displays all nodes in the stack                 ***
*** INPUT ARGS : none                                             ***
*** OUTPUT ARGS : none                                            ***
*** RETURN : number of items pushed to stack                      ***
********************************************************************/
int ingestData()
{
   string userFile = "keywords.txt";

    //check for file
    ifstream infile;
    infile.open(userFile);
        if(!infile)
        {
            cout << "Error opening file." << endl;
            exit(102);
        }
    
    //read from file to temporary node, push from temp to stack
    Node tempNode;
    int count = 0;

    while(infile >> tempNode.likes)
    {
      //infile >> tempNode.likes;
      infile >> tempNode.views;
      infile.ignore();
      getline(infile, tempNode.title);

      //cout << "inserting: " << tempNode.title << ", " << tempNode.likes << ", " << tempNode.views << endl;
      tree.insertNode(tempNode.title, tempNode.likes, tempNode.views);     
      count ++;
      //cout << "eof status: " << infile.eof() << endl;
    }

   //cout << "\n" << count << "/10 items inserted." << endl;
   infile.close();
   return count;
}