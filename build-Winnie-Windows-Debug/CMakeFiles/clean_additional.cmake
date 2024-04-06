# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Winnie_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Winnie_autogen.dir/ParseCache.txt"
  "Winnie_autogen"
  )
endif()
