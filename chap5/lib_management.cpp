#include <iostream>
#include <string>
using namespace std;

class LibMat
{
    public:
        LibMat() { cout << "LibMat::LibMat() default constructor!" << endl; };

        virtual ~LibMat() { cout << "LibMat::~LibMat() destructor!" << endl; };
        virtual void print() const
            { cout << "LibMat::print() -- I am a LibMat object!" << endl; };

};

class Book : public LibMat
{
    public:
        Book ( const string &title, const string &author )
            : _title(title), _author(author){
                cout << "Book::Book( " << _title
                     << ", " << _author << " ) constructor" << endl;
            };

        virtual ~Book(){
            cout << "Book::~Book() destructor!" << endl;
        };

        virtual void print() const {
            cout << "Book::print() -- I am a Book object! "
                 << "My title is: " << _title << endl
                 << "My author is: " << _author << endl;
        };

    protected:
        string _title;
        string _author;
};

class AudioBook : public Book
{
    public:
        AudioBook ( const string &title,
                    const string &author,
                    const string &narrator )
            : Book(title, author), _narrator(narrator)
        {
            cout << "AudioBook::AudioBook( " << _title
                 << ", " << _author
                 << ", " << _narrator
                 << " ) constructor" << endl;
        }

        ~AudioBook()
        {
            cout << "AudioBook::~AudioBook() destructor!" << endl;
        };

        virtual void print() const {
            cout << "AudioBook::print() -- I am an AudioBook object!" << endl
                 << "My title is: " << _title << endl
                 << "My author is: " << _author << endl
                 << "My narrator is: " << _narrator << endl;
        };

        const string& narrator() const { return _narrator; };

    protected:
        string _narrator;

};

void print( const LibMat &mat )
{
    cout << "in global print(): about to print mat.print() " << endl;
    mat.print();
}

int main()
{
    cout << endl << "Creating a LibMat object to print()" << endl;
    LibMat libmat;
    print(libmat);

    cout << endl << "Creating a Book object to print()" << endl;
    Book b("The Castle", "Franz Kafka");
    print(b);

    cout << endl << "Creating a AudioBook object to print()" << endl;
    AudioBook ab("Mason and Dixon","Thomas Pynchon","Edwin Leonard");
    print(ab);
}
