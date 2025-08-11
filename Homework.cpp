#include <iostream>
using namespace std;

// Завдання 1 //

class Car {
 public:

	Car(int km) : mileage(km) {
		totalCars++;
		cout << "Car created. Mileage: " << mileage
             << " km. Total cars: " << totalCars << endl;
	}
	~Car () {
	totalCars--;
	cout << "Car destroyed. Mileage was: " << mileage
             << " km. Remaining cars: " << totalCars << endl;
	}

	void ShowMileage() const {
		cout << "Car drove " << mileage << " km." << endl;
	}

	static int GetTotalCars() {
		return totalCars;
	}

 private:
	int mileage;
	static int totalCars;

};

int Car::totalCars = 0;


int main() {
	Car a(1000);
	Car b(2500);

	a.ShowMilеage();
	b.ShowMilеage();

	cout << "Total cars (inside block): " << Car::GetTotalCars() << endl;
    cout << "Total cars (after block): " << Car::GetTotalCars() << endl;
    return 0;
}
	
// Завдання 2 //

int main (){
	Car* c1 = new Car (1000);
	Car* c2 = new Car (3500);
	Car* c3 = new Car (5600);

	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
	cout << "\n--- Deleting c1 ---\n";
	delete c1;
	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
	cout << "\n--- Deleting c2 ---\n";
	delete c2;
	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
	cout << "\n--- Deleting c3 ---\n";
	delete c3;
	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
		return 0;
	}
	
	// Завдання 3 //

int main (){
	Car* c1 = new Car (1000);
	Car* c2 = new Car (3500);
	Car* c3 = new Car (5600);



	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
	cout << "\n--- Deleting c1 ---\n";
	delete c1;
	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
	cout << "\n--- Deleting c2 ---\n";
	delete c2;
	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
	cout << "\n--- Deleting c3 ---\n";
	delete c3;
	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;

		return 0;
	} 

// Завдання 4 //

	class Car {
 public:

	Car(int km) : mileage(km) {totalCars++;}
	~Car () { totalCars--; }

	int GetMilleage() const {return mileage;}
	static int GetTotalCars() {return totalCars;}

 private:
	int mileage;
	static int totalCars;

};

int Car::totalCars = 0;

int main (){
	Car* c1 = new Car (1000);
	Car* c2 = new Car (3500);
	Car* c3 = new Car (5600);
	
	int (Car::*ptc)() const = &Car::GetMilleage;

	cout << "Car 1 mileage: " << (c1->*ptc) () << endl;
	cout << "Car 2 mileage: " << (c2->*ptc) () << endl; 
	cout << "Car 3 mileage: " << (c3->*ptc) () << endl; 

	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
	cout << "\n--- Deleting c1 ---\n";
	delete c1;
	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
	cout << "\n--- Deleting c2 ---\n";
	delete c2;
	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
	cout << "\n--- Deleting c3 ---\n";
	delete c3;
	cout << "\nTotal cars now: " << Car::GetTotalCars() << endl;
	
	return 0;
}

// Завдання 5 //

class Car {
 public:

	int years;
	int horsepower;

	Car(int km, int yr, int hp) : 
		mileage(km), years(yr), horsepower(hp) {
		totalCars++;}

	~Car () {totalCars--;}

	int GetMileage() const {return mileage;}
	static int GetTotalCars() {return totalCars;}

 private:
	int mileage;
	static int totalCars;
};
int Car::totalCars = 0;

int main (){
	Car c1(1000, 2020, 150);
    Car c2(3500, 2021, 180);
    Car c3(5600, 2019, 140);

    using Field = int Car::*;

    array<Field, 2> fields = { &Car::years, &Car::horsepower };
    array<const char*, 2> names = { "year", "horsepower" };

    array<Car*, 3> cars = { &c1, &c2, &c3 };

    for (size_t i = 0; i < cars.size(); ++i) {
        cout << "Car #" << i + 1 << ":\n";
        for (size_t j = 0; j < fields.size(); ++j) {
            cout << "  " << names[j] << " = " << cars[i]->*fields[j] << '\n';
        }

        cout << "  mileage = " << cars[i]->GetMileage() << '\n';
    }
	return 0;
}