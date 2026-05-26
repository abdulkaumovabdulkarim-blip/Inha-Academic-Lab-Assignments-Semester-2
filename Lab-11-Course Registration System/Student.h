#pragma once
#include <QString>

class Student {
public:
    QString name;
    QString id;
    QString course;
    int credits;
    int semester;

    QString summary() const {
        return "Registered Student:\n"
            "Name: " + name + "\n"
            "ID: " + id + "\n"
            "Course: " + course + "\n"
            "Credits: " + QString::number(credits) + "\n"
            "Semester: " + QString::number(semester);
    }
};