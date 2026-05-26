#pragma once

#include <QMainWindow>
#include "ui_RegistrationWindow.h"

class RegistrationWindow : public QMainWindow
{
	Q_OBJECT

public:
	RegistrationWindow(QWidget *parent = nullptr);
	~RegistrationWindow(){}
private slots:
	void on_pushButton_clicked(); 
	void on_pushButton_2_clicked();    
private:
	Ui::RegistrationWindowClass ui;
};

