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
  renderer.Copy(library.hero, SDL2pp::NullOpt, SDL2pp::Rect(Width / 10 - 32, Height - Height / 10 - y - 64, 64, 64), direction, SDL2pp::NullOpt);
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
  if (direction > newDirection)
  {
    direction -= 0.5;
    if (direction <= newDirection)
    {
      while (newDirection >= 360)
        newDirection -= 360;
      direction = newDirection;
    }
  }
  if (direction < newDirection)
  {
    direction += 0.5;
    if (direction >= newDirection)
    {
      while (newDirection >= 360)
        newDirection -= 360;
      direction = newDirection;
    }
  }
}

void Hero::jump()
{
  vy += 1.6f;
  newDirection += 90;
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
