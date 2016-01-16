#ifndef IMAGEVIEWERWIDGET_H
#define IMAGEVIEWERWIDGET_H

#include <QWidget>

class QLabel;
class QScrollArea;
class ImageViewerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewerWidget(QWidget *parent = 0);
    ~ImageViewerWidget();

protected:
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *, QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    QLabel *m_label;
    QScrollArea *m_scrollArea;
    QPixmap m_pixmap;
    qreal m_delta;
    QSize m_size;
    bool m_leftButtonDown;
    QPoint m_mouseDownPos;
    QPoint m_labelSrcPos;
};

#endif // IMAGEVIEWERWIDGET_H
