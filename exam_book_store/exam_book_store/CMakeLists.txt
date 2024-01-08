cmake_minimum_required(VERSION 3.14)

project(exam_book_store LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Xml)

add_executable(exam_book_store
  main.cpp
  item.h item.cpp
  customer.h customer.cpp
  transaction.h transaction.cpp
  transactionmemento.h transactionmemento.cpp
)
target_link_libraries(exam_book_store PRIVATE
    Qt6::Core
    Qt6::Xml
)

include(GNUInstallDirs)
install(TARGETS exam_book_store
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
