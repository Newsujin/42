#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define STR_ERROR 0

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& rhs);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter();

		static int checkType(const std::string& literal);
		static void strError(const std::string& literal);
		static void sizeError(const std::string& literal);
		static void printResult(char c, int i, float f, double d, bool isSpecial);

		static void charConvert(const std::string& literal);
		static void intConvert(const std::string& literal);
		static void floatConvert(const std::string& literal);
		static void doubleConvert(const std::string& literal);

	public:
		static void convert(const std::string& literal);
};

#endif