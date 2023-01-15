#pragma once
#include "AbstractClasses.h"

using namespace std;
class Paralelogram : public Body2D
{
private:
public:
	Paralelogram();
	Paralelogram(const double** Vertices, const double X, const double Y);
	Paralelogram(const Paralelogram& AnotherParalelogram);
	~Paralelogram();

	const double CalculatePerimeter();
	const double CalculateArea();
};

class Ellipse : public Body2D 
{
public:
	Ellipse();
	Ellipse(const double NewX, const double NewY);
	Ellipse(const Ellipse& AnotherEllipse);
	~Ellipse();
};

class Vector
{
private:
	double X;
	double Y;
	double Z;
public:
	Vector();
	Vector(const double X, const double Y, const double Z);
	Vector(const Vector& AnotherVector);
	Vector(Vector&& AnotherVector);

	const Vector& operator=(const Vector& AnotherVector);
	const Vector& operator=(Vector&& AnotherVector);
	friend const Vector operator+(Vector Left, const Vector& Right);
	friend const Vector operator-(Vector Left, const Vector& Right);
	const Vector& operator+=(const Vector& AnotherVector);
	const Vector& operator-=(const Vector& AnotherVector);

	double GetVectorCoordinateX() const;
	void SetVectorCoordinateX(const double NewX);
	double GetVectorCoordinateY() const;
	void SetVectorCoordinateY(const double NewY);
	double GetVectorCoordinateZ() const;
	void SetVectorCoordinateZ(const double NewZ);
	void SetAllCoordinates(const double NewX, const double NewY, const double NewZ);
};

class Box : public Body3D 
{
private:
	Vector Min;
	Vector Max;
public:
	Box();
	Box(const double NewX, const double NewY, const double NewZ, const Vector& NewMin, const Vector& NewMax);
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