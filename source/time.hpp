#include <string>
#include <cstdint>
#include <sstream>

enum Time
{
  SECONDS = 1'000,
  MINUTES = SECONDS * 60,
};

[[nodiscard]]
auto
time_to_miliseconds (std::string &time)
{
  std::istringstream is{time};

  uint64_t minutes, seconds, miliseconds;

  // NOTE: dummy STL without a proper formatting scan tool.
  char dummy;

  // Input example: [00:00.00]
  is >> dummy >> minutes >> dummy >> seconds >> dummy >> miliseconds >> dummy;

  miliseconds += minutes * MINUTES + seconds * SECONDS;

  return miliseconds;
}

/* TODO: create struct for Time that accepts a string and has a function to transform into miliseconds. */
