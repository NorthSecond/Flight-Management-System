#include "Management.h"


Management::Management(QWidget* parent)
	: QMainWindow(parent), dataRepo()
{
	ui.setupUi(this);
	
	// 设置高分采样
	//QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	//QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	
	// 设置管理界面尺寸
	//this->setStyleSheet("background-color:white");
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
	id_lbl->setGeometry(15, 10, 85, 30);
	
	id_le = new QLineEdit(this);
	id_le->setGeometry(100, 10, 100, 30);
	
	depart_lbl = new QLabel(this);
	depart_lbl->setText("Departure");
	depart_lbl->setGeometry(200, 10, 100, 30);
	
	from_le = new QLineEdit(this);
	from_le->setGeometry(300, 10, 100, 30);
	
	dst_lbl = new QLabel(this);
	dst_lbl->setText("Destination");
	dst_lbl->setGeometry(400, 10, 100, 30);
	
	dst_le = new QLineEdit(this);
	dst_le->setGeometry(500, 10, 100, 30);
	
	days_lbl = new QLabel(this);
	days_lbl->setText("Date");
	days_lbl->setGeometry(10, 150, 65, 30);
	
	//TODO: 七个选择框
	/*date_de = new QDateEdit(this);
	date_de->setGeometry(150, 200, 100, 30);
	*/
	mon_cb = new QCheckBox(this);
	mon_cb->setText("Mon");
	mon_cb->setGeometry(70, 150, 50, 30);
	
	tue_cb = new QCheckBox(this);
	tue_cb->setText("Tue");
	tue_cb->setGeometry(120, 150, 50, 30);
	
	wed_cb = new QCheckBox(this);
	wed_cb->setText("Wed");
	wed_cb->setGeometry(170, 150, 50, 30);
	
	thu_cb = new QCheckBox(this);
	thu_cb->setText("Thu");
	thu_cb->setGeometry(220, 150, 50, 30);

	fri_cb = new QCheckBox(this);
	fri_cb->setText("Fri");
	fri_cb->setGeometry(270, 150, 50, 30);
	
	sat_cb = new QCheckBox(this);
	sat_cb->setText("Sat");
	sat_cb->setGeometry(320, 150, 50, 30);
	
	sun_cb = new QCheckBox(this);
	sun_cb->setText("Sun");
	sun_cb->setGeometry(370, 150, 50, 30);
	
	depart_time_lbl = new QLabel(this);
	depart_time_lbl->setText("Departure Time");
	depart_time_lbl->setGeometry(15, 50, 75, 30);
	
	depart_time_le = new QLineEdit(this);
	depart_time_le->setGeometry(100, 50, 100, 30);
	
	arrive_time_lbl = new QLabel(this);
	arrive_time_lbl->setText("Arrival Time");
	arrive_time_lbl->setGeometry(200, 50, 100, 30);
	
	arrive_time_le = new QLineEdit(this);
	arrive_time_le->setGeometry(300, 50, 100, 30);
	
	status_lbl = new QLabel(this);
	status_lbl->setText("Status");
	status_lbl->setGeometry(600, 10, 100, 30);
	
	status_le = new QLineEdit(this);
	status_le->setGeometry(700, 10, 85, 30);
	
	type_lbl = new QLabel(this);
	type_lbl->setText("Type");
	type_lbl->setGeometry(400, 50, 100, 30);
	
	type_le = new QLineEdit(this);
	type_le->setGeometry(500, 50, 100, 30);

	aircraft_lbl = new QLabel(this);
	aircraft_lbl->setText("Aircraft");
	aircraft_lbl->setGeometry(600, 50, 100, 30);
	
	aircraft_le = new QLineEdit(this);
	aircraft_le->setGeometry(700, 50, 85, 30);

	// 各种类型的票数和价格
	eco_count_lbl = new QLabel(this);
	eco_count_lbl->setText("Eco Count");
	eco_count_lbl->setGeometry(10, 100, 70, 30);
	
	eco_count_le = new QLineEdit(this);
	eco_count_le->setGeometry(80, 100, 53, 30);
	
	eco_price_lbl = new QLabel(this);
	eco_price_lbl->setText("Eco Price");
	eco_price_lbl->setGeometry(133, 100, 70, 30);
	
	eco_price_le = new QLineEdit(this);
	eco_price_le->setGeometry(203, 100, 53, 30);
	
	bus_count_lbl = new QLabel(this);
	bus_count_lbl->setText("Busi Count");
	bus_count_lbl->setGeometry(256, 100, 70, 30);
	
	bus_count_le = new QLineEdit(this);
	bus_count_le->setGeometry(326, 100, 53, 30);
	
	bus_price_lbl = new QLabel(this);
	bus_price_lbl->setText("Busi Price");
	bus_price_lbl->setGeometry(379, 100, 70, 30);
	
	bus_price_le = new QLineEdit(this);
	bus_price_le->setGeometry(449, 100, 53, 30);
	
	first_count_lbl = new QLabel(this);
	first_count_lbl->setText("First Count");
	first_count_lbl->setGeometry(502, 100, 70, 30);
	
	first_count_le = new QLineEdit(this);
	first_count_le->setGeometry(572, 100, 53, 30);

	first_price_lbl = new QLabel(this);
	first_price_lbl->setText("First Price");
	first_price_lbl->setGeometry(625, 100, 70, 30);
	
	first_price_le = new QLineEdit(this);
	first_price_le->setGeometry(695, 100, 53, 30);
	
	
	// 查询按钮
	search_btn = new QPushButton(this);
	search_btn->setText("Search");
	search_btn->setGeometry(500, 150, 100, 30);
	
	insert_btn = new QPushButton(this);
	insert_btn->setText("Insert");
	insert_btn->setGeometry(650, 150, 100, 30);

	update_btn = new QPushButton(this);
	update_btn->setText("Update");
	update_btn->setGeometry(250, 560, 100, 30);
	
	back_btn = new QPushButton(this);
	back_btn->setText("Back");
	back_btn->setGeometry(550, 560, 100, 30);
	
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
	table->setGeometry(15, 215, 770, 350);
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
	QString eco_count = eco_count_le->text();
	QString eco_price = eco_price_le->text();
	QString bus_count = bus_count_le->text();
	QString bus_price = bus_price_le->text();
	QString first_count = first_count_le->text();
	QString first_price = first_price_le->text();

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
	QString sql = "select * from FlightInfo where 1=1";
	if (!flight_id.isEmpty())
		sql += " and flight_id = '" + flight_id + "'";
	if (!departure.isEmpty())
		sql += " and from_airport = '" + departure + "'";
	if (!destination.isEmpty())
		sql += " and dst_airport = '" + destination + "'";
	if (!depart_time.isEmpty())
		sql += " and departure_time = '" + depart_time + "'";
	if (!arrive_time.isEmpty())
		sql += " and arrival_time = '" + arrive_time + "'";
	if (!status.isEmpty())
		sql += " and status = '" + status + "'";
	if (!type.isEmpty())
		sql += " and type = '" + type + "'";
	if (!aircraft.isEmpty())
		sql += " and aircraft = '" + aircraft + "'";
	if (!eco_count.isEmpty())
		sql += " and economy_seats = '" + eco_count + "'";
	if (!eco_price.isEmpty())
		sql += " and economy_price = '" + eco_price + "'";
	if (!bus_count.isEmpty())
		sql += " and business_seats = '" + bus_count + "'";
	if (!bus_price.isEmpty())
		sql += " and business_price = '" + bus_price + "'";
	if (!first_count.isEmpty())
		sql += " and first_seats = '" + first_count + "'";
	if (!first_price.isEmpty())
		sql += " and first_price = '" + first_price + "'";
	if (mon == "1")
		sql += " and monday = 1";
	if (tue == "1")
		sql += " and tuesday = 1";
	if (wed == "1")
		sql += " and wednesday = 1";
	if (thu == "1")
		sql += " and thursday = 1";
	if (fri == "1")
		sql += " and friday = 1";
	if (sat == "1")
		sql += " and saturday = 1";
	if (sun == "1")
		sql += " and sunday = 1";
	sql += " order by flight_id;";
	// 执行sql语句
	QSqlQuery query(db);
	if (!query.exec(sql)) {
		// 如果执行失败，弹出错误信息
		QMessageBox::warning(this, "Error", "Search failed!");
		//return;
	}
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
		// 最后三个枚举类型
		switch (query.value(18).toInt())
		{
		case FlightInfo::FlightType::FlightTypeUnknown:
			mod->setItem(row, 18, new QStandardItem("unknow"));
			break;
		case FlightInfo::FlightType::FlightTypeDomestic:
			mod->setItem(row, 18, new QStandardItem("domestic"));
			break;
		case FlightInfo::FlightType::FlightTypeInternational:
			mod->setItem(row, 18, new QStandardItem("international"));
			break;
		}
		switch (query.value(19).toInt())
		{
		case FlightInfo::FlightStatus::FlightStatusUnknown:
			mod->setItem(row, 19, new QStandardItem("unknow"));
			break;
		case FlightInfo::FlightStatus::FlightStatusOnTime:
			mod->setItem(row, 19, new QStandardItem("ontime"));
			break;
		case FlightInfo::FlightStatus::FlightStatusDelayed:
			mod->setItem(row, 19, new QStandardItem("delay"));
			break;
		case FlightInfo::FlightStatus::FlightStatusCancelled:
			mod->setItem(row, 19, new QStandardItem("cancelled"));
			break;
		case FlightInfo::FlightStatus::FlightStatusArrived:
			mod->setItem(row, 19, new QStandardItem("arrived"));
			break;
		}
		switch (query.value(20).toInt())
		{
		case FlightInfo::AircraftType::Boeing:
			mod->setItem(row, 20, new QStandardItem("Boeing"));
			break;
		case FlightInfo::AircraftType::Airbus:
			mod->setItem(row, 20, new QStandardItem("Airbus"));
			break;
		case FlightInfo::AircraftType::Comac:
			mod->setItem(row, 20, new QStandardItem("Comac"));
			break;
		case FlightInfo::AircraftType::Embraer:
			mod->setItem(row, 20, new QStandardItem("Embraer"));
			break;
		case FlightInfo::AircraftType::Bombardier:
			mod->setItem(row, 20, new QStandardItem("Bombardier"));
			break;
		case FlightInfo::AircraftType::Antonov:
			mod->setItem(row, 20, new QStandardItem("Antonov"));
			break;
		case FlightInfo::AircraftType::Lockheed:
			mod->setItem(row, 20, new QStandardItem("Lockheed"));
			break;
		case FlightInfo::AircraftType::McDonnellDouglas:
			mod->setItem(row, 20, new QStandardItem("McDonnellDouglas"));
			break;
		case FlightInfo::AircraftType::DeHavilland:
			mod->setItem(row, 20, new QStandardItem("DeHavilland"));
			break;
		case FlightInfo::AircraftType::Other:
			mod->setItem(row, 20, new QStandardItem("Other"));
			break;
		}	
		row++;
	}
}

void Management::insert_record()
{
	// 获取输入的值
	QString flight_id = id_le->text();
	QString departure = from_le->text();
	QString destination = dst_le->text();
	QString depart_time = depart_time_le->text();
	QTime depart_time_qt = QTime::fromString(depart_time, "hh:mm");
	QString arrive_time = arrive_time_le->text();
	QTime arrive_time_qt = QTime::fromString(arrive_time, "hh:mm");
	QString status = status_le->text();
	int fli_status;
	if (status == "FlightStatusScheduled") {
		fli_status = 1;
	}
	else if (status == "FlightStatusDeparted") {
		fli_status = 2;
	}
	else if (status == "FlightStatusDelayed") {
		fli_status = 3;
	}
	else if (status == "FlightStatusCancelled") {
		fli_status = 4;
	}
	else if (status == "FlightStatusArrived") {
		fli_status = 5;
	}
	else {
		fli_status = 0;
	}
	QString type = type_le->text();
	int fli_type;
	if (type == "FlightTypeDomestic") {
		fli_type = 1;
	}
	else if (type == "FlightTypeInternational") {
		fli_type = 2;
	}
	else {
		fli_type = 0;
	}
	QString aircraft = aircraft_le->text();
	int fli_aircraft;
	if (aircraft == "Boeing") {
		fli_aircraft = 1;
	}
	else if (aircraft == "Airbus") {
		fli_aircraft = 2;
	}
	else if (aircraft == "Comac") {
		fli_aircraft = 3;
	}
	else if (aircraft == "Embraer") {
		fli_aircraft = 4;
	}
	else if (aircraft == "Bombardier") {
		fli_aircraft = 5;
	}
	else if (aircraft == "Antonov") {
		fli_aircraft = 6;
	}
	else if (aircraft == "Lockheed") {
		fli_aircraft = 7;
	}
	else if (aircraft == "McDonnellDouglas") {
		fli_aircraft = 8;
	}
	else if (aircraft == "DeHavilland") {
		fli_aircraft = 9;
	}
	else if (aircraft == "Other") {
		fli_aircraft = 10;
	}
	else {
		fli_aircraft = 0;
	}

	// 获取checkbox的值
	QBitArray week(7);
	week.setBit(0, mon_cb->isChecked());
	week.setBit(1, tue_cb->isChecked());
	week.setBit(2, wed_cb->isChecked());
	week.setBit(3, thu_cb->isChecked());
	week.setBit(4, fri_cb->isChecked());
	week.setBit(5, sat_cb->isChecked());
	week.setBit(6, sun_cb->isChecked());
	
	// 获取三种座位数量和票价
	int first_class = first_count_le->text().toInt();
	int bus_class = bus_count_le->text().toInt();
	int eco_class = eco_count_le->text().toInt();
	int first_price = first_price_le->text().toInt();
	int bus_price = bus_price_le->text().toInt();
	int eco_price = eco_price_le->text().toInt();
	
	QMap<QString, size_t> seats
	{
	{"Economy", eco_class},
	{"Business", bus_class},
	{"First", first_class}
	};

	QMap<QString, size_t> prices
	{
	{"Economy", eco_price},
	{"Business", bus_price},
	{"First", first_price}
	};

	// 定义一个新的FlightInfo
	FlightInfo new_flight(flight_id, departure, destination, week,
		depart_time_qt, arrive_time_qt, seats, prices, fli_status, fli_type, fli_aircraft);
	if (dataRepo.addFlightInfo(new_flight)) {
		QMessageBox::information(this, "Information", "Add successfully!");
	}
	else {
		QMessageBox::warning(this, "Warning", "Add failed!");
	}
}

void Management::update_record()
{
	// 获取被改变的行
	int row = table->currentIndex().row();
	// new a FlightInfo class from the select row
	FlightInfo newInfo();
	QBitArray week(7);
	// mod->item(row, 3-9) -> week
	week.setBit(0, mod->item(row, 3)->text() == "1");
	week.setBit(1, mod->item(row, 4)->text() == "1");
	week.setBit(2, mod->item(row, 5)->text() == "1");
	week.setBit(3, mod->item(row, 6)->text() == "1");
	week.setBit(4, mod->item(row, 7)->text() == "1");
	week.setBit(5, mod->item(row, 8)->text() == "1");
	week.setBit(6, mod->item(row, 9)->text() == "1");
	// mod->item(row, 0-2) -> flight_id, departure, destination
	
	QMap<QString, size_t> seats
	{
	{"Economy", mod->item(row, 12)->text().toUInt()},
	{"Business", mod->item(row, 14)->text().toUInt()},
	{"First", mod->item(row, 16)->text().toUInt()}
	};
	
	QMap<QString, size_t> prices
	{
	{"Economy", mod->item(row, 13)->text().toUInt()},
	{"Business", mod->item(row, 15)->text().toUInt()},
	{"First", mod->item(row, 17)->text().toUInt()}
	};
	
	// 18-20 三个枚举类型
	int status, type, aircraft;
	
	if (mod->item(row, 18)->text() == "FlightTypeUnknown") {
		type = 0;
	}
	else if (mod->item(row, 18)->text() == "FlightTypeDomestic") {
		type = 1;
	}
	else if (mod->item(row, 18)->text() == "FlightTypeInternational") {
		type = 2;
	}

	if (mod->item(row, 19)->text() == "FlightStatusScheduled") {
		status = 1;
	}
	else if (mod->item(row, 19)->text() == "FlightStatusDeparted") {
		status = 2;
	}
	else if (mod->item(row, 19)->text() == "FlightStatusDelayed") {
		status = 3;
	}
	else if (mod->item(row, 19)->text() == "FlightStatusCancelled") {
		status = 4;
	}
	else if (mod->item(row, 19)->text() == "FlightStatusArrived") {
		status = 5;
	} else {
		status = 0;
	}
	
	if (mod->item(row, 20)->text() == "AircraftTypeUnknown") {
		aircraft = 0;
	}
	else if (mod->item(row, 20)->text() == "Airbus") {
		aircraft = 1;
	}
	else if (mod->item(row, 20)->text() == "Comac") {
		aircraft = 2;
	}
	else if (mod->item(row, 20)->text() == "Embraer") {
		aircraft = 3;
	}
	else if (mod->item(row, 20)->text() == "Bombardier") {
		aircraft = 4;
	}
	else if (mod->item(row, 20)->text() == "Antonov") {
		aircraft = 5;
	}
	else if (mod->item(row, 20)->text() == "Lockheed") {
		aircraft = 6;
	}
	else if (mod->item(row, 20)->text() == "McDonnellDouglas") {
		aircraft = 7;
	}
	else if (mod->item(row, 20)->text() == "DeHavilland") {
		aircraft = 8;
	}
	else {
		aircraft = 9;
	}
	/*
	mod->item(row, 0)->text(), mod->item(row, 1)->text(), mod->item(row, 2)->text(), 
		mod->item(row, 3)->text(), mod->item(row, 4)->text(), mod->item(row, 5)->text(), mod->item(row, 6)->text(), 
		mod->item(row, 7)->text(), mod->item(row, 8)->text(), mod->item(row, 9)->text(), mod->item(row, 10)->text(), 
		mod->item(row, 11)->text(), mod->item(row, 12)->text(), mod->item(row, 13)->text(), mod->item(row, 14)->text(), 
		mod->item(row, 15)->text(), mod->item(row, 16)->text(), mod->item(row, 17)->text(), mod->item(row, 18)->text(), 
		mod->item(row, 19)->text(), mod->item(row, 20)->text()
	*/

	// 转换成QTime
	QTime departTime = QTime::fromString(mod->item(row, 10)->text(), "hh:mm");
	QTime arrTime = QTime::fromString(mod->item(row, 11)->text(), "hh:mm");
	// 可以新建FlightInfo了
	FlightInfo info(mod->item(row, 0)->text(), mod->item(row, 1)->text(), mod->item(row, 2)->text(),
		week, departTime, arrTime, seats, prices, status, type, aircraft);
	// 保存到数据库
	dataRepo.updateFlightInfo(info);
}

void Management::back()
{
	FlightManagement* fm = new FlightManagement();
	fm->show();
	this->close();
}
