QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common.cpp \
    exception.cpp \
    loader/loader.cpp \
    loader/nca.cpp \
    loader/nsp.cpp \
    main.cpp \
    mainwindow.cpp \
    ui/filesystem_modal.cpp \
    ui/filesystem_treeview.cpp \
    util.cpp \
    vfs/filesystem.cpp

HEADERS += \
    common.h \
    exception.h \
    loader/loader.h \
    loader/nca.h \
    loader/nsp.h \
    mainwindow.h \
    ui/filesystem_modal.h \
    ui/filesystem_treeview.h \
    util.h \
    vfs/filesystem.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
