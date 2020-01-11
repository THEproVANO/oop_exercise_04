#pragma once
#include <iostream>

template<class T>
struct Vertex {
    using vertex = std::pair<T,T>;
    vertex coordinates;
};

template<class T>
Vertex<T> operator+(const Vertex<T>& A, const Vertex<T>& B) {
    Vertex<T> res;
    res.coordinates.first = A.coordinates.first + B.coordinates.first;
    res.coordinates.second = A.coordinates.second + B.coordinates.second;
	return res;
}

template<class T>
Vertex<T> operator/=(Vertex<T>& A, const double B) {
    A.coordinates.first /= B;
    A.coordinates.second /= B;
	return A;
}

template<class T>
std::istream& operator>> (std::istream& is, Vertex<T>& p)
{
    std::cout << "Coordinate 'x': ";
    is >> p.coordinates.first;
    std::cout << "Coordinate 'y': ";
    is >> p.coordinates.second;
	return is;
}

template<class T>
std::ostream& operator<< (std::ostream& os, const Vertex<T>& p) {
    os << '[' << p.coordinates.first << ' ' << p.coordinates.second << ']';
	return os;
}
