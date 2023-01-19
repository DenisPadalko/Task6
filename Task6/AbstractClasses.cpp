#include "AbstractClasses.h"
#include <iostream>

Body2D::Body2D() : X(0), Y(0)
{}

Body2D::Body2D(const double NewX, const double NewY) : X(NewX), Y(NewY)
{}

Body2D::Body2D(const Body2D& AnotherBody) : X(AnotherBody.X), Y(AnotherBody.Y)
{}

Body2D::Body2D(Body2D&& AnotherBody)
{
	X = move(AnotherBody.X);
	Y = move(AnotherBody.Y);
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

Body3D::Body3D() : Z(0)
{}

Body3D::Body3D(const double NewX, const double NewY, const double NewZ) : Z(NewZ), Body2D(NewX, NewY)
{}

Body3D::Body3D(const Body3D& AnotherBody) : Z(AnotherBody.Z), Body2D(AnotherBody.GetX(), AnotherBody.GetY())
{}

Body3D::Body3D(Body3D&& AnotherBody) : Body2D(AnotherBody.GetX(), AnotherBody.GetY())
{
	AnotherBody.SetX(0);
	AnotherBody.SetY(0);
	Z = move(AnotherBody.Z);
}

const double Body3D::GetZ() const
{
	return Z;
}

void Body3D::SetZ(const double NewZ)
{
	Z = NewZ;
}