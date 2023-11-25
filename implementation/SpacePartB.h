// LALAGUI Baraa Fatima Zohra

#ifndef SPACEPARTB_H

#define SPACEPARTB_H

#include <iostream>

#include <fstream>

#include "MailServerPartB.h"

#include "User.h"

#include "Message.h"

#include "UserInfo.h"

using namespace std;

int cryptpassword(string password);

class SpacePartB

{

private:
    MailServerPartB LocalServer;

    UserInfo mailDeliverySubsystem;

    double AverageExcutionTime;

public:
    MailServerPartB &getserver() { return LocalServer; }

    SpacePartB(MailServerPartB &something) : LocalServer(something)

    {

        AverageExcutionTime = 0;
    }

    void WriteMessage(User m)

    {

        string str;

        int id;

        cout << m.getOwner().getName() << endl;

        cout << "To : " << endl
             << "Name : ";

        getline(cin, str);

        cout << "ID : ";
        cin >> id;

        UserInfo reciever(str, id);

        string text;

        cin.ignore();

        cout << "*****" << endl;

        getline(cin, text);

        cout << "\n*****" << endl;

        Message msg(m.getOwner(), reciever, text);

        LocalServer.putInServer(msg);
    }

    // to get emails from file

    void WriteMessage(User m, string str, int id, string text)

    {

        UserInfo reciever(str, id);

        Message msg(m.getOwner(), reciever, text);

        LocalServer.putInServer(msg);
    }

    User *SignUp()

    {
        cin.ignore();

        string str;

        string password;

        cout << "SIGN Up : " << endl;

        cout << "Enter full name : ";
        getline(cin, str);

        cout << "Enter Password  : ";
        getline(cin, password);

        int id = cryptpassword(password);

        UserInfo newUser(str, id);

        User *mail = new User(newUser);

        cin.ignore();

        while (!LocalServer.getUsers().insert(mail))

        {

            cout << "Invalid password, try again : ";
            cin >> password;

            int idtry = cryptpassword(password);
            newUser.setID(idtry);

            mail->setOwner(newUser);
        }

        cout << "Your personal ID is : " << mail->getOwner().getID();

        return mail;
    }

    User *SignIn()
    {
        cin.ignore();
        string str;

        int id;

        string password;

        cout << "SIGN IN : \n";

        cout << "Full name  : ";
        getline(cin, str);

        cout << "Password : ";
        getline(cin, password);

        id = cryptpassword(password);

        UserInfo tempuser(str, id);

        User *tempmail = new User(tempuser);

        char ok;

        while (!LocalServer.getUsers().contains(tempmail))
        {
            cout << "Name or Password wrong \n";

            cout << "Retry (y/n) \n";
            cin >> ok;

            if (ok == 'y')
            {
                SignIn();
                return LocalServer.getUsers().findUser(tempmail);
            }
        }
        return tempmail;
    }

    int getCurrentSize()
    {
        return LocalServer.getCurrentSize();
    }

    void ReSetCurrentSize()
    {
        LocalServer.setCurrentSize(0);
    }

    bool send()

    {

        if (LocalServer.getMails().empty())

        {

            return true;
        }

        Message temp = LocalServer.getMails().front();

        LocalServer.getMails().pop();

        User *recepteur = new User(temp.getReciever());

        if (!LocalServer.getUsers().contains(recepteur))

        {

            LocalServer.getMails().push(temp);

            return false;
        }

        LocalServer.getUsers().findUser(recepteur)->pushing(temp);

        return true;
    }

    void MakeEmpty()

    {

        while (!LocalServer.getMails().empty())

        {
            Message first = LocalServer.getMails().front();

            if (LocalServer.getMails().back() == LocalServer.getMails().front() )

            {

                  int counter = 0;

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

            send();
        }
    }

    // utility function used To get users from file

    User *SignUp(string str, int &id)

    {
        UserInfo newUser(str, id);

        User *mail = new User(newUser);

        while (!LocalServer.getUsers().insert(mail))

        {

            cout << "Invalid Password, try again : ";

            cin >> id;

            newUser.setID(id);

            mail->setOwner(newUser);
        }

        return mail;
    }
};

// getting users from file (signing up from files)
void MakeUsers(User **users, int Size, SpacePartB &MySpace)

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

void WriteMessages(User **users, int Size, SpacePartB &MySpace)

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
