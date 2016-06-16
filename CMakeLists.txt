cmake_minimum_required (VERSION 2.8.11)
project (ArrayBackedNanoCubes)

SET(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(AFTER src)

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "/usr/local/include")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/usr/local/lib")

# set(Boost_USE_STATIC_LIBS OFF)
# set(Boost_USE_MULTITHREADED ON)
# set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.61.0 COMPONENTS iostreams system filesystem serialization)

if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})

	add_executable (test_exe
	  ./src/main_test.cpp
	  ./src/SanityTest.cpp
	  ./src/ArrayStoreTest.cpp
	  ./src/ArrayStore.h
	  ./src/ArrayBackedNanoCube.cpp
	  )
	target_link_libraries(test_exe ${Boost_LIBRARIES})
endif()

enable_testing()
add_test(test test_exe)
