project(pybind11_test)

#**************************************************************************************************
# General cMake settings
#**************************************************************************************************
cmake_minimum_required(VERSION 3.5)

#**************************************************************************************************
# Find Package ************************************************************************************


#**************************************************************************************************
# Include *****************************************************************************************
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/modules/pybind11_opencv_numpy)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/modules/pybind11_opencv_numpy/pybind11/include)


#**************************************************************************************************
# Set variable ************************************************************************************
SET(SOURCES    
# ${CMAKE_CURRENT_SOURCE_DIR}/src/CppClasses.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/classes_pybind11.cpp
)


#**************************************************************************************************
# Set compiler ************************************************************************************
SET(CMAKE_CXX_FLAGS "-std=c++17 -Wall -O3 -fPIC")

#**************************************************************************************************
# Linker ******************************************************************************************


#**************************************************************************************************
# Make configuration
#**************************************************************************************************
add_library(pyBindClass SHARED ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/classes_pybind11.cpp)
target_compile_options(pyBindClass PRIVATE -O3)
set_target_properties(pyBindClass PROPERTIES PREFIX "")
target_link_libraries(pyBindClass -pthread -lstdc++fs ${PYTHON_LIBRARIES})
install(TARGETS pyBindClass DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/python/lib)