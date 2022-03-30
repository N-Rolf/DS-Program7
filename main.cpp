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

int main()
{
    HashPython list;
    //USER MENU
    int selection = 0;
    do{
        cout << "\nChoose an Option...\n";
        cout << "1: Enter a new file name.\n";
        cout << "2: Exit. \n";
        cin.clear();
        cin >> selection;
        switch(selection){
            case ENTER_FILENAME:{
                //cout << "Enter file name: \"file.txt\"" << endl;
                //cin << setFile(userFile);
                break;
                }
            case EXIT:{
                cout << "\nExiting...\n";
                break;
                }
        }
    }while(selection != 2);
   
   return 0;
}
