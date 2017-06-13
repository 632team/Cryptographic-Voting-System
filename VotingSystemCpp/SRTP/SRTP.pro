#-------------------------------------------------
#
# Project created by QtCreator 2017-05-27T21:07:29
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SRTP
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    userinfo.cpp \
    dao.cpp \
    voter.cpp \
    candidate.cpp \
    candidatewindow.cpp \
    loginfailure.cpp \
    registerwindow.cpp \
    inputerrorwindow.cpp \
    registersuccessful.cpp \
    candidatelistwindow.cpp \
    rsa.cpp \
    registercenter.cpp \
    notvaliduerwindow.cpp \
    signaturesystem.cpp \
    voterhelp.cpp \
    countcenter.cpp \
    showresult.cpp \
    qcustomplot.cpp \
    fhe_can.cpp

HEADERS  += mainwindow.h \
    userinfo.h \
    dao.h \
    voter.h \
    candidate.h \
    candidatewindow.h \
    loginfailure.h \
    registerwindow.h \
    inputerrorwindow.h \
    registersuccessful.h \
    candidatelistwindow.h \
    rsa.h \
    registercenter.h \
    notvaliduerwindow.h \
    signaturesystem.h \
    voterhelp.h \
    countcenter.h \
    showresult.h \
    qcustomplot.h \
    fhe_can.h \
    fhe_solve.h

FORMS    += mainwindow.ui \
    userinfo.ui \
    candidatewindow.ui \
    loginfailure.ui \
    registerwindow.ui \
    inputerrorwindow.ui \
    registersuccessful.ui \
    candidatelistwindow.ui \
    notvaliduerwindow.ui \
    showresult.ui

DISTFILES += \
    Photo.jpg

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../文档/mimaxue/HElib/src/release/ -lfhe
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../文档/mimaxue/HElib/src/debug/ -lfhe
else:unix: LIBS += -L$$PWD/../文档/mimaxue/HElib/src/ -lfhe

INCLUDEPATH += $$PWD/../文档/mimaxue/HElib/src
DEPENDPATH += $$PWD/../文档/mimaxue/HElib/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../文档/mimaxue/HElib/src/release/libfhe.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../文档/mimaxue/HElib/src/debug/libfhe.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../文档/mimaxue/HElib/src/release/fhe.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../文档/mimaxue/HElib/src/debug/fhe.lib
else:unix: PRE_TARGETDEPS += $$PWD/../文档/mimaxue/HElib/src/libfhe.a

unix|win32: LIBS += -lntl

unix|win32: LIBS += -lgmp
