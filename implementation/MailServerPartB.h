// LALAGUI Baraa Fatima Zohra

#ifndef MAILSERVERPARTB_H

#define MAILSERVERPARTB_H

#include <iostream>

#include <queue>

#include "UserInfo.h"

#include "BSTree.h"

#include "User.h"

#include "Message.h"

class MailServerPartB
{

private:
    queue<Message> Mails;

    BSTree Users;

    int CurrentSize = 0;


public:
    MailServerPartB() : CurrentSize(0)

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

    queue<Message> &getMails()

    {

        return Mails;
    }

    BSTree &getUsers()

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