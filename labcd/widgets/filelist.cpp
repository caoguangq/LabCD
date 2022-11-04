#include <QVBoxLayout>
#include "filelist.h"

FileList::FileList(QWidget *parent)
	: QWidget(parent)
{
	// ����
	QVBoxLayout* vLayout = new QVBoxLayout(this);
	fList = new QListWidget(this);
	vLayout->addWidget(fList);
	// ����
	setLayout(vLayout);
}

FileList::~FileList()
{

}

void FileList::addFileNames(QStringList t1List, QStringList t2List)
{
	t1Files = t1List;
	t2Files = t2List;
	// ��ʾ
	fList->addItems(t1Files);
	fList->setCurrentRow(t1Files.size() - 1);  // �ƶ�λ��
}
