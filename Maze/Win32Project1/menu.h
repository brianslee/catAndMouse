#pragma once
namespace Menu {
	class Menu {
		private:
			int current;
			int optionNum;
			sf::Font font;
			sf::Text* choice;
		public:
			Menu();
	};
}