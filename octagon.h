#pragma once
#include <iostream>
#include <cmath>
#include "vertex.h"


//Класс "Восьмиугольника", методы аналогичны пятиугольнику
template<class T>
struct Octagon {
    Vertex<T> vertices[8];
    Octagon(std::istream& is);
	double area() const;
    Vertex<T> center() const;
	void print(std::ostream& os) const;
};

template<class T>
Octagon<T>::Octagon(std::istream& is) {
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "Input coordinate 'x': ";
        is >> vertices[i].coordinates.first;
        std::cout << "Input coordinate 'y': ";
        is >> vertices[i].coordinates.second;
	}
}

template<class T>
double Octagon<T>::area() const {
	double area = 0;
	for (int i = 0; i < 8; i++) {
        area += (vertices[i].coordinates.first) * (vertices[(i + 1) % 8].coordinates.second) - (vertices[(i + 1) % 8].coordinates.first) * (vertices[i].coordinates.second);
	}
	area *= 0.5;
	return abs(area);
}


template<class T>
Vertex<T> Octagon<T>::center() const {
    Vertex<T> res;
    res.coordinates.first = (vertices[0].coordinates.first + vertices[1].coordinates.first + vertices[2].coordinates.first + vertices[3].coordinates.first + vertices[4].coordinates.first + vertices[5].coordinates.first + vertices[6].coordinates.first + vertices[7].coordinates.first) / 8;
    res.coordinates.second = (vertices[0].coordinates.second + vertices[1].coordinates.second + vertices[2].coordinates.second + vertices[3].coordinates.second + vertices[4].coordinates.second + vertices[5].coordinates.second + vertices[6].coordinates.first + vertices[7].coordinates.second) / 8;
	return res;

}

template<class T>
void Octagon<T>::print(std::ostream& os) const {
	for (int i = 0; i < 8; ++i) {
		os << vertices[i];
		if (i + 1 != 8) {
			os << ' ';
		}
	}
}
