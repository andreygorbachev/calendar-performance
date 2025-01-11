project(quantlib-calendar)

set(BOOST_INCLUDE_LIBRARIES math)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
  boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG        boost-1.87.0
)
FetchContent_MakeAvailable(boost)
