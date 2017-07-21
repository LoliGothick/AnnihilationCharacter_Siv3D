#include "TerrainControl.hpp"

namespace game {
	TerrainControl::TerrainControl():m_terrainFont(TERRAIN_SIZE)
	{
		m_activeTerrains[0].resize(siv::Window::Size().x / TERRAIN_SIZE+2, true);
		m_activeTerrains[1].resize(siv::Window::Size().x / TERRAIN_SIZE+2, true);
		m_activeTerrains[2].resize(siv::Window::Size().x / TERRAIN_SIZE+2, true);
	}

	//���̒n�`���Z�b�g����
	void TerrainControl::NextTerrainLoad() {
		m_offset = 0;

		//�擪�̃f�[�^����폜
		m_activeTerrains[0].pop_front();
		//�Ō���ɐV�����n�`�f�[�^���Z�b�g����
		m_activeTerrains[0].push_back( false);
	}

	void TerrainControl::Update()
	{
		m_offset += 2;
		if (m_offset >= TERRAIN_SIZE)
			NextTerrainLoad();
		for (size_t i = 0; i < m_activeTerrains[0].size(); i++) {
			if(m_activeTerrains[0][i])
				m_terrainFont(L"��").draw(i*TERRAIN_SIZE-m_offset, 425);
		}
	}


}
