﻿#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QGraphicsView>
#include <QAction>
#include <QLabel>
#include <QString>
#include "labcd.h"

LabCD::LabCD(QWidget *parent)
    : QMainWindow(parent)
{
    /* 状态栏 */
    QStatusBar* lcdStatusBar = statusBar();
    QLabel* messageState = new QLabel("当前消息：", this);  // 用于显示消息
    lcdStatusBar->addWidget(messageState);

    /* 菜单栏 */
    QMenuBar* lcdMenuBar = menuBar();
    QMenu* fileMenu = new QMenu("文件", this);
    QAction* openAct = fileMenu->addAction(
        QIcon(":/menu/resources/File.png"), "打开文件");
    QAction* opensAct = fileMenu->addAction(
        QIcon(":/menu/resources/Folder.png"), "打开文件夹");
    lcdMenuBar->addMenu(fileMenu);
    QMenu* aboutMenu = new QMenu("关于", this);
    lcdMenuBar->addMenu(aboutMenu);

    /* 工具栏 */
    QToolBar* lcdToolBar = new QToolBar(this);
    QAction* enlargeAct = lcdToolBar->addAction(
        QIcon(":/tools/resources/Enlarge.png"), "放大");
    QAction* narrowAct = lcdToolBar->addAction(
        QIcon(":/tools/resources/Narrow.png"), "缩小");
    QAction* fullAct = lcdToolBar->addAction(
        QIcon(":/tools/resources/Full.png"), "全幅缩放");
    lcdToolBar->addSeparator();
    QAction* undoAct = lcdToolBar->addAction(
        QIcon(":/tools/resources/Undo.png"), "撤销");
    QAction* redoAct = lcdToolBar->addAction(
        QIcon(":/tools/resources/Redo.png"), "重做");
    lcdToolBar->setMovable(false);
    addToolBar(Qt::LeftToolBarArea, lcdToolBar);

    /* 绘图界面 */
    QGraphicsView* canvas = new QGraphicsView(this);
    setCentralWidget(canvas);

    /* 图像文件列表 */
    QDockWidget* filesDock = new QDockWidget("图像列表", this);
    filesDock->setAllowedAreas(Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, filesDock);

    /* 标签列表 */
    QDockWidget* labelsDock = new QDockWidget("标签列表", this);
    labelsDock->setAllowedAreas(Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, labelsDock);
    
    /* 界面设置 */
    resize(800, 600);
    setWindowTitle("LabCD - 遥感变化检测标注工具");
    setWindowIcon(QIcon(":/main/resources/Icon.png"));
}

LabCD::~LabCD()
{

}
