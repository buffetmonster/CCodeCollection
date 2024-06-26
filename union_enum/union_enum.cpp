#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Define an enum for data types
enum data_type { INT_TYPE, FLOAT_TYPE, STRING_TYPE };

// Define a struct that includes the union and a type indicator
struct Data {
  union {
    int i;
    float f;
    char str[20];
  } value;
  enum data_type type;
  int a=1;
};

// Function to determine data type stored in the struct
void getDataType(struct Data* data, char* type) {
  switch (data->type) {
    case INT_TYPE:
      strcpy(type, "int");
      break;
    case FLOAT_TYPE:
      strcpy(type, "float");
      break;
    case STRING_TYPE:
      strcpy(type, "char array");
      break;
    default:
      strcpy(type, "unknown");
      break;
  }
}

int main() {
  struct Data data;
  char dataType[20];

  // Accessing members
  data.value.i = 100;
  data.type = INT_TYPE;
  printf("Integer value: %d\n", data.value.i);

  // Assigning a float value (overwrites integer)
  data.value.f = 3.14;
  data.type = FLOAT_TYPE;
  printf("Float value: %f\n", data.value.f);

  // Assigning a string (overwrites float)
  strcpy(data.value.str, "Hello world");
  data.type = STRING_TYPE;
  printf("String value: %s\n", data.value.str);

  // Determine and print data types
  data.value.i = 100;
  data.type = INT_TYPE;
  getDataType(&data, dataType);
  printf("Integer value: %d (type: %s)\n", data.value.i, dataType);

  data.value.f = 3.14;
  data.type = FLOAT_TYPE;
  getDataType(&data, dataType);
  printf("Float value: %f (type: %s)\n", data.value.f, dataType);

  strcpy(data.value.str, "Hello world");
  data.type = STRING_TYPE;
  getDataType(&data, dataType);
  printf("String value: %s (type: %s)\n", data.value.str, dataType);

  return 0;
}