#include "SearchResult.h"

SearchResult::SearchResult(QWidget *parent)
	: QWidget(parent), dataRepo()
{
	// 设置高分辨率渲染
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	// 搜索界面初始化
	this->setStyleSheet("background-color:white");
	// 初期搜索界面是扁平的
	this->setFixedSize(360, 240);
	
	// 这里实时窗口的宽度和高度 防止寄掉
	size_t windowWidth = this->frameGeometry().width();
	size_t windowHeight = this->frameGeometry().height();
	

	// 搜索选项
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

	// 绑定对应的信号槽
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
	// 搜索结果
	// 可以搜索的几种情况
	// 只输入航班号
	// 输入始发地和目的地
	// 输入始发地和目的地和日期
	
	if (id_edit->text().trimmed() == "" &&
		(from_edit->text().trimmed() == "" || dst_edit->text().trimmed() == "")) {
		// 无效查询
		QMessageBox::warning(this, "Warning", "Please input the flight ID or the departure and destination");
	}
	else
	{
		// 有效查询 换界面了
		// 更改大小
		this->setFixedSize(360, 640);
		// 更改背景颜色
		this->setStyleSheet("background-color:white");
		// 隐藏原有所有内容
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
		// 显示搜索结果
		
		// 从数据库中读取数据
		// 读取数据的时候需要判断是哪种情况
		if (id_edit->text().trimmed() != "") 
		{ // 1. 只输入航班号
			result.push_back(dataRepo.getFlightInfo(id_edit->text().trimmed()));
		}
		else if (date_edit->date() != QDate::currentDate()) 
		{ // 2. 输入始发地和目的地和日期
			result = dataRepo.getFlightInfo(from_edit->text().trimmed(), dst_edit->text().trimmed(), date_edit->date());
		}
		else 
		{ // 3. 无效查询
			QMessageBox::warning(this, "Warning", "Please input the flight ID or the departure and destination");
		}
	}
	// TODO: 将内容展示在list中
}

void SearchResult::returnSearch()
{
	// 隐藏搜索结果界面

	// resize
	
	// 将原来这些元素恢复在界面中
}

void SearchResult::onReset()
{
	// 重置
	id_edit->setText("");
	from_edit->setText("");
	dst_edit->setText("");
	date_edit->setDate(QDate::currentDate());
	
}

void SearchResult::onBack()
{
	// 返回
	FlightManagement w;
	w.show();
	this->hide();
}

void SearchResult::onExit()
{
	// 退出
	this->close();
}