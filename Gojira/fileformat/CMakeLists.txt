project(fileformat)
aux_source_directory(./elf GOJIRA_FILEFORMAT_ELF_DIR)
aux_source_directory(./pe GOJIRA_FILEFORMAT_PE_DIR)
aux_source_directory(./mp3 GOJIRA_FILEFORMAT_MP3_DIR)

add_library(
    ${PROJECT_NAME}
    ${GOJIRA_FILEFORMAT_ELF_DIR}
    ${GOJIRA_FILEFORMAT_PE_DIR}
    ${GOJIRA_FILEFORMAT_MP3_DIR}
    )