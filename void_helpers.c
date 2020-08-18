#include <stdio.h>
#include <stdlib.h>
#include "void_helpers.h"

int Compare_age(void* a, void* b){
  Student* one = (Student*)a;
  Student* two = (Student*)b;
return(one->age - two->age);
}

void Print(void* s){
  Student* student = (Student*)s;
  printf("ID: %d, Age: %d", student->student_id, student->age);
}
