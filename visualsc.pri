

CONFIG(release, debug|release) {
    OBJECTS_DIR = $${PWD}/bin/release
} else {
    OBJECTS_DIR = $${PWD}/bin/debug
}

QMAKE_RPATHDIR+=$${OBJECTS_DIR}
MOC_DIR = $${OBJECTS_DIR}
DESTDIR = $${OBJECTS_DIR}
OBJECTS_DIR = $${OBJECTS_DIR}
DLLDESTDIR = $${OBJECTS_DIR}
UI_DIR = $${OBJECTS_DIR}
RCC_DIR = $${OBJECTS_DIR}
LIB_PATH = $${OBJECTS_DIR}


