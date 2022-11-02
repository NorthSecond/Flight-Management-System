#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FlightManagement.h"

class FlightManagement : public QMainWindow
{
    Q_OBJECT

public:
    FlightManagement(QWidget *parent = nullptr);
    ~FlightManagement();

private:
    Ui::FlightManagementClass ui;

public slots:
	void searchFlight();
	void management();
	void exit();
};
