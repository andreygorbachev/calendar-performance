project("isda-cds-model-calendar")

add_executable(${PROJECT_NAME}
  IMM.cpp
  isda-cds-model-calendar.cpp
  IMM.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  isda_cds_model_c_v1.8.3
)
