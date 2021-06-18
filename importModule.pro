TEMPLATE = subdirs

isEmpty(PREFIX) {
  PREFIX = /opt/importLib
}

SUBDIRS += \
    importLib \
    module1 \
    module2 \
    test \
#    testWithoutSubproject # after make install
