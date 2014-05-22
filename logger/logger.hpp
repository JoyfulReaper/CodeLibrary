/**
 * @file logger.hpp
 * @author Kyle Givler
 * 
 * Provide logging mechanism
 */

#ifndef _LOGGER_H_
#define _LOGGER_H_

enum class Level {FINE, CONFIG, INFO, WARNING, ERROR, SEVERE};

class logger
{
public:
  logger(std::string name = "Logger", size_t maxStreams = 5, std::ostream &initStream = std::cerr);
  
  void log(std::string message);
  void log(Level level, std::string message);
  
  void setLevel(Level level);
  Level getLevel();
  
  Level ignoreLevel(Level level);
  
  std::string getName();
  
  bool addStream(std::ostream &o);
  bool removeStream(std::ostream &o);
  
  /**
   * Enable Logging
   */
  void enable();
  
  /*
   * Disable Logging
   */
  void disable();
  
  /**
   * Check if logging is enabled
   * @return true if enabled, false if disabled
   */
  bool isEnabled();
  
private:
  size_t maxStreams; // Maximum number of output streams
  std::string name; // Name of the logger
  Level iLevel; // Current logging level
  bool enabled; // Is logging enabled?
};

#endif