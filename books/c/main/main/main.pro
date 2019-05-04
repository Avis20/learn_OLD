QT += core
QT -= gui

TARGET = main
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.c \
    chapter5.c \
    chapter1.c \
    mygrep.c \
    myqsort.c \
    chapter4.c \
    chapter6.c

HEADERS += \
    chapter5.h \
    chapter1.h \
    mygrep.h \
    myqsort.h \
    chapter4.h \
    chapter6.h

DISTFILES += \
    mygrep.t

