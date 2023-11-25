// LALAGUI Baraa Fatima Zohra

#ifndef HASHTABLE_H

#define HASHTABLE_H

#include <vector>

#include <list>

#include <string>

#include <algorithm>

#include <functional>

#include "User.h"

using namespace std;



bool isPrime( int n )

{

    if( n == 2 || n == 3 )

        return true;



    if( n == 1 || n % 2 == 0 )

        return false;



    for( int i = 3; i * i <= n; i += 2 )

        if( n % i == 0 )

            return false;



    return true;

}



/**

* Internal method to return a prime number at least as large as n.

* Assumes n > 0.

*/

int nextPrime( int n )

{

    if( n % 2 == 0 )

        ++n;

 for( ; !isPrime( n ); n += 2 )

        ;



    return n;

}

int nextPrime( int n );



// SeparateChaining Hash table class

//

// CONSTRUCTION: an approximate initial size or default of 101

//

// ******************PUBLIC OPERATIONS*********************

// bool insert( x )       --> Insert x

// bool remove( x )       --> Remove x

// bool contains( x )     --> Return true if x is present

// void makeEmpty( )      --> Remove all items



class HashTable

{

  public:

    explicit HashTable( int size = 101 ) : currentSize{ 0 }

      { theLists.resize( size ); }//resize(size)



    bool contains( const User & x )

    {

        auto & whichList = theLists[ myhash( x ) ];

        return find( begin( whichList ), end( whichList ), x ) != end( whichList );

    }

    void makeEmpty( )

    {

        for( auto & thisList : theLists )

            thisList.clear( );

    }



    bool insert( const User & x )

    {

        auto & whichList = theLists[ myhash( x ) ];

        if( find( begin( whichList ), end( whichList ), x ) != end( whichList) )//don t allow duplicate

        return false;

        whichList.push_back( x );


        if( ++currentSize > theLists.size( ) )

            rehash( );

        return true;

    }



    bool insert( User && x )

    {



        auto & whichList = theLists[ myhash( x ) ];

        if( find( begin( whichList ), end( whichList ), x ) != end( whichList ) )

            {return false;}

        whichList.push_back( std::move( x ) );





        if( ++currentSize > theLists.size( ) )

            rehash( );



        return true;

    }





    bool remove( const User & x )

    {

        auto & whichList = theLists[ myhash( x ) ];

        auto itr = find( begin( whichList ), end( whichList ), x );



        if( itr == end( whichList ) )

            return false;

        whichList.erase( itr );

        --currentSize;

        return true;

    }

    /*
            overwriting the function for class user

    */
   const list<User>::iterator & findUser(const User & u)
   {

        auto & whichList = theLists[ myhash( u ) ];
        const auto & temp = find( begin( whichList ), end( whichList ), u );

        return temp ;

   }

    void read(User user)
    {
            findUser(user)->readMail();
    }

    const list<User>::iterator find(list<User>::iterator fitr, list<User>::iterator litr, const User & u)//overwriting for the function find

    {

        for(;fitr!=litr;fitr++)

        {

            if((*fitr).getOwner().getID() == u.getOwner().getID())

                    break;
        }

        return fitr;

    }



  private:

    vector<list<User>> theLists;   // The array of Lists

    int  currentSize;



    void rehash( )

    {

        vector<list<User>> oldLists = theLists;



            // Create new double-sized, empty table

        theLists.resize( nextPrime( 2 * theLists.size( ) ) );

        for( auto & thisList : theLists )

            thisList.clear( );



            // Copy table over

        currentSize = 0;

        for( auto & thisList : oldLists )

            for( auto & x : thisList )

                insert( std::move( x ) );

    }

    size_t myhash( const User & x ) const

    {

        static hash<int> hf;

        return hf( x.getOwner().getID() ) % theLists.size( );

    }

};

// second hash function can be the small prime number before the size so we get x = prime -(hf(x)%prime) static hash<type> hf



#endif // HASHTABLE_H
