#pragma once

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

	virtual const double CalculatePerimeter() = 0;
	virtual const double CalculateArea() = 0;
};

class Body3D : public Body2D 
{
private:
	double Z;
public:
	Body3D();
	Body3D(const double NewX, const double NewY, const double NewZ);
	Body3D(const Body3D& NewBody);
	Body3D(Body3D&& NewBody);

	const double GetZ() const;
	void SetZ(const double NewZ);

	virtual const double CalculateVolume() = 0;
	virtual const double CalculateSurfaceArea() = 0;
};