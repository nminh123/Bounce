#include "../include/Game.hpp"

int main(int, char**){
    Game game;
    while(game.IsRunning()){
        game.ProcessEvent();
        game.Update();
        game.Render();
    }
}
