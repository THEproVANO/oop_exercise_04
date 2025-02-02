#pragma once
#include <tuple>
#include <type_traits>
#include <iostream>
#include "vertex.h"


template<class T>
struct is_Vertex : std::false_type {};

template<class T>
struct is_Vertex<Vertex<T>> : std::true_type {};

template<class T>
struct is_figurelike_tuple : std::false_type {};

template<class Head, class... Tail>
struct is_figurelike_tuple<std::tuple<Head, Tail...>> :
    std::conjunction<is_Vertex<Head>, std::is_same<Head, Tail>...> {};

template<class T>
inline constexpr bool is_figurelike_tuple_v = is_figurelike_tuple<T>::value;



template<class T, class = void>
struct has_method_area : std::false_type {};

template<class T>
struct has_method_area<T, std::void_t<decltype(std::declval<const T&>().area())>> : std::true_type {};

template<class T>
inline constexpr bool has_method_area_v = has_method_area<T>::value;

template<class T>
std::enable_if_t<has_method_area_v<T>, double> area(const T& object) {
    return object.area();
}



template<class T, class = void>
struct has_method_center : std::false_type {};

template<class T>
struct has_method_center<T, std::void_t<decltype(std::declval<const T&>().center())>> : std::true_type {};

template<class T>
inline constexpr bool has_method_center_v = has_method_center<T>::value;

template<class T>
std::enable_if_t<has_method_center_v<T>, Vertex<double>> center(const T& object) {
	return object.center();
}


template<class T, class = void>
struct has_method_print : std::false_type {};

template<class T>
struct has_method_print<T, std::void_t<decltype(std::declval<const T&>().print(std::cout))>> : std::true_type {};

template<class T>
inline constexpr bool has_method_print_v = has_method_print<T>::value;

template<class T>
std::enable_if_t<has_method_print_v<T>, void> print(std::ostream& os, const T& object) {
	object.print(os);
}

template<size_t Id, class T>
double compute_area(const T& tuple) {
    if constexpr (Id >= std::tuple_size_v<T>)
		return 0;
	else {
        const auto x1 = std::get<Id - 0>(tuple).coordinates.first - std::get<0>(tuple).coordinates.first;
        const auto y1 = std::get<Id - 0>(tuple).coordinates.second - std::get<0>(tuple).coordinates.second;
        const auto x2 = std::get<Id - 1>(tuple).coordinates.first - std::get<0>(tuple).coordinates.first;
        const auto y2 = std::get<Id - 1>(tuple).coordinates.second - std::get<0>(tuple).coordinates.second;
		const double local_area = std::abs(x1 * y2 - y1 * x2) * 0.5;
		return local_area + compute_area<Id + 1>(tuple);
	}
}

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, double>
area(const T& object) {
    if constexpr (std::tuple_size_v<T> < 3)
		throw std::logic_error("It`s not a figure");
    else
		return compute_area<2>(object);
}

template<size_t Id, class T>
Vertex<double> tuple_center(const T& object) {
    if constexpr (Id >= std::tuple_size<T>::value)
        return Vertex<double> { std::make_pair(0,0) };
    else
    {
        Vertex<double> res = std::get<Id>(object);
		return res + tuple_center<Id + 1>(object);
	}
}

template<class T>
Vertex<double> compute_center(const T& tuple)
{
    Vertex<double> res{ std::make_pair(0,0) };
	res = tuple_center<0>(tuple);
	res /= std::tuple_size_v<T>;
	return res;
}

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, Vertex<double>>
center(const T& object) {
    if constexpr (std::tuple_size_v<T> < 3)
		throw std::logic_error("It`s not a figure");
    else
		return compute_center(object);
}

template<size_t Id, class T>
void print(const T& object, std::ostream& os) {
    if constexpr (Id >= std::tuple_size<T>::value)
		std::cout << "\n";
    else
    {
		os << std::get<Id>(object) << " ";
		print<Id + 1>(object, os);
	}
}

template<class T>
std::enable_if_t<is_figurelike_tuple_v<T>, void>
print(std::ostream& os, const T& object) {
    if constexpr (std::tuple_size_v<T> < 3)
		throw std::logic_error("It`s not a figure");
    else
		print<0>(object, os);
}
