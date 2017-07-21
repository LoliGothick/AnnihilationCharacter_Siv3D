#pragma once
#include <string>
#include "Action.hpp"

namespace elipmocframework {
	//�t�H���g�I�u�W�F�N�g
	class FontObject {
		double scale=1;
		const siv::Font font;
		siv::String text;
		siv::Vec2 pos;
		//�����x
		double opacity=255;
		ActionList actionList;

	public:
		FontObject& AddAction(std::unique_ptr<ActionBase>&& action) {
			actionList.push_back(std::move(action));
			return *this;
		}
		//pos�A�N�Z�T
		siv::Vec2 GetPos()const { return pos; }
		FontObject& SetPos(const siv::Vec2& _pos) { pos = _pos; return *this; }

		//scale�A�N�Z�T
		double GetScale() const{ return scale; };
		FontObject& SetScale(double _scale) { scale = _scale; return *this; }

		//text�A�N�Z�T
		siv::String GetText() const { return text; }
		FontObject& SetText(const siv::String& _text) { text = _text; return *this; }

		FontObject(int fontsize=20) :scale(1),font(fontsize) {

		}

		FontObject(siv::String _text, int fontsize = 20) :scale(1), font(fontsize),text(_text) {

		}

		virtual void Update() {
			actionList.Update();
		}

		virtual void Draw() const{
			siv::Mat3x2 mat = siv::Mat3x2::Scale(scale, pos);
			siv::Transformer2D t(mat, false);
			font(text).draw(pos,siv::AlphaF(opacity));
		}
		void DrawCenter()const {
			siv::Mat3x2 mat = siv::Mat3x2::Scale(scale, pos);
			siv::Transformer2D t(mat, false);
			font(text).drawCenter(pos,siv::AlphaF(opacity));
		}

	};
}