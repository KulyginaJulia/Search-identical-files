#pragma once

#include <QtWidgets/QMainWindow>
#include "AnalyzeModel.h"
#include "ui_SearchIndeticalApplication.h"

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
