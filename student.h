#ifndef STUDENT_H
#define STUDENT_H
#include <QString>

class Student
{
public:
    Student(int id, QString fio, int age, QString group);
    Student();
    int id;
    QString fio;
    int age;
    QString group;

};

#endif // STUDENT_H
