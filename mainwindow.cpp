#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inpaint.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建你的控件
    InPaint *paintBoard = new InPaint(this);
    // 用 setGeometry 一次性设置位置和大小
    paintBoard->setGeometry(50, 100, 400, 300);

    // 加到已有的布局中，比如一个垂直布局
//    ui->verticalLayout->addWidget(paintBoard);
}

MainWindow::~MainWindow()
{
    delete ui;
}

