QT += widgets network

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    # drawwidget.cpp \
    # countertask.cpp \
    # counterwidget.cpp \
    handledelegate.cpp \
    main.cpp \
    # savethread.cpp \
    # todolista.cpp \
    # mutextask.cpp \
    savestudentthread.cpp \
    scoredelegate.cpp \
    studentwidget.cpp
    # weatherwidget.cpp

HEADERS += \
    # drawwidget.h \
    # countertask.h \
    # counterwidget.h \
    # savethread.h \
    # todolista.h \
    # mutextask.h \
    handledelegate.h \
    savestudentthread.h \
    scoredelegate.h \
    studentwidget.h
    # weatherwidget.h


TRANSLATIONS += \
    HelloQt_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
