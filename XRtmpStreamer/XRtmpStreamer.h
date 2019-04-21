#ifndef XRTMPSTREAMER_H
#define XRTMPSTREAMER_H

#include <QWidget>

namespace Ui {
class XRtmpStreamer;
}

class XRtmpStreamer : public QWidget
{
	Q_OBJECT
public:
    explicit XRtmpStreamer(QWidget *parent = 0);
    ~XRtmpStreamer();

public slots:
	void Stream();

private slots:
    void on_startButton_clicked();

private:
    Ui::XRtmpStreamer *ui;
};

#endif


