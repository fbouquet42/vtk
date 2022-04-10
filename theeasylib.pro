message("read The Easy Library QtConfigfile (theeasylib.pro)")

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG+=sdk_no_version_check

DESTDIR = ./build/
CONFIG  += release
CONFIG -= app_bundle
TARGET = viewer
TEMPLATE = app

MOC_DIR = build/.moc
OBJECTS_DIR = build/.obj
UI_DIR      = build/.ui
RCC_DIR     = build/

LIBS += -L/usr/local/opt/vtk/lib/ -lvtkGUISupportQt-9.1 -lvtkCommonExecutionModel-9.1 -lvtkIOCore-9.1 -lvtkCommonColor-9.1 -lvtkCommonCore-9.1 -lvtkFiltersSources-9.1 -lvtkInteractionStyle-9.1 -lvtkRenderingContextOpenGL2-9.1 -lvtkRenderingCore-9.1 -lvtkRenderingFreeType-9.1 -lvtkRenderingGL2PSOpenGL2-9.1 -lvtkRenderingOpenGL2-9.1
#LIBS+= -L/usr/local/Cellar/glfw/3.3.7/lib -lglfw
#LIBS += -L/usr/local/Cellar/glew/2.2.0_1/lib -lGLEW
INCLUDEPATH += /usr/local/opt/vtk/include/vtk-9.1/

SOURCES += main.cxx \
	window.cxx \
	toolBar.cxx \
	renderWindow.cxx \
	renderInteractor.cxx

HEADERS  += window.h \
	toolBar.h \
	renderWindow.h \
	renderInteractor.h

FORMS    += \
