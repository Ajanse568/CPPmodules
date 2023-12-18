#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() = default;

ScalarConverter::~ScalarConverter() = default;

ScalarConverter::ScalarConverter(const ScalarConverter &obj) = default;

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) = default;

bool is_digits(std::string& str)
{
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

ScalarConverter::Type ScalarConverter::checkType(std::string str) {
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


void ScalarConverter::convert(std::string &str) {
    Type type = checkType(str);

    switch (type) {
        case CHAR:
            printCast(static_cast<char>(str[0]));
            break;
        case INT:
            printCast(std::stoi(str));
            break;
        case FLOAT:
            printCast(std::stof(str));
            break;
        case DOUBLE:
            printCast(std::stod(str));
            break;
        case IMPOSSIBLE:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            break;
    }
}