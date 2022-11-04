#pragma once

#include <QtWidgets/QMainWindow>
#include "widgets/labeltable.h"
#include "widgets/filelist.h"

class LabCD : public QMainWindow
{
    Q_OBJECT

private:
    void openDir();

public:
    FileList* fListWidget;  // �����б�
    LabelTable* labTableWidget;  // ��ǩ�б�

    LabCD(QWidget *parent = nullptr);
    ~LabCD();
};
