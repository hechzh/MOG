SET(SRC_LIST test.cpp)
ADD_EXECUTABLE(MOGTest ${SRC_LIST})
TARGET_LINK_LIBRARIES(MOGTest MOGHello MOGpoint2d functional_autodiff)
TARGET_LINK_LIBRARIES(MOGTest ${GTEST_LIBRARIES} pthread)