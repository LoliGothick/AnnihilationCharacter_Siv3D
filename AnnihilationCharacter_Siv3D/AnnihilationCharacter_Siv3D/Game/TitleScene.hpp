#pragma once
#include "SceneBase.hpp"
namespace game {
	
	class TitleScene :public MySceneBase {
		const siv::Font m_titleFont;
		const siv::Font m_subTitleFont;
		const siv::Font m_guideFont;
		double m_angle=0;
	public:
		TitleScene():m_titleFont(40),m_subTitleFont(20),m_guideFont(15){}
		virtual void init()override {
			siv::Graphics::SetBackground(siv::Palette::Black);
		}
		virtual void update()override {
			if (siv::Input::KeyEnter.clicked)
				changeScene(L"SelectPlayer");
			m_angle+=3;
		}
		virtual void draw() const override{
			using namespace siv::Math;
			using namespace siv::Window;
			m_titleFont(L"���ŕ���").drawCenter(Center().x, Center().y - 70);
			m_subTitleFont(L"�`AnnihilationCharacter�`").drawCenter(Center().x,Center().y, siv::Palette::Gold);
			m_guideFont(L"Start EnterKey").drawCenter(Center().x, Center().y + 40, { 0,100,255,static_cast<uint32>(128 - 127 * Sin(Radians(m_angle))) });
		}
	};
}