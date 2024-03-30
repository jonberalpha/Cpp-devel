add_library(SpiderCtrl src/MovtCtrl.cpp src/SpiderCtrl.cpp)

target_include_directories(SpiderCtrl PUBLIC
      ${PROJECT_SOURCE_DIR}/BCM2835
      ${PROJECT_SOURCE_DIR}/RaspiLib/inc
      ${PROJECT_SOURCE_DIR}/RaspiBlocks/inc
      ${PROJECT_SOURCE_DIR}/Spider/inc
      ${CMAKE_CURRENT_SOURCE_DIR}/include
)
