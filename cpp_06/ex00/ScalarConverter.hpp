#ifndef __SCALARCASTER_H__
#define __SCALARCASTER_H__

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include <climits>
#include <cfloat>
#include <cmath>

class ScalarConverter {

public:

	static void	convert( std::string& str );

private:

    ScalarConverter();
    ScalarConverter( ScalarConverter const& src );
    ~ScalarConverter();

    ScalarConverter& operator=( ScalarConverter const& rhs );


    enum Type {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        IMPOSSIBLE
    };

    static Type     checkType( std::string str );

   template <typename T> static void printCast(T type)
   {
       std::cout << "char: ";
       printChar(type);
       std::cout << "int: ";
       printInt(type);
       std::cout << "float: ";
       printFloat(type);
       std::cout << "double: ";
       printDouble(type);
   }
    template <typename T> static void printChar(T c) {
        if (std::isnan(c) || CHAR_MIN > c || c > CHAR_MAX)
            std::cout << "impossible" << std::endl;
        else if (std::isprint(static_cast<char>(c)))
            std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }

    template <typename T> static void printInt(T i)
    {
        if (std::isnan(i) || INT32_MIN > i || i > 2147483647.)
            std::cout << "impossible" << std::endl;
        else
            std::cout << static_cast<int>(i) << std::endl;
    }

    template <typename T> static void printFloat(T f)
    {
        if(std::isinf(f))
        {
            if (f < 0)
                std::cout << "-";
            else
                std::cout << "+";
            std::cout << "inff" << std::endl;
            return;
        }
        if (std::isnan(f))
        {
            std::cout << "nanf" << std::endl;
            return;
        }
        if (-FLT_MAX > f || f > FLT_MAX)
            std::cout << "impossible" << std::endl;
        else
        {
            std::cout << static_cast<float>(f);
            if (static_cast<float>(f) - static_cast<int>(f) == 0)
                std::cout << ".0";
            std::cout << "f" << std::endl;
        }
    }

    template <typename T> static void printDouble(T d)
    {
        if(std::isinf(d))
        {
            if (d < 0)
                std::cout << "-";
            else
                std::cout << "+";
            std::cout << "inf" << std::endl;
            return;
        }
        if (std::isnan(d))
        {
            std::cout << "nan" << std::endl;
            return;
        }
        if (-DBL_MAX > d || d > DBL_MAX)
            std::cout << "impossible" << std::endl;
        else
        {
            std::cout << static_cast<double>(d);
            if (static_cast<double>(d) - static_cast<int>(d) == 0)
                std::cout << ".0";
            std::cout << std::endl;
        }
    }
};

#endif