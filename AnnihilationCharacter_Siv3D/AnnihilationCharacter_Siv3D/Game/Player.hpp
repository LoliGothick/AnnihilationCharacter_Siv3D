#pragma once
#include "FontObject.hpp"

namespace game {

	class Player :public elipmocframework::FontObject {

		static constexpr double speed=3.5;
		//�d�͉����x
		double m_g=0.3;
		//Y�̑��x
		double m_yv=0;
		//�W�����v�����񐔋L�^
		int m_jumpCount=0;
		//�f�o�b�N�p
		siv::Circle circle;

		//�ړ��A�N�V����
		void Move() {
			SetPos({ GetPos().x,GetPos().y + m_yv });
			m_yv += m_g;
			if (GetUnderY() >= 425) {
				m_jumpCount = 0;
				SetUnderY(425 );
				m_yv = 0;
			}
			if (siv::Input::KeySpace.clicked &&m_jumpCount < 2) {
				m_yv = -10;
				m_jumpCount++;
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