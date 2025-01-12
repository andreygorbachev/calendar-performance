project(quantlib-calendar)

add_executable(${PROJECT_NAME}
  quantlib-calendar.cpp
)

include(FetchContent)

set(BOOST_INCLUDE_LIBRARIES math)
set(BOOST_ENABLE_CMAKE ON)

FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG        boost-1.87.0
)

FetchContent_Declare(
  QuantLib
  GIT_REPOSITORY https://github.com/lballabio/QuantLib.git
  GIT_TAG        v1.36
)

FetchContent_MakeAvailable(
	Boost
#	QuantLib
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  Boost::math
#  QuantLib
)
