#include <string>
#include <cstdint>
#include <sstream>
#include <string_view>

enum TIME
{
  SECONDS = 1'000,
  MINUTES = SECONDS * 60,
};

struct Time
{
  Time (const std::string &);
  ~Time () = default;
  uint64_t miliseconds;
};

// Input example: 00:00.00
Time::Time (const std::string &time)
{
  std::istringstream is{time};

  uint64_t minutes, seconds;

  // NOTE: dummy STL without a proper formatting scan tool.
  char dummy;

  is >> minutes >> dummy >> seconds >> dummy >> miliseconds;

  miliseconds += minutes * MINUTES + seconds * SECONDS;
}
