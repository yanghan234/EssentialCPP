#include <iostream>
#include <vector>
#include <string>
using namespace std;

class UserProfile
{
    public:
        string FirstName;
        string LastName;
        unsigned int LoggedCount;
        unsigned int GuessCount;
        unsigned int GuessCorrectCount;
        unsigned int ilevel;
        float GuessCorrectRatio;

    private:
        vector<string> _levels = {"Junior","Sophemore","Senior","Professional"};


};
