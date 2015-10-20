cmake_minimum_required(VERSION 2.8.3)
project(my_smart_dog)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

add_message_files(FILES msgLegs.msg)
add_service_files(FILES srvLegs.srv)


## Generate added messages and services with any dependencies listed here
generate_messages(DEPENDENCIES std_msgs)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES my_smart_dog
  CATKIN_DEPENDS roscpp std_msgs
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(MDLegsPublisher src/MDLegsPublisher.cpp)
target_link_libraries(MDLegsPublisher ${catkin_LIBRARIES})
add_dependencies(MDLegsPublisher my_smart_dog_generate_messages_cpp)

add_executable(MDLegsSubscriber src/MDLegsSubscriber.cpp)
target_link_libraries(MDLegsSubscriber ${catkin_LIBRARIES})
add_dependencies(MDLegsSubscriber my_smart_dog_generate_messages_cpp)

add_executable(MDLegsServiceServer src/MDLegsServiceServer.cpp)
target_link_libraries(MDLegsServiceServer ${catkin_LIBRARIES})
add_dependencies(MDLegsServiceServer my_smart_dog_generate_messages_cpp)

add_executable(MDLegsServiceClient src/MDLegsServiceClient.cpp)
target_link_libraries(MDLegsServiceClient ${catkin_LIBRARIES})
add_dependencies(MDLegsServiceClient my_smart_dog_generate_messages_cpp)