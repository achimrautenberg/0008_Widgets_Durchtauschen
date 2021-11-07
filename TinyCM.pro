QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Account.cpp \
    Dlg_Login.cpp \
    Widget_Accounts.cpp \
    Widget_Plugins.cpp \
    common.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Account.h \
    Dlg_Login.h \
    MainWindow.h \
    Widget_Accounts.h \
    Widget_Plugins.h \
    common.h

FORMS += \
    Dlg_Login.ui \
    MainWindow.ui \
    Widget_Accounts.ui \
    Widget_Plugins.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
