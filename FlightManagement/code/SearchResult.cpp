#include "SearchResult.h"

SearchResult::SearchResult(QWidget* parent)
	: QMainWindow(parent), dataRepo()
{
	ui.setupUi(this);
	// ���ø߷ֱ�����Ⱦ
	//QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	//QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	// ���������ʼ��
	this->setStyleSheet("background-color:white");
	// �������������Ǳ�ƽ��
	this->setFixedSize(960, 680);

	// ����ʵʱ���ڵĿ�Ⱥ͸߶� ��ֹ�ĵ�
	size_t windowWidth = this->frameGeometry().width();
	size_t windowHeight = this->frameGeometry().height();


	// ����ѡ��
	id_lbl = new QLabel(this);
	id_lbl->setText("Flight ID");
	id_lbl->setGeometry(20, 20, 80, 20);
	id_lbl->setStyleSheet("font-size: 14px;");
	id_edit = new QLineEdit(this);
	id_edit->setGeometry(100, 20, 80, 20);
	id_edit->setStyleSheet("font-size: 14px;");
	from_lbl = new QLabel(this);
	from_lbl->setText("From");
	from_lbl->setGeometry(200, 20, 80, 20);
	from_lbl->setStyleSheet("font-size: 14px;");
	from_edit = new QLineEdit(this);
	from_edit->setGeometry(280, 20, 80, 20);
	from_edit->setStyleSheet("font-size: 14px;");
	dst_lbl = new QLabel(this);
	dst_lbl->setText("To");
	dst_lbl->setGeometry(400, 20, 80, 20);
	dst_lbl->setStyleSheet("font-size: 14px;");
	dst_edit = new QLineEdit(this);
	dst_edit->setGeometry(450, 20, 80, 20);
	dst_edit->setStyleSheet("font-size: 14px;");
	date_lbl = new QLabel(this);

	date_lbl->setText("Date");
	date_lbl->setGeometry(550, 20, 80, 20);
	date_lbl->setStyleSheet("font-size: 14px;");
	date_edit = new QDateEdit(this);
	date_edit->setCalendarPopup(true);
	date_edit->setDisplayFormat("yyyy-MM-dd");
	date_edit->setDate(QDate::currentDate());
	date_edit->setGeometry(600, 20, 160, 20);
	date_edit->setStyleSheet("font-size: 14px;");
	search_btn = new QPushButton(this);
	search_btn->setText("Search");
	search_btn->setGeometry(800, 20, 80, 20);
	search_btn->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");

	reset_btn = new QPushButton(this);
	reset_btn->setText("Reset");
	reset_btn->setGeometry(120, 650, 80, 20);
	reset_btn->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");

	back_btn = new QPushButton(this);
	back_btn->setText("Back");
	back_btn->setGeometry(220, 650, 80, 20);
	back_btn->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");

	exit_btn = new QPushButton(this);
	exit_btn->setText("Exit");
	exit_btn->setGeometry(320, 650, 80, 20);
	exit_btn->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");

	mod = new QStandardItemModel();
	mod->setHorizontalHeaderItem(0, new QStandardItem("Flight ID"));
	mod->setHorizontalHeaderItem(1, new QStandardItem("From"));
	mod->setHorizontalHeaderItem(2, new QStandardItem("To"));
	mod->setHorizontalHeaderItem(3, new QStandardItem("Eco seats"));
	mod->setHorizontalHeaderItem(4, new QStandardItem("Eco rice"));
	mod->setHorizontalHeaderItem(5, new QStandardItem("Bus seats"));
	mod->setHorizontalHeaderItem(6, new QStandardItem("Bus price"));
	mod->setHorizontalHeaderItem(7, new QStandardItem("First seats"));
	mod->setHorizontalHeaderItem(8, new QStandardItem("First prize"));

	// ���ñ��
	table = new QTableView(this);
	table->setGeometry(50, 60, 870, 590);
	table->setModel(mod);
	table->setEditTriggers(QAbstractItemView::NoEditTriggers);

	// �󶨶�Ӧ���źŲ�
	connect(search_btn, SIGNAL(clicked()), this, SLOT(onSearchResult()));
	connect(reset_btn, SIGNAL(clicked()), this, SLOT(onReset()));
	connect(back_btn, SIGNAL(clicked()), this, SLOT(onBack()));
	connect(exit_btn, SIGNAL(clicked()), this, SLOT(onExit()));


}

SearchResult::~SearchResult()
{}

void SearchResult::onSearchResult()
{
	// �������
	// ���������ļ������
	// ֻ���뺽���
	// ����ʼ���غ�Ŀ�ĵ�
	// ����ʼ���غ�Ŀ�ĵغ�����

	if (id_edit->text() == "" &&
		(from_edit->text() == "" || dst_edit->text() == "")) {
		// ��Ч��ѯ
		QMessageBox::warning(this, "Warning", "Please input the flight ID or the departure and destination");
	}
	else
	{
		// �����ݿ��ж�ȡ����
		// ��ȡ���ݵ�ʱ����Ҫ�ж����������
		result.clear();
		if (id_edit->text() != "")
		{ // 1. ֻ���뺽���
			result.push_back(dataRepo.getFlightInfo(id_edit->text()));
		}
		else /*if (date_edit->date() != QDate::currentDate())*/
		{ // 2. ����ʼ���غ�Ŀ�ĵغ�����
			result = dataRepo.getFlightInfo(from_edit->text(), dst_edit->text(), date_edit->date());
		}
		//else
		//{ // 3. ��Ч��ѯ
		//	result = dataRepo.getFlightInfo(from_edit->text(), dst_edit->text());
		//}
	}
	mod->clear();
	if (result.size() == 1 && result[0].getFlightId() == "ERROR") {
		QMessageBox::information(this, "Information", "No result");
		return;
	}
	// ������չʾ��table��
	for (int i = 0; i < result.size(); i++) {
		mod->setItem(i, 0, new QStandardItem(result[i].getFlightId()));
		mod->setItem(i, 1, new QStandardItem(result[i].getFromAirport()));
		mod->setItem(i, 2, new QStandardItem(result[i].getDstAirport()));
		mod->setItem(i, 3, new QStandardItem(QString::number(result[i].getSeats().value("Economy"))));
		mod->setItem(i, 4, new QStandardItem(QString::number(result[i].getPrice().value("Economy"))));
		mod->setItem(i, 5, new QStandardItem(QString::number(result[i].getSeats().value("Business"))));
		mod->setItem(i, 6, new QStandardItem(QString::number(result[i].getPrice().value("Business"))));
		mod->setItem(i, 7, new QStandardItem(QString::number(result[i].getSeats().value("First"))));
		mod->setItem(i, 8, new QStandardItem(QString::number(result[i].getPrice().value("First"))));
	}
}

void SearchResult::onReset()
{
	// ����
	id_edit->setText("");
	from_edit->setText("");
	dst_edit->setText("");
	date_edit->setDate(QDate::currentDate());
}

void SearchResult::onBack()
{
	// ����
	FlightManagement* fm = new FlightManagement();
	fm->show();
	this->hide();
}

void SearchResult::onExit()
{
	// �˳�
	this->close();
	exit(0);
}