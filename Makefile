# Makefile — compilation simple du mini-projet
# Usage :
#   make          -> compiler
#   make run      -> executer (tableau terminal)
#   make csv      -> executer + sauver CSV
#   make clean    -> nettoyer
#   make help     -> aide

CC       = gcc
CFLAGS   = -O2 -Wall -Wextra -std=c11
INCLUDES = -Isource/common \
           -Isource/insertion \
           -Isource/quick \
           -Isource/merge \
           -Isource/heap \
           -Isource/counting \
           -Isource/bucket \
           -Isource/bubble \
           -Isource/selection

SRCS = source/common/utils.c \
       source/insertion/insertion_sort.c \
       source/quick/quick_sort.c \
       source/merge/merge_sort.c \
       source/heap/heap_sort.c \
       source/counting/counting_sort.c \
       source/bucket/bucket_sort.c \
       source/bubble/bubble_sort.c \
       source/selection/selection_sort.c \
       source/benchmark.c

ifeq ($(OS),Windows_NT)
  TARGET = bin/benchmark.exe
  MKDIR  = if not exist bin mkdir bin
  RM     = del /Q
else
  TARGET = bin/benchmark
  MKDIR  = mkdir -p bin
  RM     = rm -f
endif

.PHONY: all run csv clean help

all: $(TARGET)

$(TARGET): $(SRCS)
	@$(MKDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(TARGET)
	@echo OK : $(TARGET)

run: $(TARGET)
	$(TARGET)

csv: $(TARGET)
	$(TARGET) > visualisation/csv/resultats.csv
	@echo CSV : visualisation/csv/resultats.csv

clean:
	-$(RM) $(TARGET)
	@echo Nettoyage OK

help:
	@echo make        compiler
	@echo make run    executer
	@echo make csv    executer + CSV
	@echo make clean  nettoyer
