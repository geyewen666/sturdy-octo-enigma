#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include "/home/hqyj/fsmpBeeper.h"  // 你的蜂鸣器头文件

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void onBeeperStartClicked();  // 蜂鸣器响
    void onBeeperStopClicked();   // 蜂鸣器关

private:
    // UI
    QPushButton *btn_beep_on;
    QPushButton *btn_beep_off;
    QLabel      *label_title;
    QLabel      *label_status;

    // 蜂鸣器驱动对象
    fsmpBeeper *beeper;
};

#endif // WIDGET_H
