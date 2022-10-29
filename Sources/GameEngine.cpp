#include <GameEngine.hpp>

#include <RenderComponent.hpp>

GameEngine* g_pGE = nullptr;

GameEngine::GameEngine()
{
  g_pGE = this;
}

void GameEngine::OnStart()
{
  g_cRenderEngine.OnStart();
}

void GameEngine::OnUpdate()
{
  g_cRenderEngine.OnUpdate();
}

void GameEngine::OnDestroy()
{
  g_cRenderEngine.OnDestroy();
}
