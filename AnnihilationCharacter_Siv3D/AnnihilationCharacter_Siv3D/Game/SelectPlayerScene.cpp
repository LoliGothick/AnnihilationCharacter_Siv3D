#include "SelectPlayerScene.hpp"
#include "FontObject.hpp"

namespace game {
	using elipmocframework::FontObject;
	using elipmocframework::CreateScaleAction;

	void SelectPlayerScene::init() {
		using namespace siv::Window;
		//FontObject���̐������ăp�����[�^��ݒ�
		(playerFonts[0] = std::make_unique<FontObject>())
			->SetText(L"��").SetPos({ Center().x - 50, Center().y });
		(playerFonts[1] = std::make_unique<FontObject>())
			->SetText(L"�l").SetPos(Center()).SetScale(10);
		(playerFonts[2] = std::make_unique<FontObject>())
			->SetText(L"��").SetPos({ Center().x + 50, Center().y });
	}


	void SelectPlayerScene::update() {

		//enter�L�[�̏���
		if (siv::Input::KeyEnter.clicked) {

			//��l���̕�����ݒ肵�ăV�[����J�ڂ���
			m_data->player = playerFonts[selectIndex]->GetText();
			changeScene(L"Game");
		}

		//���E�L�[�̏����B������Ă���A�����Ɋg��k���A�j���[�V������ݒ肷��
		if ((siv::Input::KeyRight.clicked || siv::Input::KeyLeft.clicked) && actionInterval == 0) {
			actionInterval = 5;
			playerFonts[selectIndex]->AddAction(CreateScaleAction(*playerFonts[selectIndex], 1, 5));
			if (siv::Input::KeyRight.clicked)
				selectIndex = (selectIndex + 1) % 3;
			else
				selectIndex = (selectIndex + 2) % 3;

			playerFonts[selectIndex]->AddAction(CreateScaleAction(*playerFonts[selectIndex], 10, 5));
		}
		if (actionInterval != 0)actionInterval--;

		//�g��k���A�j���[�V�����X�V
		for (auto&& item : playerFonts)
			item->Update();

	}


	//�����̕`��
	void SelectPlayerScene::draw() const {

		for (const auto& item : playerFonts)
			item->DrawCenter();
		guideFont(L"��l����I��ł�������").draw({ 50,50 });
	}

}