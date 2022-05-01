#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new MyModel();
    view = new MytableView();
    ui->verticalLayout->addWidget(view);

    view->setModel(model);



    QVector<Student> mas;

    mas.append(Student(1, "dsfdf", 18, "BSBO-01-20"));
    mas.append(Student(12, "dsfdf", 18, "BSBO-01-20"));
    mas.append(Student(121, "Pavel Garbuzov", 19, "BSBO-01-20"));

    model->SetStudents(mas);
}

MainWindow::~MainWindow()
{
    delete ui;
}





