#include <iostream>
using namespace std;

// Завдання 1 //

int Rise_to_power (int a, int b)
{
if (b == 0)
      return 1;
else
   return a * Rise_to_power(a, b - 1);
}

int main ()
{
   int a, b;
   
   cout << "Enter a number: ";
   cin >> a;
   
   cout << "Enter the exponent: ";
   cin >> b;

   int result = Rise_to_power (a, b);
   cout << a << " raised to the power " << b << " is " << result << endl;
   
   return 0;
}


// Завдання 2-6 //

class Employee 
{
private:
   int age;
   int years_of_service;
   int salary;

public:
void set_info (int a, int b)
{
   age = a;
   years_of_service = b;
   calculate_salary ();
}

void calculate_salary ()
{
   int base = 3000;
   int bonus = years_of_service * 100;
   salary = base + bonus;
}

void get_info ()
{
  cout << "Age: " << age << " | Years of service: " << years_of_service << " | Salary " << salary << endl;
}

int salary_in_thousand ()
{
   int round_salary = ((salary + 5) / 10) * 10;
   return round_salary / 1000;
}

};

int main ()
{
Employee one;
   one.set_info (32, 5);
   one.get_info ();
   cout << "Salary: " << one.salary_in_thousand () << "k" << endl;

Employee two;
    two.set_info (28, 7);
    two.get_info ();
cout << "Rounded salary: " << two.salary_in_thousand () << "k" << endl;

   return 0;
}



// Завдання 7 //

class Square
{
public:
    int Side;
} // тут повінна бути крапка з комою ; //

// Завдання 8 //

class Cat
{
    int GetAge() const; // GetAge() оголошений, але не визначений, немає public тож цей метод зараховується до private //
   private:
    int itsAge;
};

// Завдання 9 //

class TV
{
public:
    void SetStation(int Station);
    int GetStation() const;

private:
    int itsStation;
};
main() // main  повинна мати тип int //
{
    TV myTV;
    myTV.itsStation = 9; // ми не можемо змінювати напряму itsStation, так як вона у приватному доступі //
    TV.SetStation(10); // клас TV це тип, а не обєкт //
    TV myOtherTV(2); // у класі не має конструктора, який приймає int //
}
