#include "FISW/Drawable.h"
#include "FISW/Game.h"

int main() {

    FISW::Game game = FISW::Game(800.0f, 600.0f, "dia 1", FISW::WindowStyle::Default,
        {
            new FISW::Drawable("bloodboi.png", 100.0f, 100.0f, 256.0f, 256.0f),
        } //
    );

    int ret = game.run();

    return ret;
}
