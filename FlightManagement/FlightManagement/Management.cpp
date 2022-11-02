#include<QLabel>
#include <QTableview>


#include "Management.h"

Management::Management(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// 设置高分采样
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	
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
	QLabel* id_lbl = new QLabel(this);
	id_lbl->setText("Flight ID");

	
}

Management::~Management()
{}
