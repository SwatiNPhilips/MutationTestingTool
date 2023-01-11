rootdir = $(realpath ..)
INC=$(rootdir)/INC/

CC = g++
CFLAGS = -std=c++17 -c -Wall -I$(INC)
LDFLAGS=

SOURCES = main.cpp \
ConfigurationFile.cpp\
Execute.cpp\
FileOperation.cpp\
MutateFactory.cpp\
MutateOperation.cpp\
MutateOperationFactory.cpp \
ReplaceInsertWithIndex.cpp\
ReplaceBoolean.cpp\
ReplaceEquals.cpp\
ReplaceIntegers.cpp\
ReplaceIncrement.cpp\
ReplaceDecrement.cpp\
ReplaceAddition.cpp\
ReplaceSubtraction.cpp\
ReplaceMultiplication.cpp\
ReplaceDivision.cpp\
Report.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=output

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o output
