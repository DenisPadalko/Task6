#include "ChildClasses.h"
#include <math.h>
#include <iostream>

Paralelogram::Paralelogram() 
{
	SetX(0);
	SetY(0);
}

Paralelogram::Paralelogram(const double X, const double Y, const Point& PointA, const Point& PointB) : A(PointA), B(PointB)
{
	SetX(X);
	SetY(Y);
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

const double Paralelogram::FindFirstSide() const
{
	return sqrt(pow(A.GetPointCoordinateX() - B.GetPointCoordinateX(), 2) + pow(A.GetPointCoordinateY() - B.GetPointCoordinateY(), 2));
}

const double Paralelogram::FindSecondSide() const
{
	double X = 2 * this->GetX() - A.GetPointCoordinateX();
	double Y = 2 * this->GetY() - A.GetPointCoordinateY();
	return sqrt(pow(X - B.GetPointCoordinateX(), 2) + pow(Y - B.GetPointCoordinateY(), 2));
}

const double Paralelogram::CalculatePerimeter() const
{
	return (FindFirstSide() + FindSecondSide()) * 2;
}

const double Paralelogram::CalculateArea() const
{
	double Diagonal = sqrt(pow(this->GetX() - A.GetPointCoordinateX(), 2) + pow(this->GetY() - A.GetPointCoordinateY(), 2));
	double SideA = FindFirstSide();
	double SideB = FindSecondSide();
	double Cos = (pow(SideA, 2) + pow(SideB, 2) - pow(Diagonal, 2)) / (2 * SideA * SideB);
	return SideA * SideB * sqrt(1 - pow(Cos, 2));
}

const Point& Paralelogram::GetCenter() const
{
	Point* P = new Point(this->GetX(), this->GetY(), 0);
	return *P;
}

const vector<Point*> Paralelogram::GetVertices() const
{
	vector<Point*> vec;
	Point* a = new Point(A.GetPointCoordinateX(), A.GetPointCoordinateY(), 0);
	vec.push_back(a);
	Point* b = new Point(B.GetPointCoordinateX(), B.GetPointCoordinateY(), 0);
	vec.push_back(b);
	double X3 = 2 * this->GetX() - A.GetPointCoordinateX();
	double Y3 = 2 * this->GetY() - A.GetPointCoordinateY();
	double X4 = 2 * this->GetX() - B.GetPointCoordinateX();
	double Y4 = 2 * this->GetX() - B.GetPointCoordinateY();
	Point* c = new Point(X3, Y3, 0);
	vec.push_back(c);
	Point* d = new Point(X4, Y4, 0);
	vec.push_back(d);
	return vec;
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

const double Ellipse::CalculatePerimeter() const
{
	cout << "Perimeter cannot be calculated for ellipse" << endl;
	return 0;
}

const double Ellipse::CalculateArea() const
{
	return 3.14 * FirstRadius * SecondRadius;
}

const double Ellipse::GetFirstRadius() const 
{
	return FirstRadius;
}

const double Ellipse::GetSecondRadius() const 
{
	return SecondRadius;
}

const Point& Ellipse::GetCenter() const
{
	Point* P = new Point(this->GetX(), this->GetY(), 0);
	return *P;
}

const vector<Point*> Ellipse::GetVertices() const
{
	cout << "Cannot get vertices for ellipse" << endl; 
	vector<Point*> vec;
	Point* a = new Point();
	vec.push_back(a);
	return vec;
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

const double Box::CalculateVolume() const
{
	return (Max.GetPointCoordinateX() - Min.GetPointCoordinateX()) *
		(Max.GetPointCoordinateY() - Min.GetPointCoordinateY()) *
		(Max.GetPointCoordinateZ() - Min.GetPointCoordinateZ());
}

const double Box::CalculateSurfaceArea() const
{
	Point Size = Max - Min;
	return 0.5 * (Size.GetPointCoordinateX() * Size.GetPointCoordinateY() + Size.GetPointCoordinateX() * Size.GetPointCoordinateZ() + 
		Size.GetPointCoordinateY() * Size.GetPointCoordinateZ());
}

const Point& Box::GetCenter() const
{
	Point* P = new Point(this->GetX(), this->GetY(), this->GetZ());
	return *P;
}

const vector<Point*> Box::GetVertices() const
{
	vector<Point*> vec;
	Point* P1 = new Point(Min.GetPointCoordinateX(), Min.GetPointCoordinateY(), Min.GetPointCoordinateZ());
	vec.push_back(P1);
	Point* P2 = new Point(Min.GetPointCoordinateX(), Max.GetPointCoordinateY(), Min.GetPointCoordinateZ());
	vec.push_back(P2);
	Point* P3 = new Point(Max.GetPointCoordinateX(), Max.GetPointCoordinateY(), Min.GetPointCoordinateZ());
	vec.push_back(P3);
	Point* P4 = new Point(Max.GetPointCoordinateX(), Min.GetPointCoordinateY(), Min.GetPointCoordinateZ());
	vec.push_back(P4);
	Point* P5 = new Point(Max.GetPointCoordinateX(), Min.GetPointCoordinateY(), Max.GetPointCoordinateZ());
	vec.push_back(P5);
	Point* P6 = new Point(Min.GetPointCoordinateX(), Min.GetPointCoordinateY(), Max.GetPointCoordinateZ());
	vec.push_back(P6);
	Point* P7 = new Point(Min.GetPointCoordinateX(), Max.GetPointCoordinateY(), Max.GetPointCoordinateZ());
	vec.push_back(P7);
	Point* P8 = new Point(Max.GetPointCoordinateX(), Max.GetPointCoordinateY(), Max.GetPointCoordinateZ());
	vec.push_back(P8);
	return vec;
}

Ball::Ball() : Radius(1)
{
	SetX(0);
	SetY(0);
	SetZ(0);
}

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

const double Ball::CalculateVolume() const
{
	return (4 * 3.14 * pow(Radius, 3)) / 3;
}

const double Ball::CalculateSurfaceArea() const
{
	return 4 * 3.14 * pow(Radius, 2);
}

const Point& Ball::GetCenter() const
{
	Point* P = new Point(this->GetX(), this->GetY(), this->GetZ());
	return *P;
}

const vector<Point*> Ball::GetVertices() const
{
	cout << "Cannot get vertices for ball" << endl;
	vector<Point*> vec;
	Point* a = new Point();
	vec.push_back(a);
	return vec;
}