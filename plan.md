# Qt 5.15 学习计划

## 第一阶段：核心机制（2-3 周）

### 1. 信号与槽（Signal & Slot）
- 五种连接方式：`connect(sender, SIGNAL(), receiver, SLOT())` 旧式、函数指针新式、lambda、`QSignalMapper`、自动连接（`on_xxx_xxx`）
- 练习：把你项目里的 lambda 式改成函数指针式，再加一个 "清空" 按钮

### 2. 对象模型 & 元对象系统
- `QObject` 父子关系与内存管理
- `MOC`（Meta-Object Compiler）干了什么
- `qobject_cast`、`Q_OBJECT` 宏的作用

### 3. 事件系统
- 事件 vs 信号的区别
- `event()`、`eventFilter()`、各具体事件函数（`mousePressEvent`、`keyPressEvent` 等）
- 练习：给你的窗口加个 ESC 关闭功能

## 第二阶段：常用控件（3-4 周）

### 4. 布局管理
- `QVBoxLayout` / `QHBoxLayout` / `QGridLayout` / `QFormLayout`
- 用代码写布局 vs 用 Qt Designer 拖布局
- `QSpacerItem`、`sizePolicy`、`stretch`
- 练习：把你当前项目用代码布局重写一遍（不用 .ui）

### 5. 核心控件
- 输入：`QLineEdit`、`QTextEdit`、`QSpinBox`、`QComboBox`、`QDateEdit`
- 显示：`QLabel`、`QProgressBar`、`QListWidget`、`QTableWidget`
- 按钮类：`QPushButton`、`QCheckBox`、`QRadioButton`、`QButtonGroup`
- 容器：`QGroupBox`、`QTabWidget`、`QStackedWidget`、`QScrollArea`

### 6. 对话框
- `QMessageBox`（你已用过）、`QFileDialog`、`QInputDialog`、`QColorDialog`
- 练习：做一个简单的 "用户信息登记" 表单

## 第三阶段：模型/视图 & 数据（2-3 周）

### 7. Model/View 架构
- `QListView` / `QTreeView` / `QTableView` + 对应的 Model
- `QStringListModel`、`QStandardItemModel`
- 自定义 Model（继承 `QAbstractListModel`）
- 练习：做一个待办事项列表（增删改）

### 8. 文件与数据
- `QFile`、`QDataStream`、`QTextStream`
- `QSettings` 读写配置
- `QJsonDocument` JSON 处理
- 练习：把待办事项持久化到本地 JSON 文件

## 第四阶段：进阶（3-4 周）

### 9. 绘图与图形
- `QPainter` 2D 绘图
- `QPixmap` / `QImage` 图片处理
- `QGraphicsView` 框架（场景/视图/图元）

### 10. 多线程
- `QThread`、`QThreadPool` + `QRunnable`
- `QtConcurrent`、`QFuture` / `QFutureWatcher`
- 线程间通信：跨线程信号槽、`QMutex`、`QWaitCondition`
- 练习：做一个带进度条的批量文件复制工具

### 11. 网络
- `QNetworkAccessManager`、`QNetworkReply`
- 练习：做一个简单的 HTTP GET 天气查询客户端

## 第五阶段：项目实战

做一个综合项目，比如：
- **简易记事本**（QTextEdit + 文件读写 + 查找替换 + 打印）
- **图片浏览器**（QGraphicsView + 缩略图列表 + 缩放旋转）
- **学生管理系统**（QTableView + SQL/JSON + 增删改查）

---

## 学习建议

| 方面 | 建议 |
|------|------|
| **官方文档** | Qt 5.15 文档离线版或 [doc.qt.io/qt-5](https://doc.qt.io/qt-5/)，遇到类直接 F1 查 |
| **调试** | 尽早熟悉 `qDebug()` 输出和 Qt Creator 的调试器 |
| **代码规范** | 每个控件练习都写一个小 demo，不要光看 |
| **源码** | 遇到困惑时直接看 Qt 源码（Qt Creator 里 F2 跳转），比任何教程都权威 |
| **Assistant** | Qt 自带的 Qt Assistant 离线文档工具，建议常开 |
