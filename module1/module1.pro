CONFIG -= qt

TEMPLATE = lib
DEFINES += MODULE1_LIBRARY

CONFIG += c++11

isEmpty(PREFIX) {
  PREFIX = /opt/importLib
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    module1.cpp

HEADERS += \
    module1.h

target.path = $${PREFIX}/lib
!isEmpty(target.path): INSTALLS += target


LIBS += -L$$OUT_PWD/../importLib/ -limportLib

INCLUDEPATH += $$PWD/../importLib
DEPENDPATH += $$PWD/../importLib
