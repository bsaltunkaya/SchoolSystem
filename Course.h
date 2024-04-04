//
// Created by Bekir Sadık Altunkaya on 20.03.2024.
//

#ifndef SCHOOLSYSTEM_COURSE_H
#define SCHOOLSYSTEM_COURSE_H

#include <iostream>
#include <string>
#include "Student.h"
namespace PA3
{
    class Student;//to prevent circ. depend.
    class Course {
    private:
        std::string code;
        std::string name;
        Student** students;
        int studentCount;
        int studentCapacity;



    public:
//some getters and setters defined even not used, good practice IMO
        Course();

        Course(const std::string &newCode, const std::string &newName);

        ~Course();

        const std::string &getCode() const{return code;}

        void setCode(const std::string &newCode){code=newCode;}

        const std::string &getName() const{return name;}

        void setName(const std::string &newName){name = newName;}

        void PrintAllStudentsOfCourse();
        int getStudentCount() const{return studentCount;}
        void setStudentCount(int newStudentCount){studentCount=newStudentCount;}
        Student** getStudents() const{return students;}
        void setStudents(Student** newStudents){students=newStudents;}
        int getStudentCapacity() const{return studentCapacity;}
        void setStudentCapacity(int newStudentCapacity){studentCapacity=newStudentCapacity;}



    };
}

#endif //SCHOOLSYSTEM_COURSE_H
