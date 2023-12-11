#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

bool is_digits(std::string& str)
{
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

ScalarConverter::Type ScalarConverter::checkType(std::string &str) {
    std::string preDec;
    std::string postDec;

    if (str.length() == 1 && !std::isdigit(str[0]))
        return CHAR;
    if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
        return FLOAT;
    if (str == "-inf" || str == "+inf" || str == "nan" || str == "inf")
        return DOUBLE;
    if (str.length() > 1 && (str[0] == '-' || str[0] == '+'))
        str = str.substr(1);
    if (is_digits(str))
        return INT;
    if (str.find('.') == std::string::npos)
        return IMPOSSIBLE;
    if (str.find('.') != str.rfind('.'))
        return IMPOSSIBLE;
    preDec = str.substr(0, str.find('.'));
    postDec = str.substr(str.find('.') + 1);
    if (is_digits(preDec) && is_digits(postDec))
        return DOUBLE;
    if (postDec[postDec.length() - 1] == 'f')
        postDec = postDec.substr(0, postDec.length() - 1);
    if (is_digits(preDec) && is_digits(postDec))
        return FLOAT;
    return IMPOSSIBLE;
}

template<typename T> void ScalarConverter::printConversions(T type) {
    std::cout << "char: ";
    printChar(type);
    std::cout << "int: ";
    printInt(type);
    std::cout << "float: ";
    printFloat(type);
    std::cout << "double: ";
    printDouble(type);
}

template <typename T> void ScalarConverter::printChar(T c) {
    if (std::isnan(c) || CHAR_MIN > c || c > CHAR_MAX)
        std::cout << "impossible" << std::endl;
    else if (std::isprint(static_cast<char>(c)))
        std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

template <typename T> void ScalarConverter::printInt(T i)
{
    if (std::isnan(i) || INT32_MIN > i || i > INT32_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(i) << std::endl;
}

template <typename T> void ScalarConverter::printFloat(T f)
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

template <typename T> void ScalarConverter::printDouble(T d)
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

void ScalarConverter::convert(std::string &str) {
    Type type = checkType(str);
    switch (type) {
        case CHAR:
            printConversions(static_cast<char>(str[0]));
            break;
        case INT:
            printConversions(std::stoi(str));
            break;
        case FLOAT:
            printConversions(std::stof(str));
            break;
        case DOUBLE:
            printConversions(std::stod(str));
            break;
        case IMPOSSIBLE:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}