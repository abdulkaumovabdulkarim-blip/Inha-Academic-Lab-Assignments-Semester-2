#include "QtWidgetsClass.h"
#include <QFile>
#include <QMessageBox>
#include "Student.h"



QtWidgetsClass::QtWidgetsClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QFile file("students.txt");

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::warning(this, "File Error",
			"Cannot open students.txt for reading.");
		return;
	}
	QTextStream in(&file);
	QString result;

	while (!in.atEnd())
	{
		QString line = in.readLine();
		Student student = Student::fromLine(line);
		result += student.name + " - " + student.course +
			" (" + QString::number(student.credits) + " credits)\n";
	}

	file.close();
	QString Result = "Registered Students!";
	ui.label->setText(Result);
	ui.label_2->setText(result);
}


QtWidgetsClass::~QtWidgetsClass()
{}

