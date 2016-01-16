#include "imageviewerwidget.h"
#include <QLabel>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QEvent>
#include <QWheelEvent>
#include <QDebug>

ImageViewerWidget::ImageViewerWidget(QWidget *parent)
    : QWidget(parent)
    , m_pixmap(":/test")
    , m_leftButtonDown(false)
{
    QWidget *scrollWidget = new QWidget();
    QGridLayout *gLayout = new QGridLayout(scrollWidget);
    gLayout->setSpacing(0);
    gLayout->setContentsMargins(0, 0, 0, 0);

    m_label = new QLabel(scrollWidget);
    m_label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    m_label->setScaledContents(true);
    m_label->setPixmap(m_pixmap);
    m_label->setAlignment(Qt::AlignCenter);
    gLayout->addWidget(m_label);

    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scrollArea->setWidgetResizable(true);
    m_scrollArea->setWidget(scrollWidget);

    QHBoxLayout *mLayout = new QHBoxLayout();
    mLayout->setContentsMargins(0, 0, 0, 0);
    mLayout->setSpacing(0);
    mLayout->addWidget(m_scrollArea);

    this->setLayout(mLayout);
    this->installEventFilter(this);

    m_delta = 1.0;
}

ImageViewerWidget::~ImageViewerWidget()
{

}

void ImageViewerWidget::showEvent(QShowEvent *)
{
    m_size = m_label->size();
}

bool ImageViewerWidget::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::Wheel) {
        QWheelEvent *we = static_cast<QWheelEvent*>(event);
        QPoint mousePos = m_scrollArea->mapFromGlobal(QCursor::pos());
        QPoint labelPos = m_label->pos();
        QSize labelSize = m_label->size();
        if (!m_label->rect().contains(mousePos)) {
            mousePos.setX(m_size.width() / 2);
            mousePos.setY(m_size.height() / 2);
        }
        qreal x = (mousePos.x() - labelPos.x()) * 1.0 / labelSize.width();
        qreal y = (mousePos.y() - labelPos.y()) * 1.0 / labelSize.height();

        QPoint p = we->angleDelta();
        qreal delta = m_delta + (p.y() > 0 ?  0.2:-0.2);
        if (delta <= 0.2 || delta > 5.0) {
            return true;
        }

        m_delta = delta;
        QSize newSize = m_size * m_delta;
        m_label->resize(newSize);

        labelSize = m_label->size();
        QPoint newLabelPos;
        newLabelPos.setX(mousePos.x() - x * labelSize.width());
        newLabelPos.setY(mousePos.y() - y * labelSize.height());

        m_label->move(newLabelPos);
        if (qFuzzyCompare(m_delta, 1.0)) {
            m_label->move(0, 0);
            qDebug() << "1";
        } else if (p.y() < 0 && m_delta > 1.0){
            if (m_label->x() > 0 || m_label->x() + m_label->width() < m_size.width()) {
                newLabelPos.setX(0);
                qDebug() << "2";
            }
            if (m_label->y() > 0 || m_label->y() + m_label->height() < m_size.height()) {
                newLabelPos.setY(0);
                qDebug() << "3";
            }
            m_label->move(newLabelPos);
        } else if (p.y() > 0 && m_delta < 1.0) {
//            if (m_label->x() < 0 || m_label->x() + m_label->width() > m_size.width()) {
//                newLabelPos.setX(0);
//                qDebug() << "4";
//            }
//            if (m_label->y() < 0 || m_label->y() + m_label->height() > m_size.height()) {
//                newLabelPos.setY(0);
//                qDebug() << "5";
//            }
            m_label->move(newLabelPos);
        } else {
            m_label->move(newLabelPos);
            qDebug() << "6";
        }
        return true;
    }
    return false;
}

void ImageViewerWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_leftButtonDown = true;
    }
    m_mouseDownPos = event->pos();
    m_labelSrcPos = m_label->pos();
    QWidget::mousePressEvent(event);
}

void ImageViewerWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_leftButtonDown = false;
    QWidget::mouseMoveEvent(event);
}

void ImageViewerWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_leftButtonDown) {
        m_label->move(m_labelSrcPos + event->pos() - m_mouseDownPos);
    }
    QWidget::mouseMoveEvent(event);
}
