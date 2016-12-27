#include "library.hpp"

Library::Library(SDL2pp::Renderer &renderer):
  hero(renderer, SDL2pp::Surface("hero.bmp")),
  block(renderer, SDL2pp::Surface("block.bmp")),
  spike(renderer, SDL2pp::Surface("spike.bmp"))
{
}
