#ifndef EASYLIB_RENDERINTERACTOR_H
# define EASYLIB_RENDERINTERACTOR_H

#include <vtkInteractorStyleTrackballCamera.h>

namespace tel {

	class RenderInteractor : public vtkInteractorStyleTrackballCamera
	{
		public:
			static RenderInteractor* New();
			vtkTypeMacro(RenderInteractor, vtkInteractorStyleTrackballCamera);

		virtual void OnRightButtonDown() override;
	};

} //el

#endif //EASYLIB_RENDERINTERACTOR_H
