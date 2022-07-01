#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class BadLengthException : public exception {
private:
    char* length;
public:
    BadLengthException(int n)
    {
        string length_string = to_string(n);
        length = new char(length_string.size());
        for (size_t i = 0; i < length_string.size(); i++)
        {
            *(length + i) = length_string[i];
        }
        // length on hackerrank doesnt end where it should
        *(length + length_string.size()) = '\0'; // Deals with hackerrank error
    }
    const char * what() const throw ()
    {
        return length;
    }
};

/* Define the exception here */


bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if(n < 5) {
        throw BadLengthException(n);
    }
    for(int i = 0; i < n-1; i++) {
        if(username[i] == 'w' && username[i+1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

int getSize (const char * s) {
    const char * t; // first copy the pointer to not change the original
    int size = 0;

    for (t = s; *t != '\0'; t++) {
        size++;
    }

    return size;
}

int main() {
    int T; cin >> T;
    while(T--) {
        string username;
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if(isValid) {
                cout << "Valid" << '\n';
            } else {
                cout << "Invalid" << '\n';
            }
        } catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';
            cout << getSize(e.what()) << endl;
        }
    }
    // cout << check() << endl;
    return 0;
}
