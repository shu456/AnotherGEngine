#ifndef COMPONENTS_HPP
#define COMPONENTS_HPP

#include <unordered_map>

template<typename T>
class Components
{
public:
  T* AddNewComponent(unsigned u32ID)
  {
    //replace with memory manager next time
    T* pNewComp = new T();
    m_vComponents[u32ID] = (pNewComp);
    return pNewComp;
  }

  T* GetComponent(unsigned u32ID)
  {
    auto it = m_vComponents.find(u32ID);
    if (it != m_vComponents.end())
      return it->second;
    return nullptr;
  }

  void OnStart()
  {
    for (auto& pComp : m_vComponents)
      pComp.second->OnStart();
  }

  void OnUpdate()
  {
    for (auto& pComp : m_vComponents)
      pComp.second->OnUpdate();
  }

  void OnDestroy()
  {
    for (auto& pComp : m_vComponents)
      pComp.second->OnDestroy();
  }

  ~Components()
  {
    for (auto& pComp : m_vComponents)
    {
      delete pComp.second;
    }
  }
private:
  std::unordered_map<unsigned,T*> m_vComponents;
};

#endif

