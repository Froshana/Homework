// Завдання 1 //
/*
#include <iostream>

struct MyErr { const char* msg; };

int main() {
    try {
        throw MyErr{"Ділення на нуль"};
    } catch (const MyErr& e) {
        std::cerr << "Error: " << e.msg << '\n';
    }
}

*/
// Завдання 2 //
#include <iostream>

struct MyErr {
    const char* msg;   
    int num;           
    int den;           

	int numerator()   const noexcept { return num; }
    int denominator() const noexcept { return den; }
};

int main() {
    try {

		throw MyErr{"Ділення на нуль", 10, 0};
    } catch (const MyErr& e) {
        std::cerr << "Error: " << e.msg
                  << " | a =" << e.numerator()
                  << ", b =" << e.denominator() << '\n';
    }
    return 0;
}

// Завдання 3 //

#include <iostream>

struct MyErr {
    const char* msg;
    int num;
    int den;

    int numerator()   const { return num; }
    int denominator() const { return den; }
};

// Похідний виняток
struct DivideByZeroErr : public MyErr {
    DivideByZeroErr(const char* m, int a, int b) {
        msg = m; num = a; den = b;
    }
};

int main() {
    try {
		throw DivideByZeroErr("Ділення на нуль", 10, 0);
    }
    catch (const DivideByZeroErr& e) {          
        std::cerr << "[Derived] " << e.msg
                  << " | a=" << e.numerator()
                  << ", b=" << e.denominator() << '\n';
    }
    catch (const MyErr& e) {                      
        std::cerr << "[Base] " << e.msg
                  << " | a=" << e.numerator()
                  << ", b=" << e.denominator() << '\n';
    }
}

// Завдання 4 //

#include <iostream>

struct MyErr {
    const char* msg;
    int num;
    int den;

    MyErr(const char* m, int a, int b) : msg(m), num(a), den(b) {}
    int numerator()   const { return num; }
    int denominator() const { return den; }
};

struct DivideByZeroErr : public MyErr {
    DivideByZeroErr(const char* m, int a, int b) : MyErr(m, a, b) {}
};

int level3(int a, int b) {
    if (b == 0) throw DivideByZeroErr("Ділення на нуль", a, b); 
   return a / b;
}

int level2(int a, int b) {
    return level3(a, b);
}

int level1(int a, int b) {
    return level2(a, b);
}

int main() {
    try {
      std::cout << level1(10, 0) << '\n';

    }
    catch (const DivideByZeroErr& e){
        std::cerr << "[Derived] " << e.msg
                  << " | a=" << e.numerator()
                  << ", b=" << e.denominator() << '\n';
    }
    catch (const MyErr& e) {         
        std::cerr << "[Base] " << e.msg
                  << " | a=" << e.numerator()
                  << ", b=" << e.denominator() << '\n';
    }
}

// Завдання 4 //
#include <iostream>
#include <string>
using namespace std;

class xOutOfMemory
{
public:
    xOutOfMemory()
    {
        theMsg = new char[20];
        strcpy(theMsg, "error in memory");
    }
    ~xOutOfMemory()
    {
        delete[] theMsg;
        cout << "Memory restored. " << endl;
    }
    char *Message() { return theMsg; }

private:
    char *theMsg;
};

int main()
{
    try
    {
        char *var = new char; //Виділення пам'яті для повидомлення про те, що невистачає пам'яті. 
        if (var == nullptr)
        {
            xOutOfMemory *px = new xOutOfMemory; 
            throw px;
        }
    }
    catch (xOutOfMemory *theException)
    {
        cout << theException->Message() << endl;
        delete theException;
    }
    return 0;
}
new не повертає nullptr
У звичайному режими char* var = new char; при нестачі пам’яті не дасть nullptr, таким чином if (var == nullptr) ніколи не спрацює.
Витік var
немає(delete var; ) а отже у звичайному виконанні var ніколи не звільняється. 
