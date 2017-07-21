#pragma once
#include <deque>
namespace game {
	//�n�`�z��𐧌䂷��N���X
	class TerrainControl {
		//�n�`��̃T�C�Y
		static constexpr size_t TERRAIN_SIZE= 40;
		//���[����
		static constexpr size_t LANE_NUM=3;
		//�n�`���̃��X�g
		std::deque<bool>m_terrainFlags[LANE_NUM];
		//���݉�ʂɕ\������Ă���n�`
		std::deque<bool> m_activeTerrains[LANE_NUM];
		//�\���p�̒n�`����
		const siv::Font m_terrainFont;
		//�n�`�����炷
		double m_offset = 0;

		void NextTerrainLoad();
	public:
		TerrainControl();
		void Update();
	};
}