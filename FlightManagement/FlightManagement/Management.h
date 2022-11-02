#pragma once

#include <QMainWindow>
#include "ui_ManagementUI.h"

class Management : public QMainWindow
{
	Q_OBJECT

public:
	Management(QWidget *parent = nullptr);
	~Management();

private:
	Ui::ManagementClass ui;
};
