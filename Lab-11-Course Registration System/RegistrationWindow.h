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
	void on_btnRegister_clicked(); 
	void on_btnClear_clicked();    
private:
	Ui::RegistrationWindowClass ui;
};

