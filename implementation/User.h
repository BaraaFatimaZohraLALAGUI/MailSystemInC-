// LALAGUI Baraa Fatima Zohra

#ifndef USER_H

#define USER_H

#include <iostream>

#include "Message.h"

#include <list>

#include "UserInfo.h"

using namespace std;

class User
{

private:

    //owner of the mailbox
    UserInfo owner;

    //the mailbox : it has all the message that are sent to the owner
    list<Message> MailBox;

public:

    //Constructor 
    User(UserInfo user) : owner(user)
    {
    }

    //pushing a new message into the mailbox (in front)
    void pushing(const Message &msg)
    {
        MailBox.push_front(msg);
    }

    //reads all the messages of the owner 
        //writting the messages on screen
    void reading()
    {

        if (!MailBox.empty())
        {

            Message temp = MailBox.front();

            temp.readMessage();

            MailBox.pop_front();

            MailBox.push_back(temp);

            MailBox.back().setSeen(true);
        }
    }

    //check if all the messages in the mailbox are seen 
            //the owner of the milbox has read all his/her messages
    bool checkMail()
    {

        if (MailBox.empty())

        {

            return false;
        }

        if (!MailBox.front().getSeen())

        {

            return true;
        }

        return false;
    }


    //reads all the unseen messages of the owner 
        //writting the messages on screen
    void readMail()
    {

        if (checkMail())

        {

            while (checkMail())

            {

                reading();
            }
        }

        //if all the messages are read
        else

            cout << "You have read all your messages !" << endl;
    }

    //Setters and getters of data members

    const UserInfo &getOwner() const
    {

        return owner;
    }

    void setOwner(UserInfo &user)
    {

        owner = user;
    }

    list<Message> &getMymail()
    {

        return MailBox;
    }


    //overloading operators
    
    bool operator==(const User &user) const
    {

        if (owner.getName() == user.getOwner().getName() && owner.getID() == user.getOwner().getID())

        {

            return true;
        }

        return false;
    }

    bool operator<(const User &user) const
    {

        if (owner.getID() < user.getOwner().getID())

        {

            return true;
        }

        return false;
    }

    bool operator>(const User &user) const
    {

        if (owner.getID() > user.getOwner().getID())

        {

            return true;
        }

        return false;
    }

    friend ostream &operator<<(ostream &output, User &user);

    void operator=(User &x)
    {

        UserInfo temp(x.getOwner());

        owner = temp;

        for (auto &val : x.getMymail())

        {

            MailBox.push_front(val);
        }
    }

   
};

//overloading extraction operator

ostream &operator<<(ostream &output, User &user)
{

    cout << "the user :" << endl;

    cout << "Name : ";

    output << user.getOwner().getName() << endl;

    cout << "ID : ";

    output << user.getOwner().getID() << endl;

    return output;
}

#endif // USER_H