#include <iostream>
using namespace std;

// Завдання 1 //

class SimpleCircle{
 public:
	SimpleCircle (int radius = 1) : itsRadius(radius){}

	SimpleCircle& operator++(){
		++itsRadius;
		return *this;
	}
	
	SimpleCircle operator++(int){
		SimpleCircle temp = *this;
		itsRadius++;
		return temp;
	}

	int GetRadius() const {return itsRadius;}

 private:
	int itsRadius;

};

int main(){
	SimpleCircle circle(10);

	cout << " Радіус = " << circle.GetRadius() << endl;

	++circle;
	cout << "" << circle.GetRadius() << endl;

	circle++;
	cout << "" << circle.GetRadius() << endl;

	return 0;
}
// Завдання 2-3 //

class SimpleCircle{
 public:
	SimpleCircle(int radius = 1){
		itsRadius = new int(radius);
	}

	SimpleCircle(const SimpleCircle& other){
		itsRadius = new int(*other.itsRadius);
	}

	SimpleCircle& operator=(const SimpleCircle& other){
		if (this != &other) {
			delet itsRadius;
			itsradius = new int(*other.itsRadius);
		}
		return *this;
	}

	~SimpleCircle() {
		delete itsRadius;
	}

	SimpleCircle operator ++(){
		++(*itsRadius);
		return *this;
	}

	SimpleCircle operator++(int){
		SimpleCircle temp = *this;
		++(*itsRadius);
		return temp;
	}

	int Getradius() const{
		return *itsRadius;
	}

 private:
	int* itsRadius;
};

int main(){
	SimpleCircle circle(10);

	cout << " Радіус = " << circle.GetRadius() << endl;

	++circle;
	cout << "" << circle.GetRadius() << endl;

	circle++;
	cout << "" << circle.GetRadius() << endl;

	return 0;
}

// Завдання 4 //

class SimpleCircle{
 public:
	SimpleCircle(int radius = 1){
		itsRadius = new int(radius);
	}

	SimpleCircle(const SimpleCircle& other){
		itsRadius = new int(*other.itsRadius);
	}

	SimpleCircle& operator=(const SimpleCircle& other){
		if (this != &other){
			delete itsRadius;
			itsRadius = new int(*other.itsRadius);
		}
		return *this;
	}

	~SimpleCircle(){
		delete itsRadius;
	}

 private:
	int *itsRadius;
}

int main (){
	SimpleCircle a(5);
	SimpleCircle b = a;

	SimpleCircle c;
	c = a;

	cout << "a radius: " << a.GetRadius() << endl;
	cout << "b radius: " << b.GetRadius() << endl;
	cout << "c radius: " << c.GetRadius() << endl;

	return 0;
}

// Завдання 5 //

class SimpleCircle{
 public:
	SimpleCircle(int radius = 1){
		itsRadius = new int(radius);
	}

	SimpleCircle(const SimpleCircle& other){
		itsRadius = new int(*other.itsRadius);
	}

	SimpleCircle& operator=(const SimpleCircle& other){
		if (this != &other) {
			delete itsRadius;
			itsRadius = new int(*other.itsRadius);
		}
		return *this;
	}

	~SimpleCircle() {
		delete itsRadius;
	}

	SimpleCircle operator ++(){
		++(*itsRadius);
		return *this;
	}

	SimpleCircle operator++(int){
		SimpleCircle temp = *this;
		++(*itsRadius);
		return temp;
	}

	int GetRadius() const{
		return *itsRadius;
	}

 private:
	int* itsRadius;
};

int main (){
	SimpleCircle circle1;
	SimpleCircle circle2(9);

	++circle1;
	cout << "circle1: " << circle1.GetRadius() << endl;

	circle2++;
	cout << "circle2: " << circle2.GetRadius() << endl;


	circle1 = circle2;
	cout << "circle1: " << circle1.GetRadius() << endl;


	return 0;
}

// Завдання 6 //

SQUARE SQUARE::operator=(const SQUARE &rhs)
{
	itsSide = new int; // якщо є динамічна пам'ть, то потрібно реалізувати конструктор копіювання, оператор прісвоєння та деструктор, тут не очіщається стара пам'ять, повертає об'єкт за значенням, а не за посиланням
	*itsSide = rhs.GetSide();
	return *this: // потрібно поставити ; замість :
}   

// Завдання 7 //

VeryShort VeryShort::operator+(const VeryShort &rhs)
{
	itsVal += rhs.GetItsVal(); // змінює об'єкт непраильно, хоча по ідеї має створити новий
	return *this; // його ж повертає
}   

// Завдання 8 //

class Shape {
 public:
	void ShowType(){
		cout << "Фігура." << endl;
	}
};

class Rectangle : public Shape {
 public:
	void ShowType(){
		cout << "Прямокутник." << endl;
	}
};

class Square : public Rectangle {
 public:
	void ShowType(){
		cout << "Квадрат." << endl;
	}
};

int main (){
	Square sq;
	sq.ShowType();

	return 0;
}

// Завдання 9 //

class Shape {
 public:
	Shape(){};
	void ShowType(){
		cout << "Фігура." << endl;
	}
};

class Rectangle : public Shape {
 public:
	Rectangle(int length, int width){}
	void ShowType(){
		cout << "Прямокутник." << endl;
	}
};

class Square : public Rectangle {
 public:
 	Square(int length) : Rectangle(length, length){}
	void ShowType(){
		cout << "Квадрат." << endl;
	}
};

int main (){
	Square s(5);

	return 0;
}
