#include "eudaq/BufferSerializer.hh"

namespace eudaq {

  void BufferSerializer::Deserialize(unsigned char * data, size_t len) {
    if (!len) return;
    if (len+m_offset > m_data.size()) {
      EUDAQ_THROW("Deserialize asked for " + to_string(len) +
                  ", only have " + to_string(m_data.size()));
    }
    std::copy(&m_data[m_offset], &m_data[m_offset] + len, data);
    //m_data.erase(m_data.begin(), m_data.begin() + len);
    m_offset += len;
    //std::string tmp(data, data+len);
    //std::cout << "Deserialize: " << len << /*" \"" << tmp << "\"" <<*/ std::endl;
    //tmp = std::string(begin(), end());
    //std::cout << "Remaining: " << (end()-begin()) << /*" \"" << tmp << "\"" <<*/ std::endl;
  }


}