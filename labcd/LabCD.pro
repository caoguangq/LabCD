# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = LabCD
DESTDIR = ./x64/Release
CONFIG += release
LIBS += -L"." \
    -lgdal_i \
    -lopencv_world455 \
    -ljsoncpp_static
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += release
UI_DIR += GeneratedFiles
RCC_DIR += .
include(LabCD.pri)
TRANSLATIONS += i18n/English.ts
