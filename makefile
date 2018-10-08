#target: dependencies
#	rule to build
#

# Work cited: https://askubuntu.com/questions/433943/how-to-clean-executable-using-make-clean
# 	      https://www.cs.bu.edu/teaching/cpp/writing-makefiles/

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g
CXXFLAGS += -Wall 
#CXXFLAGS += -O3
#CXXFLAGS += -pedantic-errors
#LDFLAGS = -lboost_date_time
OBJS =numberSum.o recursiveMain.o recursiveMenu.o recursiveValidate.o stringReverse.o triangle.o 
SRCS =numberSum.cpp recursiveMain.cpp recursiveMenu.cpp recursiveValidate.cpp stringReverse.cpp triangle.cpp
HEADERS =numberSum.hpp recursiveMenu.hpp recursiveValidate.hpp stringReverse.hpp triangle.hpp

recursiveMain: ${OBJS}
	${CXX} ${CXXFLAGS} -o recursiveMain recursiveMain.o numberSum.o recursiveMenu.o recursiveValidate.o stringReverse.o triangle.o

recursiveMain.o: recursiveMain.cpp ${HEADERS}
	 ${CXX} ${CXXFLAGS} -c recursiveMain.cpp

numberSum.o:numberSum.o 
recursiveMenu.o:recursiveMenu.o
recursiveValidate.o:recursiveValidate.o
stringReverse.o:stringReverse.o
triangle.o:triangle.o

clean: ${OBJS}
	-rm *.o ${OBJS} recursiveMain
