#include "RegistrationWindow.h"
#include <QMessageBox>
#include "Student.h"

RegistrationWindow::RegistrationWindow(QWidget* parent) : QMainWindow(parent) {
    ui.setupUi(this);
    this->setWindowTitle("Student Registration"); 
}

void RegistrationWindow::on_btnRegister_clicked() {
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
    if (credits <= 0) {
        QMessageBox::critical(this, "Error", "Credits must be a positive number.");
        return;
    }

    int semester = semStr.toInt();
    if (semester < 1 || semester > 8) {
        QMessageBox::critical(this, "Error", "Semester must be from 1 to 8.");
        return;
    }

    Student s;
    s.name = name;
    s.id = id;
    s.course = course;
    s.credits = credits;
    s.semester = semester;

    QMessageBox::information(this, "Registration Successful", "Student registered successfully.");
    ui.label_3->setText(s.summary());
}

void RegistrationWindow::on_btnClear_clicked() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Clear Form", "Are you sure you want to clear?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        ui.lineEdit->clear();
        ui.lineEdit_2->clear();
        ui.lineEdit_3->clear();
        ui.lineEdit_4->clear();
        ui.lineEdit_5->clear();
        ui.label_3->clear();
        ui.lineEdit->setFocus();
    }
}