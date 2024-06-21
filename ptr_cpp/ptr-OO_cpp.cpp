#include <iostream>
#include <cstring>

typedef struct {
  int id;
  char name[64];
} Person;

void Ternary_operator (int a, int b)
{
    int max = (a > b)? a : b;
    std::cout << "Ternary_operator bonus : A:" << a << " B:" << b << " Max: " << max << std::endl;
    return;
}

class ValueComparator {
public:
  // Function to find the maximum of two integers using a ternary operator within the class
  void findMax(int a, int b) {
    maxy = (a > b) ? a : b;
    aX = a;
    bX = b;
  }

  // Function to print the comparison result (optional, promotes modularity)
  void printResult(int a, int b) {
    std::cout << "Ternary_operator bonus OO: A:" << a << " B:" << b << " Max: " << maxy << std::endl;
  }
  void printResultX(void) {
    std::cout << "Ternary_operator bonusX OO: A:" << aX << " B:" << bX << " Max: " << maxy << std::endl;
  }
private:
  int maxy {};
  int aX {};
  int bX {};
};

class StringManipulator {
public:
  void StringStd(void) {
    std::string full_name;//Empty string
    std::string planet {"Earth. Where the sky is blue"};//Initialize with string literal
	  std::string prefered_planet{planet};//Initialize with other existing string
    std::string message {"Hello there",5};	//Initialize with part of a string literal.
		//Contains hello
    std::string weird_message(4,'e');//Initialize with multiple copies of a char
		// contains eeee
    std::string greeting{"Hello World"};
    std::string saying_hello{ greeting,6,5};//Initialize with part of an existing std::string

    std::cout << "full_name : " << full_name << std::endl;
	  std::cout << "planet : " << planet << std::endl;
	  std::cout << "prefered_planet : " << prefered_planet << std::endl;
	  std::cout << "message : " << message << std::endl;
	  std::cout << "weird_message : " << weird_message << std::endl;
	  std::cout << "greeting : " << greeting << std::endl;
	  std::cout << "saying_hello : " << saying_hello << std::endl;

    //Changing std::string at runtime, automatically free and reallocated
    planet = "Earth. Where the sky is blue Earth. Where the sky is blue Earth. Where ";
    std::cout << "planet : " << planet << std::endl;
  }
  // Function to find the maximum of two integers using a ternary operator within the class
  void CString(void) {
    // c-string, bad as need to null terminate: use string literal
    char messagec [] {'H','e','l','l','o','\0'};
    std::cout << "\nCString!" << std::endl;
    messagec [3] ='L'; //We can change it
    std::cout << "messagec : " << messagec << std::endl;
    std::cout << "sizeof(messagec) : " << sizeof(messagec) << std::endl;
    std::cout << "\nconvert to upper!" << std::endl;
    for ( char c : messagec){
      //the conversion does something weird so need to cast else we get it's ASCII code. Or do in 2 steps as per comment below.
      std::cout << "changed to upperx  : " << (char)toupper(c) << std::endl;
      //std::cout << "changed to upperx  : " << (int)toupper(c) << std::endl;
      //char thechar = toupper(c);
      //std::cout << "changed to upper  : " << thechar << std::endl;
    }
  }
  void PtrString(void) {

    // ptr to char
    std::cout << "\nPtrString!" << std::endl;
    const char *message {"Hello World!"};
    std::cout << "message : " << message << std::endl;

    //*message = "B"; // Compiler error
    std::cout << "*message : " << *message << std::endl;
    std::cout << "*message : " << *(message + 1)<< std::endl;
  }
  void PtrStringHeap(void) {
    int size {};
    // ptr to char from heap  World:PtrStringHeap!
    //ptr below is string length + null to terminate (5 + 1)
    std::cout << "\nPtrStringHeap!" << std::endl;
    //const char *message {new char[6]{"Hello"}}; //5 will fail as needs null terminator
    const char *message {new char[]{"Hello"}};
    size = strlen(message) + 1; //extra char for nullprt
    std::cout << "message : " << message << ":" << size << std::endl;
    std::cout << "careful this is just the size of the ptr:" << sizeof(message) << ":" << sizeof(message[0]) << ":" << std::endl;
    for(int i {};  i < size; i++){
      if(std::isupper(message[i])){
        std::cout << "char Upper: " << message[i] << ":" << i+1 << std::endl;
      }else{
        std::cout << "char Lower/other: " << message[i] << ":" << i+1 << std::endl;
      }  
    }
  }
  void StringFun(void) {
    //Allow users to modify the string
    std::cout << "\nString" << std::endl;
    // string literal
    char message1[] {"Hello World!"};
    message1[0] = 'B';
    std::cout << "message1 : " << message1 << std::endl;

    int scores [] {1,2,5};
    int count { std::size(scores)}; // std::size( C++17)
    //if not => C++17
    //int count {sizeof(scores)/sizeof(scores[0])}; 

    std::cout << "sizeof(scores) : " << sizeof(scores) << std::endl;
    std::cout << "sizeof(scores[0]) : " << sizeof(scores[0]) << std::endl;
    std::cout << "count : " << count << std::endl;
    for(int i {0} ; i < count ; ++i){
        std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }
    //Range based for loop
    for ( auto i : scores){
        std::cout << "scores R  : " << i << std::endl;       
    }
  }
  void CreateWithNew(void) {
    //This is heap, so need to return later!
    VariablePtr = new int;
    *VariablePtr = 69;
  }
  void PrintVal(void){
    if (VariablePtr == nullptr){
        std::cout << "MyVarPtr : It's nullptr, can't PrintVal" << std::endl;
        return;
    }
    std::cout << "MyVarPtr : " << *VariablePtr << std::endl;
  }
  void Delete(void) {
    if (VariablePtr == nullptr){
        std::cout << "MyVarPtr : It's nullptr, probably deleted already. so didn't repeat Delete" << std::endl;
        return;
    }
    delete VariablePtr;
    VariablePtr = {};
  }
  void ExhaustMemory(void){
    int cycle {0};
    while (1){
        cycle++;
        try{
            int *BigAlloc = new int[1200000000]; 
        }catch (std::exception& ex){
            std::cout << "Out of memory on loop:" << cycle << std::endl;
            break;
        }
    }
  }
  void ExhaustMemoryNoThrow(void){
    int cycle {0};
    while (1){
        cycle++;
        int *BigAlloc = new (std::nothrow) int[1200000000]; 
        if (BigAlloc == nullptr){
            std::cout << "Out of memory on loop:" << cycle << std::endl;
            break;
        }
    }
  }

private:
  int *VariablePtr {};
};

class StringStdClass {
public:
  //Constuctors
  StringStdClass() = default; //we set a default constructor, not required but done anyway. Good practice if want to add more non default constructors
  void StringStd(void) {
    planet = std::string{"Earth. Where the sky is blue"};//Initialize with string literal
	  prefered_planet = std::string{planet};//Initialize with other existing string
    message = std::string{"Hello there",5};	//Initialize with part of a string literal.
		//Contains hello
    //std::string weird_message;
    weird_message=std::string(4,'e');//Initialize with multiple copies of a char
		// contains eeee
    greeting = std::string{"Hello World"};
    saying_hello = std::string{ greeting,6,5};//Initialize with part of an existing std::string
  }
  void StringStdPrt(void) {
    std::cout << "full_name : " << full_name << std::endl;
	  std::cout << "planet : " << planet << std::endl;
	  std::cout << "prefered_planet : " << prefered_planet << std::endl;
	  std::cout << "message : " << message << std::endl;
	  std::cout << "weird_message : " << weird_message << std::endl;
	  std::cout << "greeting : " << greeting << std::endl;
	  std::cout << "saying_hello : " << saying_hello << std::endl;

    //Changing std::string at runtime, automatically free and reallocate
    planet = "Earth. Where the sky is blue Earth. Where the sky is blue Earth. Where ";
    std::cout << "planet : " << planet << std::endl;
  }
private:
  std::string full_name;//Empty string
  std::string planet;
  std::string prefered_planet;
  std::string message;
  std::string weird_message;
  std::string greeting;
  std::string saying_hello;
};

int main() {
    //bonus 
    int First {13};
    int Second {17};
    Ternary_operator(First, Second);
    //Same but OO
    ValueComparator comparator; // Create an object of ValueComparator
    StringStdClass StringStd;
    comparator.findMax(First,Second); 
    comparator.printResult(First,Second);
    comparator.printResultX();

    //Strings
    StringManipulator stringex; //Create object
    stringex.CString();
    stringex.PtrString();
    stringex.PtrStringHeap();
    //return 0;
    stringex.StringFun();
    //using new and delete
    stringex.CreateWithNew();
    stringex.PrintVal();
    stringex.Delete();
    stringex.PrintVal();
    stringex.Delete();
    //stringex.ExhaustMemory();
    stringex.ExhaustMemoryNoThrow();
    StringStd.StringStd();
    StringStd.StringStdPrt();

    Person *pPerson = (Person*) malloc(sizeof(Person));
    if (NULL == pPerson){
      puts("malloc failure");
      return -1;
    }
    // Fill the allocated memory with example data
    //typedef struct {
    //  int id;
    //  char name[64];
    //} Person;
    pPerson->id = 12345; // Set the ID
    strncpy(pPerson->name, "John Doe", sizeof(pPerson->name) - 1);
    pPerson->name[sizeof(pPerson->name) - 1] = '\0'; // Ensure null termination
  
    // Print the example data
    printf("Person Info:\n");
    printf("ID: %d\n", pPerson->id);
    printf("Name: %s\n", pPerson->name);
    free(pPerson);
    return 0;
}

