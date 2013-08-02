#include "BsEditorWindowBase.h"
#include "CmApplication.h"
#include "CmSceneObject.h"
#include "CmRenderWindow.h"

#include "BsCamera.h"
#include "BsGUIWindowFrameWidget.h"
#include "BsEngineGUI.h"

using namespace CamelotFramework;
using namespace BansheeEngine;

namespace BansheeEditor
{
	EditorWindowBase::EditorWindowBase()
	{
		RENDER_WINDOW_DESC renderWindowDesc;
		renderWindowDesc.width = 200;
		renderWindowDesc.height = 200;
		renderWindowDesc.title = "EditorWindow";
		renderWindowDesc.fullscreen = false;
		renderWindowDesc.border = WindowBorder::None;
		renderWindowDesc.toolWindow = true;

		mRenderWindow = RenderWindow::create(renderWindowDesc, gApplication().getPrimaryWindow());

		mSceneObject = SceneObject::create("EditorWindow");

		HCamera camera = mSceneObject->addComponent<Camera>();
		camera->initialize(mRenderWindow, 0.0f, 0.0f, 1.0f, 1.0f, 0);
		camera->setNearClipDistance(5);
		camera->setAspectRatio(1.0f);
		camera->setIgnoreSceneRenderables(true);

		mGUI = mSceneObject->addComponent<GUIWidget>();
		mGUI->initialize(camera->getViewport().get(), mRenderWindow.get());
		mGUI->setDepth(128);

		mGUI->setSkin(&EngineGUI::instance().getSkin());

		GameObjectHandle<WindowFrameWidget> frame = mSceneObject->addComponent<WindowFrameWidget>();
		frame->setSkin(&EngineGUI::instance().getSkin());
		frame->initialize(camera->getViewport().get(), mRenderWindow.get());
		frame->setDepth(129);
	}

	EditorWindowBase::~EditorWindowBase()
	{
		mRenderWindow->destroy();
	}

	void EditorWindowBase::setPosition(CM::INT32 x, CM::INT32 y)
	{
		// TODO
	}

	void EditorWindowBase::setSize(CM::UINT32 width, CM::UINT32 height)
	{
		// TODO
	}
}