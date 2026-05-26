#pragma once
#include <QString>

class Student {
public:
    QString name;
    QString id;
    QString course;
    int credits;
    int semester;

    Student();
    Student(QString name, QString id, QString course,
        int credits, int semester);
    QString toLine();
    static Student fromLine(const QString& line);
};
