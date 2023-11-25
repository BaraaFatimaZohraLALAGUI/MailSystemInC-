// LALAGUI Baraa Fatima Zohra

#ifndef MAILSERVER_H
#define MAILSERVER_H
#include<iostream>
#include<queue>
#include"UserInfo.h"
#include"HashTable.h"
#include"User.h"
#include"Message.h"


class MailServerPartA{

    private:

    //a queue that stores the messages sent by all the users in the mailserver
    queue<Message> Mails;

    //HashTable that stores all the users of the mailserver 
    HashTable Users;

    //the size of the mails (the number of messages in the mailserver)
    int curentSize = 0;


    public:

    MailServerPartA()
    {

    }

    //Setters and getters of data members 

    int getCurrentSize()
    {
        return curentSize;
    }

    void setCurrentSize(int size)
    {
        curentSize = size;
    }

    queue<Message>& getMails()
    {
        return Mails;
    }

    HashTable& getUsers()
    {
        return Users;
    }


    //put a message in the queue of mails 
        //adding a new message to the server
    void putInServer(Message &msg)
    {
        Mails.push(msg);

        //increment the size of the mails queue
        curentSize++;
    }


};


#endif
