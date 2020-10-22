# CMakeLists text file of the project
# RFAL code release version 1.0

cmake_minimum_required(VERSION 3.1.0)

project(rfal_demo)

# RFAL library variant to link the executable with
set(RFAL_VARIANT "st25r3911" CACHE STRING "Select the RFAL library")

# Compile the RFAL library variant to link the executable with
add_subdirectory(rfal/${RFAL_VARIANT})
add_subdirectory(nfc_poller)
