#pragma once
#include <QString>
#include <QStringList>

class AnalyzeModel {
public:
	AnalyzeModel() {}

	QStringList compare();

	QString folder1, folder2;
};