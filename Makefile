
output: main.o ConfigurationFile.o Execute.o FileOperation.o MutateFactory.o MutateOperation.o MutateOperationFactory.o ReplaceInsertWithIndex.o ReplaceEquals.o ReplaceBoolean.o ReplaceIntegers.o Report.o
	g++ main.o ConfigurationFile.o Execute.o FileOperation.o MutateFactory.o MutateOperation.o MutateOperationFactory.o ReplaceInsertWithIndex.o ReplaceEquals.o ReplaceBoolean.o ReplaceIntegers.o Report.o -o output

main.o: main.cpp
	g++ -c main.cpp

ConfigurationFile.o: ConfigurationFile.cpp
	g++ -c ConfigurationFile.cpp

Execute.o: Execute.cpp
	g++ -c Execute.cpp

FileOperation.o: FileOperation.cpp
	g++ -c FileOperation.cpp

MutateFactory.o: MutateFactory.cpp
	g++ -c MutateFactory.cpp

MutateOperation.o: MutateOperation.cpp
	g++ -c MutateOperation.cpp

MutateOperationFactory.o: MutateOperationFactory.cpp
	g++ -c MutateOperationFactory.cpp

ReplaceInsertWithIndex.o: ReplaceInsertWithIndex.cpp
	g++ -c ReplaceInsertWithIndex.cpp

ReplaceBoolean.o: ReplaceBoolean.cpp
	g++ -c ReplaceBoolean.cpp

ReplaceEquals.o: ReplaceEquals.cpp
	g++ -c ReplaceEquals.cpp

ReplaceIntegers.o: ReplaceIntegers.cpp
	g++ -c ReplaceIntegers.cpp

Report.o: Report.cpp
	g++ -c Report.cpp

clean:
	rm -f *.o output
