#include "ScalarConverter.hpp"

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

// 잘못된 형식일 경우
void ScalarConverter::strError(const std::string& literal) {
	std::cout << "str error: \"" << literal << "\"\n";
}

// 범위를 벗어날 경우
void ScalarConverter::sizeError(const std::string& literal) {
	std::cout << "Invalid Type: \"" << literal << "\"\n";
}

void ScalarConverter::printCharResult(char c) {
	if (c < 32 || c >= 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";
}

void ScalarConverter::printFloatDoubleResult(int i, float f, double d) {
	if (f - i == 0)
	{
		std::cout << "float: " << f << ".0f\n";
		std::cout << "double: " << d << ".0\n";
	}
	else
	{
		std::cout << "float: " << f << "f\n";
		std::cout << "double: " << d << "\n";
	}
}