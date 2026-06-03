 #include <iostream>
#include <math.h>
#include <fstream>
#include <random>
#include <cstdio>

using namespace std;

// Класс точки
class Point {
private:
    double x, y;

public:
    // Простой конструктор 
    Point(double x1 = 0, double y1 = 0) {
        x = x1;
        y = y1;
    }

    // Метод для задания координат
    void SetPosition(double x2, double y2) {
        x = x2;
        y = y2;
    }

    // Функции для получения координат 
    double GetPositionX() {
        return x;
    }

    double GetPositionY() {
        return y;
    }

    // Какой-то умный дядька сказал, что в классе должен быть хотя-бы номинальный деструктор 
    ~Point() {
         
    }
};

// Проверяем принадлежность и возвращаем true/false
bool ValidatePoint(Point A) {
    double x = A.GetPositionX() * A.GetPositionX();
    double y = A.GetPositionY() * A.GetPositionY();
    double result = x + y;
         
    if (fabs(3 - result) <= numeric_limits<double>::epsilon()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    setlocale(0, "ru");
    
    Point A;
    bool result;
    double x, y;
    
    double& refX{ x }, & refY{ y }; // для избежания дублирования данных
    Point& refA{ A };
    cin >> refX;
	cin >> refY;
     
        A.SetPosition(refX, refY);
        result = ValidatePoint(refA);
        
        if (result == true) {
            cout << "\n пренадлежит";
        }
        else {
            cout << "\n не принадлежит";
        }
        return 0;
    }
 