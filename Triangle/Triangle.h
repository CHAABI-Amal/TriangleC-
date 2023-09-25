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
