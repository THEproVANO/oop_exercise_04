#pragma once
#include <iostream>
#include <cmath>
#include "vertex.h"

//Класс "Пятиугольника", методы аналогичны пятиугольнику
template<class T>
struct Pentagon
{
    Vertex<T> vertices[5];
    Pentagon(std::istream& is);
	double area() const;
    Vertex<T> center() const;
	void print(std::ostream& os) const;
};

template<class T>
Pentagon<T>::Pentagon(std::istream& is)
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Input coordinate 'x': ";
        is >> vertices[i].coordinates.first;
        std::cout << "Input coordinate 'y': ";
        is >> vertices[i].coordinates.second;
	}
}

template<class T>
double Pentagon<T>::area() const
{
	double area = 0;
	for (int i = 0; i < 5; i++) {
        area += (vertices[i].coordinates.first) * (vertices[(i + 1) % 5].coordinates.second) - (vertices[(i + 1) % 5].coordinates.first) * (vertices[i].coordinates.second);
	}
	area *= 0.5;
	return abs(area);
}
	

template<class T>
Vertex<T> Pentagon<T>::center() const
{
    Vertex<T> res;
    res.coordinates.first = (vertices[0].coordinates.first + vertices[1].coordinates.first + vertices[2].coordinates.first + vertices[3].coordinates.first + vertices[4].coordinates.first) / 5;
    res.coordinates.second = (vertices[0].coordinates.second + vertices[1].coordinates.second + vertices[2].coordinates.second + vertices[3].coordinates.second + vertices[4].coordinates.second) / 5;
	return res;

}

template<class T>
void Pentagon<T>::print(std::ostream& os) const
{
	for (int i = 0; i < 5; ++i) {
		os << vertices[i];
		if (i + 1 != 5) {
			os << ' ';
		}
	}
}
