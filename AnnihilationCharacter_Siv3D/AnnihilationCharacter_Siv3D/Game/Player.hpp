#pragma once
#include "FontObject.hpp"

namespace game {

	class Player :public elipmocframework::FontObject {

		static constexpr double speed=3.5;
		//重力加速度
		double m_g=0.3;
		//Yの速度
		double m_yv=0;
		//ジャンプした回数記録
		int m_jumpCount=0;
		//デバック用
		siv::Circle circle;

		//移動アクション
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

		//主人公の足元の高さを得る
		double GetUnderY() {
			return GetPos().y + 35 ;
		}

		//主人公の足元の高さをセットする
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