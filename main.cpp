#include "FISW/Game.h"
#include "FISW/Screen.h"
#include "FISW/Drawable.h"

int main() {

	FISW::Drawable drawables[] = {
			FISW::Drawable("bloodboi.png", 10.0f, 10.0f),
	};

	FISW::Screen Screens[] = {
		FISW::Screen(drawables), 		
	};

	FISW::Game game = FISW::Game(Screens);

	int ret = game.run();

	return ret;
}
