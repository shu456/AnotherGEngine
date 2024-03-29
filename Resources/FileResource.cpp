#include <FileResource.hpp>

#include <iostream>
#include <fstream>

std::filesystem::path shaderResourceDir{ "Shaders" };

FileResource::FileResource(std::filesystem::path const& path) : Resource()
{
  LoadFile(shaderResourceDir / path);
}

std::string_view FileResource::getData() const
{
  return m_data;
}

void FileResource::LoadFile(std::filesystem::path const& path)
{
  std::ifstream _file;
  _file.open(path);
  if (_file)
  {
    std::ostringstream ss;
    ss << _file.rdbuf(); // reading data
    m_data = ss.str();
    _file.close();
  }
  else
  {
    std::cerr << path << " file loaded failed" << std::endl;
  }
}
