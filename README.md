# MutationTestingTool
This tool generates mutation files for C++<br/>
The config file contains the file details and type of the mutation you want to perform<br/>
INTEGER = 0 <br/>
INSERT = 1<br/>
BOOLEAN = 2<br/>
EQUALS = 3<br/>

The further mutents can be extended, find the architecture to extend in ppt.<br/>

To use cmake follow below steps:
1. make build dir in root directory. 
2. Run, cd build
3. Run, cmake .. 
The above command will generate Makefile and other files in build directory.
4. Simply run make in build directory.
5. To install boost library use following command.

Ubuntu: "sudo apt-get install libboost-all-dev"
Visual studio Windows : Install the package using package manager console using command "NuGet\Install-Package boost -Version 1.66.0"

Note: CMake supports out-of-source build. Even the most simple project should never mix-up
sources with generated files. In-source build is a BAD choice.

Contributors:<br/>
Ganesh D <br/>
Ashutosh Gupta <br/>
Swati Ashok Navalgundkar <br/>
