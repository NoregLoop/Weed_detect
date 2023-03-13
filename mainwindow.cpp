#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QMenu>
#include <QIcon>
#include <QMenuBar>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->setWindowIcon(QIcon(":/icon/zhiyin.ico"));
    this->setWindowTitle("杂草检测系统");

    QAction *actOpen =new QAction("打开");
    actOpen->setShortcut(QKeySequence("Ctrl+F"));
    QAction *actSave =new QAction("保存");
    actSave->setShortcut(QKeySequence("Ctrl+S"));

    QMenu *fileMenu =menuBar()->addMenu("&File");

    fileMenu->addAction(actOpen);
    fileMenu->addAction(actSave);

    connect(actOpen,SIGNAL(triggered(bool)),this,SLOT(openFile()));

}

void MainWindow::openFile(){
    QFileDialog::getOpenFileName();
}

MainWindow::~MainWindow()
{
    delete ui;
}

