﻿#include "TitleScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameScene.hpp"

void Main()
{
	siv::Window::SetTitle(L"消滅文字 ver 114524");
	siv::Window::Resize(700, 480);
	game::MySceneManager mySceneManager;
	mySceneManager.add<game::TitleScene>(L"Title");
	mySceneManager.add<game::SelectPlayerScene>(L"SelectPlayer");
	mySceneManager.add<game::GameScene>(L"Game");
	while (siv::System::Update() && mySceneManager.updateAndDraw());
}
