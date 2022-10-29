#include <iostream>
#include <RenderComponent.hpp>

#include <TestGameObject.hpp>

void TestObject::OnStart()
{
  RenderComponent* rc = AddNewComponent<RenderComponent>();

  rc->SetupShader("vert.vert", "frag.frag");

  RenderComponent* rc1 = GetComponent< RenderComponent >();

  if (rc1 == rc)
  {
    std::cout << "Success" << std::endl;
  }
  else
  {
    std::cout << "Failed" << std::endl;
  }
}
