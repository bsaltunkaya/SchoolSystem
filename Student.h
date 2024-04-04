//
// Created by Bekir Sadık Altunkaya on 20.03.2024.
//

#ifndef SCHOOLSYSTEM_STUDENT_H
#define SCHOOLSYSTEM_STUDENT_H

#include <iostream>
#include <string>
#include "Course.h"

namespace PA3
{
    class Course;//added to prevent circ. dep.
    class Student {
    private:
        int id;
        std::string name;
        Course** courses;
        int courseCount;
        int courseCapacity;
        static int studentCount;

    public:
//some getters and setters defined even not used, good practice IMO

        Student();

        Student(int newId, std::string newName);

        ~Student();

        int getId() const{return id;}

        void setId(int newId){id=newId;}

        const std::string &getName() const{return name;}

        void setName(const std::string &newName){name=newName;}

        static int getStudentCount(){return studentCount;}



        int getCourseCount() const{return courseCount;}

        int getCourseCapacity() const{return courseCapacity;}

        void setCourseCapacity(int newCourseCapacity){courseCapacity=newCourseCapacity;}

        void setCourseCount(int newCourseCount){courseCount=newCourseCount;}
        Course** getCourses() const{return courses;}
        void setCourses(Course** newCourses){courses=newCourses;}
    };
}



#endif //SCHOOLSYSTEM_STUDENT_H
