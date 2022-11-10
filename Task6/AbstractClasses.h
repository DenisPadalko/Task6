#pragma once

class Body2D 
{
private:
	double X, Y; // coordinates of the center
public:
	const double GetX() const
	{
		return X;
	}
	void SetX(const double NewX)
	{
		X = NewX;
	}
	const double GetY() const
	{
		return Y;
	}
	void SetY(const double NewY) 
	{
		Y = NewY;
	}

	virtual const double CalculatePerimeter() = 0;
	virtual const double CalculateArea() = 0;
};

class Body3D : public Body2D 
{
private:
	double Z;
public:
	const double GetZ() const 
	{
		return Z;
	}
	void SetZ(const double NewZ)
	{
		Z = NewZ;
	}
	virtual const double CalculateVolume() = 0;
	virtual const double CalculateSurfaceArea() = 0;
};