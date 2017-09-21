SET(SRC_LIST main.cpp ../lib/point2d/point2d.cpp ../lib/point2d/point2d.h)
ADD_EXECUTABLE(MOGOptimization ${SRC_LIST})
TARGET_LINK_LIBRARIES(MOGOptimization MOGHello MOGSubsriber MOGpoint2d ${catkin_LIBRARIES} ${Boost_LIBRARIES} )
