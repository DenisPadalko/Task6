#include <iostream>
#include "ChildClasses.h"
#include "Task6.h"

int main()
{
	Paralelogram* p = new Paralelogram(1, 1, Point(-2, 1, 0), Point(0, 4, 0));
	Point Center = p->GetCenter();
	cout << "Center of paralelogram: (" << Center.GetPointCoordinateX() << ", " << Center.GetPointCoordinateY() << ")" << endl;
	cout << "Vertices of paralelogram: ";
	vector<Point*> Vertices = p->GetVertices();
	for (Point* Vertice : Vertices)
	{
		cout << "(" << Vertice->GetPointCoordinateX() << ", " << Vertice->GetPointCoordinateY() << ")" << endl;
	}
	cout << endl << endl << endl;
	Ellipse* ellipse = new Ellipse();
	cout << "Radius 1 of ellipse: " << ellipse->GetFirstRadius() << endl;
	cout << "Radius 2 of ellipse: " << ellipse->GetSecondRadius() << endl;
	Center.~Point();
	Center = ellipse->GetCenter();
	cout << "Center of ellipse: (" << Center.GetPointCoordinateX() << ", " << Center.GetPointCoordinateY() << ")" << endl;
	Vertices.~vector();
	Vertices = ellipse->GetVertices();
	return 0;
}