 
/*Задача:
Определить принадлежность точки А к функции X^2+Y^2=1 при условии что координаты точки A вводятся с клавиатуры */


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
		//Простой конструктор 
		Point(double x1 = 0, double y1 = 0) {
			x = x1;
			y = y1;
		}
		//Метод для задания координат
		void SetPosition(double x2, double y2) {
			x = x2;
			y = y2;
		}
		//Функции для получения координат 
		double GetPositionX() {
			return x;
		}
		double GetPositionY() {
			return y;
		}
		//Какой-то умный дядька сказал, что в классе должен быть хотя-бы номинальный деструктор 
		~Point() {
			 
		}
}; // проверяем принадлежность и возвращаем true/false
bool ValidatePoint(Point A) {
	double x = A.GetPositionX() * A.GetPositionX();
	double y = A.GetPositionY() * A.GetPositionY();
	double result = x + y ;
		 
	if (fabs(3-result) <= numeric_limits<double>::epsilon()){
		return true;
	}
	else {
		return false;
	}
 }
int main()
{
	setlocale(0, "ru");
	Point A;
	bool result;
	double x, y;
	int ids;
	string skipx, skipy;
	double& refX{ x }, & refY{ y }; // для избежания дублированния данных
	Point& refA{ A };
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> distrib(0.0000000000000001, 2.9999999999999999);
	while (true) {
		fstream file("number_ebat7.txt");
		FILE* file2 = fopen("data.txt", "w");
		int written;
		while (true) {
			x = distrib(gen);
			y = 3 - x;
			x = sqrt(x);
			y = sqrt(y);
			A.SetPosition(refX, refY);
			result = ValidatePoint(refA);
			if (result == true) {
				//fprintf(file2, "%.17g\t", x, "%.17g\t", y, "\n");
				printf("%.15g\t", x, "%.15g\t", y, "\n");
			}


		}

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
}
/* Функция в условиях описывает единичную математическую окружнось, смысл которой в работе с иррациональными значениями. Максимум который
может позволить вместить в себя переменная типа double, это 16 знаков после запятой. От этого следует что чтобы получать корректный результат -
нужно вводить координаты точки с точностью до 16 знаков после запятой */  
 
