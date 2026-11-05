TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

config_files.files = $$PWD/*.in $$PWD/*.oracle
config_files.path = $$OUT_PWD

SOURCES += \
        main.cpp

COPIES += config_files
