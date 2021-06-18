QT -= gui
CONFIG -= qt

CONFIG += c++11 console
CONFIG -= app_bundle

#PREFIX = /opt/importLib
isEmpty(PREFIX) {
  PREFIX = /opt/importLib
}

#QMAKE_LFLAGS_RPATH += /opt/importLib/lib

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

target.path = /opt/importLib/bin
LIBS += -ldl

QMAKE_LFLAGS_RPATH=
QMAKE_LFLAGS += "-Wl,-rpath,$${PREFIX}/lib"

LIBS += -L$$OUT_PWD/../importLib/ -limportLib

INCLUDEPATH += $$PWD/../importLib
DEPENDPATH += $$PWD/../importLib

!isEmpty(target.path): INSTALLS += target
