#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H
#include<string>
#include<vector>


//header just for classes no functions

struct city{

    std::string name;
    std::string message; //intended to hold one word
    city *next;
    city *previous;
    bool transmit;
    city(){
        next = NULL;
        previous = NULL;
        transmit = true;
        name = "";
        message="";
    }

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
        void printPath();
        void sendEntireMessage(std::vector<std::string>&);
        void modMessage(std::string, std::string); //modify message, and send modified message to next node
        void updMessageLog(); // update the changes made to the master file, for tracking

    protected:
    private:
        city *head;  //havent set head or tail yet
        city *tail;
        int queueSize;
        int queueHead;
        int queueTail;
        void addCity(city *, std::string);
        bool queueIsFull(); //send when full
        void transmitMsg(std::string);
        std::string *arrayQueue;
};

#endif // COMMUNICATIONNETWORK_H
