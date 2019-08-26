#include "FISW/Game.h"
#include "FISW/Screen.h"
#include "FISW/Drawable.h"
#include <vector>

int main() {

	FISW::Game game = FISW::Game(
		{
			new FISW::Screen({
				new FISW::Drawable("bloodboi.png", 10.0f, 10.0f),
			}),
		}
	);

	int ret = game.run();

	return ret;
}
