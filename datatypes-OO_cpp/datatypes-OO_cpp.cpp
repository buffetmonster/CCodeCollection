#include <iostream>
#include <iomanip>

//can't shorten, and doesn't exist for this version of g++ 11.
//#define USING_CPP23 ( __cplusplus >= 2023L )
//#define USING_CPP22 ( __cplusplus >= 2022L )
#define USING_CPP21 ( __cplusplus >= 202100L )
#define USING_CPP20 ( __cplusplus >= 202002L )
#define USING_CPP17 ( __cplusplus >= 201703L )
#define USING_CPP14 ( __cplusplus >= 201402L )
#define USING_CPP11 ( __cplusplus >= 201103L )

class DataTypeSizer {
public:
  template<typename T>
  static void printSize(const std::string& typeName) {
    std::cout << typeName << " size: " << sizeof(T) << " bytes" << std::endl;
  }
};

class CheckCPP {
public:
  // Set version based on preprocessor definitions
  //static constexpr unsigned int VER = USING_CPP23 | USING_CPP22 | USING_CPP21 | USING_CPP20 | USING_CPP17 | USING_CPP14 | USING_CPP11;
  static constexpr unsigned int VER = USING_CPP20 | USING_CPP17 | USING_CPP14 | USING_CPP11;
  static void ver(void) {
    std::cout << "From trial and error looks like g++ 11 is supporting 20 and older, can select 23 but uses 20: " << std::endl;
    std::cout << "VER: " << VER << std::endl;
    std::cout << "__cplusplus: " << __cplusplus << std::endl;
    std::cout << "CheckCPP: (configure via the makefile) Using C++";

    if (VER & USING_CPP21) {
      std::cout << " 21";
    }
    if (VER & USING_CPP20) {
      std::cout << " 20";
    }
    if (VER & USING_CPP17) {
      std::cout << " 17";
    }
    if (VER & USING_CPP14) {
      std::cout << " 14";
    }
    if (VER & USING_CPP11) {
      std::cout << " 11";
    }
    else {
      std::cout << " (unknown)"; // Handle case where no version matches
    }
    std::cout << std::endl;
  }
};

int main() {
  //std::cout << "Using C++20: " << USING_CPP11 << std::endl;
  CheckCPP::ver();
  DataTypeSizer::printSize<char>("char");
  DataTypeSizer::printSize<short>("short");
  DataTypeSizer::printSize<int>("int");
  DataTypeSizer::printSize<long>("long");
  DataTypeSizer::printSize<long long>("long long");

  DataTypeSizer::printSize<float>("float");
  DataTypeSizer::printSize<double>("double");
  DataTypeSizer::printSize<long double>("long double");

  DataTypeSizer::printSize<bool>("bool");

  // Bonus: Size of pointers
  DataTypeSizer::printSize<int*>("int* (pointer to int)");
  DataTypeSizer::printSize<char*>("char* (pointer to char)");
  DataTypeSizer::printSize<long int*>("long int* (pointer to char)");

  //Declare and initialize the variables
  float number1 {1.12345678901234567890f}; // Precision : 7
  double number2 {1.12345678901234567890}; // Precision : 15
  long double number3  {1.12345678901234567890L};

  //Precision
  //std::cout << std::setprecision(20); // Control the precision from std::cout.
  //std::cout << "number1 is : " << number1 << std::endl; //7 digits
  //std::cout << "number2 is : " << number2 << std::endl; // 15'ish digits
  //std::cout << "number3 is : " << number3 << std::endl; // 15+ digits

  //Precision
  std::cout << std::setprecision(20); // Control the precision from std::cout.
  std::cout << "number1 is : " << number1 << ": manually check precision we want :1.123456 78901234567890f expect 7" << std::endl; //7 digits
  std::cout << "number2 is : " << number2 << ": manually check precision we want :1.1234567890123 4567890 expect 15" << std::endl; // 15'ish digits
  std::cout << "number3 is : " << number3 << ": manually check precision we want :1.1234567890123 4567890L expect >15" << std::endl; // 15+ digits
  return 0;
}