cmake_minimum_required(VERSION 2.8)
project( ShowImage )
find_package( OpenCV REQUIRED )


set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS program_options) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable( ShowImage main.cpp )
    target_link_libraries( ShowImage ${OpenCV_LIBS} ${Boost_LIBRARIES})
endif()