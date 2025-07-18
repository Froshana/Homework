#include <iostream>
using namespace std;

// Завдання 1 //

class Rectangle {
 public:
	virtual ~Rectangle(){}

	virtual Rectangle* clone() const = 0;

	virtual void draw() const {
		cout << "Rectangle" << endl;
	}
};

class Square : public Rectangle {
 public:
	Square() = default;
	Square(const Square& other) = default;

	virtual Square* clone() const override {
		return new Square(*this);
	}
	void draw() const override {
		cout << "Square" << endl;
	}
};

void printCopy(const Rectangle* r){
	Rectangle* copy = r->clone();
	copy->draw();
	delete copy;
}

int main (){
	Square sq;
	printCopy(&sq);

	return 0;
}

// Завдання 2 //

void SomeFunction(Shape); // функція приймає параметр за значенням
Shape *pRect = new Rectangle; // *pRect об'єкт типу Rectangle але копіюється лише  базова частина, усі додаткові поля та методи Rectangle зникають у копії
SomeFunction(*pRect);


// Завдання 3 //

class Shape
{
public:
	Shape();
	virtual ~Shape();
	virtual Shape(const Shape&); // конструктор не може бути віртуальнимБ немає реалізації конструктора/деструктора
};
