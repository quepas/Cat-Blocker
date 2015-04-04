cmake_minimum_required (VERSION 2.8)
project (Cat-Blocker)

add_definitions(-DUNICODE -D_UNICODE)
set (CMAKE_CXX_FLAGS_DEBUG "/MTd")

file (GLOB SOURCE_FILE_LIST src/*.cpp)
file (GLOB HEADER_FILE_LIST src/*.h)

set (CINDER_INC "D:/Programowanie/Biblioteki/cinder_0.8.6_vc2013/include")
set (CINDER_BOOST_INC "D:/Programowanie/Biblioteki/cinder_0.8.6_vc2013/boost")
set (CINDER_LIB "D:/Programowanie/Biblioteki/cinder_0.8.6_vc2013/lib/msw/x86")
set (BOOST_LIB "D:/Programowanie/Biblioteki/Tidy/boost_1_55_0_vc2013/lib32-msvc-12.0")

include_directories (${CINDER_INC} ${CINDER_BOOST_INC})
link_directories (${CINDER_LIB} ${BOOST_LIB})

add_executable(CatBlockerApp ${SOURCE_FILE_LIST} ${HEADER_FILE_LIST})
