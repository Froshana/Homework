/**
#include <iostream>
using namespace std;

class Vehicle {
 public:
	Vehicle() {}
	virtual ~Vehicle() {}

	virtual void Speed() { cout << "Vehicle is moving..." << endl; }	
	virtual void Sound() = 0;

};
/*
class Car : public Vehicle {
 public:
	void Speed() override { cout << "The car accelerates to 220 km/h" << endl; }
	void Sound() override { cout << "Vrun Vrun" << endl; }
	};

class Bus : public Vehicle {
 public:
	void Speed() override { cout << "The bus accelerates to 150 km/h" << endl; }
	void Sound() override { cout << "Bzhin Bzhin Bzhin" << endl; }
};
int main() {
	void (Vehicle::*pFunc)() = nullptr;
	Vehicle* ptr = nullptr;

	int Power;
	int Transportation;
	int Method;
	bool fQuit = false;

	while (!fQuit) {
		cout << "(0)Quit (1)Car (2)Bus" << endl;
		cin >> Transportation;

		switch (Transportation) {
			case 1:
				ptr = new Car;
				break;
			case 2:
				ptr = new Bus;
				break;
			default:
				fQuit = true;
				break;
		}

		if (fQuit)
			break;
		
		cout << "(1)Speed (2)Sound: ";
		cin >> Method;

		switch (Method) {
			case 1:
				pFunc = &Vehicle::Speed;
				break;
			default:
				pFunc = &Vehicle::Sound;
				break;
		}

		(ptr->*pFunc)();
		delete ptr;
	}

	
	return 0;
}


// Завдання 2 // 

class Car : public Vehicle {
 public:
	void Speed() override { Vehicle::Speed();
		cout << "The car accelerates..." << endl;
	}
	virtual void Sound() = 0; 
	virtual ~Car() {}
};

class SportsCar : public Car {
	void Speed () override { 
		Car::Speed();
		cout << "Max speed is 350 km/h" << endl;
	}
	void Sound () override { cout << "Bzzzzzzzzun" << endl; }
};

class Wagon : public Car {
	void Speed () override { 
		Car::Speed();
		cout << "Max speed is 190 km/h" << endl;
	}
	void Sound () override { cout << "Fzhin Fzhin" << endl; }
};

class Coupe : public Car {
	void Speed () override { 
		Car::Speed();
		cout << "Max speed is 200 km/h" << endl;}
	void Sound () override { cout << "Biu Biu" << endl; }
};

int main() {
	Car* cars[3];
	cars[0] = new SportsCar;
	cars[1] = new Wagon;
	cars[2] = new Coupe;

	for (int i = 0; i < 3; ++i) {
		cars[i] -> Speed();
		cars[i] -> Sound();
		cout << "------------" << endl;
		delete cars[i];
	}
	return 0;
} 
*/
// Завдання 3 //

#include <iostream>
using namespace std;

class Car {
 public:
	Car (int km) : Speed(km) {
		Fuel++;
		cout << "The car drove " << Speed << " km" << endl;
	}

	~Car() {
		Fuel--;
		cout << "Car stopped. Speed was: " << Speed << ". Now it 0 on speedometer" << endl;
	}
	static int GetFuel() {
		return Fuel;
	}

 private:
 	int Speed;
 	static int Fuel;
};

int Car::Fuel = 0;

int main() {
	{
		Car a(100);
		Car b(200);
		cout << "Currently fuel count: " << Car::GetFuel() << endl;
	}
	cout << "After stop, fuel count: " << Car::GetFuel() << endl;
	return 0;
}