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
	QFileDialog folderOpen(this, tr("Select folder"));
	folderOpen.setAcceptMode(QFileDialog::AcceptOpen);
	folderOpen.setFileMode(QFileDialog::Directory);

	if (!folderOpen.exec())
		return;

	QStringList folderNames = folderOpen.selectedFiles();
	if (folderNames.size() == 0)
		return;
	QString folderName = folderNames[0];

	QFileInfo fi(folderName);
	if (!fi.exists() || !fi.isReadable()) {
		QMessageBox::critical(this, "Error in directory opening", QString("Can't open directory %1").arg(folderName));
		return;
	}
	ui.path1Label->setText(folderName);
	model->folder1 = folderName;
}

void SearchIndeticalApplication::openSecondFolder() {
	QFileDialog folderOpen(this, tr("Select folder"));
	folderOpen.setAcceptMode(QFileDialog::AcceptOpen);
	folderOpen.setFileMode(QFileDialog::Directory);

	if (!folderOpen.exec())
		return;

	QStringList folderNames = folderOpen.selectedFiles();
	if (folderNames.size() == 0)
		return;
	QString folderName = folderNames[0];

	QFileInfo fi(folderName);
	if (!fi.exists() || !fi.isReadable()) {
		QMessageBox::critical(this, "Error in directory opening", QString("Can't open directory %1").arg(folderName));
		return;
	}
	ui.path2Label->setText(folderName);
	model->folder2 = folderName;
}

void SearchIndeticalApplication::compare() {
	ui.resultOuttputWidget->clear();

	QStringList output = model->compare();

	foreach(QString text, output) {
		ui.resultOuttputWidget->append(text);
	}
}