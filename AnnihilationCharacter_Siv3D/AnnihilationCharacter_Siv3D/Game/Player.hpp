#pragma once
#include "FontObject.hpp"
#include <memory>

namespace game {

	class TerrainControl;
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
		void Move(const std::unique_ptr<TerrainControl>&);
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

		void Update2(const std::unique_ptr<TerrainControl>&);
	};

}