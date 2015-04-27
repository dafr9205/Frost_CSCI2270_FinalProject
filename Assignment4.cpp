// Daniel Frost
// CSCI2270
// Assignment 4 *Modified* for Final Project to Include Additional Functionality
// End-of-World "Modifiable / Update-able Message with Message Logger" Communication Program
// The purpose will be to illustrate a last-resort message program, using a linked-list structure,
// to allow for a chain-link message to be updated, and have an external message log be updated
// with which city updated, at what time (for message trace and change - a - bility.)
// Professor Hoenigman

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "CommunicationNetwork.h"

using namespace std;

void showMenu();

int main(int argc,const char * argv[])  //for CLA
{
    int menuChoice=0; //user choice from menu
    string name;
    string othername;
    const int BUILDNETWORK = 1,
              PRINTNETWORKPATH = 2,
              ENQUEUE = 3,
              DEQUEUE = 4,
              PRINTQUEUE = 5,
              SENDENTIREMESSAGE = 6,
              MODIFYMESSAGE = 7,
              UPDATEMESSAGLELOG = 8,
              QUIT = 9;

    CommunicationNetwork commNetwork (10);

    ifstream msgInput ("messageIn.txt");

    string* fileQueue = new string[100];

    int i = 0;

    while(msgInput >> fileQueue[i]){
        i++;   //call support function to pass the word
        }

    int j = 0 ;

    do
    {
        showMenu();
        cin >> menuChoice;

            //while (menuChoice != 1 or 2 or 3 or 4 or 5 or 6 or 7)   //validate menu choice
            //{
                //cout << "Please enter a valid menu choice: ";
                //cin >> menuChoice;
            //}


        if (menuChoice != 9)
        {
            switch (menuChoice)
            {
                case BUILDNETWORK:
                    commNetwork.buildNetwork();   //create the head of the network
                    break;


                case PRINTNETWORKPATH:
                    commNetwork.printPath();   //pass head of network to printpath function
                    break;


                case ENQUEUE:
                    if (j < i){
                        int error = commNetwork.enqueue(fileQueue[j]);
                        if (error == 1)
                            j++;  //call transmit msg function     //i is tail, j is the head
                    }else{
                        cout <<"No more words to queue."<<endl;
                    }

                    break;


                case DEQUEUE:
                    commNetwork.dequeue();//create a new function to ask the user what city and cin it.
                    break;


                case PRINTQUEUE:
                    commNetwork.printQueue();
                    break;


                case SENDENTIREMESSAGE:
                    commNetwork.sendEntireMessage();
                    break;

                /*case MODIFYMESSAGE:
                    commNetwork.modMessage();
                    break;

                case UPDATEMESSAGLELOG:
                    commNetwork.updMessageLog();
                    break;*/

                case QUIT:

                    break;

            }
        }else{
        cout<<"Goodbye!"<<endl;
        }

    }
    while (menuChoice != QUIT);
    //free (fileQueue);
    return 0;
}


void showMenu()
{
    cout << "======Main Menu=====" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Enqueue" << endl;
    cout << "4. Dequeue"<< endl;
    cout << "5. Print Queue" << endl;
    cout << "6. Send Entire Message" << endl;
    cout << "7. Modify the Message" << endl;
    cout << "8. Update the Message Log" << endl;
    cout << "9. Quit" << endl;
}

