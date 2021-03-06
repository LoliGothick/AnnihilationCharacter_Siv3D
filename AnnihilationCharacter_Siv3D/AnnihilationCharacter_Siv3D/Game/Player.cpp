#include "Player.hpp"
#include "TerrainControl.hpp"

namespace game {


	//移動アクション
	void Player::Move(const std::unique_ptr<TerrainControl>& terrainControl) {
		SetPos({ GetPos().x,GetPos().y + m_yv });
		m_yv += m_g;
		if (GetUnderY() >= terrainControl->GetTerrainY(m_underLane)) {
			m_jumpCount = 0;
			SetUnderY(terrainControl->GetTerrainY(m_underLane));
			m_yv = 0;
		}
		if (siv::Input::KeySpace.clicked &&m_jumpCount < 2) {
			m_yv = -10;
			m_jumpCount++;
		}
		if (m_jumpCount != 0) {
			for(int i=TerrainControl::LANE_NUM-1;i>=0;i--)
				if (GetUnderY() < terrainControl->GetTerrainY(i)) {
					m_underLane = i;
					break;
				}
		}

		if (siv::Input::KeyDown.clicked && m_jumpCount == 0 && m_underLane!=0)
			m_underLane--;
		if (siv::Input::KeyRight.pressed)
			SetPos({ GetPos().x + speed, GetPos().y });
		if (siv::Input::KeyLeft.pressed)
			SetPos({ GetPos().x - speed, GetPos().y });
	}

	void Player::Update2(const std::unique_ptr<TerrainControl>& terrainControl) {
		elipmocframework::FontObject::Update();
		Move(terrainControl);
		circle.setPos(GetPos().x, GetUnderY()).draw(siv::Palette::Red);
	}
}