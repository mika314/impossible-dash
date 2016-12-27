#pragma once
#include <SDL2pp/SDL2pp.hh>
#include <vector>
#include <algorithm>

class Library;

class Level
{
public:
  Level(SDL2pp::Renderer &, Library &, const float &scroll);
  void draw();
  float getBottom() const;
  bool isGameOver(float x, float y) const;
private:
  SDL2pp::Renderer &renderer;
  Library &library;
  const float &scroll;
  std::vector<std::pair<int, bool> > data;
};
