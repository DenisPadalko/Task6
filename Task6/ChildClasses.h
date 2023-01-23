#pragma once
#include "AbstractClasses.h"

class Paralelogram : public Body2D
{
private:
	Point A;
	Point B;
public:
	Paralelogram();
	Paralelogram(const double X, const double Y, const Point& PointA, const Point& PointB);
	Paralelogram(const Paralelogram& AnotherParalelogram);
	Paralelogram(Paralelogram&& AnotherParalelogram);
	~Paralelogram();

	const double FindFirstSide() const;
	const double FindSecondSide() const;
	const double CalculatePerimeter() const;
	const double CalculateArea() const;
	const Point& GetCenter() const;
	const vector<Point*> GetVertices() const;
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

	const double CalculatePerimeter() const;
	const double CalculateArea() const;
	const double GetFirstRadius() const;
	const double GetSecondRadius() const;
	const Point& GetCenter() const;
	const vector<Point*> GetVertices() const;
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

	const double CalculateVolume() const;
	const double CalculateSurfaceArea() const;
	const Point& GetCenter() const;
	const vector<Point*> GetVertices() const;
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

	const double CalculateVolume() const;
	const double CalculateSurfaceArea() const;
	const Point& GetCenter() const;
	const vector<Point*> GetVertices() const;
};