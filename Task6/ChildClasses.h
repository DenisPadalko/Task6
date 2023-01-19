#pragma once
#include "AbstractClasses.h"

class Point2D 
{
private:
	double X, Y;
public:
	Point2D();
	Point2D(const double NewX, const double NewY);
	Point2D(const Point2D& AnotherPoint);
	Point2D(Point2D&& AnotherPoint);

	const Point2D operator=(const Point2D& AnotherPoint);
	const Point2D operator=(Point2D&& AnotherPoint);
	friend const Point2D operator+(Point2D Left, const Point2D& Right);
	friend const Point2D operator-(Point2D Left, const Point2D& Right);
	const Point2D& operator+=(const Point2D& AnotherPoint);
	const Point2D& operator-=(const Point2D& AnotherPoint);

	const double GetPointCoordinateX();
	void SetPointCoordinateX(const double NewX);
	const double GetPointCoordinateY();
	void SetPointCoordinateY(const double NewY);
};

class Paralelogram : public Body2D
{
private:
	Point2D* A;
	Point2D* B;
public:
	Paralelogram();
	Paralelogram(const double X, const double Y, const double XOfPointA, const double YOfPointA, const double XOfPointB, const double YOfPointB);
	Paralelogram(const Paralelogram& AnotherParalelogram);
	Paralelogram(Paralelogram&& AnotherParalelogram);
	~Paralelogram();

	const double FindFirstSide();
	const double FindSecondSide();
	const double CalculatePerimeter();
	const double CalculateArea();
};

class Ellipse : public Body2D 
{
private:
	double FirstRadius;
	double SecondRadius;
public:
	Ellipse();
	Ellipse(const double NewX, const double NewY, const double NewFirstRadius, const double NewSecondRadius);
	Ellipse(const Ellipse& AnotherEllipse);
	Ellipse(Ellipse&& AnotherEllipse);
	~Ellipse();

	const double CalculatePerimeter();
	const double CalculateArea();
};

class Point
{
private:
	double X;
	double Y;
	double Z;
public:
	Point();
	Point(const double X, const double Y, const double Z);
	Point(const Point& AnotherPoint);
	Point(Point&& AnotherPoint);

	const Point& operator=(const Point& AnotherPoint);
	const Point& operator=(Point&& AnotherPoint);
	friend const Point operator+(Point Left, const Point& Right);
	friend const Point operator-(Point Left, const Point& Right);
	const Point& operator+=(const Point& AnotherPoint);
	const Point& operator-=(const Point& AnotherPoint);

	double GetPointCoordinateX() const;
	void SetPointCoordinateX(const double NewX);
	double GetPointCoordinateY() const;
	void SetPointCoordinateY(const double NewY);
	double GetPointCoordinateZ() const;
	void SetPointCoordinateZ(const double NewZ);
	void SetAllCoordinates(const double NewX, const double NewY, const double NewZ);
};

class Box : public Body3D 
{
private:
	Point Min;
	Point Max;
public:
	Box();
	Box(const double NewX, const double NewY, const double NewZ, const Point& NewMin, const Point& NewMax);
	Box(const Box& AnotherBox);
	Box(Box&& AnotherBox);
	~Box();

	const double CalculateVolume();
	const double CalculateSurfaceArea();
};

class Ball : public Body3D 
{
private:
	double Radius;
public:
	Ball();
	Ball(const double NewRadius, const double X, const double Y, const double Z);
	Ball(const Ball& AnotherBall);
	Ball(Ball&& AnotherBall);
	~Ball();

	const double CalculateVolume();
	const double CalculateSurfaceArea();
};