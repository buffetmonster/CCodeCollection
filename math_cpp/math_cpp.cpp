#include <iostream>
#include <cmath>

int main() {
    // Integer arithmetic
    int A = 10;
    int B = 5;
    int Sum = A + B;
    int Difference = A - B;
    int Product = A * B;
    int Quotient = A / B;
    int Remainder = A % B;

    std::cout << "Integer arithmetic:" << std::endl;
    std::cout << "Sum: " << Sum << std::endl;
    std::cout << "Difference: " << Difference << std::endl;
    std::cout << "Product: " << Product << std::endl;
    std::cout << "Quotient: " << Quotient << std::endl;
    std::cout << "Remainder: " << Remainder << std::endl;

    // Floating-point arithmetic
    double X = 3.14;
    double Y = 2.0;
    double Result = X / Y;
    double SquareRoot = sqrt(X);

    std::cout << "\nFloating-point arithmetic:" << std::endl;
    std::cout << "Division: " << Result << std::endl;
    std::cout << "Square root of " << X << ": " << SquareRoot << std::endl;

    // Mixed arithmetic
    int M = 10;
    double N = 3.5;
    double MixedResult = M / N; // Implicit type conversion from int to double

    std::cout << "\nMixed arithmetic:" << std::endl;
    std::cout << "Division (mixed types): " << MixedResult << std::endl;

    // Math functions
    double Angle = 45.0;
    double Radians = Angle * M_PI / 180.0; // Convert degrees to radians
    double SineValue = sin(Radians);
    double CosineValue = cos(Radians);

    std::cout << "\nTrigonometric functions:" << std::endl;
    std::cout << "Sine of " << Angle << " degrees: " << SineValue << std::endl;
    std::cout << "Cosine of " << Angle << " degrees: " << CosineValue << std::endl;

    return 0;
}