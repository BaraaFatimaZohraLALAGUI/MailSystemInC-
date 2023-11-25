// LALAGUI Baraa Fatima Zohra

#ifndef SPACEPARTA_H

#define SPACEPARTA_H

#include <iostream>

#include <fstream>

#include "MailServerPartA.h"

#include "User.h"

#include "Message.h"

#include "UserInfo.h"

#include <string>

using namespace std;

int cryptpassword(string password)
{

    string temp = password;
    int digit[5];
    int id = 0;
    for (int i = 0; i < 5; i++)
    {
        digit[i] = (int)password[i];
    }

    id = ((digit[0] * digit[1]  * digit[3] + digit[1] * digit[2] + digit[3] * digit[4]) * 793) % 100000;

    return id;
}

class SpacePartA

{

private:

    // the local server that the space manages
    MailServerPartA LocalServer;

    //the mail User that sends notification
    UserInfo mailDeliverySubsystem;

    //variable that keeps track of the execution time of the sending  
    double AverageExcutionTime;

public:

    // constructor 
    SpacePartA(MailServerPartA &something) : LocalServer(something)
    {

        AverageExcutionTime = 0;
    }

    //getters
     MailServerPartA &getserver() 
        { return LocalServer; }
    
    int getCurrentSize()
    {
        return LocalServer.getCurrentSize();
    }


    // a method to write a message to a user 

    void WriteMessage(User m)
    {

        string str;

        int id;

        //printing the name of the sender of the message 
        cout << m.getOwner().getName() << endl;

        //the sender writes the reciever's informations
        cout << "To : " << endl
             << "   Name : ";

        getline(cin, str);

        cout << "   ID : ";
        cin >> id;

        // initializing a temporary user receiver with the informations provided by the sender
            // to check his/her existence when we want to send it
        UserInfo reciever(str, id);

        string text;

        cin.ignore();

        //the user writes the message he wants to send to the specified receiver
        cout << "*************************************************************************************************************************************" << endl;

        getline(cin, text);

        cout << "\n************************************************************************************************************************************" << endl;

        //making a message with the infos provided by the sender 
        Message msg(m.getOwner(), reciever, text);

        // putting the new message into the mailserver
        LocalServer.putInServer(msg);
    }



    // fill the mailserver's queue mails with emails from file (the data set prepared)
        //to test with our data set
    void WriteMessage(User m, string str, int id, string text)
    {

        UserInfo reciever(str, id);

        Message msg(m.getOwner(), reciever, text);

        LocalServer.putInServer(msg);
    }


    // signing up : adding a new user to the mailserver

    User *SignUp()

    {
        cin.ignore();

        string str;

        string password;

        cout << "SIGN Up : " << endl;

        //gettingthe informations of the new user

        cout << "Enter full name : ";
        getline(cin, str);

        cout << "Enter Password  : ";
        getline(cin, password);

        //making a user ID out of his/her pssword
        int id = cryptpassword(password);

        UserInfo newUser(str, id);

        User *mail = new User(newUser);

        cin.ignore();


        // if the user's ID already exists than we can't add it
        while (!LocalServer.getUsers().insert(*mail))

        {

            //asking the user to input a different password untill the ID is valid
            cout << "Invalid password, try again : ";
                getline(cin, password);

            //crypting the password of the user to generate a unique ID out of it 
            int idtry = cryptpassword(password);
            
            // setting to the user the new ID 
            newUser.setID(idtry);

            // making the User with its new infos
            mail->setOwner(newUser);
        }

        // telling the User his/her ID after successfully adding the user into the mailserver
        cout << "Your personal ID is : " << mail->getOwner().getID();

        // returning the new User added to the mail server
        return mail;
    }



    // reading the mailBox of a given user from the space class
    void read(User user)
    {
        LocalServer.getUsers().findUser(user)->readMail();
    }

    // 
    User *SignIn()
    {
        cin.ignore();
        string str;

        int id;

        string password;


        //getting informations from User to open his/her account 
        cout << "SIGN IN : \n";

        cout << "       Full name  : ";
        getline(cin, str);

        cout << "       Password : ";
        getline(cin, password);

        //crypt password to know the ID
        id = cryptpassword(password);

        //temporary user used to check if the user exists
        UserInfo tempuser(str, id);
        User *tempmail = new User(tempuser);

        char ok;

        // check if the user exists  in mailserver 
            //if it doesn't : correct informations entered
        while (!LocalServer.getUsers().contains(*tempmail))
        {
            cout << "Name or Password wrong \n";

            cout << "Retry (y/n) \n";
            cin >> ok;

            if (ok == 'y')
            {
                SignIn();
                return tempmail;
            }
        }
        return tempmail;
    }


    bool send()
    {

        // base case : if all the messages are sent to their receivers
        if (LocalServer.getMails().empty())
        {
            return true;
        }

        //a temporary Message t ogo through all the messages in the mailserver
        Message temp = LocalServer.getMails().front();

        //poping the most recent message after storing it in temp
        LocalServer.getMails().pop();

        //storing the reciever in a temporary User to check if the reciever exists then sends the message 
        User *recepteur = new User(temp.getReciever());

        //checking if the reciever exists in the mailserver
        if (!LocalServer.getUsers().contains(*recepteur))
        {

            //if it does not exist we push the message  back to the maiserver 
            // ( to try again later when the mails queue has only messages that couldn't be sent)
            LocalServer.getMails().push(temp);

            return false;
        }

        // push the message into receiver's mailbox
        LocalServer.getUsers().findUser(*recepteur)->pushing(temp);

        return true;
    }


    // send all the messages got from senders to their ideal recievers
    void MakeEmpty()
    {

        //send messages that are in the mails queue one by one to their recievers according to the order they come in
        while (!LocalServer.getMails().empty() )

        {
            Message first = LocalServer.getMails().front();

            if (LocalServer.getMails().back() == LocalServer.getMails().front())
            {

                int counter =0;

                //trying to send the unsent message for three times (when the queue has only the unsent messages in it)
                while (counter != 3)
                {

                    if (send())
                    {
                        break;
                    }

                    else
                    {

                        counter++;
                    }
                }

                // notifying the sender that message couldn't be sent
                if (counter == 3)
                {

                    UserInfo destinataire = LocalServer.getMails().front().getSender();

                    int destinateur = LocalServer.getMails().front().getReciever().getID();

                    string notif = "Address not found , your message wasn't delivered to " + to_string(destinateur);

                    LocalServer.getMails().pop();

                    Message notification(mailDeliverySubsystem, destinataire, notif);

                    LocalServer.putInServer(notification);
                }
            }

            //sending the message to the appropriate receiver
            send();
        }
    }


    // Making Users by getting their data from file
    User *SignUp(string str, int &id)

    {

        UserInfo newUser(str, id);

        User *mail = new User(newUser);

        while (!LocalServer.getUsers().insert(*mail))

        {

            cout << "Invalid ID, try again : ";

            cin >> id;

            newUser.setID(id);

            mail->setOwner(newUser);
        }

        return mail;
    }


    void ReSetCurrentSize()
    {
        LocalServer.setCurrentSize(0);
    }
};

// get Users drom file and put them in the
void MakeUsers(User **users, int Size, SpacePartA &MySpace)

{

    string name;

    int ID;

    ifstream inputName, inputId;

    inputName.open("Name.txt");

    inputId.open("ID.txt");

    for (int i(0); i < Size; i++)

    {

        getline(inputName, name);

        inputId >> ID;

        users[i] = MySpace.SignUp(name, ID);
    }
}

void WriteMessages(User **users, int Size, SpacePartA &MySpace)

{

    string name;

    int ID;

    string text;

    ifstream inputName, inputId, inputText;

    inputName.open("Namesend.txt");

    inputId.open("IDsend.txt");

    inputText.open("Emails.txt");

    for (int i(0); i < Size; i++)

    {

        getline(inputName, name);

        inputId >> ID;

        getline(inputText, text);

        MySpace.WriteMessage(*users[i], name, ID, text);
    }
}

#endif // SPACE_H
