#pragma once
#include "FontObject.hpp"

namespace game {

	class Player :public elipmocframework::FontObject {

		static constexpr double speed=3.5;
		//�d�͉����x
		double g=0.3;
		//Y�̑��x
		double yv=0;
		int jumpCount=0;
		//�ړ��A�N�V����
		void Move() {
			SetPos({ GetPos().x,GetPos().y + yv });
			yv += g;
			if (GetPos().y >= siv::Window::Size().y-75) {
				jumpCount = 0;
				SetPos({ GetPos().x,siv::Window::Size().y-75 });
				yv = 0;
			}
			if (siv::Input::KeySpace.clicked &&jumpCount < 2) {
				yv = -10;
				jumpCount++;
			}
			if (siv::Input::KeyRight.pressed)
				SetPos({ GetPos().x + speed, GetPos().y });
			if (siv::Input::KeyLeft.pressed)
				SetPos({ GetPos().x - speed, GetPos().y });
		}
	public:


		virtual void Update()override {
			elipmocframework::FontObject::Update();
			Move();
		}
	};

}