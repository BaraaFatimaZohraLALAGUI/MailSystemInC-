// LALAGUI Baraa Fatima Zohra

#include <iostream>
#include "SpacePartA.h"
#include "SpacePartB.h"
#include "SpacePartC.h"

using namespace std;

/**
 * Functions to test the code for the different implementation of Users ADT
 *
 */

void HomePagePartA()
{

    MailServerPartA local;

    SpacePartA s(local);

    User *user;

first:

    cout << "                                            WELCOME TO EMAIL SERVICE " << endl;

    cout << "                                                    HOME" << endl;

    int choice;

    cout << endl;

    cout << "TO SIGN UP PRESS 01" << endl;

    cout << "TO SIGN IN PRESS 02" << endl;

    cout << "TO CLOSE PRESS 00" << endl;

    cout << endl;

    cin >> choice;

    switch (choice)

    {

    case 01:

    {

        user = s.SignUp();

        break;
    }

    case 02:

    {

        user = s.SignIn();

        break;
    }

    default:

    {

        return;
    }
    }

    while (choice != 0)

    {

        cout << endl;

        cout << "TO LOG OUT PRESS 00 " << endl;

        cout << "TO WRITE MESSAGE PRESS 01" << endl;

        cout << "TO READ MAIL PRESS 02" << endl;

        cout << "TO CHANGE ACOUNT PRESS 03" << endl;

        cout << endl;

        cin >> choice;

        cin.ignore();

        switch (choice)

        {

        case 01:

        {

            s.WriteMessage(*user);

            s.MakeEmpty();

            break;
        }

        case 02:

        {

            s.read(*user);

            break;
        }

        case 03:

        {

            goto first;
        }

        default:

        {

            return;
        }
        }
    }
}

void HomePagePartB()
{

    MailServerPartB local;

    SpacePartB s(local);

    User *user;

first:

    cout << "                                            WELCOME TO EMAIL SERVICE " << endl;

    cout << "                                                    HOME" << endl;

    int choice;

    cout << endl;

    cout << "TO SIGN UP PRESS 01" << endl;

    cout << "TO SIGN IN PRESS 02" << endl;

    cout << "TO CLOSE PRESS 00" << endl;

    cout << endl;

    cin >> choice;

    switch (choice)

    {

    case 01:

    {

        user = s.SignUp();

        break;
    }

    case 02:

    {

        user = s.SignIn();

        break;
    }

    default:

    {

        return;
    }
    }

    while (choice != 0)

    {

        cout << endl;

        cout << "TO LOG OUT PRESS 00 " << endl;

        cout << "TO WRITE MESSAGE PRESS 01" << endl;

        cout << "TO READ MAIL PRESS 02" << endl;

        cout << "TO CHANGE ACOUNT PRESS 03" << endl;

        cout << endl;

        cin >> choice;

        cin.ignore();

        switch (choice)

        {

        case 01:

        {

            s.WriteMessage(*user);

            s.MakeEmpty();

            break;
        }

        case 02:

        {

            user->readMail();

            break;
        }

        case 03:

        {

            goto first;
        }

        default:

        {

            return;
        }
        }
    }
}

void HomePagePartC()
{

    MailServerPartC local;

    SpacePartC s(local);

    User *user;

first:

    cout << "                                            WELCOME TO EMAIL SERVICE " << endl;

    cout << "                                                    HOME" << endl;

    int choice;

    cout << endl;

    cout << "TO SIGN UP PRESS 01" << endl;

    cout << "TO SIGN IN PRESS 02" << endl;

    cout << "TO CLOSE PRESS 00" << endl;

    cout << endl;

    cin >> choice;

    switch (choice)

    {

    case 01:

    {

        user = s.SignUp();

        break;
    }

    case 02:

    {

        user = s.SignIn();

        break;
    }

    default:

    {

        return;
    }
    }

    while (choice != 0)

    {

        cout << endl;

        cout << "TO LOG OUT PRESS 00 " << endl;

        cout << "TO WRITE MESSAGE PRESS 01" << endl;

        cout << "TO READ MAIL PRESS 02" << endl;

        cout << "TO CHANGE ACOUNT PRESS 03" << endl;

        cout << endl;

        cin >> choice;

        cin.ignore();

        switch (choice)

        {

        case 01:

        {

            s.WriteMessage(*user);

            s.MakeEmpty();

            break;
        }

        case 02:

        {

            user->readMail();

            break;
        }

        case 03:

        {

            goto first;
        }

        default:

        {

            return;
        }
        }
    }
}