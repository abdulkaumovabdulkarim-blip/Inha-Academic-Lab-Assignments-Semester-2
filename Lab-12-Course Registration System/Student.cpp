#include "Student.h"
#include <QStringList>

Student::Student(){}
Student::Student(QString name, QString id, QString course,
    int credits, int semester)
    : name(name), id(id), course(course),
    credits(credits), semester(semester)
{
}

QString Student::toLine()
{
    return name + "|" + id + "|" + course + "|" +
        QString::number(credits) + "|" + QString::number(semester);
}

Student Student::fromLine(const QString& line)
{
    QStringList parts = line.split("|");

    if (parts.size() != 5) {
        return Student();
    }
    int credits = parts[3].toInt();
    int semester = parts[4].toInt();
    return Student(parts[0], parts[1], parts[2], credits, semester);
}
