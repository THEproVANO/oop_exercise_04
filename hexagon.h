#pragma once
#include <iostream>
#include <cmath>
#include "vertex.h"

//Класс "Шестиугольника"
template<class T>
struct Hexagon
{
    Vertex<T> vertices[6];
    Hexagon(std::istream& is);
	double area() const;
    Vertex<T> center() const;
	void print(std::ostream& os) const;
};

template<class T>
Hexagon<T>::Hexagon(std::istream& is)
{
    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Input coordinate 'x': ";
        is >> vertices[i].coordinates.first;
        std::cout << "Input coordinate 'y': ";
        is >> vertices[i].coordinates.second;
    }
}

template<class T>
double Hexagon<T>::area() const //вывод площади фигуры
{
	double area = 0;
	for (int i = 0; i < 6; i++) {
        area += (vertices[i].coordinates.first) * (vertices[(i + 1) % 6].coordinates.second) - (vertices[(i + 1) % 6].coordinates.first) * (vertices[i].coordinates.second);
	}
	area *= 0.5;
	return abs(area);
}


template<class T>
Vertex<T> Hexagon<T>::center() const //вывод центра фигуры
{
    Vertex<T> res;
    res.coordinates.first = (vertices[0].coordinates.first + vertices[1].coordinates.first + vertices[2].coordinates.first + vertices[3].coordinates.first + vertices[4].coordinates.first + vertices[5].coordinates.first) / 6;
    res.coordinates.second = (vertices[0].coordinates.second + vertices[1].coordinates.second + vertices[2].coordinates.second + vertices[3].coordinates.second + vertices[4].coordinates.second + vertices[5].coordinates.second) / 6;
	return res;
}

template<class T>
void Hexagon<T>::print(std::ostream& os) const //вывод координат фигуры
{
    for (int i = 0; i < 6; ++i)
    {
		os << vertices[i];
        if (i + 1 != 6)
			os << ' ';
	}
}
