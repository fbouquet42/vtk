message('   including src.pri')

INCLUDEPATH += $$PWD

SOURCES += $$PWD/main.cxx \
	$$PWD/window.cxx \
	$$PWD/toolBar.cxx \
	$$PWD/renderWindow.cxx \
	$$PWD/renderInteractor.cxx

HEADERS  += $$PWD/window.h \
	$$PWD/toolBar.h \
	$$PWD/renderWindow.h \
	$$PWD/renderInteractor.h
