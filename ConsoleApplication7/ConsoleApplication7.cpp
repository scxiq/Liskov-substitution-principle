#include <iostream>

// Базовий клас, що визначає інтерфейс
class Shape {
public:
    virtual double area() const = 0;
};

// Клас прямокутника, який реалізує інтерфейс базового класу
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

// Клас квадрата, також реалізує інтерфейс базового класу
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() const override {
        return side * side;
    }
};

// Функція, яка використовує об'єкти базового класу
void printArea(const Shape& shape) {
    std::cout << "Area: " << shape.area() << "\n";
}

int main() {
    // Використання принципу підстановки Лісков
    Rectangle rectangle(5.0, 3.0);
    Square square(4.0);

    // Об'єкти похідних класів можуть бути передані в функцію, яка очікує об'єкт базового класу
    printArea(rectangle);
    printArea(square);

    return 0;
}
