#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QTableview>
#include <QLineedit>
#include <QPushbutton>
#include <QDateEdit>
#include <QMessagebox>
#include <QVector>
#include <QCheckbox>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>

#include "ui_ManagementUI.h"
#include "FlightInfo.h"
#include "DatabaseRepository.h"
#include "FlightManagement.h"

class Management : public QMainWindow
{
	Q_OBJECT

public:
	Management(QWidget *parent = nullptr);
	~Management();
	
private:

	QLabel* id_lbl;
	QLabel* depart_lbl;
	QLabel* dst_lbl;
	QLabel* days_lbl;
	QLabel* depart_time_lbl;
	QLabel* arrive_time_lbl;
	QLabel* status_lbl;
	QLabel* type_lbl;
	//QLabel* seats_lbl;
	//QLabel* price_lbl;
	QLabel* aircraft_lbl;
	QLabel* eco_count_lbl;
	QLabel* eco_price_lbl;
	QLabel* bus_count_lbl;
	QLabel* bus_price_lbl;
	QLabel* first_count_lbl;
	QLabel* first_price_lbl;
	
	QLineEdit* id_le;
	QLineEdit* from_le;
	QLineEdit* dst_le;
	QLineEdit* depart_time_le;
	QLineEdit* arrive_time_le;
	//QLineEdit* seats_le;
	//QLineEdit* price_le;
	QLineEdit* aircraft_le;
	QLineEdit* status_le;
	QLineEdit* type_le;
	QLineEdit* eco_count_le;
	QLineEdit* eco_price_le;
	QLineEdit* bus_count_le;
	QLineEdit* bus_price_le;
	QLineEdit* first_count_le;
	QLineEdit* first_price_le; 
	
	QCheckBox* mon_cb;
	QCheckBox* tue_cb;
	QCheckBox* wed_cb;
	QCheckBox* thu_cb;
	QCheckBox* fri_cb;
	QCheckBox* sat_cb;
	QCheckBox* sun_cb;

	QPushButton* search_btn;
	QPushButton* insert_btn;
	QPushButton* update_btn;
	QPushButton* back_btn;

	QStandardItemModel* mod;
	QTableView* table;
	
private:
	Ui::ManagementClass ui;

	DatabaseRepository dataRepo;
	QVector<FlightInfo> infos;

public slots:
	void search_res();
	void insert_record();
	void update_record();
	void back();
};
