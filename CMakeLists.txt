cmake_minimum_required (VERSION 2.8.11)
project (ArrayBackedNanoCubes)

SET(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(AFTER src)

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/usr/local/include")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/usr/local/lib")

# set(Boost_USE_STATIC_LIBS OFF)
# set(Boost_USE_MULTITHREADED ON)
# set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.60.0 COMPONENTS iostreams system filesystem serialization)

if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})

	add_executable (sanity_check
	  src/sanity_check.cpp
	  src/ArrayBackedNanoCube.cpp
	  )
	target_link_libraries(sanity_check ${Boost_LIBRARIES})
endif()
