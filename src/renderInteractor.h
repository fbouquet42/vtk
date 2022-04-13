#ifndef EASYLIB_RENDERINTERACTOR_H
# define EASYLIB_RENDERINTERACTOR_H

#include <vtkInteractorStyleTrackballCamera.h>

#include <QAction>

namespace tel {

	class RenderInteractor : public vtkInteractorStyleTrackballCamera
	{
		public:
			static RenderInteractor* New();
			vtkTypeMacro(RenderInteractor, vtkInteractorStyleTrackballCamera);

			RenderInteractor();
			virtual ~RenderInteractor();

			virtual void OnRightButtonDown() override;

		private:
			QAction *cutAct;
			QAction *copyAct;
			QAction *pasteAct;
	};

} //el

#endif //EASYLIB_RENDERINTERACTOR_H
