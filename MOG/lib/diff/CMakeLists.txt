SET(LIBSTATIC_SRC functionaudi.cpp functionaudi.cpp functionaudi.h Expression_tree.cpp Expression_tree.h classaudi.cpp classaudi.h)
ADD_LIBRARY(functional_autodiff SHARED ${LIBSTATIC_SRC})
SET_TARGET_PROPERTIES(functional_autodiff PROPERTIES LIBRARY_OUTPATH_DIRETORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})