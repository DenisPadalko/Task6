#include "ChildClasses.h"
#include <math.h>
#include <iostream>

Point2D::Point2D() : X(0), Y(0)
{}

Point2D::Point2D(const double NewX, const double NewY) : X(NewX), Y(NewY)
{}

Point2D::Point2D(const Point2D& AnotherPoint) : X(AnotherPoint.X), Y(AnotherPoint.Y)
{}

Point2D::Point2D(Point2D&& AnotherPoint) : X(AnotherPoint.X), Y(AnotherPoint.Y)
{
	AnotherPoint.X = 0;
	AnotherPoint.Y = 0;
}

const Point2D Point2D::operator=(const Point2D& AnotherPoint) 
{
	X = AnotherPoint.X;
	Y = AnotherPoint.Y;
}

const Point2D Point2D::operator=(Point2D&& AnotherPoint) 
{
	X = AnotherPoint.X;
	Y = AnotherPoint.Y;
	AnotherPoint.X = 0;
	AnotherPoint.Y = 0;
}

const Point2D operator+(Point2D Left, const Point2D& Right) 
{
	return Left += Right;
}

const Point2D operator-(Point2D Left, const Point2D& Right) 
{
	return Left -= Right;
}

const Point2D& Point2D::operator+=(const Point2D& AnotherPoint) 
{
	X += AnotherPoint.X;
	Y += AnotherPoint.Y;
	return *this;
}

const Point2D& Point2D::operator-=(const Point2D& AnotherPoint) 
{
	X -= AnotherPoint.X;
	Y -= AnotherPoint.Y;
	return *this;
}

const double Point2D::GetPointCoordinateX() 
{
	return X;
}

void Point2D::SetPointCoordinateX(const double NewX)
{
	X = NewX;
}

const double Point2D::GetPointCoordinateY() 
{
	return Y;
}

void Point2D::SetPointCoordinateY(const double NewY) 
{
	Y = NewY;
}

Paralelogram::Paralelogram() 
{
	SetX(1);
	SetY(1);
	A = new Point2D(-2, 1);
	B = new Point2D(0, 4);
}

Paralelogram::Paralelogram(const double X, const double Y, const double XOfPointA, const double YOfPointA, const double XOfPointB, const double YOfPointB) 
{
	SetX(X);
	SetY(Y);
	A = new Point2D(XOfPointA, YOfPointA);
	B = new Point2D(XOfPointB, YOfPointB);
}

Paralelogram::Paralelogram(const Paralelogram& AnotherParalelogram) : A(AnotherParalelogram.A), B(AnotherParalelogram.B)
{
	SetX(AnotherParalelogram.GetX());
	SetY(AnotherParalelogram.GetY());
}

Paralelogram::Paralelogram(Paralelogram&& AnotherParalelogram) 
{
	SetX(AnotherParalelogram.GetX());
	SetY(AnotherParalelogram.GetY());
	AnotherParalelogram.SetX(0);
	AnotherParalelogram.SetY(0);
	A = move(AnotherParalelogram.A);
	B = move(AnotherParalelogram.B);
}

Paralelogram::~Paralelogram() 
{
}

const double Paralelogram::FindFirstSide() 
{
	return sqrt(pow(A->GetPointCoordinateX() - B->GetPointCoordinateX(), 2) + pow(A->GetPointCoordinateY() - B->GetPointCoordinateY(), 2));
}

const double Paralelogram::FindSecondSide() 
{
	double X = 2 * this->GetX() - A->GetPointCoordinateX();
	double Y = 2 * this->GetY() - A->GetPointCoordinateY();
	return sqrt(pow(X - B->GetPointCoordinateX(), 2) + pow(Y - B->GetPointCoordinateY(), 2));
}

const double Paralelogram::CalculatePerimeter() 
{
	return (FindFirstSide() + FindSecondSide()) * 2;
}

const double Paralelogram::CalculateArea() 
{
	double Diagonal = sqrt(pow(this->GetX() - A->GetPointCoordinateX(), 2) + pow(this->GetY() - A->GetPointCoordinateY(), 2));
	double SideA = FindFirstSide();
	double SideB = FindSecondSide();
	double Cos = (pow(SideA, 2) + pow(SideB, 2) - pow(Diagonal, 2)) / (2 * SideA * SideB);
	return SideA * SideB * sqrt(1 - pow(Cos, 2));
}

Ellipse::Ellipse() : FirstRadius(6), SecondRadius(4)
{
	SetX(0);
	SetY(0);
}

Ellipse::Ellipse(const double NewX, const double NewY, const double NewFirstRadius, const double NewSecondRadius) : FirstRadius(NewFirstRadius), SecondRadius(NewSecondRadius)
{
	SetX(NewX);
	SetY(NewY);
}

Ellipse::Ellipse(const Ellipse& AnotherEllipse) : FirstRadius(AnotherEllipse.FirstRadius), SecondRadius(AnotherEllipse.SecondRadius)
{
	SetX(AnotherEllipse.GetX());
	SetY(AnotherEllipse.GetY());
}

Ellipse::Ellipse(Ellipse&& AnotherEllipse) : FirstRadius(AnotherEllipse.FirstRadius), SecondRadius(AnotherEllipse.SecondRadius)
{
	SetX(AnotherEllipse.GetX());
	SetY(AnotherEllipse.GetY());
	AnotherEllipse.FirstRadius = 0;
	AnotherEllipse.SecondRadius = 0;
}

Ellipse::~Ellipse() 
{}

const double Ellipse::CalculatePerimeter() 
{
	cout << "Perimeter cannot be calculated for ellipse" << endl;
	return 0;
}

const double Ellipse::CalculateArea() 
{
	return 3.14 * FirstRadius * SecondRadius;
}

Point::Point() : X(0), Y(0), Z(0)
{}

Point::Point(const double NewX, const double NewY, const double NewZ) : X(NewX), Y(NewY), Z(NewZ)
{}

Point::Point(const Point& AnotherPoint) : X(AnotherPoint.X), Y(AnotherPoint.Y), Z (AnotherPoint.Z)
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
}

const Point& Point::operator=(Point&& AnotherPoint)
{
	X = AnotherPoint.X;
	Y = AnotherPoint.Y;
	Z = AnotherPoint.Z;
	AnotherPoint.X = 0;
	AnotherPoint.Y = 0;
	AnotherPoint.Z = 0;
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

const Point operator+(Point Left, const Point& Right)
{
	return Left += Right;
}

const Point operator-(Point Left, const Point& Right)
{
	return Left -= Right;
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

Box::Box() 
{
	SetX(0);
	SetY(0);
	SetZ(0);
}

Box::Box(const double NewX, const double NewY, const double NewZ, const Point& NewMin, const Point& NewMax) : Min(NewMin), Max(NewMax)
{
	SetX(NewX);
	SetY(NewY);
	SetZ(NewZ);
}

Box::Box(const Box& AnotherBox) : Min(AnotherBox.Min), Max(AnotherBox.Max)
{
	SetX(AnotherBox.GetX());
	SetY(AnotherBox.GetY());
	SetZ(AnotherBox.GetZ());
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
	return (Max.GetPointCoordinateX() - Min.GetPointCoordinateX()) *
		(Max.GetPointCoordinateY() - Min.GetPointCoordinateY()) *
		(Max.GetPointCoordinateZ() - Min.GetPointCoordinateZ());
}

const double Box::CalculateSurfaceArea()
{
	Point Size = Max - Min;
	return 0.5 * (Size.GetPointCoordinateX() * Size.GetPointCoordinateY() + Size.GetPointCoordinateX() * Size.GetPointCoordinateZ() + 
		Size.GetPointCoordinateY() * Size.GetPointCoordinateZ());
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