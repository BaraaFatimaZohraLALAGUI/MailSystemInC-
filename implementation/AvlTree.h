// LALAGUI Baraa Fatima Zohra

#ifndef AVL_TREE_H

#define AVL_TREE_H

#include <algorithm>

#include <iostream>

#include "User.h"

using namespace std;

 

// AvlTree class

//

// CONSTRUCTION: zero parameter

//

// ******************PUBLIC OPERATIONS*********************

// void insert( x )       --> Insert x

// void remove( x )       --> Remove x (unimplemented)

// bool contains( x )     --> Return true if x is present

// Comparable findMin( )  --> Return smallest item

// Comparable findMax( )  --> Return largest item

// boolean isEmpty( )     --> Return true if empty; else false

// void makeEmpty( )      --> Remove all items

// void printTree( )      --> Print tree in sorted order

// ******************ERRORS********************************

// Throws UnderflowException as warranted

 

class AvlTree

{

  public:

    AvlTree( ) : root{ nullptr }

      { }

 

    AvlTree( const AvlTree & rhs ) : root{ nullptr }

    {

        root = clone( rhs.root );

    }

 

    AvlTree( AvlTree && rhs ) : root{ rhs.root }

    {

        rhs.root = nullptr;

    }

 

    ~AvlTree( )

    {

        makeEmpty( );

    }

 

    /**

     * Deep copy.

     */

    AvlTree & operator=( const AvlTree & rhs )

    {

        AvlTree copy = rhs;

        std::swap( *this, copy );

        return *this;

    }

 

    /**

     * Move.

     */

    AvlTree & operator=( AvlTree && rhs )

    {

        std::swap( root, rhs.root );

 

        return *this;

    }

 

    bool contains(User * & x ) const

    {

        return contains( x, root );

    }

 

    /**

     * Test if the tree is logically empty.

     * Return true if empty, false otherwise.

     */

    bool isEmpty( ) const

    {

        return root == nullptr;

    }

 

    /**

     * Print the tree contents in sorted order.

     */

    void printTree( ) const

    {

        if( isEmpty( ) )

            cout << "Empty tree" << endl;

        else

            printTree( root );

    }

 

    /**

     * Make the tree logically empty.

     */

    void makeEmpty( )

    {

        makeEmpty( root );

    }

 

    /**

     * Insert x into the tree; duplicates are ignored.

     */

    bool insert(User * & x )

    {

        return insert( x, root );

    }

 

 

    User * findUser(User * x)

    {

        x=findUser(x,root);

        return x;

    }

  private:

    struct AvlNode

    {

        User * element;

        AvlNode   *left;

        AvlNode   *right;

        int       height;

 
        AvlNode(User * ele, AvlNode *lt, AvlNode *rt, int h = 0 )

          : element{ ele }, left{ lt }, right{ rt }, height{ h } { }

 

    };

 

    AvlNode *root;

 

 

    /**

     * Internal method to insert into a subtree.

     * x is the item to insert.

     * t is the node that roots the subtree.

     * Set the new root of the subtree.

     */

    User * findUser(User * x,AvlNode * t)

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

    bool insert(User * & x, AvlNode * & t )

    {

        if( t == nullptr )

        {

            t = new AvlNode{ x, nullptr, nullptr };

            balance( t );

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

 

    static const int ALLOWED_IMBALANCE = 1;

 

    // Assume t is balanced or within one of being balanced

    void balance( AvlNode * & t )

    {

        if( t == nullptr )

            return;

 

        if( height( t->left ) - height( t->right ) > ALLOWED_IMBALANCE )

            if( height( t->left->left ) >= height( t->left->right ) )

                rotateWithLeftChild( t );

            else

                doubleWithLeftChild( t );

        else

        if( height( t->right ) - height( t->left ) > ALLOWED_IMBALANCE )

            if( height( t->right->right ) >= height( t->right->left ) )

                rotateWithRightChild( t );

            else

                doubleWithRightChild( t );

 

        t->height = max( height( t->left ), height( t->right ) ) + 1;

    }

 

    /**

     * Internal method to find the smallest item in a subtree t.

     * Return node containing the smallest item.

     */

    AvlNode * findMin( AvlNode *t ) const

    {

        if( t == nullptr )

            return nullptr;

        if( t->left == nullptr )

            return t;

        return findMin( t->left );

    }

 

    /**

     * Internal method to find the largest item in a subtree t.

     * Return node containing the largest item.

     */

    AvlNode * findMax( AvlNode *t ) const

    {

        if( t != nullptr )

            while( t->right != nullptr )

                t = t->right;

        return t;

    }

 

 

    /**

     * Internal method to test if an item is in a subtree.

     * x is item to search for.

     * t is the node that roots the tree.

     */

   bool contains( const User * x, AvlNode *t ) const

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

/****** NONRECURSIVE VERSION*************************

    bool contains( const Comparable & x, AvlNode *t ) const

    {

        while( t != nullptr )

            if( x < t->element )

                t = t->left;

            else if( t->element < x )

                t = t->right;

            else

                return true;    // Match

 

        return false;   // No match

    }

*****************************************************/

 

    /**

     * Internal method to make subtree empty.

     */

    void makeEmpty( AvlNode * & t )

    {

        if( t != nullptr )

        {

            makeEmpty( t->left );

            makeEmpty( t->right );

            delete t;

        }

        t = nullptr;

    }

 

    /**

     * Internal method to print a subtree rooted at t in sorted order.

     */

    void printTree( AvlNode *t ) const

    {

        if( t != nullptr )

        {

            printTree( t->left );

            cout << *(t->element) << endl;

            printTree( t->right );

        }

    }

 

    /**

     * Internal method to clone subtree.

     */

    AvlNode * clone( AvlNode *t ) const

    {

        if( t == nullptr )

            return nullptr;

        else

        {

            User* temp=new User(*(t->element));

            return new AvlNode(temp, clone( t->left ), clone( t->right ), t->height );

        }

 

    }

        // Avl manipulations

    /**

     * Return the height of node t or -1 if nullptr.

     */

    int height( AvlNode *t ) const

    {

        return t == nullptr ? -1 : t->height;

    }

 

    int max( int lhs, int rhs ) const

    {

        return lhs > rhs ? lhs : rhs;

    }

 

    /**

     * Rotate binary tree node with left child.

     * For AVL trees, this is a single rotation for case 1.

     * Update heights, then set new root.

     */

    void rotateWithLeftChild( AvlNode * & k2 )

    {

        AvlNode *k1 = k2->left;

        k2->left = k1->right;

        k1->right = k2;

        k2->height = max( height( k2->left ), height( k2->right ) ) + 1;

        k1->height = max( height( k1->left ), k2->height ) + 1;

        k2 = k1;

    }

 

    /**

     * Rotate binary tree node with right child.

     * For AVL trees, this is a single rotation for case 4.

     * Update heights, then set new root.

     */

    void rotateWithRightChild( AvlNode * & k1 )

    {

        AvlNode *k2 = k1->right;

        k1->right = k2->left;

        k2->left = k1;

        k1->height = max( height( k1->left ), height( k1->right ) ) + 1;

        k2->height = max( height( k2->right ), k1->height ) + 1;

        k1 = k2;

    }

 

    /**

     * Double rotate binary tree node: first left child.

     * with its right child; then node k3 with new left child.

     * For AVL trees, this is a double rotation for case 2.

     * Update heights, then set new root.

     */

    void doubleWithLeftChild( AvlNode * & k3 )

    {

        rotateWithRightChild( k3->left );

        rotateWithLeftChild( k3 );

    }

 

    /**

     * Double rotate binary tree node: first right child.

     * with its left child; then node k1 with new right child.

     * For AVL trees, this is a double rotation for case 3.

     * Update heights, then set new root.

     */

    void doubleWithRightChild( AvlNode * & k1 )

    {

        rotateWithLeftChild( k1->right );

        rotateWithRightChild( k1 );

    }

};

 

#endif