#pragma once
#include <vector>

using namespace std;
struct Point
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

class Body2D 
{
private:
	double X, Y; // coordinates of the center
public:
	Body2D();
	Body2D(const double NewX, const double NewY);
	Body2D(const Body2D& NewBody);
	Body2D(Body2D&& NewBody);

	const double GetX() const;
	void SetX(const double NewX);
	const double GetY() const;
	void SetY(const double NewY);

	virtual const double CalculatePerimeter() const = 0;
	virtual const double CalculateArea() const = 0;
	virtual const Point& GetCenter() const = 0;
	virtual const vector<Point*> GetVertices() const = 0;
};

class Body3D
{
private:
	double X, Y, Z; // Z coordinate of the center
public:
	Body3D();
	Body3D(const double NewX, const double NewY, const double NewZ);
	Body3D(const Body3D& NewBody);
	Body3D(Body3D&& NewBody);

	const double GetX() const;
	void SetX(const double NewX);
	const double GetY() const;
	void SetY(const double NewY); 
	const double GetZ() const;
	void SetZ(const double NewZ);

	virtual const double CalculateVolume() const = 0;
	virtual const double CalculateSurfaceArea() const = 0;
	virtual const Point& GetCenter() const = 0;
	virtual const vector<Point*> GetVertices() const = 0;
};