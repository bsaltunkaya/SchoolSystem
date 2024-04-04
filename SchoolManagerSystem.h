//
// Created by Bekir Sadık Altunkaya on 20.03.2024.
//

#ifndef SCHOOLSYSTEM_SCHOOLMANAGERSYSTEM_H
#define SCHOOLSYSTEM_SCHOOLMANAGERSYSTEM_H
#include <iostream>

namespace PA3
{
    class Student;//these two classes are declared here to prevent
    class Course; //circular dependancy issues
    class SchoolManagerSystem {
    private:
        Student ** students;//dynamic arrays for students and courses
        Course ** courses;
        int numStudents;//those 4 int variables are needed for memory management
        int numCourses;
        int capacityStudents;
        int capacityCourses;
        // preliminary functions for needed operations
        void AddStudent(int id, std::string name);
        void AddCourse(const std::string &code, const std::string &name);
        void EnrollStudentToCourse(Student& student, Course& course);
        void DropStudentFromCourse(Student& student, Course& course);
        void PrintAllStudents();
        void PrintAllCourses();
        void DeleteStudent(Student& student);
        void DeleteCourse(Course& course);
        //helper functions
        Student* FindStudentById(int id);
        Course* FindCourseByCode(const std::string &code);




    public:
        SchoolManagerSystem(int beginningStudentCapacity, int beginningCourseCapacity);
        //menu and run functions
        void run();
        void Student_menu();
        void Course_menu();
        void SelectStudentMenu(Student& student);
        void SelectCourseMenu(Course& course);
    };
}
#endif //SCHOOLSYSTEM_SCHOOLMANAGERSYSTEM_H
