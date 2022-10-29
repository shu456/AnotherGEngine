#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <GameEngine.hpp>
#include <GameObject.h>

#include <TestGameObject.hpp>

void processInput(GLFWwindow* window)
{
  int keyPressed{ glfwGetKey(window, GLFW_KEY_ESCAPE) };
  if (keyPressed == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* , int width, int height)
{
  glViewport(0, 0, width, height);
}

int CreateWindow(GLFWwindow* &window,const char* sWindowName)
{
  window = glfwCreateWindow(800, 600, sWindowName, NULL, NULL);
  if (nullptr == window)
  {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  
  return 0;
}

int main()
{
  GLFWwindow* window{ nullptr };
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

  CreateWindow(window,"LearnOpenGL");
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    return -1;
  }

  GameEngine GE;

  TestObject go;
  go.OnStart();

  //initializing all the Components
  GE.OnStart();
  while (!glfwWindowShouldClose(window))
  {
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //update loop
    GE.OnUpdate();

    //input first
    glfwPollEvents();
    //flip the buffer
    glfwSwapBuffers(window);
  }
  GE.OnDestroy();
  //clean up everything
  glfwTerminate();
  return 0;
}