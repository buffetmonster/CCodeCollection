#include <iostream>
#define USE_CONSTRUCTOR //hash if no constructor is required
const double PI {3.1415926535897932384626433832795};

class Cylinder {
  public : 
    #ifdef USE_CONSTRUCTOR
    //Constuctors
    Cylinder() = default; //will populate with private values automatically. If no constructers defined it will take a default value
    Cylinder(double rad_param,double height_param){ //But if constructor defined as here then default should also be added
      std::cout << "Cylinder inside : " << rad_param << " : " << height_param << std::endl;
      base_radius = rad_param;
      height = height_param;
    }
    #endif
    //Functions (methods)
    double volume(){
      return PI * base_radius * base_radius * height;
    }
    
    //Setter and getter methods
    double get_base_radius(){
      return base_radius;
    }
    double get_height(){
      return height;
    }
    void set_base_radius(double rad_param){
      base_radius = rad_param;
    }
    void set_height(double height_param){
      height = height_param;
    }
  private : 
    //Member variables
    double base_radius{1};
    double height{1};
};



int main(){

  std::cout << "Cylinder cylinder1;" << std::endl;
  Cylinder cylinder1; //will use default private constructor values
  std::cout << "volume : " << cylinder1.volume() << std::endl;
  //Modify our object
  cylinder1.set_base_radius(100);
  cylinder1.set_height(10);
  std::cout << "Set base and height params:" << 100 << " : " << 10 << std::endl;
  std::cout << "volume : " << cylinder1.volume() << std::endl;
  //will use params provided
  std::cout << "cylinder1(10,10)" << std::endl;
#ifdef USE_CONSTRUCTOR
  Cylinder cylinder2(10.1,10.1);
  std::cout << "volume : " << cylinder2.volume() << std::endl;
#endif
  return 0;
}