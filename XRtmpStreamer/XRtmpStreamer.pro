
QT += core
QT += gui
QT += xml
QT += widgets
QT += network
QT += multimedia


APP_SOURCE_TREE = $$PWD
#message("APP_SOURCE_TREE is: $$APP_SOURCE_TREE")

isEmpty(APP_BUILD_TREE) {
    sub_dir = $$_PRO_FILE_PWD_
    sub_dir ~= s,^$$re_escape($$PWD),,
    APP_BUILD_TREE = $$clean_path($$OUT_PWD)
    APP_BUILD_TREE ~= s,$$re_escape($$sub_dir)$,,
}
#message("APP_BUILD_TREE is: $$APP_BUILD_TREE")

APP_LIBRARY_PATH = $$clean_path($$APP_SOURCE_TREE/../lib)
#message("APP_LIBRARY_PATH is: $$APP_LIBRARY_PATH")



TEMPLATE = app
TARGET = XRtmpStreamer
DESTDIR = $$clean_path($$APP_SOURCE_TREE/../bin)

CONFIG += c++11
CONFIG += console

#DEFINES += WIN64 QT_MULTIMEDIA_LIB QT_WIDGETS_LIB
#DEFINES += QT_NO_DEBUG_OUTPUT


INCLUDEPATH += .
INCLUDEPATH += $$APP_SOURCE_TREE/../include


LIBS += -L$$APP_LIBRARY_PATH -lavcodec
LIBS += -L$$APP_LIBRARY_PATH -lavdevice
LIBS += -L$$APP_LIBRARY_PATH -lavfilter
LIBS += -L$$APP_LIBRARY_PATH -lavformat
LIBS += -L$$APP_LIBRARY_PATH -lavutil
LIBS += -L$$APP_LIBRARY_PATH -lpostproc
LIBS += -L$$APP_LIBRARY_PATH -lswresample
LIBS += -L$$APP_LIBRARY_PATH -lswscale

LIBS += $$APP_LIBRARY_PATH/libopencv_*.a



HEADERS += XAudioRecord.h \
    XBilateralFilter.h \
    XController.h \
    XData.h \
    XDataThread.h \
    XFilter.h \
    XMediaEncode.h \
    XRtmp.h \
    XVideoCapture.h \
    XRtmpStreamer.h

SOURCES += main.cpp \
    XAudioRecord.cpp \
    XBilateralFilter.cpp \
    XController.cpp \
    XData.cpp \
    XDataThread.cpp \
    XFilter.cpp \
    XMediaEncode.cpp \
    XRtmp.cpp \
    XVideoCapture.cpp \
    XRtmpStreamer.cpp

RESOURCES += XRtmpStreamer.qrc

FORMS += \
    XRtmpStreamer.ui



