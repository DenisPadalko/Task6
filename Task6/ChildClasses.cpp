#include "ChildClasses.h"
#include <math.h>
#include <iostream>

Paralelogram::Paralelogram() 
{
	SetX(1.5);
	SetY(0.5);
}

Paralelogram::Paralelogram(const double** Vertices, const double X, const double Y) 
{
	SetX(X);
	SetY(Y);
}

Paralelogram::Paralelogram(const Paralelogram& AnotherParalelogram) 
{
	SetX(AnotherParalelogram.GetX());
	SetY(AnotherParalelogram.GetY());
}

Paralelogram::~Paralelogram() 
{
}

const double Paralelogram::CalculatePerimeter() 
{
}

const double Paralelogram::CalculateArea() 
{
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

Vector::Vector(const Vector& AnotherVector) : X(AnotherVector.X), Y(AnotherVector.Y), Z (AnotherVector.Z)
{}

Vector::Vector(Vector&& AnotherVector) : X(AnotherVector.X), Y(AnotherVector.Y), Z(AnotherVector.Z)
{
	AnotherVector.X = NULL;
	AnotherVector.Y = NULL;
	AnotherVector.Z = NULL;
}

const Vector& Vector::operator=(const Vector& AnotherVector) 
{
	X = AnotherVector.X;
	Y = AnotherVector.Y;
	Z = AnotherVector.Z;
}

const Vector& Vector::operator=(Vector&& AnotherVector)
{
	X = AnotherVector.X;
	Y = AnotherVector.Y;
	Z = AnotherVector.Z;
	AnotherVector.X = 0;
	AnotherVector.Y = 0;
	AnotherVector.Z = 0;
}

const Vector operator+(Vector Left, const Vector& Right)
{
	return Left += Right;
}

const Vector operator-(Vector Left, const Vector& Right)
{
	return Left -= Right;
}

const Vector& Vector::operator+=(const Vector& AnotherVector)
{
	X += AnotherVector.X;
	Y += AnotherVector.Y;
	Z += AnotherVector.Z;
	return *this;
}

const Vector& Vector::operator-=(const Vector& AnotherVector)
{
	X -= AnotherVector.X;
	Y -= AnotherVector.Y;
	Z -= AnotherVector.Z;
	return *this;
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
{
	SetX(0);
	SetY(0);
	SetZ(0);
}

Box::Box(const double NewX, const double NewY, const double NewZ, const Vector& NewMin, const Vector& NewMax)
{
	SetX(NewX);
	SetY(NewY);
	SetZ(NewZ);
	Min = NewMin;
	Max = NewMax;
}

Box::Box(const Box& AnotherBox) 
{
	SetX(AnotherBox.GetX());
	SetY(AnotherBox.GetY());
	SetZ(AnotherBox.GetZ());
	Min = AnotherBox.Min;
	Max = AnotherBox.Max;
}

Box::Box(Box&& AnotherBox)
{
	SetX(AnotherBox.GetX());
	SetY(AnotherBox.GetY());
	SetZ(AnotherBox.GetZ());
	Min = move(AnotherBox.Min);
	Max = move(AnotherBox.Max);

	AnotherBox.SetX(0);
	AnotherBox.SetY(0);
	AnotherBox.SetZ(0);
}

Box::~Box() 
{}

const double Box::CalculateVolume()
{
	return (Max.GetVectorCoordinateX() - Min.GetVectorCoordinateX()) *
		(Max.GetVectorCoordinateY() - Min.GetVectorCoordinateY()) *
		(Max.GetVectorCoordinateZ() - Min.GetVectorCoordinateZ());
}

const double Box::CalculateSurfaceArea()
{
	Vector Size = Max - Min;
	return 0.5 * (Size.GetVectorCoordinateX() * Size.GetVectorCoordinateY() + Size.GetVectorCoordinateX() * Size.GetVectorCoordinateZ() + 
		Size.GetVectorCoordinateY() * Size.GetVectorCoordinateZ());
}

Ball::Ball() : Radius(0)
{}

Ball::Ball(const double NewRadius, const double NewX, const double NewY, const double NewZ) : Radius(NewRadius)
{
	SetX(NewX);
	SetY(NewY);
	SetZ(NewZ);
}

Ball::Ball(const Ball& AnotherBall) : Radius(AnotherBall.Radius)
{
	SetX(AnotherBall.GetX());
	SetY(AnotherBall.GetY());
	SetZ(AnotherBall.GetZ());
}

Ball::Ball(Ball&& AnotherBall) : Radius(AnotherBall.Radius)
{
	SetX(AnotherBall.GetX());
	SetY(AnotherBall.GetY());
	SetZ(AnotherBall.GetZ()); 
	AnotherBall.SetX(0);
	AnotherBall.SetY(0);
	AnotherBall.SetZ(0);
	AnotherBall.Radius = 0;
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