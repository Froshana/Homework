// Завдання 1 //

#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::ifstream in(argv[1], std::ios::in | std::ios::binary);
    if (!in) {
        std::cerr << "Error: cannot open file '" << argv[1] << "'\n";
        return 2;
    }

    int ch;
    while ((ch = in.get()) != std::char_traits<char>::eof()) {
        unsigned char uch = static_cast<unsigned char>(ch);
        if (std::isprint(uch)) {    
            std::cout << static_cast<char>(uch);
        }
    
    }

    in.close(); 
    return 0;
}

// Завдання 2 //

#include <iostream>

int main(int argc, char* argv[]) {

    for (int i = argc - 1; i >= 1; --i) {
     	std::cout << argv[i];
        if (i > 1) std::cout << ' ';
    }
    std::cout << '\n';

    return 0;
}

// Завдання 3 //

#include <iostream> 

int main() { 
	cout << "Hello world!" << endl; // використання cout без простору імен std
	
	return 0; 
}

// Завдання 4 //

// Перший варіант //
 #include <iostream>
int main() {
    std::cout << "Hello world!" << std::endl; // додати std::
    return 0;
}

// Другий варіант //
#include <iostream>
using namespace std; // додати загальне підключення простору імен
int main() {
    cout << "Hello world!" << endl;
    return 0;
}

// Третіий варіант //
#include <iostream>
int main() {
    using std::cout; // додати локальні using декларації
    using std::endl;
    cout << "Hello world!" << endl;
    return 0;
}