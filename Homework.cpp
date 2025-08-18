
#include <iostream>
#include <string>
using namespace std;

// Завдання 1 //

int main (){
	clog << "[INFO] Program started\n";

	cout << "Enter your full name: ";
	string name;
	getline(cin,name);

	cout << "Enter your age: ";
	int age;
	if (!(cin >> age)){
		cerr << "[ERROR] Invalid input.\n";
		return 1;
	}
	if (age < 0){
		cerr << "[ERROR] Age cannot be negative.\n";
		return 1;
	}
	clog << "[INFO] Input received; printing greeting...\n";
    cout << "Hello, " << name << "! You are " << age << " years old.\n";
    clog << "[INFO] Program finished successfully." << endl;

	return 0;
}

// Завдання 2 //

int main() {
    string name;
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << name << '\n';
    return 0;
}

// Завдання 3 //

#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "enter a phrase: ";
    while (cin.get(ch)) {
        if (ch == '#') continue;          
        cout << (ch == '!' ? '$' : ch);     
    }
    return 0;
}