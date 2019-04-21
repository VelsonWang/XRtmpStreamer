
#include "XRtmpStreamer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    XRtmpStreamer win;
    win.show();
	return a.exec();
}
