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
    ui(new Ui::Dialog),
    m_pixmap(":/test")
{
    ui->setupUi(this);
    ui->label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->label->setScaledContents(true);

    ui->label->setPixmap(m_pixmap);
    this->installEventFilter(this);
    ui->label->setAlignment(Qt::AlignCenter);

    m_delta = 1.0;
}

Dialog::~Dialog()
{
    delete ui;
}

QPoint s_center;

void Dialog::showEvent(QShowEvent *)
{
    m_size = ui->label->size();
}

bool Dialog::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::Wheel) {
        QWheelEvent *we = static_cast<QWheelEvent*>(event);
        QPoint mousePos = ui->scrollArea->mapFromGlobal(QCursor::pos());
        QPoint labelPos = ui->label->pos();
        QSize labelSize = ui->label->size();
        qreal x = (mousePos.x() - labelPos.x()) * 1.0 / labelSize.width();
        qreal y = (mousePos.y() - labelPos.y()) * 1.0 / labelSize.height();
        qDebug() << "x:" << x << ",y:" << y;

        QPoint p = we->angleDelta();
        m_delta += p.y() > 0 ?  0.2:-0.2;
        qDebug() << "delta:" << m_delta;
        QSize newSize = m_size * m_delta;
        ui->label->resize(newSize);
        qDebug() << "resize:" << newSize;

        labelSize = ui->label->size();
        QPoint newLabelPos;
        newLabelPos.setX(mousePos.x() - x * labelSize.width());
        newLabelPos.setY(mousePos.y() - y * labelSize.height());

        qDebug() << "new label pos:" << newLabelPos;

        qDebug() << "right:" << ui->label->rect().right();
        qDebug() << "bottom:" << ui->label->rect().bottom();

        ui->label->move(newLabelPos);
        if (m_delta == 1.0) {
            ui->label->move(0, 0);
            qDebug() << "1111";
        } else if (p.y() < 0 && m_delta > 1.0){
            if (ui->label->x() > 0 || ui->label->x() + ui->label->width() < m_size.width()) {
                newLabelPos.setX(0);
            } else if (ui->label->y() > 0 || ui->label->y() + ui->label->height() < m_size.height()) {
                newLabelPos.setY(0);
            }
            ui->label->move(newLabelPos);
        } else {
            ui->label->move(newLabelPos);
            qDebug() << "3333";
        }

        qDebug() << "last, pos:" << ui->label->pos() << ", rect:" << ui->label->rect();
        return true;
    }
    return false;
}
