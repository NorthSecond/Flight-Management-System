#include<QLabel>
#include <QTableview>


#include "Management.h"

Management::Management(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// ���ø߷ֲ���
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	
	// ���ù������ߴ�
	this->setStyleSheet("background-color:white");
	this->setFixedSize(800, 600);
	this->setWindowTitle("Flight Management System");
	//this->setWindowIcon(QIcon("icon.png"));
	
	// ����ʵʱ���ڵĿ�Ⱥ͸߶� ��ֹ�ĵ�
	size_t windowWidth = this->frameGeometry().width();
	size_t windowHeight = this->frameGeometry().height();
	
	// ��������Ϊ����������
	// �ϲ����ǲ�ѯ���棬�²�����һ��tableview
	
	// �ϲ��ֵĲ�ѯ����
	QLabel* id_lbl = new QLabel(this);
	id_lbl->setText("Flight ID");

	
}

Management::~Management()
{}
