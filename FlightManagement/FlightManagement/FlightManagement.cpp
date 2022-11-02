#include <QMessagebox>
#include <QTableview>
#include <QLabel>
#include <QPushButton>

#include "FlightManagement.h"
#include "DatabaseRepository.h"
#include "FlightInfo.h"

FlightManagement::FlightManagement(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	// 设置高分辨率渲染
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	
	// Initialize the database.
	//DatabaseRepository db;
	
	// initial the view
	// 设置登录界面
	this->setStyleSheet("background-color:white");
	this->setFixedSize(512, 288);
	this->setWindowTitle("Flight Management System");
	//this->setWindowIcon(QIcon("icon.png"));
	
	size_t windowWidth = this->frameGeometry().width();
	size_t windowHeight = this->frameGeometry().height();
	
	// 一级界面对应的一些元素
	QLabel* initial_info_label = new QLabel(this);
	initial_info_label->setText("Flight Management System");
	// TODO: 设置相对位置
	initial_info_label->setGeometry(200, 50, 200, 30);
	initial_info_label->setStyleSheet("font-size:20px;");
	
	QPushButton* search_button = new QPushButton(this);
	search_button->setText("Search Flight");
	// TODO: 相对位置
	search_button->setGeometry(200, 100, 100, 30);
	search_button->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");
	
	QPushButton* management_button = new QPushButton(this);
	management_button->setText("Management");
	// TODO: 相对位置+1
	management_button->setGeometry(200, 150, 100, 30);
	management_button->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");
	
	QPushButton* exit_button = new QPushButton(this);
	exit_button->setText("Exit");
	// TODO
	exit_button->setGeometry(200, 200, 100, 30);
	exit_button->setStyleSheet("border:2px solid #000000; border-radius:10px;"
		"text-decoration:underline;font-size:14px;font - weight:bold; font - family:Arial;");

	// TODO: 设置对应的图标
	
	// 绑定信号槽
	connect(search_button, &QPushButton::clicked, this, &FlightManagement::searchFlight);
	connect(management_button, &QPushButton::clicked, this, &FlightManagement::management);
	connect(exit_button, &QPushButton::clicked, this, &FlightManagement::exit);
}

FlightManagement::~FlightManagement()
{}

void FlightManagement::searchFlight()
{
	
}

void FlightManagement::management()
{

}

void FlightManagement::exit()
{
	this->close();
}