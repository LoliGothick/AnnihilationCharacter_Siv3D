#pragma once

namespace game {
	//�V�[���Ԃŋ��L����f�[�^
	struct ShareGameData {/*empty*/ };
	//�V�[������N���X
	using MySceneManager = ham::SceneManager<siv::String, ShareGameData>;
	//�V�[���̊��N���X
	using MySceneBase = MySceneManager::Scene;
}