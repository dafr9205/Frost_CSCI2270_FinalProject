# Frost_CSCI2270_FinalProject

Project Summary:

For my final project in this class, I will be modifying a previous HW assignment to include additional functionality. The assignment will be assignment 4, where we used enqueue and dequeue to transmit a message from city to city. The additional functionality that I will be adding will be related to the message itself; I would like to include options to modify the message, and change an output file to include a message of which city the message was modified in, and possibly even something like a timestamp. I am attempting to create a “post-apocalyptic” messaging system, which can be used between main city hubs to communicate with each-other (as well as update the message, and see who the last city to update or change it was.) I might even include message history in a “show-file log,” so that you can see when it was changed. 

How to Run:

I will be using a menu-style function, which will allow the user to make changes to the message. 
I have included to additional menu functions to the original layout.
If option 7 is chosen, the system asks the user for a replacement word, then asks which city is sending the replacement word.
If option 8 is chosen, the updated message is outputted to a new log file, which tracks changes made to the original message (including which node sent the last update).


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


