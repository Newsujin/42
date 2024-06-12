#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& rhs) { (void)rhs; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) { (void)rhs; return *this; }
ScalarConverter::~ScalarConverter() {}


void ScalarConverter::charConvert(const std::string& literal) {
	char c = literal[0];
	printCharResult(c);

	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::intConvert(const std::string& literal) {
	errno = 0;
	char* endptr;
	long l = std::strtol(literal.c_str(), &endptr, 10);

	if (errno == ERANGE || l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max() || *endptr != '\0') {
		sizeError(literal);
		return;
	}

	int i = static_cast<int>(l);
	char c = static_cast<char>(i);
	printCharResult(c);

	std::cout << "int: " << i << "\n";
	std::cout << "float: " << static_cast<float>(i) << ".0f\n";
	std::cout << "double: " << static_cast<double>(i) << ".0\n";
}

void ScalarConverter::floatConvert(const std::string& literal) {
	errno = 0;
	float f = std::strtof(literal.c_str(), NULL);
	double d = std::strtod(literal.c_str(), NULL);

	if (errno == ERANGE) {
		sizeError(literal);
		return;
	}

	char c = static_cast<char>(f);
	int i = static_cast<int>(f);

	if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else {
		if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
			sizeError(literal);
			return ;
		}
		else {
			printCharResult(c);
			std::cout << "int: " << i << "\n";
		}
	}
	printFloatDoubleResult(i, f, d);
}

void ScalarConverter::doubleConvert(const std::string& literal) {
	errno = 0;
	double d = std::strtod(literal.c_str(), NULL);

	if (errno == ERANGE) {
		sizeError(literal);
		return;
	}

	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else {
		if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
			sizeError(literal);
			return ;
		}
		else {
			printCharResult(c);
			std::cout << "int: " << i << "\n";
		}
	}
	printFloatDoubleResult(i, f, d);
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
