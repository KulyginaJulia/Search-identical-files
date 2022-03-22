#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication1.h"
#include "AnalyzeModel.h"

class SearchIndeticalApplication : public QMainWindow
{
    Q_OBJECT

public:
	SearchIndeticalApplication(QWidget *parent = Q_NULLPTR);

public slots:
	void openFirstFolder();
	void openSecondFolder();
	void compare();

private:
    Ui::SearchIdenticalApplicationClass ui;
	AnalyzeModel* model;
};
