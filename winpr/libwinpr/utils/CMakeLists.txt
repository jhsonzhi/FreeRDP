# WinPR: Windows Portable Runtime
# libwinpr-utils cmake build script
#
# Copyright 2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(MODULE_NAME "winpr-utils")
set(MODULE_PREFIX "WINPR_UTILS")

set(${MODULE_PREFIX}_COLLECTIONS_SRCS
	collections/Queue.c
	collections/Stack.c
	collections/Reference.c
	collections/ArrayList.c
	collections/Dictionary.c
	collections/ListDictionary.c
	collections/KeyValuePair.c
	collections/CountdownEvent.c
	collections/BufferPool.c
	collections/ObjectPool.c
	collections/MessageQueue.c)

set(${MODULE_PREFIX}_SRCS
	sam.c
	ntlm.c
	print.c
	stream.c
	cmdline.c)

set(${MODULE_PREFIX}_SRCS ${${MODULE_PREFIX}_SRCS}
	${${MODULE_PREFIX}_COLLECTIONS_SRCS})

include_directories(${ZLIB_INCLUDE_DIRS})
include_directories(${OPENSSL_INCLUDE_DIR})

add_complex_library(MODULE ${MODULE_NAME} TYPE "OBJECT"
	MONOLITHIC ${MONOLITHIC_BUILD}
	SOURCES ${${MODULE_PREFIX}_SRCS})

set_target_properties(${MODULE_NAME} PROPERTIES VERSION ${WINPR_VERSION_FULL} SOVERSION ${WINPR_VERSION} PREFIX "lib")

set(${MODULE_PREFIX}_LIBS
	${ZLIB_LIBRARIES}
	${OPENSSL_LIBRARIES})
	
set_complex_link_libraries(VARIABLE ${MODULE_PREFIX}_LIBS
	MONOLITHIC ${MONOLITHIC_BUILD} INTERNAL
	MODULE winpr
	MODULES winpr-crt winpr-synch)

if(MONOLITHIC_BUILD)
	set(WINPR_LIBS ${WINPR_LIBS} ${${MODULE_PREFIX}_LIBS} PARENT_SCOPE)
else()	
	target_link_libraries(${MODULE_NAME} ${${MODULE_PREFIX}_LIBS})
	install(TARGETS ${MODULE_NAME} DESTINATION ${CMAKE_INSTALL_LIBDIR})
endif()

set_property(TARGET ${MODULE_NAME} PROPERTY FOLDER "WinPR")

if(BUILD_TESTING)
	add_subdirectory(test)
endif()

