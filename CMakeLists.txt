project(BREADY)

cmake_minimum_required(VERSION 2.6)

################################################################################
# The version number.
################################################################################
SET (gatb-tool_VERSION_MAJOR 1)
SET (gatb-tool_VERSION_MINOR 0)
SET (gatb-tool_VERSION_PATCH 0)

IF (DEFINED MAJOR)
    SET (gatb-tool_VERSION_MAJOR ${MAJOR})
ENDIF()
IF (DEFINED MINOR)
    SET (gatb-tool_VERSION_MINOR ${MINOR})
ENDIF()
IF (DEFINED PATCH)
    SET (gatb-tool_VERSION_PATCH ${PATCH})
ENDIF()

set (gatb-tool-version ${gatb-tool_VERSION_MAJOR}.${gatb-tool_VERSION_MINOR}.${gatb-tool_VERSION_PATCH})

# However, continuous integration has priority over local compilation
IF (DEFINED JENKINS_TAG)
    SET (gatb-tool-version ${JENKINS_TAG})
ENDIF()

################################################################################
# Define cmake modules directory
################################################################################
SET (GATB_CORE_HOME  ${PROJECT_SOURCE_DIR}/thirdparty/gatb-core/gatb-core)
SET (CMAKE_MODULE_PATH ${GATB_CORE_HOME}/cmake)

################################################################################
# THIRD PARTIES
################################################################################

# We don't want to install some GATB-CORE artifacts
SET (GATB_CORE_EXCLUDE_TOOLS     1)
SET (GATB_CORE_EXCLUDE_TESTS     1)
SET (GATB_CORE_EXCLUDE_EXAMPLES  1)

# GATB CORE
include (GatbCore)

################################################################################
#  TOOLS GENERATION
################################################################################

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

set(PROJECT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/tools)
#set(PROJECT_BINARY_DIR bin)
ADD_SUBDIRECTORY(tools)
ADD_SUBDIRECTORY(thirdparty)

