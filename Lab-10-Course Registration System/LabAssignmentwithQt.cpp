// LabAssignmentiwithQt.cpp

#include "LabAssignmentwithQt.h"

LabAssignmentwithQt::LabAssignmentwithQt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}
LabAssignmentwithQt::~LabAssignmentwithQt(){}

void LabAssignmentwithQt::on_pushButton_clicked() {
    QString name = ui.lineEdit->text();
    QString id = ui.lineEdit_2->text();
    QString course = ui.lineEdit_3->text();
    QString credit = ui.lineEdit_4->text();
    QString semester = ui.lineEdit_5->text();

    if (name.isEmpty() || id.isEmpty() || course.isEmpty() || credit.isEmpty() || semester.isEmpty()) {
        ui.label_6->setText("Error: Please fill in all fields");
        return;
    }

    ui.label_6->setText("Name: " + name + "\nId: " + id + "\nCourse: " + course + "\nCredit: " + credit + "\nSemester: " + semester + "Status: Registration successful");
}

void LabAssignmentwithQt::on_pushButton_2_clicked() {

    ui.lineEdit->clear();
    ui.lineEdit_2->clear();
    ui.lineEdit_3->clear();
    ui.lineEdit_4->clear();
    ui.lineEdit_5->clear();
    ui.label_6->clear();

    ui.lineEdit->setFocus();
}

