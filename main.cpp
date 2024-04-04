#include "SchoolManagerSystem.h"
#include "Student.h"
#include "Course.h"
int main() {
  //initialize the object to run the system
  PA3::SchoolManagerSystem SchoolManagerSystem(10, 10);

  // run menu
  SchoolManagerSystem.run();

  return 0;
}