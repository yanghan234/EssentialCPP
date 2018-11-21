#include <iostream>
#include <vector>
#include <string>
using namespace std;

template < typename valType >
class BinaryTree;

template < typename valType >
class BT_node
{
    friend class BinaryTree< valType >;
    public:
        BT_node( valType val );
        void insert_value( const valType &elem );
        void display_node();
        void remove_value( const valType &elem, BT_node *& prev );
        static void lchild_leaf( BT_node *leaf, BT_node *subtree );

    private:
        valType _val;
        int     _cnt;
        BT_node *_lchild; // cannot be reference, b/c reference cannot
        BT_node *_rchild; // refer to a null object
};

template < typename valType >
BT_node<valType>::BT_node( valType val )
    : _val(val)  // valType may be a class, so _val = val is not good.
{
    _cnt = 1;
    _lchild = 0;
    _rchild = 0;
}

template < typename valType >
void BT_node<valType>::insert_value( const valType &elem )
{
    if ( elem == _val ) {
        _cnt++;
        return;
    }

    if ( elem < _val ) {
        if ( !_lchild )
            _lchild = new BT_node( elem );
        else
            _lchild->insert_value( elem );
    }
    else if ( elem > _val ) {
        if ( !_rchild )
            _rchild = new BT_node( elem );
        else
            _rchild->insert_value( elem );
    }
}

template < typename valType >
void BT_node<valType>::remove_value( const valType &elem, BT_node<valType> *& prev )
{
    if ( elem < _val )
    {
        if ( !_lchild )
            return;
        else _lchild->remove_value( elem, _lchild );
    }
    else if ( elem > _val )
    {
        if ( !_rchild )
            return;
        else _rchild->remove_value( elem, _rchild );
    }
    else
    {
        if ( _rchild )
        {
            prev = _rchild;
            if ( _lchild )
            {
                if ( !prev->_lchild )
                    prev->_lchild = _lchild;
                else BT_node::lchild_leaf( _lchild, prev->_lchild );
            }
        }
        prev = _lchild;
        delete this;
    }

}

template < typename valType >
void BT_node<valType>::lchild_leaf( BT_node *leaf, BT_node *subtree )
{
    while ( subtree->_lchild )
        subtree = subtree->_lchild;
    subtree->_lchild = leaf;

}

template < typename valType >
void BT_node<valType>::display_node()
{
    cout << "{ " << _val << ", " << _cnt << " }" << endl;
    if ( _lchild ) _lchild->display_node();
    if ( _rchild ) _rchild->display_node();
}

template < typename valType >
class BinaryTree
{
    public:
        BinaryTree();
        void insert( const valType &elem );
        bool find( const valType &elem );

        void remove( const valType &elem );
        void remove_root( );
        inline void clear() { if ( _root ) clear(_root); _root=0; };

        void display_tree();

    private:
        BT_node<valType> *_root;
        void clear(BT_node<valType> *ptr);
        bool find( BT_node<valType> *ptr, const valType &elem );
};

template < typename valType >
BinaryTree<valType>::BinaryTree() : _root(0) {}

template < typename valType >
inline void BinaryTree<valType>::insert( const valType &elem )
{
    if ( !_root )
        _root = new BT_node<valType>( elem );
    else _root->insert_value( elem );
}

template < typename valType >
inline void BinaryTree<valType>::remove( const valType &elem )
{
    if ( _root ) {
        if ( _root->_val == elem )
            remove_root();
        else
            _root->remove_value(elem, _root);
    }
}

template < typename valType >
void BinaryTree<valType>::remove_root( )
{
    if ( !_root ) return;

    BT_node<valType> *tmp = _root;
    if ( _root->_rchild ) {
        _root = _root->_rchild;

        if ( tmp->_lchild ) {
            BT_node<valType> *lc = tmp->_lchild;
            BT_node<valType> *newlc = _root->_lchild;
            if ( !newlc )
                _root->_lchild = lc;
            else
                BT_node<valType>::lchild_leaf( lc, newlc );
        }
    }
    else
        _root = _root->_rchild;
    delete tmp;
}

template < typename valType >
void BinaryTree<valType>::clear(BT_node<valType> *ptr)
{
    if ( ptr )
    {
        clear( ptr->_lchild );
        clear( ptr->_rchild );
        delete ptr;
    }
}

template < typename valType >
void BinaryTree<valType>::display_tree()
{
    if ( _root ) _root->display_node();
}

template < typename valType >
bool BinaryTree<valType>::find( const valType &elem )
{
    BT_node<valType> *ptr = _root;
    return find( ptr, elem );
}

template < typename valType >
bool BinaryTree<valType>::find( BT_node<valType> *ptr, const valType &elem )
{
    if ( !ptr ) return false;
    if ( ptr->_val == elem ) return true;
    else if ( elem < ptr->_val ) return find( ptr->_lchild, elem );
    else return find( ptr->_rchild, elem );
}

int main()
{
    BinaryTree<int> bt;
    bt.insert(2);
    bt.insert(4);
    bt.insert(1);
    bt.insert(5);
    bt.insert(3);
    bt.insert(3);
    bt.insert(-1);
    bt.display_tree();

    bt.remove(2);

    bt.display_tree();

    BinaryTree<int> bt2;
    const int size = 1000;
    int arr[size];
    for ( int i = 0; i < size; i++ )
    {
        arr[i] = i;
        bt2.insert(arr[i]);
    }

    cout << bt2.find(1) << endl;
    cout << bt2.find(10) << endl;
    cout << bt2.find(100) << endl;
    cout << bt2.find(1000) << endl;
    bt2.insert(1000);
    cout << bt2.find(1000) << endl;

}

