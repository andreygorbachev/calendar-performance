project("gregorian-calendar")

add_executable(${PROJECT_NAME}
  NYM.cpp
  IMM.cpp
  gregorian-calendar.cpp
  NYM.h
  IMM.h
)

#find_package(Calendar)
include(FetchContent)
FetchContent_Declare(
  calendar
  GIT_REPOSITORY https://github.com/andreygorbachev/calendar.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(calendar)

target_link_libraries(${PROJECT_NAME} PRIVATE
  calendar
)
