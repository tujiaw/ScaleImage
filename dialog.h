#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

//protected:
//    void showEvent(QShowEvent *);
//    bool eventFilter(QObject *, QEvent *);
//    void mousePressEvent(QMouseEvent *);
//    void mouseReleaseEvent(QMouseEvent *);
//    void mouseMoveEvent(QMouseEvent *);

private:
    Ui::Dialog *ui;
//    QPixmap m_pixmap;
//    qreal m_delta;
//    QSize m_size;
//    bool m_leftButtonDown;
//    QPoint m_mouseDownPos;
//    QPoint m_labelSrcPos;
};

#endif // DIALOG_H
