QT += core gui widgets

CONFIG += c++17
TEMPLATE = app
TARGET = LibrarySystem

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    library.cpp \
    resource.cpp \
    book.cpp \
    article.cpp \
    thesis.cpp \
    digitalmedia.cpp \
    user.cpp \
    student.cpp \
    faculty.cpp \
    loan.cpp \
    reservation.cpp \
    libraryevent.cpp \
    notification.cpp

HEADERS += \
    mainwindow.h \
    library.h \
    resource.h \
    book.h \
    article.h \
    thesis.h \
    digitalmedia.h \
    user.h \
    student.h \
    faculty.h \
    loan.h \
    reservation.h \
    libraryevent.h \
    notification.h

FORMS += mainwindow.ui
