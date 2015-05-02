# Frost_CSCI2270_FinalProject

Project Summary:

For my final project in this class, I will be modifying a previous HW assignment to include additional functionality. 
The assignment I am modifying is assignment 4, where we used enqueue and dequeue to transmit a message from city to city. 
The additional functionality that I implemented will be related to the message itself.
I added an extra menu item (option 7) which allows the user to input a replacement word, as well as which node is sending the replacement word.
You can then choose option 6 to send the entire message - it shows the replacement word sent, starting at the node the user chose to send the replacement message from. 

How to Run:

I will be using a menu-style function, which will allow the user to make changes to the message. 
I have included additional menu functions to the original options from our assignment.
If option 7 is chosen, the system asks the user for a replacement word, then asks which city is sending the replacement word.
The modified medsage can then be tested by sending the entire message (option 6).
If option 8 is chosen, the updated message is outputted to a new log file, which tracks changes made to the original message (including which node sent the last update).
*Please note - option 8 is not operational yet.*


The new menu layout has had two additional menu functions added, right before the quit function. (Those options are now #7 and #8 - seen below, with asterisks):

======Main Menu=====
1. Build Network
2. Print Network Path
3. Enqueue
4. Dequeue
5. Print Queue
6. Send Entire Message
7. *Replace a Word*
8. *Update the Message Log*   
9. Quit

Options 7 and 8 are the new options included, which allow for changes to the message (including which node is updating a word).


Future Features:

I am still working on getting a version of this program running with option 8. This option will use ofstream to write the new, modified message,
into a seperate message output file, so that a message log of changes can be viewed by the user. 



Dependencies:

iostream
fstream
string (in CommunicationNetwork.cpp and .h)
sstream
vector (only in .h)
include"CommunicationNetwork.h"


System Requirements:

--any standard linux operating environment, with respective commands (i.e. sunOS vs. ubuntu, redhat, etc..)

Group Members:

Just me - Daniel Frost

Contributors:

--

Open issues/bugs:

-- Currently, option 8, that outputs the changes of the message to a logfile, is still not complete. Option 7 is fully functional. 


