#include <iostream>
#include <cmath>

void FixedPointConversion(int invar){
    //fixed-point arithmetic to avoid using float
    int invarFPN = invar*100; // Assume two decimal places
    int divisor = 224; 
    int voltage_fixed = invarFPN / divisor;

    int voltage_int = voltage_fixed / 100;
    int voltage_decimal = voltage_fixed % 100;

    printf("invar: %d Voltage: %d.%02d volts\n", invar, voltage_int, voltage_decimal);
}

// Function to lookup voltage based on myvar

void voltage_lookup(int myvar) {
  const int lookup_table[][2] = {
      {2000, 870},
      {2010, 880},
      {2020, 890},
      {2022, 900}
      // Add more entries to the lookup table as needed
  };

  for (int i = 0; i < (int)(sizeof(lookup_table) / sizeof(lookup_table[0])); ++i) {
    if (lookup_table[i][0] == myvar) {
      //return (float)lookup_table[i][1] / 100;
      printf("Voltage: %.2f volts\n", (float)lookup_table[i][1] / 100); 
    }
  }

  //return -1;
}
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

    FixedPointConversion(2022);
    FixedPointConversion(2019);
    FixedPointConversion(2016);

    voltage_lookup(2022);
    voltage_lookup(2000);
    return 0;
}