#include <iostream>
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
        void display_me( const Node<valType> * );

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

        void insert( const valType &elem );

        void display_tree( );

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
void Node<valType>::display_me( const Node<valType> *ptr )
{
    if ( !ptr ) return; // if ptr is empty, do nothing
    if ( ptr->_left )

}

template < typename valType >
ostream& operator<<( ostream &os, const Node<valType> *ptr )
{
    if ( !ptr ) return os; // if ptr is empty, do nothing
    if ( ptr->_left )
      os << ptr->_left;
    os << "{ val: " << ptr->val() << ", cnt: " << ptr->cnt() << " }" << endl;
    if ( ptr->_right )
      os << ptr->_right;
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
                p = p->_left;
            }
            else
            {
                p = p->_right;
            }
        }
        p = new Node<valType>(elem);
        return;
    }
}

template < typename valType >
void BinaryTree<valType>::display_tree( )
{
    if ( !_root )
    {
        cout << "The tree is empty." << endl;
        return;
    }
    Node<valType> *ptr = _root;
    
    cout << ptr;
}

int main()
{
    BinaryTree<int> bt;
    bt.insert(1);
    bt.insert(0);
    bt.insert(2);
    bt.display_tree();
}
