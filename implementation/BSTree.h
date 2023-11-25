// LALAGUI Baraa Fatima Zohra

#ifndef BSTREE_H

#define BSTREE_H

#include <algorithm>

#include <iostream>

#include "User.h"

using namespace std;

 

class BSTree

{

  public:

    BSTree( ) : root{ nullptr }{}//constructor

 

    BSTree( const BSTree & rhs ) : root{ nullptr }//copy constructor

    {

        root = clone( rhs.root );

    }

 

    BSTree( BSTree && rhs ) : root{ rhs.root }//move constructor

    {

        rhs.root = nullptr;

    }

 

    ~BSTree( )//destructor

    {

        makeEmpty( );

    }

 

    BSTree & operator=( const BSTree & rhs )//copy assignment

    {

        BSTree copy = rhs;

        std::swap( *this, copy );

        return *this;

    }

 

    BSTree & operator=( BSTree && rhs )//move assignment

    {

        std::swap( root, rhs.root );

 

        return *this;

    }

 

    bool contains(User * & x ) const

    {

        return contains( x, root );

    }

 

 

    bool isEmpty( ) const

    {

        return root == nullptr;

    }

 

    void printTree( ) const //in order print implemented to check if tree has users 

    {

        if( isEmpty( ) )

            cout << "Empty tree" << endl;

        else

            printTree( root );

    }

 

    void makeEmpty( )

    {

        makeEmpty( root );

    }

 

    /**

     * Insert user into the tree; duplicates are ignored.
*/

    bool insert(User * & x )

    {

        return insert( x, root );

    }

    /**

    * find user then return it to system

*/
    User * findUser(User * x)

    {

        x=findUser(x,root);

        return x;

    }

  private:

    struct BSTNode

    {

        User * element;

        BSTNode   *left;

        BSTNode   *right;

 

        BSTNode(User * ele, BSTNode *lt, BSTNode *rt )

          : element{ ele }, left{ lt }, right{ rt } { }

 

    };

 

    BSTNode *root;

 

 

    /**

     * Internal method to insert into a subtree.

     * x is the item to insert.

     * t is the node that roots the subtree.

     * Set the new root of the subtree.
*/
    

    User * findUser(User * x,BSTNode * t)

    {

        if( *x < *(t->element) )

            return findUser( x, t->left );

        else if( *(t->element) < *x )

           return findUser( x, t->right );

        else

           {

               return  t->element;

           }

    }

    bool insert(User * & x, BSTNode * & t )

    {

        if( t == nullptr )

        {

            t = new BSTNode{ x, nullptr, nullptr };

            return true;

        }

        else

        {

            if( *x < *(t->element) )

            return insert( x, t->left );

            else

            {

                if( *(t->element) < *x )

                    return insert( x, t->right );

                else

                    return false;//don't allow duplicate

            }

        }

    }

 

    /** the internal contains method */

    bool contains( const User * x, BSTNode *t ) const

    {

        if( t == nullptr )

            return false;

        if((*x)==*(t->element))

            return true;

        else if( *x < *(t->element) )

            return contains( x, t->left );

        else if( *(t->element) < *x )

            return contains( x, t->right );

            else

                return true;

    }

 

    void makeEmpty( BSTNode * & t )

    {

        if( t != nullptr )

        {

            makeEmpty( t->left );

            makeEmpty( t->right );

            delete t;

        }

        t = nullptr;

    }

 

    void printTree( BSTNode *t ) const

    {

        if( t != nullptr )

        {

            printTree( t->left );

            cout << *(t->element) << endl;

            printTree( t->right );

        }

    }

 

    /**

     * Internal method to clone subtree.0
*/ 

    BSTNode * clone( BSTNode *t ) const

    {

        if( t == nullptr )

            return nullptr;

        else

        {

            User* temp=new User(*(t->element));

            return new BSTNode(temp, clone( t->left ), clone( t->right ) );

        }

 

    }

};

 

 

#endif // BSTree_H_INCLUDED
