#include "ScalarConverter.hpp"

int ScalarConverter::checkType(const std::string& literal) {
	if (literal.length() == 1 && !isdigit(literal[0])) return CHAR;

	errno = 0;
	char* end;
	long l = std::strtol(literal.c_str(), &end, 10);

	if (*end == '\0' && errno != ERANGE &&
		l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max())
		return INT;

	errno = 0;
	std::strtof(literal.c_str(), &end);
	if ((*end == 'f' || *end == 'F') && *(end + 1) == '\0' && errno != ERANGE) return FLOAT;

	errno = 0;
	std::strtod(literal.c_str(), &end);
	if (*end == '\0' && errno != ERANGE) return DOUBLE;

	return STR_ERROR;
}

void ScalarConverter::strError(const std::string& literal) {
	std::cout << "str error: \"" << literal << "\"\n";
}

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