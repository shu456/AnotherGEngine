#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

class GameEngine
{
public:
  GameEngine();
  void OnStart();
  void OnUpdate();
  void OnDestroy();

private:

};

extern GameEngine* g_pGE;

#endif