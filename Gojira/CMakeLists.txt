cmake_minimum_required(VERSION 2.28)
project(Gojira)
include_directories(include)
set(GOJIRA_FILEFORMAT_LIB fileformat)
add_subdirectory(${GOJIRA_FILEFORMAT_LIB})
aux_source_directory(./memory GOJIRA_MEMORY_DIR)
aux_source_directory(./asm GOJIRA_ASM_DIR)
aux_source_directory(./assist GOJIRA_ASSIST_DIR)
aux_source_directory(./container GOJIRA_CONTAINER_DIR)
aux_source_directory(./hook GOJIRA_HOOK_DIR)
aux_source_directory(./io GOJIRA_IO_DIR)
aux_source_directory(./process GOJIRA_PROCESS_DIR)
aux_source_directory(./system GOJIRA_SYSTEM_DIR)
add_library(
    ${PROJECT_NAME} 
    ${GOJIRA_MEMORY_DIR} 
    ${GOJIRA_ASM_DIR} 
    ${GOJIRA_ASSIST_DIR}
    ${GOJIRA_CONTAINER_DIR}
    ${GOJIRA_HOOK_DIR}
    ${GOJIRA_IO_DIR}
    ${GOJIRA_PROCESS_DIR}
    ${GOJIRA_SYSTEM_DIR}
    ${GOJIRA_FILEFORMAT_DIR}
    )
target_link_libraries(${PROJECT_NAME} ${GOJIRA_FILEFORMAT_LIB})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


