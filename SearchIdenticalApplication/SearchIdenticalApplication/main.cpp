#include "include/SearchIndeticalApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	SearchIndeticalApplication w;
    w.show();
    return a.exec();
}
