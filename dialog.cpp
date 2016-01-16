#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QProcess>
#include <QDir>
#include <QLabel>
#include <QtWidgets>
#include <qmath.h>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
//    m_pixmap(":/test"),
//    m_leftButtonDown(false)
{
    ui->setupUi(this);
//    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
//    ui->label->setScaledContents(true);

//    ui->label->setPixmap(m_pixmap);
//    this->installEventFilter(this);
//    ui->label->setAlignment(Qt::AlignCenter);

//    m_delta = 1.0;
}

Dialog::~Dialog()
{
    delete ui;
}

//void Dialog::showEvent(QShowEvent *)
//{
//    m_size = ui->label->size();
//}

//bool Dialog::eventFilter(QObject *object, QEvent *event)
//{
//    if (event->type() == QEvent::Wheel) {
//        QWheelEvent *we = static_cast<QWheelEvent*>(event);
//        QPoint mousePos = ui->scrollArea->mapFromGlobal(QCursor::pos());
//        QPoint labelPos = ui->label->pos();
//        QSize labelSize = ui->label->size();
//        if (!ui->label->rect().contains(mousePos)) {
//            mousePos.setX(m_size.width() / 2);
//            mousePos.setY(m_size.height() / 2);
//        }
//        qreal x = (mousePos.x() - labelPos.x()) * 1.0 / labelSize.width();
//        qreal y = (mousePos.y() - labelPos.y()) * 1.0 / labelSize.height();

//        QPoint p = we->angleDelta();
//        qreal delta = m_delta + (p.y() > 0 ?  0.2:-0.2);
//        if (delta <= 0 || delta > 5) {
//            return false;
//        }
//        m_delta = delta;
//        QSize newSize = m_size * m_delta;
//        ui->label->resize(newSize);

//        labelSize = ui->label->size();
//        QPoint newLabelPos;
//        newLabelPos.setX(mousePos.x() - x * labelSize.width());
//        newLabelPos.setY(mousePos.y() - y * labelSize.height());

//        ui->label->move(newLabelPos);
//        if (qFuzzyCompare(m_delta, 1.0)) {
//            ui->label->move(0, 0);
//        } else if (p.y() < 0 && m_delta > 1.0){
//            if (ui->label->x() > 0 || ui->label->x() + ui->label->width() < m_size.width()) {
//                newLabelPos.setX(0);
//            }
//            if (ui->label->y() > 0 || ui->label->y() + ui->label->height() < m_size.height()) {
//                newLabelPos.setY(0);
//            }
//            ui->label->move(newLabelPos);
//        } else {
//            ui->label->move(newLabelPos);
//        }
//        return true;
//    }
//    return false;
//}

//void Dialog::mousePressEvent(QMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton) {
//        m_leftButtonDown = true;
//    }
//    m_mouseDownPos = event->pos();
//    m_labelSrcPos = ui->label->pos();
//    QWidget::mousePressEvent(event);
//}

//void Dialog::mouseReleaseEvent(QMouseEvent *event)
//{
//    m_leftButtonDown = false;
//    QWidget::mouseMoveEvent(event);
//}

//void Dialog::mouseMoveEvent(QMouseEvent *event)
//{
//    if (m_leftButtonDown) {
//        ui->label->move(m_labelSrcPos + event->pos() - m_mouseDownPos);
//    }
//    QWidget::mouseMoveEvent(event);
//}
