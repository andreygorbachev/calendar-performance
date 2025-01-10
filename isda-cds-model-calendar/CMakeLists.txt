project("isda-cds-model-calendar")

add_executable(${PROJECT_NAME}
  isda-cds-model-calendar.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  isda_cds_model_c_v1.8.3
)
