//
// Created by Bekir Sadık Altunkaya on 20.03.2024.
//
#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
#include "SchoolManagerSystem.h"

namespace PA3 {


    SchoolManagerSystem::SchoolManagerSystem(int beginningStudentCapacity, int beginningCourseCapacity)
    //constructor for system
    {
      students = new Student *[beginningStudentCapacity];//init arrays for students and courses
      numStudents = 0;
      capacityStudents = beginningStudentCapacity;
      courses = new Course *[beginningCourseCapacity];
      numCourses = 0;
      capacityCourses = beginningCourseCapacity;
      //fill arrays with blanks first
      for (int i = 0; i < capacityStudents; i++)
      {
        students[i] = nullptr;
      }
      for (int i = 0; i < capacityCourses; i++)
      {
        courses[i] = nullptr;
      }
    }

    void SchoolManagerSystem::AddStudent(int id, std::string name)
    {

      if (numStudents == capacityStudents)//if the student array is full
      {

        capacityStudents *= 2;
        Student** newStudents = new Student*[capacityStudents];
        for (int i = 0; i < numStudents; i++)
        {
          newStudents[i] = students[i];
        }
        delete[] students;
        students = newStudents;
      }

      students[numStudents] = new Student(id, name);
      numStudents++;
    }
    void SchoolManagerSystem::AddCourse(const std::string &code, const std::string &name)
    {

      if (numCourses == capacityCourses)//if the course array is full
      {

        capacityCourses *= 2;
        Course** newCourses = new Course*[capacityCourses];
        for (int i = 0; i < numCourses; i++) {
          newCourses[i] = courses[i];
        }
        delete[] courses;
        courses = newCourses;
      }

      courses[numCourses] = new Course(code, name);
      numCourses++;
    }
}
//following two functions dont require you to be a rocket scientist or need any comments at all
void PA3::SchoolManagerSystem::PrintAllStudents()
{
  for (int i = 0; i < numStudents; i++)
  {
    std::cout << students[i]->getId() << " " << students[i]->getName() <<"\n";
  }
}

void PA3::SchoolManagerSystem::PrintAllCourses() {
  for (int i = 0; i < numCourses; i++) {
    std::cout << courses[i]->getCode() << " " << courses[i]->getName() << "\n";
  }
}


void PA3::SchoolManagerSystem::EnrollStudentToCourse(Student& student, Course& course) {
  // check if student has enough capacity
  if (student.getCourseCount() >= student.getCourseCapacity()) {
    //resize the student array if necessary
    student.setCourseCapacity(student.getCourseCapacity() * 2);
    Course** newCourses = new Course*[student.getCourseCapacity()];
    for (int i = 0; i < student.getCourseCount(); i++) {
      newCourses[i] = student.getCourses()[i];
    }
    delete[] student.getCourses();
    student.setCourses(newCourses);
  }

  // enroll
  student.getCourses()[student.getCourseCount()] = &course;
  student.setCourseCount(student.getCourseCount() + 1);

  // check course capacity
  if (course.getStudentCount() >= course.getStudentCapacity()) {
    // resize when needed
    course.setStudentCapacity(course.getStudentCapacity() * 2);
    Student** newStudents = new Student*[course.getStudentCapacity()];
    for (int i = 0; i < course.getStudentCount(); i++) {
      newStudents[i] = course.getStudents()[i];
    }
    delete[] course.getStudents();
    course.setStudents(newStudents);
  }

  // enroll
  course.getStudents()[course.getStudentCount()] = &student;
  course.setStudentCount(course.getStudentCount() + 1);
}

void PA3::SchoolManagerSystem::run() {
  int choice;
  std::cout<<"Main_menu\n";
  do {
    std::cout << "0 exit\n1 student\n2 course\n3 list_all_students\n4 list_all_courses\n>> ";
    std::cin >> choice;
    switch (choice) {
      case 0:
        // exit
        break;
      case 1:
        // call student menu
        Student_menu();
        break;
      case 2:
        // call course menu
        Course_menu();
        break;
      case 3:
        // call the list_all_students
        PrintAllStudents();
        break;
      case 4:
        // call the list_all_courses
        PrintAllCourses();
        break;
      default:
       //no error message is given because the user can see the menu
        break;
    }
  } while (choice != 0);
}

void PA3::SchoolManagerSystem::Student_menu() {
  int choice;
  while (true) {
    std::cout << "0 up\n1 add_student\n2 select_student\n>> ";
    std::cin >> choice;
    switch (choice) {
      case 0:
        // go back
        return;
      case 1: {
        // add student
        std::cout<<">> ";
        std::string input, name;
        int id;

        std::cin.ignore();//complicated string operations were researched and used
                          //in this assignment because the input method was unnecessarily complicated
        std::getline(std::cin, input);


        size_t pos = input.rfind(' ');
        if (pos != std::string::npos) {

          name = input.substr(0, pos);
          id = std::stoi(input.substr(pos+1));
        }

        AddStudent(id, name);
        break;
      }

      case 2: {


        std::string input, name;
        int id;
        //same logic with case 1
        std::cin.ignore();
        std::getline(std::cin, input);


        size_t pos = input.rfind(' ');
        if (pos != std::string::npos) {

          name = input.substr(0, pos);
          id = std::stoi(input.substr(pos+1));
        }

        Student* studentPtr = FindStudentById(id);
        while (studentPtr == nullptr || studentPtr->getName() != name) {
          std::getline(std::cin, input);
          pos = input.rfind(' ');
          if (pos != std::string::npos) {
            name = input.substr(0, pos);
            id = std::stoi(input.substr(pos+1));
          }
          studentPtr = FindStudentById(id);
        }
        SelectStudentMenu(*studentPtr);
        break;
      }
      default:
        //no error
        break;
    }
  }
}
void PA3::SchoolManagerSystem::SelectStudentMenu(Student& student) {
  int choice;
  while (true) {
    std::cout << "0 up\n1 delete_student\n3 add_selected_student_to_a_course\n4 drop_selected_student_from_a_course\n>> ";
    std::cin >> choice;
    switch (choice) {
      case 0:
        // go back to the course menu
        return;
      case 1: {
        // delete student
        DeleteStudent(student);
        Student_menu();
        return;
      }
      case 3: {
        // Add selected student to a course
        std::cout << "0 up\n";
        for (int i = 0; i < numCourses; i++) {
          std::cout << i+1 << " " << courses[i]->getCode() << " " << courses[i]->getName() << "\n";
        }
        int courseNumber;
        std::cout<<">> ";
        std::cin >> courseNumber;
        if (courseNumber == 0) {
          // Go back to the select student menu
          return;
        }
        Course& course = *courses[courseNumber-1];
        EnrollStudentToCourse(student, course);
        break;
      }
      case 4: {
        // Drop selected student from a course
        std::cout << "0 up\n";
        for (int i = 0; i < student.getCourseCount(); i++) {
          std::cout << i+1 << " " << student.getCourses()[i]->getCode() << " " << student.getCourses()[i]->getName() << "\n";
        }
        int courseNumber;
        std::cin >> courseNumber;
        if (courseNumber == 0) {
          // Go back to the select student menu
          return;
        }
        Course& course = *student.getCourses()[courseNumber-1];
        DropStudentFromCourse(student, course);
        break;
      }
      default:

        break;
    }
  }
}

void PA3::SchoolManagerSystem::Course_menu() {
  int choice;
  while (true) {
    std::cout << "0 up\n1 add_course\n2 select_course\n>> ";
    std::cin >> choice;
    switch (choice) {
      case 0:
        return;
      case 1: {
        std::cout<<">> ";
        std::string code, name;

        std::cin >> code;
        std::cin.ignore();
        std::getline(std::cin, name);
        AddCourse(code, name);
        break;
      }

      case 2: {
        PrintAllCourses();
        std::cout<<">> ";
        std::string input, code, name;
        std::cin.ignore();
        std::getline(std::cin, input);

        size_t pos = input.rfind(' ');
        if (pos != std::string::npos) {
          code = input.substr(0, pos);
          name = input.substr(pos+1);
        }

        Course* coursePtr = FindCourseByCode(code);
        while (coursePtr == nullptr || coursePtr->getName() != name) {
          std::getline(std::cin, input);
          pos = input.rfind(' ');
          if (pos != std::string::npos) {
            code = input.substr(0, pos);
            name = input.substr(pos+1);
          }
          coursePtr = FindCourseByCode(code);
        }
        SelectCourseMenu(*coursePtr);
        break;
      }
      default:
        //no error message
        break;
    }
  }
}
void PA3::SchoolManagerSystem::SelectCourseMenu(Course& course) {
  int choice;
  while (true) {
    std::cout << "0 up\n1 delete_course\n2 list_students_registered_to_the_selected_course\n>> ";
    std::cin >> choice;
    switch (choice) {
      case 0:
        return;
      case 1: {
        DeleteCourse(course);
        Course_menu();
        return;
      }
      case 2: {
        course.PrintAllStudentsOfCourse();
        break;
      }
      default:
        //no error message

        break;
    }
  }
}
void PA3::SchoolManagerSystem::DeleteStudent(Student& student)
{
for (int i = 0; i < numStudents; i++)
{
if (students[i]->getId() == student.getId())
{
delete students[i];
students[i] = students[numStudents - 1];
students[numStudents - 1] = nullptr;
numStudents--;
break;
}
}
}
void PA3::SchoolManagerSystem::DeleteCourse(Course& course) {
  for (int i = 0; i < numCourses; i++) {
    if (courses[i]->getCode() == course.getCode()) {
      delete courses[i];
      courses[i] = courses[numCourses - 1];
      courses[numCourses - 1] = nullptr;
      numCourses--;
      break;
    }
  }
}
PA3::Student* PA3::SchoolManagerSystem::FindStudentById(int id) {
  for (int i = 0; i < numStudents; i++) {
    if (students[i]->getId() == id) {
      return students[i];
    }
  }
  return nullptr;
}
PA3::Course* PA3::SchoolManagerSystem::FindCourseByCode(const std::string& code) {
  for (int i = 0; i < numCourses; i++) {
    if (courses[i]->getCode() == code) {
      return courses[i];
    }
  }
  return nullptr;
}


void PA3::SchoolManagerSystem::DropStudentFromCourse(Student& student, Course& course) {
  // remove the course from the student's list of courses
  for (int i = 0; i < student.getCourseCount(); i++) {
    if (student.getCourses()[i]->getCode() == course.getCode()) {
      student.getCourses()[i] = student.getCourses()[student.getCourseCount() - 1];
      student.getCourses()[student.getCourseCount() - 1] = nullptr;
      student.setCourseCount(student.getCourseCount() - 1);
      break;
    }
  }

  // remove the student from the course's list of students
  for (int i = 0; i < course.getStudentCount(); i++) {
    if (course.getStudents()[i]->getId() == student.getId()) {
      course.getStudents()[i] = course.getStudents()[course.getStudentCount() - 1];
      course.getStudents()[course.getStudentCount() - 1] = nullptr;
      course.setStudentCount(course.getStudentCount() - 1);
      break;
    }
  }
}


