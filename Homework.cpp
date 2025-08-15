/*
#include <iostream>
#include <string>
using namespace std;
using String = std::string; 

 1. Оголосіть клас Animal (Тварина), який містить змінну-член, яка є об'єктом класу String.
2. Опишіть клас BoundedAray, який є масивом.
3. Опишіть клас Set, який виконується в межах масиву BoundedAray.
4. Змініть лістинг 15_1 таким чином, щоб клас String включав перевантажений оператор виведення (<<).

class Animal {
 public:
	Animal () : name () {}
	~Animal() = default;

	explicit Animal(const String& n) : name(n) {}

	const String& getName() const { return name; }
    void setName(const String& n) { name = n; }

 private:
	String name;
};

int main() {
	Animal a;
    Animal b("Cat");  

    a.setName("Dog");

    cout << "a: " << a.getName() << '\n';
    cout << "b: " << b.getName() << '\n';
    return 0;
}

// Завдання 2-3 //

#include <iostream>
using namespace std;

class BoundedArray {
public:
    static const int CAP = 8;

    BoundedArray() : sz(0) {}

    bool push_back(int v) {
        if (sz >= CAP) return false; 
        data[sz++] = v;
        return true;
    }

    bool erase_at(int i) {
        if (i < 0 || i >= sz) return false;
        for (int j = i + 1; j < sz; ++j) data[j - 1] = data[j];
        --sz;
        return true;
    }

    int size() const { return sz; }
    int operator[](int i) const { return data[i]; }
    int& operator[](int i) { return data[i]; }

    void print() const {
        cout << "[";
        for (int i = 0; i < sz; ++i) {
            cout << data[i];
            if (i + 1 < sz) cout << ", ";
        }
        cout << "]";
    }

private:
    int data[CAP];
    int sz;
};

class Set {
public:
    bool insert(int v) {
        if (contains(v)) return false;    
        return arr.push_back(v);
    }

    bool erase(int v) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == v) return arr.erase_at(i);
        }
        return false;
    }

    bool contains(int v) const {
        for (int i = 0; i < arr.size(); ++i)
            if (arr[i] == v) return true;
        return false;
    }

    int size() const { return arr.size(); }

    void print() const {
        cout << "{";
        for (int i = 0; i < arr.size(); ++i) {
            cout << arr[i];
            if (i + 1 < arr.size()) cout << ", ";
        }
        cout << "}";
    }

private:
    BoundedArray arr; 
};


int main() {
    BoundedArray a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    cout << "BoundedArray: ";
    a.print();
    cout << "  size=" << a.size() << "\n";

    Set s;
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(3); 
    cout << "Set: ";
    s.print();
    cout << "  size=" << s.size() << "\n";

    cout << "contains(2) = " << (s.contains(2) ? "yes" : "no") << "\n";
    s.erase(2);
    cout << "after erase(2): ";
    s.print();
    cout << "  size=" << s.size() << "\n";
}


// Завдання 4 //

#include <iostream>
using namespace std;

class String {
public:
    String();                         
    String(const char* const cstr);   
    String(const String&);           
    ~String();

    char& operator[](int offset);
    char  operator[](int offset) const;

    String operator+(const String&);
    void   operator+=(const String&);
    String& operator=(const String&);

    int         GetLen()    const { return itsLen; }
    const char* GetString() const { return itsString; }

    friend ostream& operator<<(ostream& os, const String& s);

private:
    String(int len);                 
    char*          itsString = nullptr;
    unsigned short itsLen    = 0;
};

String::String() {
    itsString = new char[1];
    itsString[0] = '\0';
    itsLen = 0;
}

String::String(int len) {
    itsString = new char[len + 1];
    for (int i = 0; i <= len; ++i) itsString[i] = '\0';
    itsLen = len;
}

String::String(const char* const cstr) {
    unsigned short len = 0;
    if (cstr) {
        while (cstr[len] != '\0') ++len;
    }
    itsLen = len;
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; ++i) itsString[i] = cstr[i];
    itsString[itsLen] = '\0';
}

String::String(const String& rhs) {
    itsLen = rhs.GetLen();
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; ++i) itsString[i] = rhs[i];
    itsString[itsLen] = '\0';
}

String::~String() {
    delete[] itsString;
    itsString = nullptr;
    itsLen = 0;
}

String& String::operator=(const String& rhs) {
    if (this == &rhs) return *this;
    delete[] itsString;
    itsLen = rhs.GetLen();
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; ++i) itsString[i] = rhs[i];
    itsString[itsLen] = '\0';
    return *this;
}

char& String::operator[](int offset) {
    if (offset < 0 || offset >= itsLen) return itsString[itsLen ? itsLen - 1 : 0];
    return itsString[offset];
}

char String::operator[](int offset) const {
    if (offset < 0 || offset >= itsLen) return itsString[itsLen ? itsLen - 1 : 0];
    return itsString[offset];
}

String String::operator+(const String& rhs) {
    int totalLen = itsLen + rhs.GetLen();
    String temp(totalLen);
    int i = 0, j = 0;
    for (; i < itsLen; ++i) temp[i] = itsString[i];
    for (; j < rhs.GetLen(); ++j, ++i) temp[i] = rhs[j];
    temp[totalLen] = '\0';
    return temp;
}

void String::operator+=(const String& rhs) {
    unsigned short totalLen = itsLen + rhs.GetLen();
    String temp(totalLen);
    int i = 0, j = 0;
    for (; i < itsLen; ++i) temp[i] = itsString[i];
    for (; j < rhs.GetLen(); ++j, ++i) temp[i] = rhs[j];
    temp[totalLen] = '\0';
    *this = temp;
}
std::ostream& operator<<(std::ostream& os, const String& s) {
    return os << (s.itsString ? s.itsString : "");
}


#include <iostream>
#include <string>

using namespace std;

class Animal;

void setValue(Animal &, int);

class Animal
{
public:
	int GetWeight() const { return itsWeight; }
	int GetAge() const { return itsAge; }

private:
	int itsWeight;
	int itsAge;
};

void setValue(Animal &theAnimal, int theWeight)
{
	friend class Animal; // friend треба оголосити в середині класу, а не в функції
	theAnimal.itsWeight = theWeight;
}

int main()
{
	Animal peppy;
	setValue(peppy, 5);
	return 0;
}
*/
#include <iostream>
#include <string>

using namespace std;

class Animal;

void setValue(Animal &, int);

class Animal
{
public:
	int GetWeight() const { return itsWeight; }
	int GetAge() const { return itsAge; }

private:
	int itsWeight;
	int itsAge;
	friend void setValue(Animal &theAnimal, int theWeight);

};

void setValue(Animal &theAnimal, int theWeight)
{
	theAnimal.itsWeight = theWeight;
}

int main()
{
	Animal peppy;
	setValue(peppy, 5);
	return 0;
}