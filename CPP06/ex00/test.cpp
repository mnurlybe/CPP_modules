#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <stdexcept>

class ScalarConverter {
public:
    // Delete the constructor to prevent instantiation
    ScalarConverter() = delete;

    static void convert(const std::string& literal) {
        try {
            // Try to convert to int
            size_t pos;
            int intValue = std::stoi(literal, &pos);
            if (pos == literal.length()) {
                std::cout << "Integer: " << intValue << std::endl;
                return;
            }
        } catch (const std::invalid_argument& e) {
            // Not an integer, continue
        } catch (const std::out_of_range& e) {
            // Out of range for int, continue
        }

        try {
            // Try to convert to float
            size_t pos;
            float floatValue = std::stof(literal, &pos);
            if (pos == literal.length()) {
                std::cout << "Float: " << floatValue << "f" << std::endl;
                return;
            }
        } catch (const std::invalid_argument& e) {
            // Not a float, continue
        } catch (const std::out_of_range& e) {
            // Out of range for float, continue
        }

        try {
            // Try to convert to double
            size_t pos;
            double doubleValue = std::stod(literal, &pos);
            if (pos == literal.length()) {
                std::cout << "Double: " << doubleValue << std::endl;
                return;
            }
        } catch (const std::invalid_argument& e) {
            // Not a double, continue
        } catch (const std::out_of_range& e) {
            // Out of range for double, continue
        }

        // Handle special floating-point values
        if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
            std::cout << "Positive Infinity" << std::endl;
            return;
        } else if (literal == "-inf" || literal == "-inff") {
            std::cout << "Negative Infinity" << std::endl;
            return;
        } else if (literal == "nan" || literal == "nanf") {
            std::cout << "NaN" << std::endl;
            return;
        }

        // If all conversions fail, it's an invalid literal
        std::cerr << "Invalid literal: " << literal << std::endl;
    }
};

int main() {
    ScalarConverter::convert("42");
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("nan");
    ScalarConverter::convert("invalid");

    return 0;
}
