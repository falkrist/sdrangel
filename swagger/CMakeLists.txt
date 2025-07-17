project (swagger)

# Залишаємо автоматичний пошук, щоб нічого не зламати
file(GLOB swagger_SOURCES
    ${CMAKE_SOURCE_DIR}/swagger/sdrangel/code/qt5/client/*.cpp
)

# ▼▼▼ ДОДАЙТЕ ЦЕЙ БЛОК ▼▼▼
# Явно додаємо наш новий .cpp файл до списку, щоб гарантувати його компіляцію.
list(APPEND swagger_SOURCES
    ${CMAKE_SOURCE_DIR}/swagger/sdrangel/code/qt5/client/SWGFreqScannerFrequencyModification.cpp
)
# ▲▲▲ КІНЕЦЬ БЛОКУ ▲▲▲

# Створюємо бібліотеку ТІЛЬКИ з файлів вихідного коду (.cpp)
add_library(swagger
    ${swagger_SOURCES}
)

# Папки з файлами заголовків (.h) додаються тут
include_directories(
    ${CMAKE_SOURCE_DIR}/exports
    ${CMAKE_SOURCE_DIR}/swagger/sdrangel/code/qt5/client
)

if (NOT MSVC)
    set_target_properties(swagger PROPERTIES COMPILE_FLAGS "-Wno-conversion-null -Wno-unused-variable -Wno-unused-parameter")
endif()

target_link_libraries(swagger
    Qt::Core
    Qt::Network
)

install(TARGETS swagger DESTINATION ${INSTALL_LIB_DIR})