#all Targets
all :bin/cTrace

#Toll invocations
#Executable "cTrace" depends on the file main.o Agent.o Graph.o Tree.o Session.o 
bin/cTrace: bin/main.o bin/Agent.o bin/Graph.o bin/Tree.o bin/Session.o	
	@echo 'Bulding traget:cTrace'
	@echo 'Invoking: c++ Linker'
	g++ -o bin/cTrace bin/main.o bin/Agent.o bin/Graph.o bin/Tree.o bin/Session.o  
	@echo 'Finshed building target: Ctrace'
	@echo
	
#main.o Depends on the  source and header files src/main.cpp include Session.h
bin/main.o :src/main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp
	
#Agent.o Depends on the  source and header files src/main.cpp include Session.h
bin/Agent.o :src/Agent.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Agent.o src/Agent.cpp
	
#Tree.o Depends on the  source and header files src/Tree.cpp include Session.h
bin/Tree.o :src/Tree.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Tree.o src/Tree.cpp
	
#Graph.o Depends on the  source and header files src/main.cpp include Session.h
bin/Graph.o :src/Graph.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Graph.o src/Graph.cpp
		
#Session.o Depends on the  source and header files src/main.cpp include Session.h
bin/Session.o :src/Session.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o src/Session.cpp


#clean the build directory
clean:
rm -f bin/*::
