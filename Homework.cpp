#include <iostream>
using namespace std;

// Завдання 1 //

	• int *pOne; // int - тип змінної, на який вказує вказівник, * - символ, який вказує на те, що pOne це вказівник, pOne - назва вказівника //
	• int vTwo: // vTwo назва змінної типу int //
	• int *pThree = &vTwo; // вказівнику int *pThree присвоюється адреса змінної vTwo, знак & означає адресу, отже pThree зберігає адресу vTwo //

// Завдання 2 //

unsigned short yourAge;
unsigned short *pyourAge = &yourAge;

// Завдання 3 //

int number;
int *pnumber = &number;
*pnumber = 50;

// Завдання 4 //

int main ()
{
   int my_age = 28;
   int *pmy_age = &my_age;
   cout << " My age is " << my_age << endl;

   *pmy_age = 30;
    cout << " Now my age is " << my_age << endl;

   return 0;
}

// Завдання 5 //

#include <iostream>

using namespace std;

int main()
{
	int *pInt; // використання неініціалізованного вказівника, потрібна змінна на чию адресу буде вказувати вказівник //
	*pInt = 9;
	cout << " The value at pInt: "<< *pInt;

	return 0;
}

// Завдання 6 //

#include <iostream>

using namespace std;

int main()
{
	int SomeVariable = 5;
	cout << "SomeVariable: " << SomeVariable << "\n";
	int *pVar = &SomeVariable;
	pVar = 9; // неправильно написаний вказівний, він йде з позначкою *, а без цього символа буде помилкове присвоєння, яке буде ззмінювати сам вказівник //
	cout << "SomeVariable: " << *pVar << "\n";
	return 0;
}
