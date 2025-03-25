![屏幕截图 2025-03-25 152107](https://github.com/user-attachments/assets/7b507cca-3a4d-4552-9193-c4c831ec30fb)



# 🖊️ Qt 手写板控件（InPaint）

本项目实现了一个基于 Qt 的自定义控件 `InPaint`，可用于鼠标绘图/手写输入，具有实时绘制、窗口缩放自适应等基本功能，适合作为教学示例或手写识别前端控件。



## 🚀 功能特性

- 实时鼠标绘图
- 支持窗口大小变化，自适应扩展画布
- 支持绘图区域刷新
- 易于扩展（保存、清空、颜色选择等）



## 🧱 实现步骤概览

### 1. 创建自定义控件类

- 类名：`InPaint`
- 继承自 `QWidget`
- 位于 `inpaint.h` / `inpaint.cpp`

### 2. 初始化画布（构造函数）

```cpp
mImage = QImage(size(), QImage::Format_RGB32);
mImage.fill(Qt::white);
```

- 使用 `QImage` 存储绘图内容
- 设置为白底，初始化尺寸与控件一致

### 3. 处理鼠标事件

| 函数名 | 功能说明 |
|--------|----------|
| `mousePressEvent(QMouseEvent*)` | 鼠标按下，记录起点，开始绘图 |
| `mouseMoveEvent(QMouseEvent*)`  | 鼠标移动，画线，调用 `update()` 实时刷新 |
| `mouseReleaseEvent(QMouseEvent*)` | 鼠标释放，结束绘图 |

### 4. 绘图事件（paintEvent）

```cpp
void paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawImage(rect(), mImage);
}
```

- 使用 `QPainter` 将画布内容绘制到控件上

### 5. 支持窗口缩放（resizeEvent）

- 若窗口放大，自动扩展 `mImage` 并保留原始绘图内容

```cpp
void resizeEvent(QResizeEvent *event);
```

---

## 💡 常见问题与注意事项

- **绘图不实时显示？**
  - 检查 `mouseMoveEvent()` 中是否调用了 `update()`
- **控件不显示内容？**
  - 确认 `paintEvent()` 中是否正确绘制 `mImage`
- **鼠标事件无效？**
  - 确保类继承自 `QWidget` 且函数声明正确（加 `override`）

---

## 🛠️ 可扩展功能（暂未实现）

- 清空画布：`clear()`
- 保存图像：`save(QString path)`
- 设置画笔颜色和粗细
- 添加橡皮擦、撤销、重做
- 结合机器学习实现手写识别

---

## 📁 文件结构建议

```
/project_root
│
├── mainwindow.ui
├── mainwindow.cpp/h
├── inpaint.cpp
├── inpaint.h
└── README.md   ← 就是本文件
```

---

## 📸 运行效果预览

> 启动程序后，在白色矩形区域中按住鼠标左键拖动，即可实时绘图 ✏️

---

## 📚 依赖环境

- Qt 5 或 Qt 6（推荐使用 Qt Creator）
- C++11 或以上

---

