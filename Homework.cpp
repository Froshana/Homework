#include <iostream>
using namespace std;

// Завдання 1-2 //

unsigned long int Perimeter (unsigned short int length, unsigned short int width)
{
   return 2 * (length + width); 
}

int main ()
{
   unsigned short int length, width;

   cout << "Enter length: ";
   cin >> length;

   cout << "Enter width: ";
   cin >> width;

   unsigned long int result = Perimeter (length,width);

   cout << "Perimeter = " << result << endl;

  return 0;
} 

// Завдання 3 //

#include <iostream>
using namespace std;

void myFunc(unsigned short int x); // функція void не повертає значення, краще замінити void на unsigned short int //
int main()
{
    unsigned short int x, y;
    y = myFunc(int); // неправильний виклик функціі,  ми передаємо змінну, а не тип, правильно буде так y = myFunc(x) //
    cout << "x: " << x << "y: " << y << "\n"; // x не була ініціалізована, можна або присвоїти їй число, або задопомоги cin взяти число від користувача //
// немає return 0; яка повідомляє операційній системі, що програма завершилася успішно //
}
void myFunc(unsigned short int x) //  функція myFunc оголошена, як void, як я писала треба замінити на unsigned short int umyFunc(unsigned short int x), або int //
{
    return (4 * x);
}


// Завдання 4 //

#include <iostream>
using namespace std;

int myFunc(unsigned short int x); 

int main()
{
    unsigned short int x, y;
    y = myFunc(x);
    cout << "x: " << x << " y: " << y << "\n"; // неініціалізована х, або треба оголосити або отримати через cin //
    // немає return 0;
}

int myFunc(unsigned short int x); // функція неправильно реалізована, крапка з комою закривє функцію //
{
    return (4 * x); // не обовязково тут ставити дужки, але можна і з ними //
}


// Завдання 5-6 //

int piypiy (unsigned short int x, unsigned short int y)
{
if (y != 0) 
   return x / y;

else
   return -1; 
}

int main ()
{
   unsigned short int x,y;

   cout << "Enter first number: ";
   cin >> x;

   cout << "Enter second number: ";
   cin >> y;
   
   int result = piypiy(x,y);

if (result == -1)
   cout << "Error! " << endl;

else 
   cout << "Result is: " << result << endl;

// скобки в умовах if та else я не забула, а проігнорувала, бо в мене є тільки один оператор cout, то їх можна не ставити, бо немає чого групурувати //
return 0;

}