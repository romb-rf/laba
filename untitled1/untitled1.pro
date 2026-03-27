QT += core
QT -= gui
QT += testlib

TARGET = tst
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app


GTEST_PATH = "C:\Users\rombr\Desktop\laba\googletest-1.17.0\googletest-1.17.0\googletest"
GMOCK_PATH = "C:\Users\rombr\Desktop\laba\googletest-1.17.0\googletest-1.17.0\googlemock"

# Путь к исходникам тестируемого класса
SRC_PATH = "C:\Users\rombr\Desktop\laba\labaProga"

INCLUDEPATH += $$GTEST_PATH/include \
               $$GMOCK_PATH/include \
               $$GTEST_PATH \
               $$GMOCK_PATH \
               $$SRC_PATH

VPATH += $$GTEST_PATH/src

# Исходные файлы
SOURCES += gtest-all.cc \
           main.cpp \
           tst.cpp \
           $$SRC_PATH/recursionVar1.cpp \
           $$SRC_PATH/iteration.cpp \
           $$SRC_PATH/datamanager.cpp \
           $$SRC_PATH/doptask.cpp \
           tst1.cpp \
           tst2.cpp \
           tst3.cpp

# Заголовочный файл для
HEADERS += $$SRC_PATH/recursionVar1.h \
           $$SRC_PATH/datamanager.h \
           $$SRC_PATH/doptask.h \
           $$SRC_PATH/iteration.h

DEFINES += GTEST_HAS_PTHREAD=0
