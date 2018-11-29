#include <iostream>
#include <fstream>
#include <string>
#include <exception>
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

        static Node<valType>* removeElem( const valType &elem, Node<valType> *sub );

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
        void remove( const valType &elem );
        bool search( const valType &elem );
        static Node<valType>* subtreeMin( Node<valType> *sub );

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
void BinaryTree<valType>::remove( const valType &elem )
{
    if ( !_root ) return;
    _root = Node<valType>::removeElem( elem, _root );
}

template < typename valType >
Node<valType>* Node<valType>::removeElem( const valType &elem, Node<valType> * sub )
{
    if ( !sub ) return sub; // empty tree, do nothing

    if ( sub->_val > elem )
        sub->_left  = Node<valType>::removeElem( elem, sub->_left );
    else if ( sub->_val < elem )
        sub->_right = Node<valType>::removeElem( elem, sub->_right );
    else
    {
        if ( sub->_right )
        {
            Node<valType> *minRHS = BinaryTree<valType>::subtreeMin( sub->_right );
            sub->_val = minRHS->_val;
            sub->_cnt = minRHS->_cnt;
            sub->_right = Node<valType>::removeElem( minRHS->_val, sub->_right );
        }
        else
        {
            if ( sub->_left )
            {
                Node<valType> *ptr = sub->_left;
                delete sub;
                return ptr;
            }
            else
            {
                delete sub;
                return 0;
            }
        }
    }
    return sub;
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
Node<valType>* BinaryTree<valType>::subtreeMin( Node<valType> *sub )
{
    if ( !sub ) throw new out_of_range("The subtree is empty!!");

    Node<valType> *ptr = sub;
    while ( ptr->_left )
        ptr = ptr->_left;
    return ptr;
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

    bt.remove(45);
    bt.insert(45);
    bt.remove(45);
    bt.insert(45);

    bt.displayTree();

}
