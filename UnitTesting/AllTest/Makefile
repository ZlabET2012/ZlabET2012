# nxtOSEKルートディレクトリ
NXTOSEK_ROOT = ../../../../nxtOSEK

# ターゲット実行形式ファイル名
#TARGET = Main
TARGET = oka++

# インクルードパス
USER_INC_PATH= $(NXTOSEK_ROOT)/ecrobot/nxtway_gs_balancer

# ライブラリ
USER_LIB = nxtway_gs_balancer

# C++ソースファイル
TARGET_CPP_SOURCES = UI.cpp TouchSensor.cpp Control.cpp Motor.cpp Tail.cpp Main.cpp

# TOPPERS/ATK1(OSEK)設定ファイル
TOPPERS_OSEK_OIL_SOURCE = ./model_impl.oil

# 下記のマクロは変更しないでください
O_PATH ?= build

# makefile for C++(.cpp) build
include $(NXTOSEK_ROOT)/ecrobot/ecrobot++.mak
