#include "SearchResult.h"

SearchResult::SearchResult(QWidget *parent)
	: QWidget(parent), dataRepo()
{
	// ���ø߷ֱ�����Ⱦ
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	// ���������ʼ��
	this->setStyleSheet("background-color:white");
	// �������������Ǳ�ƽ��
	this->setFixedSize(360, 240);
	
	// ����ʵʱ���ڵĿ�Ⱥ͸߶� ��ֹ�ĵ�
	size_t windowWidth = this->frameGeometry().width();
	size_t windowHeight = this->frameGeometry().height();
	

	// ����ѡ��
	id_lbl = new QLabel(this);
	id_lbl->setText("Flight ID");
	id_lbl->setGeometry(20, 20, 80, 20);
	id_lbl->setStyleSheet("font-size: 14px;");
	id_edit = new QLineEdit(this);
	id_edit->setGeometry(100, 20, 200, 20);
	id_edit->setStyleSheet("font-size: 14px;");
	from_lbl = new QLabel(this);
	from_lbl->setText("From");
	from_lbl->setGeometry(20, 60, 80, 20);
	from_lbl->setStyleSheet("font-size: 14px;");
	from_edit = new QLineEdit(this);
	from_edit->setGeometry(100, 60, 200, 20);
	from_edit->setStyleSheet("font-size: 14px;");
	dst_lbl = new QLabel(this);
	dst_lbl->setText("To");
	dst_lbl->setGeometry(20, 100, 80, 20);
	dst_lbl->setStyleSheet("font-size: 14px;");
	dst_edit = new QLineEdit(this);
	dst_edit->setGeometry(100, 100, 200, 20);
	dst_edit->setStyleSheet("font-size: 14px;");
	date_lbl = new QLabel(this);
	date_lbl->setText("Date");
	date_lbl->setGeometry(20, 140, 80, 20);
	date_lbl->setStyleSheet("font-size: 14px;");
	date_edit = new QDateEdit(this);
	date_edit->setGeometry(100, 140, 200, 20);
	date_edit->setStyleSheet("font-size: 14px;");
	search_btn = new QPushButton(this);
	search_btn->setText("Search");
	search_btn->setGeometry(20, 180, 80, 20);
	search_btn->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");

	reset_btn = new QPushButton(this);
	reset_btn->setText("Reset");
	reset_btn->setGeometry(120, 180, 80, 20);
	reset_btn->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");

	back_btn = new QPushButton(this);
	back_btn->setText("Back");
	back_btn->setGeometry(220, 180, 80, 20);
	back_btn->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");

	exit_btn = new QPushButton(this);
	exit_btn->setText("Exit");
	exit_btn->setGeometry(320, 180, 80, 20);
	exit_btn->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");

	// �󶨶�Ӧ���źŲ�
	connect(search_btn, SIGNAL(clicked()), this, SLOT(onSearchResult()));
	connect(reset_btn, SIGNAL(clicked()), this, SLOT(onReset()));
	connect(back_btn, SIGNAL(clicked()), this, SLOT(onBack()));
	connect(exit_btn, SIGNAL(clicked()), this, SLOT(onExit()));
	
	ui.setupUi(this);
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
	
	if (id_edit->text().trimmed() == "" &&
		(from_edit->text().trimmed() == "" || dst_edit->text().trimmed() == "")) {
		// ��Ч��ѯ
		QMessageBox::warning(this, "Warning", "Please input the flight ID or the departure and destination");
	}
	else
	{
		// ��Ч��ѯ ��������
		// ���Ĵ�С
		this->setFixedSize(360, 640);
		// ���ı�����ɫ
		this->setStyleSheet("background-color:white");
		// ����ԭ����������
		id_lbl->hide();
		id_edit->hide();
		from_lbl->hide();
		from_edit->hide();
		dst_lbl->hide();
		dst_edit->hide();
		date_lbl->hide();
		date_edit->hide();
		search_btn->hide();
		reset_btn->hide();
		back_btn->hide();
		exit_btn->hide();
		// ��ʾ�������
		
		// �����ݿ��ж�ȡ����
		// ��ȡ���ݵ�ʱ����Ҫ�ж����������
		if (id_edit->text().trimmed() != "") 
		{ // 1. ֻ���뺽���
			result.push_back(dataRepo.getFlightInfo(id_edit->text().trimmed()));
		}
		else if (date_edit->date() != QDate::currentDate()) 
		{ // 2. ����ʼ���غ�Ŀ�ĵغ�����
			result = dataRepo.getFlightInfo(from_edit->text().trimmed(), dst_edit->text().trimmed(), date_edit->date());
		}
		else 
		{ // 3. ��Ч��ѯ
			QMessageBox::warning(this, "Warning", "Please input the flight ID or the departure and destination");
		}
	}
	// TODO: ������չʾ��list��
}

void SearchResult::returnSearch()
{
	// ���������������

	// resize
	
	// ��ԭ����ЩԪ�ػָ��ڽ�����
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
	FlightManagement w;
	w.show();
	this->hide();
}

void SearchResult::onExit()
{
	// �˳�
	this->close();
}