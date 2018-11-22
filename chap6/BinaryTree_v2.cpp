#include <iostream>
#include <string>
using namespace std;

template < typename valType >
class BinaryTree;

template < typename valType >
class Node
{
    friend class BinaryTree<valType>;
    public:
        Node( const valType &elem );

        valType val() const { return _val; };
        unsigned cnt() const { return _cnt; };

    private:
        valType _val;
        unsigned _cnt;
        Node<valType> *_left;
        Node<valType> *_right;
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
ostream& operator<<( ostream &os, const Node<valType> *ptr )
{
    os << "{ val: " << ptr->val() << ", cnt: " << ptr->cnt() << " }" << endl;
    return os;
}

template < typename valType >
void BinaryTree<valType>::insert( const valType &elem )
{
    if ( !_root ) // if the tree is empty
        _root = new Node<valType>( elem );
}

template < typename valType >
void BinaryTree<valType>::display_tree( )
{
    if ( !_root )
        cout << "The tree is empty." << endl;
    Node<valType> *ptr = _root;
    cout << ptr;


}

int main()
{
    BinaryTree<int> bt;
    bt.insert(1);
}
