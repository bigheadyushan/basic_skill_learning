#ifndef BASIC_SKILL_LEARNING_DESIGN_PATTERN_DECORATOR_PATTERN_H
#define BASIC_SKILL_LEARNING_DESIGN_PATTERN_DECORATOR_PATTERN_H

#include <iostream>

namespace design_pattern {
/*
装饰器模式是为了实现动态的给对象添加智能
*/

class Student {
public:
    Student() {}
    Student(std::string a_name):name(a_name) {}
    virtual void show() = 0;
    std::string name;
};

class StudentDecorator: public Student {
public:
    StudentDecorator(std::string a_name, Student* student):
    _student(student), Student(a_name) {}
    virtual void show() {
        if (_student) {
            std::cout<<_student->name<<std::endl;
        }
    };
protected:
    Student* _student;
};

class Pupil: public Student {
public:
    Pupil():Student("Pupil") {}
    void show() {
        std::cout<<"I am a "<<name<<std::endl;    
    }
};

class MiddleStudent: public StudentDecorator {
public:
    MiddleStudent(Student* student):
        StudentDecorator("MiddleStudent", student) {
        if (student) {
            name = "MiddleStudent " + student->name; 
        }
    }
    void show() {
        std::cout<<"I am a "<<name<<std::endl;
    }
};

class CollegeStudent: public StudentDecorator {
public:
    CollegeStudent(Student* student):
        StudentDecorator("ColllegeStudent", student) {
        if (student) {
            name = "CollegeStudent " + student->name;
        }
    }
    void show() {
        std::cout<<"I am a "<<name<<std::endl;
    }
};


} // namespace design_pattern
#endif //BASIC_SKILL_LEARNING_DESIGN_PATTERN_DECORATOR_PATTERN_H
