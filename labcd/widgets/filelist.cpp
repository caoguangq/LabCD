#include <QVBoxLayout>
#include "filelist.h"

FileList::FileList(QWidget *parent)
	: QWidget(parent)
{
	// ����
	QVBoxLayout* vLayout = new QVBoxLayout(this);
	fList = new QListWidget(this);
	connect(fList, &QListWidget::itemDoubleClicked, [=](QListWidgetItem* item) {
		QString t1Path = item->text();
		QString t2Path = t2Files.at(fList->currentRow());
		emit FileList::FileClickRequest(t1Path, t2Path);
	});  // �����źţ���ǰ������ļ���
	vLayout->addWidget(fList);
	// ����
	setLayout(vLayout);
}

FileList::~FileList()
{

}

void FileList::addFileNames(QStringList t1List, QStringList t2List)
{
	QStringList t1Files = t1List;
	t2Files = t2List;
	// ��ʾ
	fList->addItems(t1Files);
	fList->setCurrentRow(t1Files.size() - 1);  // �ƶ�λ��
}
