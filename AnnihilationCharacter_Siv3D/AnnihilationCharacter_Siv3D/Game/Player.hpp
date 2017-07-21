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
		//�f�o�b�N�p
		siv::Circle circle;

		//�ړ��A�N�V����
		void Move() {
			SetPos({ GetPos().x,GetPos().y + yv });
			yv += g;
			if (GetUnderY() >= 425) {
				jumpCount = 0;
				SetUnderY(425 );
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
		Player():circle(3){}

		//��l���̑����̍����𓾂�
		double GetUnderY() {
			return GetPos().y + 35 ;
		}

		//��l���̑����̍������Z�b�g����
		void SetUnderY(double y) {
			SetPos({ GetPos().x,y - 35 });
		}

		virtual void Update()override {
			elipmocframework::FontObject::Update();
			Move();
			circle.setPos(GetPos().x,GetUnderY()).draw(siv::Palette::Red);
		}
	};

}