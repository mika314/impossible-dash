#include "hero.hpp"
#include "consts.hpp"
#include "library.hpp"

Hero::Hero(SDL2pp::Renderer &renderer, Library &library):
  renderer(renderer),
  library(library)
{
}

void Hero::draw()
{
  renderer.Copy(library.hero, SDL2pp::NullOpt, SDL2pp::Rect(Width / 10 - 32, Height - Height / 10 - y - 64, 64, 64));
}

void Hero::tick()
{
  x += 0.5;
  if (y >= bottom)
  {
    auto newY = y + vy;
    if (newY < bottom)
    {
      newY = bottom;
      vy = 0;
    }
    y = newY;
  }
  vy -= 0.01f;
}

void Hero::jump()
{
  vy += 1.6f;
}

const float &Hero::getX() const
{
  return x;
}

const float &Hero::getY() const
{
  return y;
}

void Hero::setBottom(float value)
{
  bottom = value;
}
