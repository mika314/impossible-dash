#include "consts.hpp"
#include "hero.hpp"
#include "level.hpp"
#include "library.hpp"
#include <SDL2pp/SDL2pp.hh>

int main(int argc, char **argv)
{
  SDL2pp::SDL sdl(SDL_INIT_EVERYTHING);
  SDL2pp::Window window("Impossible Dash", 65, 126, Width, Height, SDL_WINDOW_BORDERLESS);
  SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

  Library library(renderer);
  Hero hero(renderer, library);
  Level level(renderer, library, hero.getX());

  auto currentTick = SDL_GetTicks();
  for (auto done = false; !done;)
  {
    SDL_Event e;
    if (SDL_PollEvent(&e))
    {
      switch (e.type)
      {
      case SDL_MOUSEBUTTONDOWN:
        hero.jump();
        break;
      case SDL_QUIT:
        done = true;
        break;
      }
    }
    auto oldTick = currentTick;
    currentTick = SDL_GetTicks();
    for (; oldTick < currentTick; ++oldTick)
    {
      hero.setBottom(level.getBottom());
      hero.tick();
    }
    if (level.isGameOver(hero.getX(), hero.getY()))
      renderer.SetDrawColor(0xff, 0x00, 0x00, 0xff);
    else
      renderer.SetDrawColor(0x00, 0x00, 0x00, 0xff);
    renderer.Clear();
    level.draw();
    hero.draw();
    renderer.Present();
  }
}
