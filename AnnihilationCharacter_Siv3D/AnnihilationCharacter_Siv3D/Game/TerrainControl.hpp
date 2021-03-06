#pragma once
#include <deque>
namespace game {
	//地形配列を制御するクラス
	class TerrainControl {
	public:
		//地形一つのサイズ
		static constexpr size_t TERRAIN_SIZE = 40;
		//レーン数
		static constexpr size_t LANE_NUM = 3;
		double GetTerrainY(size_t lane)const;
		TerrainControl();
		void Update();
	private:
		//地形情報のリスト
		std::deque<bool>m_terrainFlags[LANE_NUM];
		//現在画面に表示されている地形
		std::deque<bool> m_activeTerrains[LANE_NUM];
		//表示用の地形文字
		const siv::Font m_terrainFont;
		//デバック用
		siv::Circle circle;
		//文字の高さ補正用（文字は表示位置がずれるため、ギャップを埋めなけらばならぬ）
		static constexpr size_t FIX_TERRAIN_Y=19;
		//地形の座標をずらす
		double m_offset = 0;

		void NextTerrainLoad();

	};
}