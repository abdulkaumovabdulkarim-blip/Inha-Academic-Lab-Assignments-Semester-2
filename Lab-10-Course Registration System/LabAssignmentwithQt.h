#pragma once

// LabAssignmentwithQt.h

#include <QtWidgets/QMainWindow>
#include "ui_LabAssignmentwithQt.h"

class LabAssignmentwithQt : public QMainWindow
{
    Q_OBJECT

public:
    LabAssignmentwithQt(QWidget *parent = nullptr);
    ~LabAssignmentwithQt();

private slots:
    void on_pushButton_clicked(); // Register
    void on_pushButton_2_clicked(); // Clear

private:
    Ui::LabAssignmentwithQtClass ui;
};

