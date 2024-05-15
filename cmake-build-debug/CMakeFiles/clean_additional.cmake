# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Zork-Taylor_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Zork-Taylor_autogen.dir/ParseCache.txt"
  "Zork-Taylor_autogen"
  )
endif()
