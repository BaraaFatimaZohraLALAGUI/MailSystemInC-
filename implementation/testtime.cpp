// LALAGUI Baraa Fatima Zohra G02

#include <iostream>
#include "Message.h"
#include "UserInfo.h"
#include "User.h"
#include "HashTable.h"
#include "MailServerPartA.h"
#include "MailServerPartB.h"
#include "MailServerPartC.h"
#include "SpacePartA.h"
#include "SpacePartB.h"
#include "SpacePartC.h"
#include "Time.cpp"

#include "Homepages.cpp"

using namespace std;

void ExecutionTimeTestA()
{
    cout << "THE TEST PROGRAM FOR THE EXCUTION TIME USING Hash Table " << endl;

    MailServerPartA localserver;

    SpacePartA Space(localserver);

    User *users[100];

    MakeUsers(users, 100, Space);

    WriteMessages(users, 100, Space);

    cout << "THE AVERAGE SEND TIME USING Hash Table IS : " << getAverageSendingTime(Space) << endl;

    cout << endl
         << "END" << endl;
}

void ExecutionTimeTestB()
{
    cout << "THE TEST PROGRAM FOR THE EXCUTION TIME USING BS TREE " << endl;

    MailServerPartB localserver;

    SpacePartB Space(localserver);

    User *users[100];

    MakeUsers(users, 100, Space);

    WriteMessages(users, 100, Space);

    cout << "THE AVERAGE SEND TIME USING BS TREE IS : " << getAverageSendingTime(Space) << endl;

    cout << endl
         << "END" << endl;
}

void ExecutionTimeTestC()
{
    cout << "THE TEST PROGRAM FOR THE EXCUTION TIME USING AVL tree " << endl;

    MailServerPartC localserver;

    SpacePartC Space(localserver);

    User *users[100];

    MakeUsers(users, 100, Space);

    WriteMessages(users, 100, Space);

    cout << "THE AVERAGE SEND TIME USING AVL tree IS : " << getAverageSendingTime(Space) << endl;
}

int main()

{

    ExecutionTimeTestC();
    cout << "___________________________________________________________________________________________________________________" << endl;
    ExecutionTimeTestA();
    cout << "___________________________________________________________________________________________________________________" << endl;
    ExecutionTimeTestB();
    cout << "___________________________________________________________________________________________________________________" << endl;
}