#include "Management.h"


Management::Management(QWidget* parent)
	: QMainWindow(parent), dataRepo()
{
	ui.setupUi(this);
	
	// 设置高分采样
	//QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	//QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	
	// 设置管理界面尺寸
	this->setStyleSheet("background-color:white");
	this->setFixedSize(800, 600);
	this->setWindowTitle("Flight Management System");
	//this->setWindowIcon(QIcon("icon.png"));
	
	// 这里实时窗口的宽度和高度 防止寄掉
	size_t windowWidth = this->frameGeometry().width();
	size_t windowHeight = this->frameGeometry().height();
	
	// 管理界面分为上下两部分
	// 上部分是查询界面，下部分是一个tableview
	
	// 上部分的查询界面
	id_lbl = new QLabel(this);
	id_lbl->setText("Flight ID");
	id_lbl->setGeometry(50, 50, 100, 30);
	
	id_le = new QLineEdit(this);
	id_le->setGeometry(150, 50, 100, 30);
	
	depart_lbl = new QLabel(this);
	depart_lbl->setText("Departure");
	depart_lbl->setGeometry(50, 100, 100, 30);
	
	from_le = new QLineEdit(this);
	from_le->setGeometry(150, 100, 100, 30);
	
	dst_lbl = new QLabel(this);
	dst_lbl->setText("Destination");
	dst_lbl->setGeometry(50, 150, 100, 30);
	
	dst_le = new QLineEdit(this);
	dst_le->setGeometry(150, 150, 100, 30);
	
	days_lbl = new QLabel(this);
	days_lbl->setText("Date");
	days_lbl->setGeometry(50, 200, 100, 30);
	
	//TODO: 七个选择框
	/*date_de = new QDateEdit(this);
	date_de->setGeometry(150, 200, 100, 30);
	*/
	mon_cb = new QCheckBox(this);
	mon_cb->setText("Mon");
	mon_cb->setGeometry(150, 200, 50, 30);
	
	tue_cb = new QCheckBox(this);
	tue_cb->setText("Tue");
	tue_cb->setGeometry(200, 200, 50, 30);
	
	wed_cb = new QCheckBox(this);
	wed_cb->setText("Wed");
	wed_cb->setGeometry(250, 200, 50, 30);
	
	thu_cb = new QCheckBox(this);
	thu_cb->setText("Thu");
	thu_cb->setGeometry(300, 200, 50, 30);

	fri_cb = new QCheckBox(this);
	fri_cb->setText("Fri");
	fri_cb->setGeometry(350, 200, 50, 30);
	
	sat_cb = new QCheckBox(this);
	sat_cb->setText("Sat");
	sat_cb->setGeometry(400, 200, 50, 30);
	
	sun_cb = new QCheckBox(this);
	sun_cb->setText("Sun");
	sun_cb->setGeometry(450, 200, 50, 30);
	
	depart_time_lbl = new QLabel(this);
	depart_time_lbl->setText("Departure Time");
	depart_time_lbl->setGeometry(50, 250, 100, 30);
	
	depart_time_le = new QLineEdit(this);
	depart_time_le->setGeometry(150, 250, 100, 30);
	
	arrive_time_lbl = new QLabel(this);
	arrive_time_lbl->setText("Arrival Time");
	arrive_time_lbl->setGeometry(50, 300, 100, 30);
	
	arrive_time_le = new QLineEdit(this);
	arrive_time_le->setGeometry(150, 300, 100, 30);
	
	status_lbl = new QLabel(this);
	status_lbl->setText("Status");
	status_lbl->setGeometry(50, 350, 100, 30);
	
	status_le = new QLineEdit(this);
	status_le->setGeometry(150, 350, 100, 30);
	
	type_lbl = new QLabel(this);
	type_lbl->setText("Type");
	type_lbl->setGeometry(50, 400, 100, 30);
	
	type_le = new QLineEdit(this);
	type_le->setGeometry(150, 400, 100, 30);

	aircraft_lbl = new QLabel(this);
	aircraft_lbl->setText("Aircraft");
	aircraft_lbl->setGeometry(50, 450, 100, 30);
	
	aircraft_le = new QLineEdit(this);
	aircraft_le->setGeometry(150, 450, 100, 30);

	// 查询按钮
	search_btn = new QPushButton(this);
	search_btn->setText("Search");
	search_btn->setGeometry(50, 500, 100, 30);
	
	insert_btn = new QPushButton(this);
	insert_btn->setText("Insert");
	insert_btn->setGeometry(200, 500, 100, 30);

	update_btn = new QPushButton(this);
	update_btn->setText("Update");
	update_btn->setGeometry(350, 500, 100, 30);
	
	back_btn = new QPushButton(this);
	back_btn->setText("Back");
	back_btn->setGeometry(500, 500, 100, 30);
	
	

	mod = new QStandardItemModel();
	mod->setHorizontalHeaderItem(0, new QStandardItem("Flight ID"));
	mod->setHorizontalHeaderItem(1, new QStandardItem("Departure"));
	mod->setHorizontalHeaderItem(2, new QStandardItem("Destination"));
	mod->setHorizontalHeaderItem(3, new QStandardItem("Mon"));
	mod->setHorizontalHeaderItem(4, new QStandardItem("Tue"));
	mod->setHorizontalHeaderItem(5, new QStandardItem("Wed"));
	mod->setHorizontalHeaderItem(6, new QStandardItem("Thu"));
	mod->setHorizontalHeaderItem(7, new QStandardItem("Fri"));
	mod->setHorizontalHeaderItem(8, new QStandardItem("Sat"));
	mod->setHorizontalHeaderItem(9, new QStandardItem("Sun"));
	mod->setHorizontalHeaderItem(10, new QStandardItem("Departure Time"));
	mod->setHorizontalHeaderItem(11, new QStandardItem("Arrival Time"));
	mod->setHorizontalHeaderItem(12, new QStandardItem("Eco count"));
	mod->setHorizontalHeaderItem(13, new QStandardItem("Eco price"));
	mod->setHorizontalHeaderItem(14, new QStandardItem("Bus count"));
	mod->setHorizontalHeaderItem(15, new QStandardItem("Bus price"));
	mod->setHorizontalHeaderItem(16, new QStandardItem("First count"));
	mod->setHorizontalHeaderItem(17, new QStandardItem("First price"));
	mod->setHorizontalHeaderItem(18, new QStandardItem("Type"));
	mod->setHorizontalHeaderItem(19, new QStandardItem("Status"));
	mod->setHorizontalHeaderItem(20, new QStandardItem("Aircraft"));
	
	// 下部分的tableview
	// 设置tableview的列数
	table = new QTableView(this);
	table->setGeometry(300, 50, 400, 400);
	table->setModel(mod);
	
	connect(search_btn, &QPushButton::clicked, this, &Management::search_res);
	connect(insert_btn, &QPushButton::clicked, this, &Management::insert_record);
	connect(update_btn, &QPushButton::clicked, this, &Management::update_record);
	connect(back_btn, &QPushButton::clicked, this, &Management::back);	
}

Management::~Management()
{}

void Management::search_res()
{
	// 清空tableview
	mod->removeRows(0, mod->rowCount());

	// 获取输入的值
	QString flight_id = id_le->text();
	QString departure = from_le->text();
	QString destination = dst_le->text();
	QString depart_time = depart_time_le->text();
	QString arrive_time = arrive_time_le->text();
	QString status = status_le->text();
	QString type = type_le->text();
	QString aircraft = aircraft_le->text();

	// 获取checkbox的值
	QString mon = mon_cb->isChecked() ? "1" : "0";
	QString tue = tue_cb->isChecked() ? "1" : "0";
	QString wed = wed_cb->isChecked() ? "1" : "0";
	QString thu = thu_cb->isChecked() ? "1" : "0";
	QString fri = fri_cb->isChecked() ? "1" : "0";
	QString sat = sat_cb->isChecked() ? "1" : "0";
	QString sun = sun_cb->isChecked() ? "1" : "0";

	QSqlDatabase db = dataRepo.getDatabase();

	// 拼接sql语句
	QString sql = "select * from flight where 1=1";
	if (!flight_id.isEmpty())
	{
		sql += " and flight_id = '" + flight_id + "'";
	}
	if (!departure.isEmpty())
	{
		sql += " and departure = '" + departure + "'";
	}
	if (!destination.isEmpty())
	{
		sql += " and destination = '" + destination + "'";
	}
	if (!depart_time.isEmpty())
	{
		sql += " and depart_time = '" + depart_time + "'";
	}
	if (!arrive_time.isEmpty())
	{
		sql += " and arrive_time = '" + arrive_time + "'";
	}
	if (!status.isEmpty())
	{
		sql += " and status = '" + status + "'";
	}
	if (!type.isEmpty())
	{
		sql += " and type = '" + type + "'";
	}
	if (!aircraft.isEmpty())
	{
		sql += " and aircraft = '" + aircraft + "'";
	}
	if (mon == "1")
	{
		sql += " and mon = 1";
	}
	if (tue == "1")
	{
		sql += " and tue = 1";
	}
	if (wed == "1")
	{
		sql += " and wed = 1";
	}
	if (thu == "1")
	{
		sql += " and thu = 1";
	}
	if (fri == "1")
	{
		sql += " and fri = 1";
	}
	if (sat == "1")
	{
		sql += " and sat = 1";
	}
	if (sun == "1")
	{
		sql += " and sun = 1";
	}
	// TODO: 票价有关
	sql += ";";
	QSqlQuery query(db);
	query.prepare(sql);
	query.exec();
	int row = 0;
	while (query.next())
	{
		mod->setItem(row, 0, new QStandardItem(query.value(0).toString()));
		mod->setItem(row, 1, new QStandardItem(query.value(1).toString()));
		mod->setItem(row, 2, new QStandardItem(query.value(2).toString()));
		mod->setItem(row, 3, new QStandardItem(query.value(3).toString()));
		mod->setItem(row, 4, new QStandardItem(query.value(4).toString()));
		mod->setItem(row, 5, new QStandardItem(query.value(5).toString()));
		mod->setItem(row, 6, new QStandardItem(query.value(6).toString()));
		mod->setItem(row, 7, new QStandardItem(query.value(7).toString()));
		mod->setItem(row, 8, new QStandardItem(query.value(8).toString()));
		mod->setItem(row, 9, new QStandardItem(query.value(9).toString()));
		mod->setItem(row, 10, new QStandardItem(query.value(10).toString()));
		mod->setItem(row, 11, new QStandardItem(query.value(11).toString()));
		mod->setItem(row, 12, new QStandardItem(query.value(12).toString()));
		mod->setItem(row, 13, new QStandardItem(query.value(13).toString()));
		mod->setItem(row, 14, new QStandardItem(query.value(14).toString()));
		mod->setItem(row, 15, new QStandardItem(query.value(15).toString()));
		mod->setItem(row, 16, new QStandardItem(query.value(16).toString()));
		mod->setItem(row, 17, new QStandardItem(query.value(17).toString()));
		mod->setItem(row, 18, new QStandardItem(query.value(18).toString()));
		mod->setItem(row, 19, new QStandardItem(query.value(19).toString()));
		mod->setItem(row, 20, new QStandardItem(query.value(20).toString()));
		
		//mod->setItem(row, 15, new QStandardItem(query.value(15).toString()));
		row++;
	}
	
	update();
}

void Management::insert_record()
{
	// 获取输入的值
	QString flight_id = id_le->text();
	QString departure = from_le->text();
	QString destination = dst_le->text();
	QString depart_time = depart_time_le->text();
	QString arrive_time = arrive_time_le->text();
	QString status = status_le->text();
	QString type = type_le->text();
	QString aircraft = aircraft_le->text();

	// 获取checkbox的值
	QString mon = mon_cb->isChecked() ? "1" : "0";
	QString tue = tue_cb->isChecked() ? "1" : "0";
	QString wed = wed_cb->isChecked() ? "1" : "0";
	QString thu = thu_cb->isChecked() ? "1" : "0";
	QString fri = fri_cb->isChecked() ? "1" : "0";
	QString sat = sat_cb->isChecked() ? "1" : "0";
	QString sun = sun_cb->isChecked() ? "1" : "0";

	QSqlDatabase db = dataRepo.getDatabase();

	// 拼接sql语句
	QString sql = "insert into flight values ('" + flight_id + "', '" + departure + "', '" + destination + "', '" + depart_time + "', '" + arrive_time + "', '" + status + "', '" + type + "', '" + aircraft + "', " + mon + ", " + tue + ", " + wed + ", " + thu + ", " + fri + ", " + sat + ", " + sun + ");";
	QSqlQuery query(db);
	query.prepare(sql);
	query.exec();
	//query.exec(sql);
}

void Management::update_record()
{
	return;
}

void Management::back()
{
	FlightManagement* fm = new FlightManagement();
	fm->show();
	this->close();
}
