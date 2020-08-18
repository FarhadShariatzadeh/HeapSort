#include <stdio.h>
#include <stdlib.h>


typedef struct{ 
  int student_id; 
  int age; 
} Student;

int Compare_age(void* a, void* b);
void Print(void* s);
