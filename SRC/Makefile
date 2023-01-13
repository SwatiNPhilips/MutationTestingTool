rootdir = $(realpath ..)
INC=$(rootdir)/INC/
BOOST = -lboost_filesystem

CC = g++
CFLAGS = -std=c++17 -c -Wall -I$(INC)
LDFLAGS=

SOURCES = main.cpp \
ConfigurationManager.cpp\
ConfigurationFactory.cpp\
ConfigurationOperation.cpp\
ConfigurationJSONParser.cpp\
Execute.cpp\
FileOperation.cpp\
MutateManager.cpp\
MutateOperation.cpp\
MutateOperationFactory.cpp \
ReplaceInsertWithIndex.cpp\
ReplaceBoolean.cpp\
ReplaceEquals.cpp\
ReplaceIntegers.cpp\
Report.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=MutationTestingTool

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(BOOST)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o output
