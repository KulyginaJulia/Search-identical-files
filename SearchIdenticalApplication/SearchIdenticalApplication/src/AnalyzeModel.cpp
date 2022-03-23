#include "../include/AnalyzeModel.h"
#include <QDir>
#include <QFile>
#include <QDataStream>

QStringList AnalyzeModel::compare() {
	QDir directory1(folder1);
	QStringList fileList11 = directory1.entryList(QDir::Files, QDir::Size | QDir::Reversed);

	QDir directory2(folder2);
	QStringList fileList2 = directory2.entryList(QDir::Files, QDir::Size | QDir::Reversed);

	QStringList result;
	foreach(QString filename1, fileList11) {
		QFile file1(directory1.filePath(filename1));
		if (file1.open(QIODevice::ReadOnly)) {
			bool duplicate = true;
			foreach(QString filename2, fileList2) {
				QFile file2(directory2.filePath(filename2));

				int size1 = file1.size();
				int size2 = file2.size();

				if (file1.size() < file2.size())
					break;

				if (file1.size() > file2.size())
					continue;

				if (file2.open(QIODevice::ReadOnly)) {
					char binFile1[4096];
					char binFile2[4096];

					while (duplicate) {
						int64_t rm = file1.read(&binFile1[0], 4096);
						int64_t rd = file2.read(&binFile2[0], 4096);
						int64_t len = std::min(rm, rd);

						for (int i = 0; i < len; i++) {
							if (binFile1[i] != binFile2[i]) {
								duplicate = false;
								break;
							}
						}

						if (len < 4096)
							break;

					}

					if (duplicate) {
						result << filename1 + " has duplicate which name is " + filename2;
					}
					file2.close();
				}
			}
			file1.close();
		}
	}

	return result;
}