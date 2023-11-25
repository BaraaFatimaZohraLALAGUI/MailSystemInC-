// LALAGUI Baraa Fatima Zohra

#ifndef USERINFO_H

#define USERINFO_H

#include <iostream>

using namespace std;

class UserInfo
{

private:
    string name;

    string password;

    int ID;

public:

    //setters and getters for data members

    void setName(string n)

    {

        name = n;
    }

    void setID(int id)

    {

        ID = id;
    }

    const string getName() const

    {

        return name;
    }

    const int getID() const

    {

        return ID;
    }

    //constructor

    UserInfo(string &n, int &id)

    {

        setName(n);

        setID(id);
    }


    //copy constructor
    UserInfo(const UserInfo &user)

    {

        name = user.name;

        ID = user.ID;
    }


    //constructor
    UserInfo(string &&n, int &&id)

    {

        name = std::move(n);

        ID = std::move(id);
    }


    //default constructor
    UserInfo()

    {

        name = "";

        ID = 0;
    }

    //overloading assignement operator

    UserInfo &operator=(UserInfo &user)

    {

        name = user.name;

        ID = user.ID;

        return *this;
    }


//overloading comparision operators 

    bool operator==(UserInfo &user)

    {

        if (name == user.name && ID == user.ID)

        {

            return true;
        }

        return false;
    }

    bool operator<(UserInfo &user)

    {

        if (ID < user.ID)

        {

            return true;
        }

        return false;
    }

    bool operator>(UserInfo &user)

    {

        if (ID > user.ID)

        {

            return true;
        }

        return false;
    }
};

#endif // USERINFO_H