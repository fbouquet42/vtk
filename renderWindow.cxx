#include "renderWindow.h"

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNamedColors.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkCamera.h>

tel::RenderWindow::RenderWindow() : QVTKOpenGLNativeWidget()
{
	// before initializing QApplication, set the default surface format.
QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

vtkNew<vtkGenericOpenGLRenderWindow> window;
this->setRenderWindow(window.Get());



  vtkNew<vtkNamedColors> colors;

  // Set the background color.
  std::array<unsigned char, 4> bkg{{26, 51, 102, 255}};
  colors->SetColor("BkgColor", bkg.data());

  // This creates a polygonal cylinder model with eight circumferential facets
  // (i.e, in practice an octagonal prism).
  vtkNew<vtkCylinderSource> cylinder;
  cylinder->SetResolution(8);

  // The mapper is responsible for pushing the geometry into the graphics
  // library. It may also do color mapping, if scalars or other attributes are
  // defined.
  vtkNew<vtkPolyDataMapper> cylinderMapper;
  cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

  // The actor is a grouping mechanism: besides the geometry (mapper), it
  // also has a property, transformation matrix, and/or texture map.
  // Here we set its color and rotate it around the X and Y axes.
  vtkNew<vtkActor> cylinderActor;
  cylinderActor->SetMapper(cylinderMapper);
  cylinderActor->GetProperty()->SetColor(
      colors->GetColor4d("Tomato").GetData());
  cylinderActor->RotateX(30.0);
  cylinderActor->RotateY(-45.0);

  // The renderer generates the image
  // which is then displayed on the render window.
  // It can be thought of as a scene to which the actor is added
  vtkNew<vtkRenderer> renderer;
  renderer->AddActor(cylinderActor);
  renderer->SetBackground(colors->GetColor3d("BkgColor").GetData());
  // Zoom in a little by accessing the camera and invoking its "Zoom" method.
  renderer->ResetCamera();
  renderer->GetActiveCamera()->Zoom(1.5);


  renderWindow()->AddRenderer(renderer);
	renderWindow()->Render();
  /*
  // The render window is the actual GUI window
  // that appears on the computer screen
  vtkNew<vtkRenderWindow> renderWindow;
  renderWindow->SetSize(300, 300);
  renderWindow->AddRenderer(renderer);
  renderWindow->SetWindowName("Cylinder");

  // The render window interactor captures mouse events
  // and will perform appropriate camera or actor manipulation
  // depending on the nature of the events.
  vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
  renderWindowInteractor->SetRenderWindow(renderWindow);

  // This starts the event loop and as a side effect causes an initial render.
//  renderWindow->Render();
  renderWindowInteractor->Start();
*/
// If using any of the standard view e.g. vtkContextView, then
// you can do the following.
//vtkNew<vtkContextView> view;
//view->SetRenderWindow(window.Get());

// You can continue to use `window` as a regular vtkRenderWindow
//
//
//	this->setRenderWindow(vtkGenericOpenGLRenderWindow::New());
	//this->initializeGL();
//	std::cout << "ok" << std::endl;
	//renderWindow()->
}