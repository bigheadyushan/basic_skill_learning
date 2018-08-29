#include "decorator_pattern.h"
using namespace design_pattern;
int main() {
    Pupil* pupil = new Pupil();
    pupil->show();
    StudentDecorator* middle_student = new MiddleStudent(pupil);
    middle_student->show();
    StudentDecorator* college_student = new CollegeStudent(middle_student);
    college_student->show();
    delete pupil;
    pupil = NULL;
    delete middle_student;
    middle_student = NULL;
    delete college_student;
    college_student = NULL;
    return 0;
}
