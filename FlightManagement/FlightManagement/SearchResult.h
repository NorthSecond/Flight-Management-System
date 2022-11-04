#pragma once

#include <QWidget>
#include <QLabel>
#include <QMessagebox>
#include <QTableview>
#include <QLineedit>
#include <QDateedit>
#include <QPushbutton>
#include <QVector>
#include <QStandardItemModel>

#include "ui_SearchResult.h"
#include "FlightManagement.h"
#include "FlightInfo.h"
#include "DatabaseRepository.h"

class SearchResult : public QMainWindow
{
	Q_OBJECT

public:
	SearchResult(QWidget *parent = nullptr);
	~SearchResult();

private:
	Ui::SearchResultClass ui;

	DatabaseRepository dataRepo;
	
	QLabel* id_lbl;
	QLabel* from_lbl;
	QLabel* dst_lbl;
	QLabel* date_lbl;
	
	QLineEdit* id_edit;
	QLineEdit* from_edit;
	QLineEdit* dst_edit;
	QDateEdit* date_edit;
	
	QPushButton* search_btn;
	QPushButton* reset_btn;
	QPushButton* back_btn;
	QPushButton* exit_btn;

	QVector<FlightInfo> result;
	
	QStandardItemModel* mod;
	QTableView* table;
	
public slots:
	void onSearchResult();
	void onReset();
	void onBack();
	void onExit();
};
