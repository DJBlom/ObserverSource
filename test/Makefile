##############################################################
# Contents: Paths to source files used by CppUTest
# Author: Dawid Blom.
# Date: September 18, 2022
#
# NOTE: This Makefile adds value to the CppUTests framework
# by specifying the folders where the code is to be tested.
##############################################################
PROJECT_DIR :=$(realpath ..)
TEST_DIR :=$(realpath .)
TEST_TARGET := UnitTests
CPPUTEST_CXXFLAGS=-std=c++23
CPPUTEST_LDFLAGS += $(shell pkg-config --libs opencv)

SRC_DIRS :=\
	$(PROJECT_DIR)/source/api/source\
	$(PROJECT_DIR)/source/features/source\
	$(PROJECT_DIR)/source/system/source\
	$(PROJECT_DIR)/source/thirdparty/source\



INCLUDE_DIRS :=\
	$(CPPUTEST_HOME)/include\
	$(TEST_DIR)/mocks/include\
	$(PROJECT_DIR)/source \
	$(PROJECT_DIR)/source/api/include\
	$(PROJECT_DIR)/source/features/include\
	$(PROJECT_DIR)/source/system/include\
	$(PROJECT_DIR)/source/thirdparty/include\



TEST_SRC_DIRS :=\
	$(TEST_DIR)\
	$(TEST_DIR)/tests\
	$(TEST_DIR)/mocks/source\


CPPUTEST_USE_EXTENSIONS := Y
CPPUTEST_USE_MEM_LEAK_DETECTION := N
-include $(CPPUTEST_HOME)/build/MakefileWorker.mk
