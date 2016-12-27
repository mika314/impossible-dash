#pragma once
#include <SDL2pp/SDL2pp.hh>

class Library;

class Hero
{
public:
  Hero(SDL2pp::Renderer &, Library &);
  void setBottom(float);
  void draw();
  void tick();
  void jump();
  const float &getX() const;
  const float &getY() const;
private:
  SDL2pp::Renderer &renderer;
  Library &library;
  float x = 0.0f;
  float y = 300.0f;
  float vy = 0.0f;
  float bottom = 0.0f;
  float direction = 0.0f;
  float newDirection = 0.0f;
};
