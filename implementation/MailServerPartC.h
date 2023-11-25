// LALAGUI Baraa Fatima Zohra

#ifndef MAILSERVERPARTC_H

#define MAILSERVERPARTC_H

#include<iostream>

#include<queue>

#include"UserInfo.h"

#include "AvlTree.h"

#include"User.h"

#include"Message.h"

 

class MailServerPartC{

 

private:

queue<Message> Mails;

AvlTree Users;

int CurrentSize = 0;


 

public:

 

MailServerPartC():CurrentSize(0)

{

 

}

int getCurrentSize()

{

    return CurrentSize;

}




void setCurrentSize(int size)
{
    CurrentSize = size;
}

 

queue<Message>& getMails()

{

    return Mails;

}

 

AvlTree & getUsers()

{

    return Users;

}

 

void putInServer(Message &msg)

{

    Mails.push(msg);

    CurrentSize++;

}

};

#endif // MAILSERVER_H