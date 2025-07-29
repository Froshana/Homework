// Завдання 1-2 //
#include <iostream>
using namespace std;

class Rocket {
 public:
	Rocket(double m, double f) : mass(m), fuelAmount(f){}

	void Setmass (double m) { mass = m;}
	void SetFuel (double f) {fuelAmount = f;}

	double GetMass() const {return mass;}
	double GetFuel() const {return fuelAmount;}

	virtual void Start() {
		if (fuelAmount > 0) 
			cout << "Ракета стартує 🚀\n";
		else
			cout << "Недостатньо палива\n";
		}
	
	virtual ~Rocket() = default;

 private:
	double mass;
	double fuelAmount;
};

class Airplane{
 public:
	
 Airplane (double s, double a) : speed(s), altitude(a){}

 void SetSpeed(double s){speed = s;}
 void SetAltitude(double a){ altitude = a;}

 double GetSpeed() const {return speed;}
 double GetAltitude() const {return altitude;}

 private:
	double speed;
	double altitude;
};

class Jetplane : public Rocket, public Airplane {
 public:
	Jetplane(double m, double f, double s, double a)
	: Rocket(m,f), Airplane(s,a){}

	void Start() override {
		if (GetFuel() > 0 && GetSpeed() > 0 && GetAltitude() >= 0) {
			cout << "Jetplane стартує 🛫\n";
			cout << "Швидкість:" << GetSpeed() << "\nм/с\n";
			cout << "Висота: "<< GetAltitude() << "\nм\n";
		} else {
			cout << "Недостатньо палива або некоректні дані\n";
		}
	}
	
};
/*
int main() {
	double mass, fuel, speed, altitude;
	cout << "Введіть масу 🛫Реактівного літака:\n";
	cin >> mass;

	cout << "Введіть кількість палива 🛫Реактівного літака :\n";
	cin >> fuel;

	cout << "Введіть швидкість🛫Реактівного літака :\n";
	cin >> speed;

	cout << "Введіть висоту 🛫Реактівного літака :\n";
	cin >> altitude;

	Jetplane jp(mass, fuel, speed, altitude);
	jp.Start();

	return 0;
} */

class Boeing747 : public Jetplane {
 public:
	Boeing747(double m, double f, double s, double a, int passengers)
		: Jetplane(m,f,s,a), passengerCount(passengers) {}

	void BoardPassengers (int count) {
		passengerCount += count;
		cout << "На літак сіло " <<count << " пасажирів. Всого: \n" << passengerCount;
	}

	void Start() override {
		if (GetFuel() > 0 && GetSpeed() > 0 && GetAltitude() >= 0 && passengerCount > 0) {
			cout << "Boeing747 з " << passengerCount << " пасажирами взлітає 🛫\n";
		} else {
			cout << "Boeing747 не може старувати. Перевірте паливо, висоту, швидкість або кількість пасажирів.\n" ;
		}
	}


 private:
 int passengerCount;
};

int main() {
	double mass, fuel, speed, altitude;
	int passengers;

	cout << "Введіть масу 🛫Реактівного літака:\n";
	cin >> mass;

	cout << "Введіть кількість палива 🛫Реактівного літака:\n";
	cin >> fuel;

	cout << "Введіть швидкість🛫Реактівного літака:\n";
	cin >> speed;

	cout << "Введіть висоту 🛫Реактівного літака:\n";
	cin >> altitude;

	cout << "Введіть кількість пасажирів:\n";
	cin >> passengers;

	Boeing747 boeing(mass, fuel, speed, altitude, passengers);
	boeing.Start();

	return 0;
}