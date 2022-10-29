find_package(Boost COMPONENTS unit_test_framework REQUIRED)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fPIC -g") 

set (HEADERS
    unit_tests/lib/models/player_tests.hpp
)

set (SOURCE
    unit_tests/lib/models/player_tests.cpp

	main.cpp
)

set (EXE_TARGET sm_unit_tests)

add_executable(${EXE_TARGET} ${HEADERS} ${SOURCE})

include_directories(${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${EXE_TARGET} ${LIB_SM_TARGET})

target_link_libraries(${EXE_TARGET} ${Boost_LIBRARIES})

find_package(SFML COMPONENTS window graphics system)
target_link_libraries(${EXE_TARGET} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

add_test(NAME TestSM COMMAND $<TARGET_FILE:${EXE_TARGET}>)
