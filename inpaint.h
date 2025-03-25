#ifndef INPAINT_H
#define INPAINT_H

#include <QWidget>  // 加这个头文件！
#include <QImage>
#include <QPoint>
#include <QMouseEvent>  // 添加这个头文件！

class InPaint : public QWidget  // 改为继承 QWidget
{
    Q_OBJECT  // Qt 宏：必须加，用于信号槽等机制

public:
    explicit InPaint(QWidget *parent = nullptr);  // 构造函数，带父类指针参数

private:
    QImage mImage;         // 实际绘图内容的画布
    QPoint mLastPoint;     // 上一次鼠标的位置
    bool mDrawing = false; // 是否正在绘制
//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    void paintEvent(QPaintEvent *event);


protected:
//    void paintEvent(QPaintEvent *event) override;  // 重写绘图函数（先声明即可）
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;   // 新增
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;     // 新增
};

#endif // INPAINT_H
