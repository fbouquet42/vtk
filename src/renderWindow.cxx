#include "renderWindow.h"
#include "renderInteractor.h"

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNamedColors.h>
#include <vtkType.h>
#include <vtkPoints.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkCamera.h>

tel::RenderWindow::RenderWindow() : QVTKOpenGLNativeWidget()
{
	// before initializing QApplication, set the default surface format.

vtkNew<vtkGenericOpenGLRenderWindow> window;
this->setRenderWindow(window.Get());

vtkNew<RenderInteractor> interactorStyle;
this->interactor()->SetInteractorStyle(interactorStyle);


  vtkNew<vtkNamedColors> colors;

  // Set the background color.
  std::array<unsigned char, 4> bkg{{26, 51, 102, 255}};
  colors->SetColor("BkgColor", bkg.data());

  vtkNew<vtkPoints> points;
  points->Allocate(8);
  points->InsertNextPoint(-1., 1., 1.);
  points->InsertNextPoint(1., 1., 1.);

  points->InsertNextPoint(-1., 1., -1.);
  points->InsertNextPoint(1., 1., -1.);

  points->InsertNextPoint(-1., -1., 1.);
  points->InsertNextPoint(1., -1., 1.);

  points->InsertNextPoint(-1., -1., -1.);
  points->InsertNextPoint(1., -1., -1.);

  vtkNew<vtkUnstructuredGrid> ugrid;
  ugrid->Allocate(6);

  vtkIdType ids1[4] = {0, 1, 3, 2};
  ugrid->InsertNextCell(VTK_QUAD, 4, ids1);
  vtkIdType ids2[4] = {0, 2, 6, 4};
  ugrid->InsertNextCell(VTK_QUAD, 4, ids2);
  vtkIdType ids3[4] = {0, 1, 5, 4};
  ugrid->InsertNextCell(VTK_QUAD, 4, ids3);
  vtkIdType ids4[4] = {2, 3, 7, 6};
  ugrid->InsertNextCell(VTK_QUAD, 4, ids4);
  vtkIdType ids5[4] = {1, 3, 7, 5};
  ugrid->InsertNextCell(VTK_QUAD, 4, ids5);
  vtkIdType ids6[4] = {4, 5, 7, 6};
  ugrid->InsertNextCell(VTK_QUAD, 4, ids6);

  ugrid->SetPoints(points);

  vtkNew<vtkDataSetMapper> dataSetMapper;
  dataSetMapper->SetInputData(ugrid);

  vtkNew<vtkActor> mActor;
  mActor->SetMapper(dataSetMapper);
//  mActor->GetProperty()->EdgeVisibilityOn();
  mActor->GetProperty()->SetColor(
      colors->GetColor3d("Tomato").GetData());
  mActor->RotateX(30.0);
  mActor->RotateY(-45.0);

  vtkNew<vtkRenderer> renderer;
  renderer->AddActor(mActor);
  renderer->SetBackground(colors->GetColor3d("BkgColor").GetData());
  renderer->ResetCamera();
  renderer->GetActiveCamera()->Zoom(1.5);


  renderWindow()->AddRenderer(renderer);
	renderWindow()->Render();
}
