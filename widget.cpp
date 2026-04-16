#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // 初始化蜂鸣器驱动（默认设备 /dev/input/event0）
   beeper = new fsmpBeeper("/dev/input/event0", this);

    // ===================== UI 界面 =====================
    this->setWindowTitle("蜂鸣器控制");
    this->resize(320, 220);

    // 标题
    label_title = new QLabel("开发板蜂鸣器控制器", this);
    label_title->setAlignment(Qt::AlignCenter);
    label_title->setStyleSheet("font-size:18px; font-weight:bold; margin:10px;");

    // 状态显示
    label_status = new QLabel("当前状态：已关闭", this);
    label_status->setAlignment(Qt::AlignCenter);
    label_status->setStyleSheet("font-size:14px; color:red;");

    // 按钮
    btn_beep_on  = new QPushButton("蜂鸣器响", this);
    btn_beep_off = new QPushButton("蜂鸣器关", this);

    btn_beep_on->setStyleSheet("font-size:14px; padding:10px;");
    btn_beep_off->setStyleSheet("font-size:14px; padding:10px;");

    // 布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label_title);
    layout->addWidget(label_status);
    layout->addWidget(btn_beep_on);
    layout->addWidget(btn_beep_off);
    layout->setSpacing(15);
    layout->setContentsMargins(30, 30, 30, 30);

    // ===================== 信号槽绑定 =====================
    connect(btn_beep_on,  &QPushButton::clicked, this, &Widget::onBeeperStartClicked);
    connect(btn_beep_off, &QPushButton::clicked, this, &Widget::onBeeperStopClicked);
}

Widget::~Widget()
{
    delete beeper;
}

// 蜂鸣器响
void Widget::onBeeperStartClicked()
{
    beeper->setRate(1000);  // 设置频率 1000Hz
    beeper->start();
    label_status->setText("当前状态：蜂鸣器响");
    label_status->setStyleSheet("font-size:14px; color:green;");
}

// 蜂鸣器关闭
void Widget::onBeeperStopClicked()
{
    beeper->stop();
    label_status->setText("当前状态：已关闭");
    label_status->setStyleSheet("font-size:14px; color:red;");
}
