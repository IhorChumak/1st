# Copyright 2006-2008 The FLWOR Foundation.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# - Try to find the International Components for Unicode (ICU) library
#
# Once done this will define
#
#  ICU_FOUND          - True if ICU found.
#  ICU_IO_FOUND       - True if ICU's io library found.
#  ICU_I18N_FOUND     - True if ICU's internationalization library found.
#  ICU_DATA_FOUND     - True if ICU data library found.
#
#  ICU_INCLUDE_DIRS   - Directory to include to get ICU headers
#                       Note: always include ICU headers as, e.g.,
#                       unicode/utypes.h
#  ICU_LIBRARIES      - Libraries to link against for the common ICU
#  ICU_IO_LIBRARIES   - Libraries to link against for io
#  ICU_I18N_LIBRARIES - Libraries to link against for ICU internationaliation
#                       (note: in addition to ICU_LIBRARIES)
#  ICU_DATA_LIBRARIES - Libraries to link against for ICU data
#

# Look for the header file
IF (NOT ICU_INCLUDE_DIR)
	set(ICU_INCLUDE_DIR)
ENDIF (NOT ICU_INCLUDE_DIR)
find_path(
  ICU_INCLUDE
  NAMES unicode/utypes.h
  PATHS ${ICU_INCLUDE_DIR}
  DOC "Include directory for the ICU library")

# Look for the library
IF (NOT ICU_LIBRARY_DIR)
	set(ICU_LIBRARY_DIR)
ENDIF (NOT ICU_LIBRARY_DIR)
find_library(
  ICU_LIBRARY
  NAMES icuuc cygicuuc cygicuuc32 cygicuuc38
  PATHS ${ICU_LIBRARY_DIR}
  DOC "Libraries to link against for the common parts of ICU")

if (ICU_LIBRARY)
  MESSAGE(STATUS "Found ICU library -- " ${ICU_LIBRARY})
else (ICU_LIBRARY)
  MESSAGE(STATUS "Could not find ICU library")
endif (ICU_LIBRARY)

# Copy the results to the output variables
if(ICU_INCLUDE AND ICU_LIBRARY)
  set(ICU_FOUND 1)
  set(ICU_LIBRARIES ${ICU_LIBRARY})
  set(ICU_INCLUDE_DIRS ${ICU_INCLUDE})

  # Look for the ICU io libraries
  find_library(
    ICU_IO_LIBRARY
    NAMES icuio cygicuio cygicuio32 cygicuio38
    PATHS ${ICU_LIBRARY_DIR}
    DOC "Libraries to link against for io")
  if (ICU_IO_LIBRARY)
    MESSAGE(STATUS "Found ICU io library -- " ${ICU_IO_LIBRARY})
    set(ICU_IO_FOUND 1)
    set(ICU_IO_LIBRARIES ${ICU_IO_LIBRARY})
  else (ICU_IO_LIBRARY)
    MESSAGE(STATUS "Could not find ICU io library")
    set(ICU_IO_FOUND 0)
    set(ICU_IO_LIBRARIES)
  endif (ICU_IO_LIBRARY)

  # Look for the ICU internationalization libraries
  find_library(
    ICU_I18N_LIBRARY
    NAMES icuin icui18n cygicuin cygicuin32 cygicuin38
    PATHS ${ICU_LIBRARY_DIR}
    DOC "Libraries to link against for ICU internationalization")
  if (ICU_I18N_LIBRARY)
    MESSAGE(STATUS "Found ICU internationalization library -- " ${ICU_I18N_LIBRARY})
    set(ICU_I18N_FOUND 1)
    set(ICU_I18N_LIBRARIES ${ICU_I18N_LIBRARY})
  else (ICU_I18N_LIBRARY)
    MESSAGE(STATUS "Could not find ICU internationalization library")
    set(ICU_I18N_FOUND 0)
    set(ICU_I18N_LIBRARIES)
  endif (ICU_I18N_LIBRARY)

  # Look for ICU data library
  if (CYGWIN OR MSVC)
		# On cygwin, the data library is called icudt
    SET (ICU_DATA_NAMES icudt cygicudt cygicudt38)
  else (CYGWIN OR MSVC)
    SET (ICU_DATA_NAMES icudata)
  endif (CYGWIN OR MSVC)
  find_library(
    ICU_DATA_LIBRARY
    NAMES ${ICU_DATA_NAMES}
    PATHS ${ICU_LIBRARY_DIR}
    DOC "Libraries to link against for ICU data")
  if (ICU_DATA_LIBRARY)
    MESSAGE(STATUS "Found ICU data library -- " ${ICU_DATA_LIBRARY})
    SET(ICU_DATA_FOUND 1)
    SET(ICU_DATA_LIBRARIES ${ICU_DATA_LIBRARY})
  else (ICU_DATA_LIBRARY)
    MESSAGE(STATUS "Could not find ICU data library")
    SET(ICU_DATA_FOUND 0)
    SET(ICU_DATA_LIBRARIES)
  endif (ICU_DATA_LIBRARY)

else(ICU_INCLUDE AND ICU_LIBRARY)
  set(ICU_FOUND 0)
  set(ICU_IO_FOUND 0)
  set(ICU_I18N_FOUND 0)
  set(ICU_DATA_FOUND 0)
  set(ICU_LIBRARIES)
  set(ICU_IO_LIBRARIES)
  set(ICU_I18N_LIBRARIES)
  set(ICU_DATA_LIBRARIES)
  set(ICU_INCLUDE_DIRS)
endif(ICU_INCLUDE AND ICU_LIBRARY)