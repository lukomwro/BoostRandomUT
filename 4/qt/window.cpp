#include <QtGui>
#include "widget.hpp"
#include "window.hpp"

Window::Window()
    : QWidget()
{
    Widget *native = new Widget(&helper, this);
    QLabel *nativeLabel = new QLabel(tr("Native"));
    nativeLabel->setAlignment(Qt::AlignHCenter);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(native, 0, 0);
    layout->addWidget(nativeLabel, 1, 0);
    setLayout(layout);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), native, SLOT(animate()));
    timer->start(50);

    setWindowTitle(tr("2D Painting on Native and OpenGL Widgets"));
}
