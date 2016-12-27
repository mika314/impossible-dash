#pragma once
#include <SDL2pp/SDL2pp.hh>

class Library
{
public:
  Library(SDL2pp::Renderer &renderer);
  SDL2pp::Texture hero;
  SDL2pp::Texture block;
  SDL2pp::Texture spike;
};
