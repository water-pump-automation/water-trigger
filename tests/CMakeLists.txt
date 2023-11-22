cmake_minimum_required(VERSION 3.14)
project(water_trigger_integration_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
  water_trigger_integration_test
  main.c

  cases/cases.h
  cases/success.c
  cases/failed_to_connect.c
  cases/failed_to_create_echo.c
  cases/failed_to_create_sensor.c

  ../lib/echo.o
  ../lib/sensor.o
  ../lib/network_plug.o
  ../lib/safe_memory.o

  ../include/connect.h
  ../include/safe_memory.h
  ../include/listener.h
  ../include/mock_protocol.h
  ../include/sensor.h
  ../include/trigger.h

  ../src/core/entity/boolean.h
  ../src/core/entity/water_trigger.h
  ../src/core/entity/forward.h

  ../src/core/usecases/connect_to_local_network.c
  ../src/core/usecases/detected_water.c
  ../src/core/usecases/ran_out_of_water.c
  ../src/core/usecases/reply_to_echo.c
  ../src/core/usecases/usecases.h
  
  mock/mock_forward.c
)

target_include_directories(water_trigger_integration_test PRIVATE ./cases)
target_include_directories(water_trigger_integration_test PRIVATE ../include)
target_include_directories(water_trigger_integration_test PRIVATE ../src/core/entity)
target_include_directories(water_trigger_integration_test PRIVATE ../src/core/usecases)
