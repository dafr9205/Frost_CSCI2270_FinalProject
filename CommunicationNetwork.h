#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include<string>


//header just for classes no functions

struct city{

    std::string name;
    std::string message; //intended to hold one word
    city *next;
    city *previous;

};



class CommunicationNetwork
{
    public:
        CommunicationNetwork(int);
        virtual ~CommunicationNetwork(){};
        //circular queue methods
        int enqueue(std::string);
        void dequeue(); //should send through network, call transmit msg
        void printQueue();
        void buildNetwork();
        void addCity(city *, std::string);
        void printPath();
        bool queueIsFull(); //send when full
        void transmitMsg(std::string);
        void sendEntireMessage();
        void modMessage(); //modify message, and send modified message to next node
        void updMessageLog(); // update the changes made to the master file, for tracking

    protected:
    private:
        city *head;  //havent set head or tail yet
        city *tail;
        int queueSize;
        int queueHead;
        int queueTail;
        std::string *arrayQueue;
};

#endif // COMMUNICATIONNETWORK_H
