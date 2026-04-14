#include <iostream>
#include <string>
#include <stdexcept>
#include "utils.hpp"
using namespace std;

int main() {
    string email;

    while (true) {
        cout << "Enter your email address: ";
        getline(cin, email);

        try {
            check_email(email);
            cout << "Email accepted." << endl;
            break;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << " Please try again." << endl;
        }
    }

    return 0;
}
