#include "RegistrationWindow.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include "Student.h"
#include "QtWidgetsClass.h"

RegistrationWindow::RegistrationWindow(QWidget* parent) : QMainWindow(parent) {
    ui.setupUi(this);
    this->setWindowTitle("Student Registration"); 
}

void RegistrationWindow::on_pushButton_clicked() {
    QString name = ui.lineEdit->text().trimmed();
    QString id = ui.lineEdit_2->text().trimmed();
    QString course = ui.lineEdit_3->text().trimmed();
    QString creditsStr = ui.lineEdit_3->text().trimmed();
    QString semStr = ui.lineEdit_4->text().trimmed();

    if (name.isEmpty() || id.isEmpty() || course.isEmpty() || creditsStr.isEmpty() || semStr.isEmpty()) {
        QMessageBox::warning(this, "Missing Data", "Please fill in all fields.");
        return;
    }

    int credits = creditsStr.toInt();
    /*if (credits <= 0) {
        QMessageBox::critical(this, "Error", "Credits must be a positive number.");
        return;
    }*/

    int semester = semStr.toInt();
    if (semester < 1 || semester > 8) {
        QMessageBox::critical(this, "Error", "Semester must be from 1 to 8.");
        return;
    }

    QFile file("students.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Cannot open students.txt for writing.");
        return;
    }

    Student student(name, id, course, credits, semester);
    QTextStream out(&file);
    out << student.toLine() << '\n';

    file.close();

    QMessageBox::information(this, "Saved", "Saved successfully");

    ui.lineEdit->clear();
    ui.lineEdit_2->clear();
    ui.lineEdit_3->clear();
    ui.lineEdit_4->clear();
    ui.lineEdit_5->clear();
}

void RegistrationWindow::on_pushButton_2_clicked() {
    QtWidgetsClass* loadWin = new QtWidgetsClass();
    loadWin->show();
    this->close();
}