#pragma once
#include "AbstractClasses.h"

class Paralelogram : public Body2D
{
private:
	double** CoordinatesOfVertices;
public:
	Paralelogram();
	Paralelogram(const double** Vertices, const double X, const double Y);
	Paralelogram(const Paralelogram& AnotherParalelogram);
	~Paralelogram();

	const double CalculatePerimeter();
	const double CalculateArea();
	const double CalculateLengthOfTheSide(const double X1, const double Y1, const double X2, const double Y2);
};

class Ellipse : public Body2D 
{
public:
	Ellipse();
	Ellipse(const double NewX, const double NewY);
	Ellipse(const Ellipse& AnotherEllipse);
	~Ellipse();
};

class Box : public Body3D 
{
public:
	Box();
	Box(const double NewX, const double NewY, const double NewZ);
	Box(const Box& AnotherBox);
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
	~Ball();

	const double CalculateVolume();
	const double CalculateSurfaceArea();
};