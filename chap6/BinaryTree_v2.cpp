#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template < typename valType >
class BinaryTree;

template < typename valType >
class Node;

template < typename valType >
class Node
{
    friend class BinaryTree<valType>;
    public:
        Node( const valType &elem );

        valType val() const { return _val; };
        unsigned cnt() const { return _cnt; };

        Node<valType>* left() const { return _left; };
        Node<valType>* right() const { return _right; };

    private:
        valType _val;
        unsigned _cnt;
        Node<valType> *_left = NULL;
        Node<valType> *_right = NULL;
};

template < typename valType >
class BinaryTree
{
    public:
        BinaryTree(){ _root = 0; };
        Node<valType>* root() const { return _root; };

        void insert( const valType &elem );
        bool remove( const valType &elem );
        bool search( const valType &elem );

        void displayTree( );

    private:
        Node<valType> *_root;
};

template < typename valType >
Node<valType>::Node( const valType &elem ) : _val(elem)
{
    _cnt = 1;
    _left = 0;
    _right = 0;
}

template < typename valType >
ostream& operator<<( ostream &os, const Node<valType> *ptr )
{
    if ( !ptr ) return os; // if ptr is empty, do nothing
    if ( ptr->left() )
      os << ptr->left();
    os << "{ val: " << ptr->val() << ", cnt: " << ptr->cnt() << " }" << endl;
    if ( ptr->right() )
      os << ptr->right();
    return os;
}

template < typename valType >
void BinaryTree<valType>::insert( const valType &elem )
{
    if ( !_root )
        // when the tree is empty
        _root = new Node<valType>( elem );
    else
    {
        // when the tree is not empty
        Node<valType> *p = _root;
        while ( p )
        {
            if ( p->_val == elem )
            {
                // if the value is already in the tree,
                // count the number and return
                p->_cnt++;
                return;
            }
            else if ( p->_val > elem )
            {
                if ( !(p->_left) )
                {
                    p->_left = new Node<valType>(elem);
                    return;
                }
                else
                    p = p->_left;
            }
            else
            {
                if ( !(p->_right) )
                {
                    p->_right = new Node<valType>(elem);
                    return;
                }
                else
                    p = p->_right;
            }
        }
    }
}

template < typename valType >
bool BinaryTree<valType>::remove( const valType &elem )
{
    /* return value:
     * 1: empty tree or the elem is not in the tree
     * 0: elem is in the tree and has been removed gracefully
     */
    if ( !_root )
        // empty tree
        return false;
    else
    {
        Node<valType> *ptr = _root;
        Node<valType> *parent = _root;
        while ( ptr )
        {
            if ( ptr->_val > elem )
            {   // _val > elem, find elem in left subtree
                if ( !(ptr->_left) )
                    return true;
                else
                {
                    if ( ptr == _root )
                        ptr = ptr->_left;
                    else
                    {
                        parent = ptr;
                        ptr = ptr->_left;
                    }
                }
            }
            else if ( ptr->_val < elem )
            {   // _val < elem, find elem in right subtree
                if ( !(ptr->_right) )
                    return true;
                else
                {
                    if ( ptr == _root )
                      ptr = ptr->_right;
                    else
                    {
                      parent = ptr;
                      ptr = ptr->_right;
                    }
                }

            }
            else
              break;
        } // end of while

        /* Now, we have found the target node and its parent.
         * To remove it, we substitute the tartget node
         * with the smallest value in the right subtree.
         */

        if ( ptr == parent )
        {   // ptr = parent = root, i.e. to remove root node
            if ( !(ptr->_right) )
            {
                _root = ptr->_left;
                delete ptr;
            }
            else
            {
                Node<valType> *ptr2 = ptr->_right;
                Node<valType> *parent2 = ptr->_right;
                while ( ptr2->_left )
                {
                    if ( ptr2 == ptr->_right )
                        ptr2 = ptr2->_left;
                    else
                    {
                        parent2 = ptr2;
                        ptr2 = ptr2->_left;
                    }
                }
                ptr->_val = ptr2->_val;
                ptr->_cnt = ptr2->_cnt;
                parent2->_left = 0;
                delete ptr2;
            }
        }
        else
        {
            if ( !(ptr->_right) )
            {
                if ( parent->_left == ptr )
                    parent->_left = ptr->_left;
                else
                    parent->_right = ptr->_left;
                delete ptr;
            }
            else
            {
                Node<valType> *ptr2 = ptr->_right;
                Node<valType> *parent2 = ptr->_right;
                while ( ptr2->_left )
                {
                    if ( ptr2 == ptr->_right )
                        ptr2 = ptr2->_left;
                    else
                    {
                        parent2 = ptr2;
                        ptr2 = ptr2->_left;
                    }
                }
                ptr->_val = ptr2->_val;
                ptr->_cnt = ptr2->_cnt;
                parent2->_left = 0;
                delete ptr2;
            }
        } // endif
        return true;
    }
}

template < typename valType >
bool BinaryTree<valType>::search( const valType &elem )
{
    if ( !_root )
        return false;
    else
    {
        Node<valType> *ptr = _root;
        while ( ptr )
        {
            if ( ptr->_val > elem )
            {
                if ( !(ptr->_left) )
                    return false;
                else
                    ptr = ptr->_left;
            }
            else if ( ptr->_val < elem )
            {
                if ( !(ptr->_right) )
                    return false;
                else
                    ptr = ptr->_right;
            }
            else
              return true;
        } // end of while
    } // end of if the tree is not empty
}

template < typename valType >
void BinaryTree<valType>::displayTree( )
{
    if ( !_root )
    {
        cout << "The tree is empty." << endl;
        return;
    }
    cout << _root << endl;
}

int main()
{
    // 顺便用二叉树实现了一遍排序
    int arr[10] = {9,45,485,15,567,349,167,02,12,41};
    BinaryTree<int> bt;
    for ( int i = 0; i < 10; i++ )
    {
      bt.insert(arr[i]);
    }
    bt.displayTree();

    ofstream outFile("output.dat");
    outFile << bt.root();
    outFile.close();

    bt.remove(9);
    bt.remove(12);

    bt.displayTree();

}
