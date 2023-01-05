message("You are running qmake on a generated .pro file. This may not work!")


HEADERS += ./DatabaseRepository.h \
    ./FlightInfo.h \
    ./resource.h \
    ./FlightManagement.h \
    ./SearchResult.h \
    ./Management.h
SOURCES += ./Management.cpp \
    ./SearchResult.cpp \
    ./DatabaseRepository.cpp \
    ./FlightInfo.cpp \
    ./FlightManagement.cpp \
    ./main.cpp
FORMS += ./FlightManagement.ui \
    ./ManagementUI.ui \
    ./SearchResult.ui
RESOURCES += FlightManagement.qrc
