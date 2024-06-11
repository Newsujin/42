#include "ScalarConverter.hpp"
#include <cstdlib>  // std::strtol, std::strtof, std::strtod
#include <limits>   // std::numeric_limits
#include <cerrno>   // errno, ERANGE
#include <cfloat>   // FLT_MAX, FLT_MIN
#include <iomanip>  // std::setprecision

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& rhs) { (void)rhs; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}

int ScalarConverter::checkType(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") return FLOAT;
    if (literal == "nan" || literal == "+inf" || literal == "-inf") return DOUBLE;

    // Check if it is a single character
    if (literal.length() == 1 && !isdigit(literal[0])) return CHAR;

    char* end;
    errno = 0;

    // Try converting to int
    long l = std::strtol(literal.c_str(), &end, 10);
    if (*end == '\0' && errno != ERANGE &&
        l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max()) {
        return INT;
    }

    // Try converting to float
    errno = 0;
    std::strtof(literal.c_str(), &end);
    if ((*end == 'f' || *end == 'F') && *(end + 1) == '\0' && errno != ERANGE) return FLOAT;

    // Try converting to double
    errno = 0;
    std::strtod(literal.c_str(), &end);
    if (*end == '\0' && errno != ERANGE) return DOUBLE;

    return STR_ERROR;
}

// 변환할 수 없는 잘못된 형식일 경우
void ScalarConverter::strError(const std::string& literal) {
    std::cout << "str error: \"" << literal << "\"\n";
}

// 변환할 수 있는 범위를 벗어날 경우
void ScalarConverter::sizeError(const std::string& literal) {
    std::cout << "Invalid Type: \"" << literal << "\"\n";
}

void ScalarConverter::charConvert(const std::string& literal) {
    char c = literal[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    if (!isprint(c) || c < 32 || c >= 127)
        std::cout << "char: impossible\n";
    else
        std::cout << "char: '" << c << "'\n";

    std::cout << "int: " << i << "\n";
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::intConvert(const std::string& literal) {
    errno = 0;
    char* endptr;
    long l = std::strtol(literal.c_str(), &endptr, 10);

    // Check for errors or out-of-bounds values
    if (errno == ERANGE || l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max() || *endptr != '\0') {
        std::cout << "int: impossible\n";
        std::cout << "char: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    int i = static_cast<int>(l);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    if (!isprint(c) || c < 32 || c >= 127)
        std::cout << "char: impossible\n";
    else
        std::cout << "char: '" << c << "'\n";

    std::cout << "int: " << i << "\n";
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::floatConvert(const std::string& literal) {
    errno = 0;
    float f = std::strtof(literal.c_str(), NULL);
    if (errno == ERANGE || (f == 0 && literal != "0.0f" && literal != "0.0F" && literal != "0")) {
        sizeError(literal);
        return;
    }
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);

    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
    } else {
        if (!isprint(c) || c < 32 || c >= 127)
            std::cout << "char: impossible\n";
        else
            std::cout << "char: '" << c << "'\n";

        std::cout << "int: " << i << "\n";
    }

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::doubleConvert(const std::string& literal) {
    errno = 0;
    double d = std::strtod(literal.c_str(), NULL);
    if (errno == ERANGE || (d == 0 && literal != "0.0" && literal != "0")) {
        sizeError(literal);
        return;
    }
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf") {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
    } else {
        if (!isprint(c) || c < 32 || c >= 127)
            std::cout << "char: impossible\n";
        else
            std::cout << "char: '" << c << "'\n";

        std::cout << "int: " << i << "\n";
    }

    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::convert(const std::string& literal) {
    int type = checkType(literal);
    switch (type) {
        case CHAR:
            charConvert(literal);
            break;
        case INT:
            intConvert(literal);
            break;
        case FLOAT:
            floatConvert(literal);
            break;
        case DOUBLE:
            doubleConvert(literal);
            break;
        default:
            strError(literal);
            break;
    }
}
