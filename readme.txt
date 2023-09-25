// created by amal chaabi on 25/09/23
#pragma once

#include <iostream>
using namespace std;

class Point
{
private:
	double x{}, y{};
public:
	//void initialiser(double , double);
	void initialiser(Point);
	void initialiserXY(double dx, double dy);
	//void deplacer(double dx, double dy);
	//double distance(Point) const;
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	void afficher() const;
	Point();
	Point(double dx, double dy);
	void deplacer(double dx, double dy);
	double distance(Point P) const;
	~Point();
};

class Triangle {
private:
	Point cote[3];

public:
	
	void initialiser2(Point p[3]);
	double cote1();
	double cote2();
	double cote3();
	bool isocele();
	bool equilaterale();
	bool rectangle();
	void natureDeTriangle();
	double perimetre();
	void translate(double dx, double dy);
	void afficher2();

	Triangle();
	Triangle(Point point[3]);
	~Triangle();


};

#include <iostream>
#include <cmath>
#include "Triangle.h"
using namespace std;
Point::Point() :x(0), y(0)
{

}

Point::Point(double dx, double dy) :x(dx), y(dy)
{

}

Point::~Point()
{
	//cout << "Good bye" << endl;
}
void Point::initialiser(Point P)
{
	x = P.x;
	y = P.y;
}

void Point::initialiserXY(double dx,double dy)
{
	x = dx;
	y = dy;
}

void Point::setX(double abs)
{
	x= abs;
}

void Point::setY(double ord)
{
	y = ord;
}


double Point::getX()
{
	return x;
}

double Point::getY()
{
	return y;
}


void Point::afficher() const
{
	cout << "x=" << x << "\t" << "y=" << y << "\n";
}

void Point::deplacer(double dx, double dy)
{
	x += dx;
	y += dy;
}

double Point::distance(Point P) const
{
	cout <<"x2=" << P.x << "\t" <<"x1= " << x <<"\t"<< "y2=" << P.y << "\t" <<"y1=" << y << endl;
	return  sqrt(pow((P.y - y), 2) + pow((P.x - x), 2));
}

//************************Triangle***********************

Triangle::Triangle(Point point[3])
{
	for (int i = 0; i < 3; i++) {
		cote[i] = point[i];
	}
}

void Triangle::initialiser2(Point p[3]) {
	for (int i = 0; i < 3; i++)
		cote[i].initialiser(p[i]);
		//cote[i].initialiser(p[i].getX(), p[i].getY());
}

double Triangle::cote1() {
	return cote[0].distance(cote[1]);
}

double Triangle::cote2() {
	return cote[0].distance(cote[2]);
}

double Triangle::cote3() {
	return cote[2].distance(cote[2]);
}

bool Triangle::isocele()
{
	return (
		(cote1() == cote2())||
		(cote1() == cote3())||
		(cote2() == cote3())
		);
}

bool Triangle::equilaterale()
{
	return (
		(cote1() == cote2()) &&
		(cote1() == cote3()) &&
		(cote2() == cote3())
		);
}

bool Triangle::rectangle() {
	return(
		(pow(cote1(), 2) + pow(cote2(), 2) == pow(cote3(), 2)) ||
		pow(cote1(), 2) + pow(cote3(), 2) == pow(cote2(), 2) ||
		pow(cote2(), 2) + pow(cote3(), 2) == pow(cote1(), 2)

	);
}

void Triangle::natureDeTriangle() {
	cout << "Le triangle est : ";
	if (equilaterale()) {
		cout << "equilateral\n";
	}
	else if (isocele()) {
		cout << "isosceles ";
		if (rectangle()) cout << "et rectangle\n";
		else cout << "\n";
	}
	else if (rectangle()) {
		cout << "rectangle\n";
	}
	else cout << "quelconque\n";
}

double Triangle::perimetre()
{
	return (cote1() + cote2() + cote3());
}

void Triangle::translate(double dx,double dy) {
	for(int i=0;i<3;cote[i++].deplacer(dx,dy));
}

void Triangle::afficher2()
{
	cout << "cote1= " << cote1() << " cote2= " << cote2() << " cote 3= " << cote3() << endl;
}
Triangle::~Triangle()
{
	cout << "fin";
}
int main()
{
	Point p(4, 2);
	Point p1(0, 0);
	//cout << "x=" << p.getX() << "y=" << p.getY();
	//p.afficher();

	//cout << p.distance(p1)<<endl;
	//p.deplacer(2, 3);
    //p.afficher();

	Point tab[3];
	
	for (int i = 0; i < 3; i++)
		tab[i].initialiserXY(i * 2, i + 2);
	Triangle tr(tab);
	tr.afficher2();
	
}
