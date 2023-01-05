rootdir = $(realpath ..)
INC=$(rootdir)/INC/
BOOST_ROOT := /usr/local/boost_1_66_0
BOOST_INC := ${BOOST_ROOT}/include

CC = g++
CFLAGS = -std=c++17 -c -Wall -I$(INC) -I$(BOOST_ROOT)
LDFLAGS=

SOURCES = main.cpp \
ConfigurationFile.cpp\
ConfigurationParser.cpp\
Execute.cpp\
FileOperation.cpp\
MutateFactory.cpp\
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
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o output
