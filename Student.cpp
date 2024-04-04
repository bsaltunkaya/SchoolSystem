//
// Created by Bekir Sadık Altunkaya on 20.03.2024.
//

#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

int PA3::Student::studentCount = 0;

namespace PA3
{
    Student::Student()
    {
        id = 0;
        name = "New Student";
        courseCount = 0;
        courseCapacity = 5;
        courses = new Course*[courseCapacity];
        studentCount++;
    }
    Student::Student(int newId,std::string newName)
    {
        id = newId;
        name = newName;
        courseCount = 0;
        courseCapacity = 5;
        courses = new Course*[courseCapacity];
        studentCount++;
    }
    Student::~Student()
    {
        delete[] courses;
        studentCount--;
    }


}
