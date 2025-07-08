#include <iostream>
using namespace std;

// Завдання 1 //

int main (){
	int num = 50;
	int& piy = num;
	int* piypiy = &num;

	cout << " Перше число = " << num << endl;

	piy = 10;
	cout << " Число після зміни посилання = " << num << endl;

	*piypiy = 30;
	cout << " Число після зміни вказівника = " << num << endl;

	return 0;
}

// Завдання 2 - 3 //

int main (){
	
	int varOne = 6;
	int* const piypiy = &varOne; // Вказівник константний, але значення змінне, тож видає попередження про це //

	*piypiy = 7; // Можна змінити значення, ніяких попереджень компілятора //

	int varTwo = 10;
	piypiy = &varTwo; // Неможливо змінити адресу константного вказівника //

	return 0;
}

// Завдання 4 //

	int *num;
	{
		int twonum = 30;
		num = &twonum;
	}
	cout << *num; 

// Завдання 5 //

int twonum = 30;
int *num = &twonum;

cout << *num;

// Завдання 6 //

int main (){
	int *num = new int (235);
	cout << "" << *num << endl; 

return 0; // Ми не звільнили пам'ять, що призводе до витоку //
}

// Завдання 7 //

int main (){
	int *num = new int (235);
	cout << "" << *num << endl; 

	delete num;

	return 0; 
}

// Завдання 8 //

#include <iostream>
using namespace std;

class Cat
{
public:
	Cat(int age) { itsAge = age; } //  
	~Cat() {}
	int GetAge() const { return itsAge; }

private:
	int itsAge;
};

Cat &MakeCat(int age);

int main()
{
	int age = 7;
	Cat Boots = MakeCat(age);
	cout << "Boots is: " << Boots.GetAge() << " years old" << endl;
	return 0;
}

Cat &MakeCat(int age)
{
	Cat *pCat = new Cat(age);
	return *pCat; // повертає послання, але не звільняє його, що призводить до витоку пам'яті //
}


// Завдання 9 //

#include <iostream>

using namespace std;

// Варіант перший можна  не повертати посилання на об'єкт через new, а повернути об'єкт за значенням //

class Cat
{
public:
	Cat(int age) { itsAge = age; }
	~Cat() {}
	int GetAge() const { return itsAge; }

private:
	int itsAge;
};

Cat MakeCat(int age); // певертає об'єкт , а не посилання //

int main()
{
	int age = 7;
	Cat Boots = MakeCat(age);
	cout << "Boots is: " << Boots.GetAge() << " years old" << endl;
	return 0;
}

Cat MakeCat(int age)
{
	Cat cat(age);
	return cat;
}
 // або //

#include <iostream>
using namespace std;

class Cat
{
public:
	Cat(int age) { itsAge = age; }
	~Cat() {}
	int GetAge() const { return itsAge; }

private:
	int itsAge;
};

Cat &MakeCat(int age);

int main()
{
	int age = 7;
	Cat& Boots = MakeCat(age); // робимо посилання на об'єкт //
	cout << "Boots is: " << Boots.GetAge() << " years old" << endl;
	delete &Boots; // очищаємо пам'ять //
	return 0;
}

Cat &MakeCat(int age)
{
	Cat *pCat = new Cat(age);
	return *pCat;
}

