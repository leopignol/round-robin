TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

oracle_files.files = $$PWD/*.in $$PWD/*.oracle
oracle_files.path = $$OUT_PWD

SOURCES += \
    main.cpp

COPIES += \
    oracle_files

DISTFILES += \
    1.in \
    2.in \
    1.oracle \
    2.oracle \
    README.md
