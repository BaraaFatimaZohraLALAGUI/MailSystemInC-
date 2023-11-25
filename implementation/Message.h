// LALAGUI Baraa Fatima Zohra

#ifndef MESSAGE_H
#define MESSAGE_H
#include<iostream>
#include"UserInfo.h"

class Message
{

    private:

    UserInfo sender ;
    UserInfo reciever;
    string text;
    bool seen;


    public:


    //constructor
    Message(UserInfo s, UserInfo r, string str): sender(s), reciever(r), text(str)
    {
        seen = false;
    }

    //copy constructor
    Message(const Message &msg):sender(msg.sender), reciever(msg.reciever)
    {
        text = msg.text;
        seen = false;
    }

    //Setters and getters of the  data members :

    UserInfo getSender()
    {
        return sender;
    }
    UserInfo getReciever()
    {
        return reciever;
    }
    string getText()
    {
        return text;
    }

    bool getSeen()
    {
        return seen;
    }


    void setSeen(bool ok)
    {
        seen = ok;
    }

    //to compose a message
    void fillMessage(string str)
    {
        text = str;
    }

    //writing message on screen 
    void readMessage()
    {
        cout<<"From : "<<sender.getName()<<endl;
        cout<<"To : "<<reciever.getName()<<endl;
        cout<<text<<endl;

        //make the message marked as read (the receiver read the email)
        seen = true;

    }


    //overloading the equality operator for the messges 
    bool operator==(Message &msg)
    {
        if(sender == msg.sender && reciever == msg.reciever && text == msg.text)
        {
            return true;
        }
        return false;
    }

};


#endif
