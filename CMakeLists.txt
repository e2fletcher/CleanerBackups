PROJECT(Cleaner Backups)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_EXECUTABLE(cleanerb cleanerb.cpp)
#ADD_LIBRARY(gentablam SHARED Tabla)
#TARGET_LINK_LIBRARIES(gtablas gentablam)
INSTALL(TARGETS cleanerb
            RUNTIME DESTINATION /usr/bin
            #LIBRARY DESTINATION /usr/lib
        )

