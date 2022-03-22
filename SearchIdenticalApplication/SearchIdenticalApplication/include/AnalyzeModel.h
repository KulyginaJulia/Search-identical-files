#pragma once
#include <QString>
#include <QStringList>
#include <QDir>

class AnalyzeModel {

public:
	AnalyzeModel() {}

	QString folder1, folder2;

	QStringList compare() {
		if (folder1.isEmpty() || folder2.isEmpty())
			return QStringList("i don't have any folders :( ");

		QDir directory1(folder1);
		QStringList files1 = directory1.entryList(QDir::Files, QDir::Size);
		QStringList result;
		foreach(QString filename, files1) {
			result << filename;
		}

		return result;
	}
};