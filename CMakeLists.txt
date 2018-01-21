cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

set(SHORT_NAME redtest)
project(${SHORT_NAME})
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(VITA_APP_NAME "Red Test")
set(VITA_TITLEID  "VSDK00013")

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Flags and includes
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O3 -Wno-unused-variable -Wno-unused-but-set-variable -Wno-format-truncation -fno-lto ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c+ + 11 -fno-rtti -fno-exceptions")
set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")
set(VITA_MAKE_FSELF_FLAGS "${VITA_MAKE_FSELF_FLAGS} -a 0x2808000000000000")


include_directories(
  ../common
)

add_executable(${SHORT_NAME}
  src/main.c

)

target_link_libraries(${SHORT_NAME}
SDL2_mixer
SDL2_image 
SDL2_TTF
SDL2
freetype
vorbisfile
vorbis
ogg
mikmod
pthread
jpeg
png16
mpg123
z
c
m
mad

vita2d
SceDisplay_stub
SceCtrl_stub
SceAudio_stub
SceSysmodule_stub
SceGxm_stub
SceCommonDialog_stub
ScePower_stub
SceIofilemgr_stub
SceIofilemgrForDriver_stub
SceLibKernel_stub
  
)

#vita_create_self(${SHORT_NAME}.self ${SHORT_NAME})
#vita_create_vpk(${SHORT_NAME}.vpk ${VITA_TITLEID} ${SHORT_NAME}.self

vita_create_self(eboot.bin ${SHORT_NAME} SAFE)
vita_create_vpk(${SHORT_NAME}.vpk ${VITA_TITLEID} eboot.bin
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/img/menu.png sce_sys/img/menu.png
  FILE sce_sys/img/intro.png sce_sys/img/intro.png
  FILE sce_sys/img/b1.png sce_sys/img/b1.png
  FILE sce_sys/img/b2.png sce_sys/img/b2.png
  FILE sce_sys/img/b3.png sce_sys/img/b3.png
  FILE sce_sys/img/b4.png sce_sys/img/b4.png
  FILE sce_sys/img/bs.png sce_sys/img/bs.png
  FILE sce_sys/ttf/PS3.ttf sce_sys/ttf/PS3.ttf
  FILE sce_sys/music/music.ogg sce_sys/music/music.ogg
  FILE sce_sys/music/music2.ogg sce_sys/music/music2.ogg
  FILE sce_sys/music/sontouche.ogg sce_sys/music/sontouche.ogg
  FILE sce_sys/music/sonredj.ogg sce_sys/music/sonredj.ogg
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
)
