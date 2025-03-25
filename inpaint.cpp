#include "inpaint.h"
#include <QPainter>
#include <QMouseEvent>  // 必须加，用于鼠标事件处理

InPaint::InPaint(QWidget *parent)
    : QWidget(parent)
{
    // 初始化画布为当前控件大小
    mImage = QImage(size(), QImage::Format_RGB32);
    mImage.fill(Qt::white);

    setAttribute(Qt::WA_StaticContents);  // 减少刷新开销
}

// 鼠标按下：记录起点
void InPaint::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        mLastPoint = event->pos();
        mDrawing = true;
    }
}

// 鼠标移动：画线并刷新
void InPaint::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && mDrawing) {
        QPainter painter(&mImage);
        painter.setRenderHint(QPainter::Antialiasing);  // 抗锯齿（可选）
        painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(mLastPoint, event->pos());
        mLastPoint = event->pos();
        update();  // 触发 paintEvent 重绘
    }
}

// 鼠标释放：结束绘图
void InPaint::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && mDrawing) {
        mDrawing = false;
    }
}

// 绘图事件：将图像画到屏幕上
void InPaint::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(rect(), mImage);
}

// 如果窗口被放大：扩展画布
void InPaint::resizeEvent(QResizeEvent *event)
{
    if (width() > mImage.width() || height() > mImage.height()) {
        // 创建新画布并复制旧图像内容
        QImage newImage(size(), QImage::Format_RGB32);
        newImage.fill(Qt::white);
        QPainter painter(&newImage);
        painter.drawImage(QPoint(0, 0), mImage);
        mImage = newImage;
    }

    QWidget::resizeEvent(event);  // 调用父类默认行为
}
