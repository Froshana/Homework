// Завдання 1 //

#include <iostream>
#include <string>


template <class T>
class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();

	void insert(const T& value);
	void append(const T& value);
	int is_present(const T& value) const;
	int is_empty() const { return head == nullptr;}
	int count() const { return theCount; }

private:
	class ListCell
	{
    public:
   
    	explicit ListCell(const T& value, ListCell *cell = nullptr) : val(value),
                                              	next(cell) {}
	T val;
    ListCell* next;
};
	
    T val;
    ListCell* next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};

class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(int value);
	void append(int value);
	int is_present(int value) const;
	int is_empty() const
	{
    	return head == 0;
	}
	int count() const { return theCount; }
private:
	class ListCell
	{
	public:
    	ListCell(int value, ListCell *cell = 0) : val(value),
                                              	next(cell) {}
    	int val;
    	ListCell *next;
	};
	int val;
	ListCell *next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};

List::~List() {
	ListCell* p = head;
	while (p) {
		ListCell* n = p->next;
		delete p;
		p = n;
	}
	head = tail = 0;
	theCount = 0;
}

void List::insert(int value) {
	   ListCell* node = new ListCell(value, head);
    head = node;
    if (!tail) tail = head;
    ++theCount;
}

void List::append(int value) {
    ListCell* node = new ListCell(value, 0);
    if (tail) {
        tail->next = node;
        tail = node;
    } else {
        head = tail = node;   
    }
    ++theCount;
}

int List::is_present(int value) const {
    for (ListCell* p = head; p; p = p->next) {
        if (p->val == value) return 1;
    }
    return 0;
}

int main() {
    List lst;
    std::cout << "empty " << lst.is_empty() << "\n";
    lst.insert(10);
    lst.append(20);
    lst.insert(5);
    std::cout << "count = " << lst.count() << "\n";
    std::cout << "has 20 " << lst.is_present(20) << "\n";
    std::cout << "has 99 " << lst.is_present(99) << "\n";
}

// Завдання 3 //

template <class T>
class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();

	void insert(const T& value);
	void append(const T& value);
	int is_present(const T& value) const;
	int is_empty() const { return head == nullptr;}
	int count() const { return theCount; }

private:
	class ListCell
	{
    public:
   
    	explicit ListCell(const T& value, ListCell *cell = nullptr) : val(value),
                                              	next(cell) {}
	T val;
    ListCell* next;
};
	
    T val;
    ListCell* next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};


template <class T>
List<T>::~List() {
    ListCell* p = head;
    while (p) {
        ListCell* n = p->next;
        delete p;
        p = n;
    }
    head = tail = 0;
    theCount = 0;
}

template <class T>
void List<T>::insert(const T& value) {
    ListCell* node = new ListCell(value, head);
    head = node;
    if (!tail) tail = head; 
    ++theCount;
}

template <class T>
void List<T>::append(const T& value) {
    ListCell* node = new ListCell(value, 0);
    if (tail) {
        tail->next = node;
        tail = node;
    } else {
        head = tail = node; 
    }
    ++theCount;
}

template <class T>
int List<T>::is_present(const T& value) const {
    for (ListCell* p = head; p; p = p->next) {
        if (p->val == value) return 1;
    }
    return 0;
}

int main() {
    List<int> a;
    a.insert(10);
    a.append(20);
    a.insert(5);

    std::cout << "count = " << a.count() << "\n";     
    std::cout << "has 20? " << a.is_present(20) << "\n"; 
    std::cout << "empty? " << a.is_empty() << "\n";      

    List<std::string> b;
    b.append(std::string("hello"));
    b.insert(std::string("world"));
    std::cout << "has 'hello'? " << b.is_present(std::string("hello")) << "\n"; 

    return 0;
}

// Завдання 4 //

template <class T>
class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();

	void insert(const T& value);
	void append(const T& value);
	int is_present(const T& value) const;
	int is_empty() const { return head == nullptr;}
	int count() const { return theCount; }

private:
	class ListCell
	{
    public:
   
    	explicit ListCell(const T& value, ListCell *cell = nullptr) : val(value),
                                              	next(cell) {}
	T val;
    ListCell* next;
};
	
    T val;
    ListCell* next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};


template <class T>
List<T>::~List() {
    ListCell* p = head;
    while (p) {
        ListCell* n = p->next;
        delete p;
        p = n;
    }
    head = tail = 0;
    theCount = 0;
}

template <class T>
void List<T>::insert(const T& value) {
    ListCell* node = new ListCell(value, head);
    head = node;
    if (!tail) tail = head; 
    ++theCount;
}

template <class T>
void List<T>::append(const T& value) {
    ListCell* node = new ListCell(value, 0);
    if (tail) {
        tail->next = node;
        tail = node;
    } else {
        head = tail = node; 
    }
    ++theCount;
}

template <class T>
int List<T>::is_present(const T& value) const {
    for (ListCell* p = head; p; p = p->next) {
        if (p->val == value) return 1;
    }
    return 0;
}

struct Cat {
    std::string name;
};

inline bool operator==(const Cat& a, const Cat& b) {
    return a.name == b.name;
}

inline std::ostream& operator<<(std::ostream& os, const Cat& c) {
    return os << c.name;
}

int main() {
    List<int> a;
    a.insert(10);
    a.append(20);
    a.insert(5);

    std::cout << "count = " << a.count() << "\n";
    std::cout << "has 20 " << a.is_present(20) << "\n";
    std::cout << "empty " << a.is_empty() << "\n";

    List<std::string> b;
    b.append(std::string("hello"));
    b.insert(std::string("world"));
    std::cout << " 'hello' " << b.is_present(std::string("hello")) << "\n";

    List<Cat> d;
    Cat fr; fr.name = "Frisky";
    Cat fe; fe.name = "Felix";

    d.insert(fr);
    d.append(fe);

    std::cout << "First cat is " << fr.name << " \n";
    std::cout << "Second cat is " << fe.name << "\n";

	return 0;
}

// Завдання 5 //

List<Cat> Cat_List;
Cat Felix;
CatList.append(Felix); // немає змінної CatList правильно Cat_List;
cout << "Felix is "
 	<< (Cat_List.is_present(Felix)) ? " " : " not " // неправильні дужки 
 	<< "present\n";

	// виправлений варіант //
List<Cat> Cat_List;
Cat Felix;
Felix.name = "Felix";
Cat_List.append(Felix);
cout << "Felix is "
	<< (Cat_List.is_present(Felix) ? "" : "not ")
	<< "present\n";

	// Завдання 6 //
template <class T>
class List
{ // код якій був вище //

friend bool operator==(const List& a, const List& b) {
	if (a.theCount != b.theCount) return false;
    auto pa = a.head;
    auto pb = b.head;
    while (pa && pb) {
        if (!(pa->val == pb->val)) return false; 
        pa = pa->next;
        pb = pb->next;
        }
    	return true;
    }
};

// Завдання 7 //

template <class T>
class List
{ // код якій був вище //
friend bool operator==(const List& a, const List& b) {
	if (a.theCount != b.theCount) return false;
    auto pa = a.head;
    auto pb = b.head;
    while (pa && pb) {
        if (!(pa->val == pb->val)) return false; 
        pa = pa->next;
        pb = pb->next;
        }
    	return true;
    }


friend bool operator!=(const List& a, const List& b) {
        return !(a == b);
    }
};

// Завдання 8 //
Так,для int порівлювальні елементі працюють завжди а для  типу Cat треба мати визначений operator== для Cat, інакше інстанціювання шаблону впаде на компіляції.

// Завдання 9 //

template <typename T>
void my_swap_old(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
	int a = 10;
	int b = 30;

    std::cout << "before: a = " << a << ", b = " << b << "\n";
	my_swap_old(a, b);
    std::cout << "after: a = " << a << ", b = " << b << "\n";

	return 0;
}
	
// Завдання 10 //
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
public:
	Student();
	Student(const string &name, const int age);
	Student(const Student &rhs);
	~Student();

	void SetName(const string &name);
	string GetName() const;
	void SetAge(const int age);
	int GetAge() const;
	Student &operator=(const Student &rhs);

private:
	string itsName;
	int itsAge;
};

Student::Student()
	: itsName("New Student"), itsAge(16)
{
}

Student::Student(const string &name, const int age) : itsName(name), itsAge(age)
{
}

Student::Student(const Student &rhs) : itsName(rhs.GetName()),
									   itsAge(rhs.GetAge())
{
}

Student::~Student()
{
}

void Student::SetName(const string &name)
{
	itsName = name;
}

string Student::GetName() const
{
	return itsName;
}

void Student::SetAge(const int age)
{
	itsAge = age;
}

int Student::GetAge() const
{
	return itsAge;
}

Student &Student::operator=(const Student &rhs)
{
	itsName = rhs.GetName();
	itsAge = rhs.GetAge();
	return *this;
}

ostream &operator<<(ostream &os, const Student &rhs)
{
	os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
	return os;
}

template <class T>
void ShowVector(const vector<T> &v); // Відображає властивості вектора

typedef vector<Student> SchoolClass;

int main()
{
	Student Harry;
	Student Sally("Sally", 15);
	Student Bill("Bill", 17);
	Student Peter("Peter", 16);

	SchoolClass EmptyClass;
	cout << "EmptyClass:\n";
	ShowVector(EmptyClass);

	SchoolClass GrowingClass(3);

	cout << "GrowingClass(3):\n";
	ShowVector(GrowingClass);
	GrowingClass[0] = Harry;
	GrowingClass[1] = Sally;
	GrowingClass[2] = Bill;
	cout << "GrowingClass(3) after assigning students:\n";
	ShowVector(GrowingClass);

	GrowingClass.push_back(Peter);
	cout << "GrowingClass() after aded 4ht student:\n";
	ShowVector(GrowingClass);

	GrowingClass[0].SetName("Harry");
	GrowingClass[0].SetAge(18);
	cout << "GrowingClass() after Set:\n";
	ShowVector(GrowingClass);

	GrowingClass.reserve(GrowingClass.size () + 4);
	Student Anna("Anna", 16);
	GrowingClass.push_back(Anna);
	ShowVector(GrowingClass);

	Student Kate("Kate", 16);
	GrowingClass.push_back(Kate);
	ShowVector(GrowingClass);

	Student Pavlo("Pavlo", 16);
	GrowingClass.push_back(Pavlo);
	ShowVector(GrowingClass);

	Student Bob("Bob", 16);
	GrowingClass.push_back(Bob);
	ShowVector(GrowingClass);

	for (Student& s : GrowingClass) {
		s.SetAge(s.GetAge() +1);
	}
	cout << "After +1 year for everyone:\n";
	ShowVector(GrowingClass);	
	return 0;
}

//
// Відображає властивості вектора
//
template <class T>
void ShowVector(const vector<T> &v)
{
	cout << "max_size() = " << v.max_size();
	cout << "\tsize() = " << v.size();
	cout << "\tcapacity() = " << v.capacity();
	cout << "\t " << (v.empty() ? "empty" : "not empty");
	cout << "\n";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\n";
	cout << endl;
}

// Завдання 10 //

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

class Student
{
public:
    Student();
    Student(const string &name, const int age);
    Student(const Student &rhs);
    ~Student();

    void SetName(const string &name);
    string GetName() const;
    void SetAge(const int age);
    int GetAge() const;
    Student &operator=(const Student &rhs);

private:
    string itsName;
    int itsAge;
};

Student::Student()
    : itsName("New Student"), itsAge(16)
{
}

Student::Student(const string &name, const int age) : itsName(name), itsAge(age)
{
}

Student::Student(const Student &rhs) : itsName(rhs.GetName()),
                                       itsAge(rhs.GetAge())
{
}

Student::~Student()
{
}

void Student::SetName(const string &name)
{
    itsName = name;
}

string Student::GetName() const
{
    return itsName;
}

void Student::SetAge(const int age)
{
    itsAge = age;
}

int Student::GetAge() const
{
    return itsAge;
}

Student &Student::operator=(const Student &rhs)
{
    itsName = rhs.GetName();
    itsAge = rhs.GetAge();
    return *this;
}


ostream &operator<<(ostream &os, const Student &rhs)
{
    os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
    return os;
}

struct PrintStudent {
    void operator()(const Student& s) const {
        cout << s.GetName() << " is " << s.GetAge() << " years old\n";
    }
};

template <class T>
void ShowVector(const vector<T> &v); 

typedef vector<Student> SchoolClass;

int main()
{
    Student Harry;
    Student Sally("Sally", 15);
    Student Bill("Bill", 17);
    Student Peter("Peter", 16);

    SchoolClass EmptyClass;
    cout << "EmptyClass:\n";
    ShowVector(EmptyClass);

    SchoolClass GrowingClass(3);

    cout << "GrowingClass(3):\n";
    ShowVector(GrowingClass);
    GrowingClass[0] = Harry;
    GrowingClass[1] = Sally;
    GrowingClass[2] = Bill;
    cout << "GrowingClass(3) after assigning students:\n";
    ShowVector(GrowingClass);

    GrowingClass.push_back(Peter);
    cout << "GrowingClass() after added 4th student:\n";
    ShowVector(GrowingClass);

    GrowingClass[0].SetName("Harry");
    GrowingClass[0].SetAge(18);
    cout << "GrowingClass() after Set:\n";
    ShowVector(GrowingClass);

    GrowingClass.reserve(GrowingClass.size() + 4);
    Student Anna("Anna", 16);
    GrowingClass.push_back(Anna);
    ShowVector(GrowingClass);

    Student Kate("Kate", 16);
    GrowingClass.push_back(Kate);
    ShowVector(GrowingClass);

    Student Pavlo("Pavlo", 16);
    GrowingClass.push_back(Pavlo);
    ShowVector(GrowingClass);

    Student Bob("Bob", 16);
    GrowingClass.push_back(Bob);
    ShowVector(GrowingClass);


    for (Student& s : GrowingClass) s.SetAge(s.GetAge() + 1);
    cout << "After +1 year for everyone:\n";
    ShowVector(GrowingClass);

    return 0;
}


template <class T>
void ShowVector(const vector<T> &v)
{
    cout << "max_size() = " << v.max_size();
    cout << "\tsize() = " << v.size();
    cout << "\tcapacity() = " << v.capacity();
    cout << "\t " << (v.empty() ? "empty" : "not empty");
    cout << "\n";

    std::for_each(v.begin(), v.end(), PrintStudent{});

    cout << endl;
}



