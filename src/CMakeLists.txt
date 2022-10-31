find_package(Boost COMPONENTS log log_setup REQUIRED)
find_package(Threads REQUIRED)
add_definitions(-DBOOST_LOG_DYN_LINK)

set(HEADERS
    lib/logging/logger.hpp

    lib/models/player.hpp
    lib/models/tile.hpp
    lib/models/enemy.hpp

    lib/services/tile_maker.hpp
    lib/services/map_maker.hpp

    gui/frame.hpp
)

set(SOURCES
    lib/logging/logger.cpp

    lib/models/player.cpp
    lib/models/tile.cpp

    lib/services/tile_maker.cpp
    lib/services/map_maker.cpp

    gui/frame.cpp
)

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

add_library(${LIB_SM_TARGET} SHARED ${HEADERS} ${SOURCES})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -fPIC")

install(TARGETS ${LIB_SM_TARGET}
    ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
    LIBRARY DESTINATION ${LIB_INSTALL_DIR}
)

find_package(SFML 2.5.1 COMPONENTS graphics window system audio REQUIRED)

target_link_libraries(${LIB_SM_TARGET} ${Boost_LIBRARIES})
target_link_libraries(${LIB_SM_TARGET} sfml-system sfml-window sfml-graphics sfml-audio)

include_directories(${CMAKE_SOURCE_DIR}/src)
