SOURCES += medit.cpp \
           main.cpp \
	   stareditor.cpp \
	   starrating.cpp \
	   stardelegate.cpp \
	   combodelegate.cpp \
 micronprogram.cpp
HEADERS += medit.h \
           stareditor.h \
           starrating.h \
           stardelegate.h \
	   combodelegate.h \
 micronprogram.h
TEMPLATE = app
CONFIG += warn_on \
	  thread \
	  debug \
          qt
TARGET = ../bin/medit
RESOURCES = application.qrc
