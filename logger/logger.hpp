/**
 * @file logger.hpp
 * @author Kyle Givler
 * 
 * Provide logging mechanism
 */

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <vector>
#include <iostream>

enum class Level {FINE, CONFIG, INFO, WARNING, ERROR, SEVERE};

class logger
{
public:
  /**
   * Constructor:
   * @param name The name of the logger
   * @param level The default logging level
   * @param initStream The initial stream to log to
   */
  logger(std::string name = "Logger", Level level = Level::WARNING, std::ostream &initStream = std::cerr);
  logger(const logger& copy) = delete; // Disable copy Constructor
  
  
  /**
   * Log message to output streams
   * @param message The message to log at default level
   */
  void log(std::string message);
  
  /**
   * Log message to output streams
   * @param level the priority level of the message
   * @param message The message to Log
   */
  void log(Level level, std::string message);
  
  /**
   * @param level Default logging level
   */
  void setLevel(Level level);
  
  /**
   * @return The current default logging level
   */
  Level getLevel() const;
  
  /**
   * @param level messages with <= levels are ignored
   */
  void setIgnoreLevel(Level level);
  
  /**
   * @return current ignore level
   */
  Level getIgnoreLevel();
  
  /**
   * @return the name of this logger
   */
  std::string getName() const;
  
  /**
   * Add a new output stream
   * The log message is sent to all added streams
   * @return true on sucess, false on failure
   */
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
  std::vector<std::ostream*> streams;
  std::string name; // Name of the logger
  Level logLevel; // Current logging level
  Level ignoreLevel;
  bool enabled; // Is logging enabled?
};

#endif