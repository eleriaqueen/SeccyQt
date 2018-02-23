#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPixmap viridia_png, greenill_png, skyly_png, bluefull_png, purplenum_png, pinkal_png, redria_png, oran_png, yellowboze_png, whitill_png;
    std::array<QPixmap, 11> sec_id_img;

    int pso_legacy_classval = 5;
    std::array<int, 12> psobb_classval;
    std::array<QString, 10> pso_sec_id;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
