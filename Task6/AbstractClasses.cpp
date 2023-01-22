#include "AbstractClasses.h"
#include <iostream>

Point::Point() : X(0), Y(0), Z(0)
{}

Point::Point(const double NewX, const double NewY, const double NewZ) : X(NewX), Y(NewY), Z(NewZ)
{}

Point::Point(const Point& AnotherPoint) : X(AnotherPoint.X), Y(AnotherPoint.Y), Z(AnotherPoint.Z)
{}

Point::Point(Point&& AnotherPoint) : X(AnotherPoint.X), Y(AnotherPoint.Y), Z(AnotherPoint.Z)
{
	AnotherPoint.X = 0;
	AnotherPoint.Y = 0;
	AnotherPoint.Z = 0;
}

const Point& Point::operator=(const Point& AnotherPoint)
{
	X = AnotherPoint.X;
	Y = AnotherPoint.Y;
	Z = AnotherPoint.Z;
	return *this;
}

const Point& Point::operator=(Point&& AnotherPoint)
{
	X = AnotherPoint.X;
	Y = AnotherPoint.Y;
	Z = AnotherPoint.Z;
	AnotherPoint.X = 0;
	AnotherPoint.Y = 0;
	AnotherPoint.Z = 0;
	return *this;
}

const Point operator+(Point Left, const Point& Right)
{
	return Left += Right;
}

const Point operator-(Point Left, const Point& Right)
{
	return Left -= Right;
}

const Point& Point::operator+=(const Point& AnotherPoint)
{
	X += AnotherPoint.X;
	Y += AnotherPoint.Y;
	Z += AnotherPoint.Z;
	return *this;
}

const Point& Point::operator-=(const Point& AnotherPoint)
{
	X -= AnotherPoint.X;
	Y -= AnotherPoint.Y;
	Z -= AnotherPoint.Z;
	return *this;
}

double Point::GetPointCoordinateX() const
{
	return X;
}

void Point::SetPointCoordinateX(const double NewX)
{
	X = NewX;
}

double Point::GetPointCoordinateY() const
{
	return Y;
}

void Point::SetPointCoordinateY(const double NewY)
{
	Y = NewY;
}

double Point::GetPointCoordinateZ() const
{
	return Z;
}

void Point::SetPointCoordinateZ(const double NewZ)
{
	Z = NewZ;
}

void Point::SetAllCoordinates(const double NewX, const double NewY, const double NewZ)
{
	X = NewX;
	Y = NewY;
	Z = NewZ;
}


Body2D::Body2D() : X(0), Y(0)
{}

Body2D::Body2D(const double NewX, const double NewY) : X(NewX), Y(NewY)
{}

Body2D::Body2D(const Body2D& AnotherBody) : X(AnotherBody.X), Y(AnotherBody.Y)
{}

Body2D::Body2D(Body2D&& AnotherBody) : X(AnotherBody.X), Y(AnotherBody.Y)
{
	AnotherBody.X = 0;
	AnotherBody.Y = 0;
}

const double Body2D::GetX() const
{
	return X;
}

void Body2D::SetX(const double NewX)
{
	X = NewX;
}

const double Body2D::GetY() const 
{
	return Y;
}

void Body2D::SetY(const double NewY)
{
	Y = NewY;
}

Body3D::Body3D() : X(0), Y(0), Z(0)
{}

Body3D::Body3D(const double NewX, const double NewY, const double NewZ) : X(NewX), Y(NewY), Z(NewZ)
{}

Body3D::Body3D(const Body3D& AnotherBody) : X(AnotherBody.X), Y(AnotherBody.Y), Z(AnotherBody.Z)
{}

Body3D::Body3D(Body3D&& AnotherBody) : X(AnotherBody.X), Y(AnotherBody.Y), Z(AnotherBody.Z)
{
	AnotherBody.X = 0;
	AnotherBody.Y = 0;
	AnotherBody.Z = 0;
}

const double Body3D::GetX() const 
{
	return X;
}

void Body3D::SetX(const double NewX) 
{
	X = NewX;
}

const double Body3D::GetY() const 
{
	return Y;
}

void Body3D::SetY(const double NewY) 
{
	Y = NewY;
}

const double Body3D::GetZ() const
{
	return Z;
}

void Body3D::SetZ(const double NewZ)
{
	Z = NewZ;
}