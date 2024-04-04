//
// Created by Bekir Sadık Altunkaya on 20.03.2024.
//

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

namespace PA3
{
    Course::Course()
    {
        code = "ZZZ000";
        name = "New Course";
    }
    Course::Course(const std::string &newCode, const std::string &newName)
    {
        code = newCode;
        name = newName;

    }
    Course::~Course()
    {
      delete[] students;
    }

    void Course::PrintAllStudentsOfCourse() {
      for (int i = 0; i < studentCount; i++) {
        std::cout << students[i]->getId() << " " << students[i]->getName() << "\n";
      }
    }

}
