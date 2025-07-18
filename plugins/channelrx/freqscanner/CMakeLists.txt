project(freqscanner)

set(freqscanner_SOURCES
    freqscanner.cpp
    freqscannersettings.cpp
    freqscannerbaseband.cpp
    freqscannersink.cpp
    freqscannerplugin.cpp
    freqscannerwebapiadapter.cpp
)

set(freqscanner_HEADERS
    freqscanner.h
    freqscannersettings.h
    freqscannerbaseband.h
    freqscannersink.h
    freqscannerplugin.h
    freqscannerwebapiadapter.h
)

# Цей рядок каже компілятору, де шукати .h файли для SWG класів
include_directories(
    ${CMAKE_SOURCE_DIR}/swagger/sdrangel/code/qt5/client
)

if(NOT SERVER_MODE)
    set(freqscanner_SOURCES
        ${freqscanner_SOURCES}
        freqscannergui.cpp
        freqscannergui.ui
        freqscanneraddrangedialog.cpp
        freqscanneraddrangedialog.ui
    )
    set(freqscanner_HEADERS
        ${freqscanner_HEADERS}
        freqscannergui.h
        freqscanneraddrangedialog.h
    )

    set(TARGET_NAME ${PLUGINS_PREFIX}freqscanner)
    set(TARGET_LIB "Qt::Widgets")
    set(TARGET_LIB_GUI "sdrgui")
    set(INSTALL_FOLDER ${INSTALL_PLUGINS_DIR})
else()
    set(TARGET_NAME ${PLUGINSSRV_PREFIX}freqscannersrv)
    set(TARGET_LIB "")
    set(TARGET_LIB_GUI "")
    set(INSTALL_FOLDER ${INSTALL_PLUGINSSRV_DIR})
endif()

if(NOT Qt6_FOUND)
    add_library(${TARGET_NAME} MODULE ${freqscanner_SOURCES})
else()
    qt_add_plugin(${TARGET_NAME} CLASS_NAME FreqScannerPlugin ${freqscanner_SOURCES})
endif()

if(NOT BUILD_SHARED_LIBS)
    set_property(GLOBAL APPEND PROPERTY STATIC_PLUGINS_PROPERTY ${TARGET_NAME})
endif()

# ▼▼▼ ОСНОВНЕ ВИПРАВЛЕННЯ ТУТ ▼▼▼
# Ми явно вказуємо, що наш плагін залежить від бібліотеки swagger
if(NOT SERVER_MODE)
    target_link_libraries(${TARGET_NAME} PRIVATE
        Qt::Core
        Qt::Gui
        ${TARGET_LIB}
        sdrbase
        ${TARGET_LIB_GUI}
        httpserver
        qrtplib
        swagger
    )
else()
    target_link_libraries(${TARGET_NAME} PRIVATE
        Qt::Core
        sdrbase
        httpserver
        qrtplib
        swagger
    )
endif()
# ▲▲▲ КІНЕЦЬ ВИПРАВЛЕННЯ ▲▲▲

install(TARGETS ${TARGET_NAME} DESTINATION ${INSTALL_FOLDER})

# Install debug symbols
if (WIN32)
    install(FILES $<TARGET_PDB_FILE:${TARGET_NAME}> CONFIGURATIONS Debug RelWithDebInfo DESTINATION ${INSTALL_FOLDER} )
endif()