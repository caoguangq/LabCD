#pragma once

#include <QtWidgets/QMainWindow>
#include "widgets/labeltable.h"
#include "widgets/filelist.h"
#include "widgets/multcanvas.h"

class LabCD : public QMainWindow
{
    Q_OBJECT

private:
    void openDir();

public:
    FileList* fListWidget = nullptr;  // �����б�
    LabelTable* labTableWidget = nullptr;  // ��ǩ�б�
    MultCanvas* drawCanvas = nullptr;  // ��ͼ����

    LabCD(QWidget *parent = nullptr);
    ~LabCD();
};
