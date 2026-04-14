#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include "utils.hpp"
using namespace std;

int main() {

    map<string, string> user_db;

    bool isLoggedIn = false;
    string choice;
    string email, password;

    while (true) {
	cout << "Welcome" << endl;
	if (!isLoggedIn){
		cout << "1: Sign up" << endl;
		cout << "2: Login" << endl;
	} else{
		cout << "3: Logout" << endl;
	}
	cout << "4: Exit" << endl;
	cout << "Choose an option: ";
	getline(cin, choice);
	if(choice == "1" && !isLoggedIn){
		bool validEmail = false;
		while(!validEmail){
		        cout << "Enter your email address: ";
		        getline(cin, email);
       			try{
				check_email(email);
				validEmail = true;
       			 }catch (const invalid_argument& e) {
            			cout << "Error: " << e.what() << " Please try again." << endl;
        		 }
   		 }
		cout << "Enter password: ";
		getline(cin, password);
		user_db[email] = password;
		cout << "Account created"<< endl;
	}else if (choice == "2" && !isLoggedIn){
		cout << "Enter email: ";
		getline(cin, email);
		cout << "Enter password: ";
		getline(cin, password);
		if (user_db.find(email) != user_db.end() && user_db[email] == password) {
			isLoggedIn = true;
			cout << "Successfully logged in" << endl;
		}else {
			cout << "Invalid" << endl;
		}
	}else if (choice == "3" && isLoggedIn) {
		isLoggedIn = false;
		cout << "Logged out" << endl;
	}else if (choice == "4") {
		break;
	}else {
		cout << "Invalid option" << endl;
	}
    }
    return 0;
}
