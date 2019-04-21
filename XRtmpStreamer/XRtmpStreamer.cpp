
#include "XRtmpStreamer.h"
#include "ui_XRtmpStreamer.h"
#include <iostream>
#include "XController.h"

using namespace std;

static bool isStream = false;

XRtmpStreamer::XRtmpStreamer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::XRtmpStreamer) {
    ui->setupUi(this);
}

XRtmpStreamer::~XRtmpStreamer() {
    delete ui;
}

void XRtmpStreamer::Stream()
{
	cout << "Stream";
	if (isStream)
	{
		isStream = false;
        ui->startButton->setText(QString::fromLocal8Bit("开始"));
		XController::Get()->Stop();
	}
	else
	{
		isStream=true;
        ui->startButton->setText(QString::fromLocal8Bit("停止"));
        QString url = ui->inUrl->text();
		bool ok = false;
		int camIndex = url.toInt(&ok);
		if (!ok)
		{
			XController::Get()->inUrl = url.toStdString();
		}
		else
		{
			XController::Get()->camIndex = camIndex;
		}
        XController::Get()->outUrl = ui->outUrl->text().toStdString();
        XController::Get()->Set("b", (ui->face->currentIndex() + 1) * 3 );
		XController::Get()->Start();
	}
	
}

void XRtmpStreamer::on_startButton_clicked()
{
    Stream();
}
