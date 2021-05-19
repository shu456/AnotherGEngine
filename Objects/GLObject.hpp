#ifndef GLOBJECT_HPP
#define GLOBJECT_HPP

#include <forward_list>

class GLObjectHandlerInterface
{
public:
  GLObjectHandlerInterface(bool bCreated,unsigned u32ID) :
    m_bCreated(bCreated),
    m_u32ID(u32ID)
  {}
  virtual ~GLObjectHandlerInterface() {}
  virtual unsigned Setup(unsigned) = 0;
  virtual unsigned Setup() = 0;
  virtual void Destroy() = 0;
  unsigned GetID() const
  {
    return m_u32ID;
  }
protected:
  bool m_bCreated;
  unsigned m_u32ID;
};

template<unsigned N, typename CreateFunc, typename DeleteFunc>
class GLObjectHandler : public GLObjectHandler<0xffffffff, CreateFunc, DeleteFunc>
{
public:
  GLObjectHandler(CreateFunc cF, DeleteFunc dF) :
    Base(cF, dF)
  {

  }

  unsigned Setup(unsigned arg) final
  {
    this->m_bCreated = true;
    return this->m_cF(arg);
  }

  unsigned Setup() final
  {
    return -1;
  }
protected:
  using Base = GLObjectHandler<0xffffffff, CreateFunc, DeleteFunc>;
};

template<typename CreateFunc, typename DeleteFunc>
class GLObjectHandler<0xffffffff, CreateFunc, DeleteFunc> : public GLObjectHandlerInterface
{
public:
  GLObjectHandler(CreateFunc cF, DeleteFunc dF) :
    GLObjectHandlerInterface(false, -1),
    m_cF(cF),
    m_dF(dF)
  {

  }

  virtual ~GLObjectHandler()
  {
    Destroy();
  }

  void Destroy() override
  {
    if (m_bCreated)
    {
      m_dF(m_u32ID);
      m_u32ID = -1;
    }
    m_bCreated = false;
  }
protected:
  CreateFunc m_cF;
  DeleteFunc m_dF;
};

template<typename CreateFunc, typename DeleteFunc>
class GLObjectHandler<0, CreateFunc, DeleteFunc> : public GLObjectHandler<0xffffffff, CreateFunc, DeleteFunc>
{
public:
  GLObjectHandler(CreateFunc cF, DeleteFunc dF) :
    Base(cF,dF)
  {

  }

  unsigned Setup(unsigned arg) final
  {
    return -1;
  }

  unsigned Setup() final
  {
    this->m_bCreated = true;
    return this->m_cF();
  }
protected:
  using Base = GLObjectHandler<0xffffffff, CreateFunc, DeleteFunc>;
};

template<unsigned N, typename CreateFunc, typename DeleteFunc>
inline GLObjectHandlerInterface* CreateGLObject(CreateFunc cF, DeleteFunc dF)
{
  return new GLObjectHandler<N,CreateFunc, DeleteFunc>(cF, dF);
}

#endif
