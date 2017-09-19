SET(SRC_LIST main.cpp)
ADD_EXECUTABLE(MOGOptimization ${SRC_LIST})
TARGET_LINK_LIBRARIES(MOGOptimization MOGHello MOGSubsriber ${catkin_LIBRARIES} ${Boost_LIBRARIES} )
