#include "LabAssignment11withQt.h"
#include "RegistrationWindow.h" 
#include <QMessageBox>

LabAssignment11withQt::LabAssignment11withQt(QWidget* parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
}

void LabAssignment11withQt::on_btnLogin_clicked() {
    QString user = ui.lineEdit->text().trimmed(); 
    QString pass = ui.lineEdit_2->text().trimmed(); 

    if (user == "admin" && pass == "12345") {

        RegistrationWindow* regWin = new RegistrationWindow();
        regWin->show();
        this->close();
    }
    else {
        QMessageBox::warning(this, "Invalid data", "Wrong password and username");
    }
}