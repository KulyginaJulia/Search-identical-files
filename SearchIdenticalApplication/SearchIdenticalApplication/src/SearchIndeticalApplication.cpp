#include "../include/SearchIndeticalApplication.h"
#include <QFileDialog>
#include <QMessageBox>

SearchIndeticalApplication::SearchIndeticalApplication(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.folder1Button, SIGNAL(clicked()), this, SLOT(openFirstFolder()));
	connect(ui.folder2Button, SIGNAL(clicked()), this, SLOT(openSecondFolder()));
	connect(ui.compareButton, SIGNAL(clicked()), this, SLOT(compare()));
	model = new AnalyzeModel();
}

void SearchIndeticalApplication::openFirstFolder() {
	QFileDialog fileOpen(this, tr("Open file"));
	fileOpen.setAcceptMode(QFileDialog::AcceptOpen);
	fileOpen.setFileMode(QFileDialog::Directory);

	if (!fileOpen.exec())
		return;

	QStringList fileNames = fileOpen.selectedFiles();
	if (fileNames.size() == 0)
		return;
	QString fileName = fileNames[0];

	QFileInfo fi(fileName);
	if (!fi.exists() || !fi.isReadable()) {
		QMessageBox::critical(this, "Error in file opening", QString("Can't open file %1").arg(fileName));
		return;
	}
	ui.path1Label->setText(fileName);
	model->folder1 = fileName;
}

void SearchIndeticalApplication::openSecondFolder() {
	QFileDialog fileOpen(this, tr("Open file"));
	fileOpen.setAcceptMode(QFileDialog::AcceptOpen);
	fileOpen.setFileMode(QFileDialog::Directory);

	if (!fileOpen.exec())
		return;

	QStringList fileNames = fileOpen.selectedFiles();
	if (fileNames.size() == 0)
		return;
	QString fileName = fileNames[0];

	QFileInfo fi(fileName);
	if (!fi.exists() || !fi.isReadable()) {
		QMessageBox::critical(this, "Error in file opening", QString("Can't open file %1").arg(fileName));
		return;
	}

	ui.path2Label->setText(fileName);
	model->folder2 = fileName;
}

void SearchIndeticalApplication::compare() {
	ui.resultOuttputWidget->clear();

	QStringList output = model->compare();

	foreach(QString text, output) {
		ui.resultOuttputWidget->append(text);
	}
}