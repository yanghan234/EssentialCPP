#include <vector>
#include <string>
using namespace std;
class stack{
    public:
        bool push( const string& );
        bool pop( string &elem );
        bool peek( string &elem );
        bool empty( );
        bool full( );
        bool find( const string& );
        int  count( const string& );
        int  size( );

    private:
        vector<string> _stack;
};

bool stack::push( const string& strA )
{
    if ( this->full() )
        return false;
    this->_stack.push_back(strA);
    return true;
}

bool stack::pop( string &elem )
{
    // take out the last element in stack
    // and remove it from the stack
    if ( this->empty() )
        return false;

    elem = this->_stack.back();
    this->_stack.pop_back();
    return true;
}

bool stack::peek( string &elem )
{
    if ( this->empty() )
        return false;

    elem = this->_stack.back();
    return true;
}

inline bool stack::empty()
{
    if (this->_stack.size() == 0){
        return true;
    } else {
        return false;
    }
}

inline bool stack::full()
{
    if ( this->_stack.size() == this->_stack.max_size() ){
        return true;
    } else {
        return false;
    }
}

bool stack::find( const string &str )
{
    if ( this->empty() )
        return false;

    vector<string>::iterator it;
    for ( it = this->_stack.begin(); it != this->_stack.end(); it++ ){
        if ( *it == str ){
            return true;
        }
    }
    return false;
}

int stack::count( const string &str )
{
    int count = 0;
    if ( this-> empty() )
        return count;

    vector<string>::iterator it;
    for ( it = this->_stack.begin(); it != this->_stack.end(); it++ )
        if ( *it == str )
            count++;

    return count;
}

inline int stack::size(){ return this->_stack.size(); }


