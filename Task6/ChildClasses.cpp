#include "ChildClasses.h"
#include <math.h>

Paralelogram::Paralelogram() 
{
	CoordinatesOfVertices = new double* [4];
	for (int i = 0; i < 4; ++i)
	{
		CoordinatesOfVertices[i] = new double[2];
	}
	CoordinatesOfVertices[0][0] = 0;
	CoordinatesOfVertices[0][1] = 0;
	CoordinatesOfVertices[1][0] = 1;
	CoordinatesOfVertices[1][1] = 1;
	CoordinatesOfVertices[2][0] = 2;
	CoordinatesOfVertices[2][1] = 1;
	CoordinatesOfVertices[3][0] = 1;
	CoordinatesOfVertices[3][1] = 0;
	SetX(1.5);
	SetY(0.5);
}

Paralelogram::Paralelogram(const double** Vertices, const double X, const double Y) 
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			CoordinatesOfVertices[i][j] = Vertices[i][j];
		}
	}
	SetX(X);
	SetY(Y);
}

Paralelogram::Paralelogram(const Paralelogram& AnotherParalelogram) 
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			CoordinatesOfVertices[i][j] = AnotherParalelogram.CoordinatesOfVertices[i][j];
		}
	}
	SetX(AnotherParalelogram.GetX());
	SetY(AnotherParalelogram.GetY());
}

Paralelogram::~Paralelogram() 
{
	for (int i = 0; i < 4; ++i)
	{
		delete[] CoordinatesOfVertices[i];
	}
	delete[] CoordinatesOfVertices;
}

const double Paralelogram::CalculatePerimeter() 
{
	return (CalculateLengthOfTheSide(CoordinatesOfVertices[0][0], CoordinatesOfVertices[0][1], CoordinatesOfVertices[1][0], CoordinatesOfVertices[1][1]) +
		CalculateLengthOfTheSide(CoordinatesOfVertices[1][0], CoordinatesOfVertices[1][1], CoordinatesOfVertices[2][0], CoordinatesOfVertices[2][1])) * 2;
}

const double Paralelogram::CalculateArea() 
{
	return CalculateLengthOfTheSide(CoordinatesOfVertices[0][0], CoordinatesOfVertices[0][1], CoordinatesOfVertices[1][0], CoordinatesOfVertices[1][1]) *
		CalculateLengthOfTheSide(CoordinatesOfVertices[1][0], CoordinatesOfVertices[1][1], CoordinatesOfVertices[2][0], CoordinatesOfVertices[2][1]);
}

const double Paralelogram::CalculateLengthOfTheSide(const double X1, const double Y1, const double X2, const double Y2) 
{
	return sqrt(pow(X2-X1,2) + pow(Y2-Y1, 2));
}

Ellipse::Ellipse() 
{}

Ellipse::Ellipse(const double NewX, const double NewY) 
{
	SetX(NewX);
	SetY(NewY);
}

Ellipse::Ellipse(const Ellipse& AnotherEllipse)
{
	SetX(AnotherEllipse.GetX());
	SetY(AnotherEllipse.GetY());
}

Ellipse::~Ellipse() 
{}

Vector::Vector() : X(0), Y(0), Z(0)
{}

Vector::Vector(const double NewX, const double NewY, const double NewZ) : X(NewX), Y(NewY), Z(NewZ)
{}

Vector::Vector(const Vector& AnotherVector) 
{
	X = AnotherVector.X;
	Y = AnotherVector.Y;
	Z = AnotherVector.Z;
}

Vector::Vector(Vector&& AnotherVector) 
{
	X = AnotherVector.X;
	Y = AnotherVector.Y;
	Z = AnotherVector.Z;
	AnotherVector.X = NULL;
	AnotherVector.Y = NULL;
	AnotherVector.Z = NULL;
}

double Vector::GetVectorCoordinateX() const 
{
	return X;
}

void Vector::SetVectorCoordinateX(const double NewX) 
{
	X = NewX;
}

double Vector::GetVectorCoordinateY() const 
{
	return Y;
}

void Vector::SetVectorCoordinateY(const double NewY)
{
	Y = NewY;
}

double Vector::GetVectorCoordinateZ() const 
{
	return Z;
}

void Vector::SetVectorCoordinateZ(const double NewZ) 
{
	Z = NewZ;
}

void Vector::SetAllCoordinates(const double NewX, const double NewY, const double NewZ) 
{
	X = NewX;
	Y = NewY;
	Z = NewZ;
}

Box::Box() 
{}

Box::Box(const double NewX, const double NewY, const double NewZ) 
{
	SetX(NewX);
	SetY(NewY);
	SetZ(NewZ);
}

Box::Box(const Box& AnotherBox) 
{
	SetX(AnotherBox.GetX());
	SetY(AnotherBox.GetY());
	SetZ(AnotherBox.GetZ());
}

Box::~Box() 
{}

Ball::Ball() 
{}

const double Box::CalculateVolume() 
{}

const double Box::CalculateSurfaceArea()
{}

Ball::Ball(const double NewRadius, const double NewX, const double NewY, const double NewZ)
{
	Radius = NewRadius;
	SetX(NewX);
	SetY(NewY);
	SetZ(NewZ);
}

Ball::Ball(const Ball& AnotherBall)
{
	Radius = AnotherBall.Radius;
	SetX(AnotherBall.GetX());
	SetY(AnotherBall.GetY());
	SetZ(AnotherBall.GetZ());
}

Ball::~Ball() 
{}

const double Ball::CalculateVolume()
{
	return (4 * 3.14 * pow(Radius, 3)) / 3;
}

const double Ball::CalculateSurfaceArea() 
{
	return 4 * 3.14 * pow(Radius, 2);
}