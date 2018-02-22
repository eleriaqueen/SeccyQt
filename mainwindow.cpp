#include "mainwindow.h"
#include "ui_mainwindow.h"

int pso_sum(QString, int);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    int pso_legacy_classval = 5;
    std::array<int, 12> psobb_classval = { 0, 1, 2, 9, 3, 11, 4, 5, 10, 6, 7, 8 };
    std::array<QString, 10> pso_sec_id = {"Viridia", "Greenill", "Skyly", "Bluefull", "Purplenum","Pinkal", "Redria", "Oran", "Yellowboze", "Whitill"};

    QPixmap viridia_png, greenill_png, skyly_png, bluefull_png, purplenum_png, pinkal_png, redria_png, oran_png, yellowboze_png, whitill_png;
    std::array<QPixmap, 10> sec_id_img = {viridia_png, greenill_png, skyly_png, bluefull_png, purplenum_png, pinkal_png, redria_png, oran_png, yellowboze_png, whitill_png};

    sec_id_img.at(0).load(":/img/viridia.png");
    sec_id_img.at(1).load(":/img/greenill.png");
    sec_id_img.at(2).load(":/img/skyly.png");
    sec_id_img.at(3).load(":/img/bluefull.png");
    sec_id_img.at(4).load(":/img/purplenum.png");
    sec_id_img.at(5).load(":/img/pinkal.png");
    sec_id_img.at(6).load(":/img/redria.png");
    sec_id_img.at(7).load(":/img/oran.png");
    sec_id_img.at(8).load(":/img/yellowboze.png");
    sec_id_img.at(9).load(":/img/whitill.png");

    // ui->label_0->setText(pso_sec_id.at(pso_sum(arg1, 5)));
    ui->label_1->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(0))));
    ui->label_2->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(1))));
    ui->label_3->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(2))));
    ui->label_4->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(3))));
    ui->label_5->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(4))));
    ui->label_6->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(5))));
    ui->label_7->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(6))));
    ui->label_8->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(7))));
    ui->label_9->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(8))));
    ui->label_10->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(9))));
    ui->label_11->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(10))));
    ui->label_12->setText(pso_sec_id.at(pso_sum(arg1, psobb_classval.at(11))));

    ui->img_0->setPixmap(sec_id_img.at(pso_sum(arg1, 5)));
    ui->img_1->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(0))));
    ui->img_2->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(1))));
    ui->img_3->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(2))));
    ui->img_4->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(3))));
    ui->img_5->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(4))));
    ui->img_6->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(5))));
    ui->img_7->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(6))));
    ui->img_8->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(7))));
    ui->img_9->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(8))));
    ui->img_10->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(9))));
    ui->img_11->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(10))));
    ui->img_12->setPixmap(sec_id_img.at(pso_sum(arg1, psobb_classval.at(11))));
}

int pso_sum(QString input_str, int cval)
{
    int sum = 0;
    ushort tempChar;
    int flag = 0;

    //Until we're at the end of the string... i++
    for (int i = 0; i < (input_str.length()); i++) {
        //Get the integer value of the character at i
        tempChar = input_str.at(i).unicode();
        sum += (int) tempChar;
        /* The following lines are required
           to have PSO-like Section ID calculations */
        if ((tempChar >= 0x100) && (tempChar < 0xFF61))
        {
            if (flag != 2)
            {
                flag = 2;
                sum = sum + 0x53;
            }
        }
        else if (tempChar < 0xFF91)
        {
            if (flag != 1)
            {
                flag = 1;
                sum = sum + 0x2D;
            }
        }
    }
    return ((sum + cval) % 10);
}
