#include "level.hpp"
#include "consts.hpp"
#include "library.hpp"

Level::Level(SDL2pp::Renderer &renderer, Library &library, const float &scroll):
  renderer(renderer),
  library(library),
  scroll(scroll)
{
  auto elevation = 0;
  for (int i = 0; i < 1000; ++i)
  {
    data.push_back(std::make_pair(elevation, rand() % 20 == 0));
    if (rand() % 10 == 0)
    {
      if (elevation <= 0)
        ++elevation;
      else if (elevation > Height / 2 / 64)
        --elevation;
      else
        elevation += rand() % 3 - 1;
    }
  }
}

void Level::draw()
{
  for (size_t i = 0; i < data.size(); ++i)
  {
    for (int y = 0; y < data[i].first + 1; ++y)
      renderer.Copy(library.block, SDL2pp::NullOpt, SDL2pp::Rect(i * 64 - scroll, Height - y * 64 - 64, 64, 64));
    if (data[i].second)
      renderer.Copy(library.spike, SDL2pp::NullOpt, SDL2pp::Rect(i * 64 - scroll, Height - (data[i].first + 1) * 64 - 64, 64, 64));
  }
}

float Level::getBottom() const
{
  auto i = (scroll + Width / 10 + 32) / 64;
  if (i < 0 || i >= data.size())
    return 0.0f;
  return data[i].first * 64.0f;
}

bool Level::isGameOver(float x, float y) const
{
  auto i = (scroll + Width / 10 + 32) / 64;
  auto spikeCorrection = 0.0f;
  if (i >= 0 && i < data.size() && data[i].second)
    spikeCorrection = 64;
  auto bottom = getBottom() + spikeCorrection;
  if (y < bottom)
    return true;
  return false;
}
