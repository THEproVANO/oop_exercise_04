#include <iostream>
#include <tuple>
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"
#include "templates.h"

template<class T>
void processing(std::istream& is, std::ostream& os)
{
    if constexpr (is_figurelike_tuple<T>::value)
    {
        int vert;
        std::cout << "Enter the number of vertices" << std::endl;
        std::cin >> vert;
        if (vert == 5)
        {
            Vertex<double> A, B, C, D, E;
            is >> A >> B >> C >> D >> E;
            auto object = std::make_tuple(A, B, C, D, E);
            print(os, object);
            os << "Area of object: " << area(object) << std::endl;
            os << "Center of object: " <<center(object) << std::endl;
            return;
        }
        else if (vert == 6)
        {
            Vertex<double> A, B, C, D, E, F;
            is >> A >> B >> C >> D >> E >> F;
            auto object = std::make_tuple(A, B, C, D, E, F);
            print(os, object);
            os << "Area of object: " << area(object) << std::endl;
            os << "Center of object: " <<center(object) << std::endl;
            return;
        }
        else if (vert == 8)
        {
            Vertex<double> A, B, C, D, E, F, G, I;
            is >> A >> B >> C >> D >> E >> F >> G >> I;
            auto object = std::make_tuple(A, B, C, D, E, F, G, I);
            print(os, object);
            os << "Area of object: " << area(object) << std::endl;
            os << "Center of object: " <<center(object) << std::endl;
            return;
        }
        else if (vert < 3)
        {
            std::cout << "The tuple is not a figure!\n";
        }
    }
    else
    {
        T object(is);
        print(os, object);
        os << '\n' << "Area of object: "<< area(object) << std::endl;
        os << "Center of object: " << center(object) << "\n\n";
        return;
    }
}

void PrintMenu() {
	std::cout << "Input figure type:" << std::endl;
    std::cout << "1 - Pentagon" << std::endl;
    std::cout << "2 - Octagon" << std::endl;
    std::cout << "3 - Hexagon" << std::endl;
    std::cout << "4 - Tuple" << std::endl;
    std::cout << "'q' to close application" << std::endl;
}

int main() {
	char obj_type;
	while (true) {
		PrintMenu();
		std::cin >> obj_type;
        switch (obj_type)
        {
		case'4':
            std::cout << "Input tuple:\n";
            processing<std::tuple<Vertex<double>>>(std::cin, std::cout);
			break;

		case'1':
            std::cout << "Input Vertex of the Pentagon:\n";
            processing<Pentagon<double>>(std::cin, std::cout);
			break;

		case'2':
            std::cout << "Input Vertex of the octagon:\n";
            processing<Octagon<double>>(std::cin, std::cout);
			break;

		case'3':
            std::cout << "Input Vertex of the hexagon:\n";
            processing<Hexagon<double>>(std::cin, std::cout);
			break;

		case'q':
			return 0;

		default:
            std::cout << "Incorrect input.\n\n" << std::endl;
            break;
		}
	}
    return 0;
}
