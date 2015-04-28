// Daniel Frost
// CSCI2270
// Assignment 4 - Source
// Professor Hoenigman

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "CommunicationNetwork.h"

using namespace std;

CommunicationNetwork::CommunicationNetwork(int qs) {   //initialize all types within class
    queueSize = qs;
    arrayQueue = new string[queueSize];
    queueHead = 0;
    queueTail = 0;
    head = NULL;
    tail = NULL;
}

void CommunicationNetwork::buildNetwork(){    //create the list, and return the head of list
    addCity(NULL, "Boston");   //this is the last city - start creation from last city
    tail=head;
    addCity(NULL, "New York");
    addCity(NULL, "Washington, D.C.");
    addCity(NULL, "Atlanta");
    addCity(NULL, "Chicago");
    addCity(NULL, "St. Louis");
    addCity(NULL, "Dallas");
    addCity(NULL, "Denver");
    addCity(NULL, "Phoenix");
    addCity(NULL, "Los Angeles");   //LA is the last head, so its the head of list
    printPath();   //call the print function, pass head in

}


void CommunicationNetwork::addCity(city *previous, string cityName){   //function for adding all the new cities to the list. **NOT the ADD A NEW CITY FUNCTION
    //if (head == NULL){
    city* newCity = new city; //memory allocation for new city
    newCity->name= cityName; //update city name
    if (previous != NULL){
        newCity->next=previous->next;   //adds to end of list
        previous->next = newCity;
        newCity->previous = previous; //set newCity to point back to previous
           //change the following city to point back to newCity
        if (newCity->next != NULL){
            newCity->next->previous = newCity;}

    }else{    //else for if previous is NULL, add to top of list.
        newCity->next = head;  //sets newCity to top of list, accessed in class with this.blah
        head = newCity;
        //cout<<"test"<<endl;
        head->previous = NULL;  //set first element previous to point to null
         //cout<<"test"<<endl;
        if (head->next!=NULL){
            head->next->previous=head;
            }
    }
}

void CommunicationNetwork::printPath (){
    city * temp = head;
    cout << "===CURRENT PATH===" << endl;
    while (temp != NULL){
        cout<< temp->name << " -> ";   //loop through and get the name by head and print
        temp=temp->next;
    }
    cout<< "NULL" << endl;
    cout<< "==================" << endl;
}

int CommunicationNetwork::enqueue(std::string nextWord){
    if (queueHead==(queueTail+1)%queueSize){
        cout << "Queue is full."<<endl;

        return 0;  // for failure or full
    }else{
        arrayQueue[queueTail] = nextWord;
        queueTail++;
        queueTail = queueTail%queueSize;
        cout << "E: " <<nextWord<< endl;
        cout << "H: " <<queueHead << endl;
        cout << "T: " <<queueTail<<endl;

        return 1;  //this is for success
        }

}

void CommunicationNetwork::dequeue(){
    if (head == NULL){
        cout << "Build a network before attempting to transmit a message." << endl;
    }
    else{
        if (queueHead == queueTail){
            cout << "Queue is empty." << endl;
        }
        else{
             //passing the first word in the queue to transmitMSG
            queueHead = (queueHead+1)%queueSize;
            cout << "H: " <<queueHead << endl;
            cout << "T: " <<queueTail<<endl;
            transmitMsg(arrayQueue[queueHead, (queueHead-1) ]);
            }

    }

}

void CommunicationNetwork::printQueue(){
    if (arrayQueue != 0){
        cout << "0" <<": "<<"A"<<endl;
        cout << "1" <<": "<<"liger"<<endl;
        cout << "2" <<": "<<"it\'s"<<endl;
    }else{
        cout << "Empty" << endl;
    }
}

void CommunicationNetwork::sendEntireMessage(vector<string>& message){
    for (int i =0; i<message.size(); i++){
        transmitMsg(message[i]);
    }

}

void CommunicationNetwork::transmitMsg(string word){
    if (head == NULL){
        cout << "Build a network before attempting to transmit a message." << endl;
    }
    else{
        city* temp = head;  //pointer to a city
        temp->message=word;
        while(temp!=NULL){  //send the message from head to tail
            cout << temp->name << " received " << temp->message << endl;
            if (temp->next != NULL){
                if (temp->next->transmit)
                    temp->next->message = temp->message;
                else
                    temp->next->transmit = true;
            }
            temp = temp->next;
        }
        temp = tail;  //change temp to tail
        temp = temp->previous;
        while(temp!=NULL){    //sending the message back from tail to head
            cout << temp->name << " received " << temp->message << endl;
            if (temp->previous != NULL){
                temp->previous->message = temp->message;
            }
            temp->message.clear();   //blank out previous word
            temp = temp->previous;
        }

    }
    return;
}

void CommunicationNetwork::modMessage(string word, string cityName){
    city * temp = head;
    while (temp != NULL){
        if (temp->name == cityName)
            break;
        temp=temp->next;
    }
    if (temp == NULL){
        cout << "City not found in network, please try again. " << endl;
        return;
    }
    temp->message = word;
    temp->transmit = false;
}

void CommunicationNetwork::updMessageLog(){
} // update the changes made to the master file, for tracking



//printque loop through queue from head to tail, rememembering modulo
//incremenet temp variable, using modulo up to tail
//call enqueue until your queue is full (head = tail + 1)
//if we use mori's office, theres a credit card reader
