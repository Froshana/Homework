#include <iostream>
#include <iomanip> 

// Завдання 1 //

/* Ваш вік - тут я використаю зминну  unsigned short int, бо це невелике невід'ємне число.

Площа вашого заднього двору - float (але можна і double для більшої точності, але тут мені це не потрібно )
бо площа може містити десяткові дроби.

Кількість зірок у галактиці - це дуже велике число, тому я буду використовувати змінну  long long.

Середній рівень випадання опадів за січень - double, для більшої точності.
*/

// Завдання 2 //

using namespace std;

int main() {
   unsigned short int myAge = 28;
   cout << "My age: " << myAge << endl;

   float a = 20.8;
   float yardArea = a * a;
   cout << "Yard area: " << yardArea << endl;

   long long starsPerClusterInGalaxy = 1000000;
   long long clusterInGalaxy = 150;
   long long allStarsInGalaxy = starsPerClusterInGalaxy * clusterInGalaxy;
   cout << "Stars in Galaxy: " << allStarsInGalaxy << endl;
   
   double weekOne = 39.11;
   double weekTwo = 44.67;
   double weekThree = 41.23;
   double weekFour = 47.35;

   double average = (weekOne + weekTwo + weekThree + weekFour)/4;
   cout << "Average percipitation for January: " << average << endl;

   // Завдання 3 // 

   // Варіант 1://

    const double  PI = 3.14159265358979311600; // можна long double //

    /* Варіант 2 з підключенням бібліотекі #include <numbers>
    const double PI = std::numbers::pi; */
    cout << fixed << setprecision(20);
    cout << "Pi = " << PI << endl; 

    /* я трохи змінила код для цього завдання, щоб мені змогло вивести число більше ніж дозволяє cout після коми
тому я додала бібліотеку iomanip, яка дозволила мені використати setprecision, і тепер число виводсться через cout як Pi = 3.14159265358979311600
*/
// Завдання 4 //

float Pi = PI;
cout << "F Pi = " << Pi << endl;

   return 0;
 // виведуться трохи різні цифри, бо float втрачає точнисть на 7ому знаці //

}
