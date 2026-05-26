#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_LabAssignment11withQt.h"

class LabAssignment11withQt : public QMainWindow {
    Q_OBJECT

public:
    LabAssignment11withQt(QWidget* parent = nullptr);

private slots:
    void on_pushButton_clicked();
private:
    Ui::LabAssignment11withQtClass ui;
};