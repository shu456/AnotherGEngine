#include <GameEngine.hpp>

GameEngine* g_pGE = nullptr;

GameEngine::GameEngine()
{
  g_pGE = this;
}

void GameEngine::OnStart()
{
  m_cRenderEngine.OnStart();
}

void GameEngine::OnUpdate()
{
  m_cRenderEngine.OnUpdate();
}

void GameEngine::OnDestroy()
{
  m_cRenderEngine.OnDestroy();
}
