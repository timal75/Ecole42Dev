$(DIROBJ)/Int8.o: src/Int8.cpp src/Int8.hpp src/IOperand.class.hpp \
 src/AVMException.hpp src/OperandFactory.class.hpp src/Int16.hpp \
 src/Int32.hpp src/Float.hpp src/Double.hpp src/AVM.hpp \
 src/Program.class.hpp src/Stack.class.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/Int16.o: src/Int16.cpp src/Int16.hpp src/IOperand.class.hpp \
 src/AVMException.hpp src/OperandFactory.class.hpp src/Int8.hpp \
 src/Int32.hpp src/Float.hpp src/Double.hpp src/AVM.hpp \
 src/Program.class.hpp src/Stack.class.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/Int32.o: src/Int32.cpp src/Int32.hpp src/IOperand.class.hpp \
 src/AVMException.hpp src/OperandFactory.class.hpp src/Int8.hpp \
 src/Int16.hpp src/Float.hpp src/Double.hpp src/AVM.hpp \
 src/Program.class.hpp src/Stack.class.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/Float.o: src/Float.cpp src/Float.hpp src/IOperand.class.hpp \
 src/AVMException.hpp src/OperandFactory.class.hpp src/Int8.hpp \
 src/Int16.hpp src/Int32.hpp src/Double.hpp src/AVM.hpp \
 src/Program.class.hpp src/Stack.class.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/Double.o: src/Double.cpp src/Double.hpp src/IOperand.class.hpp \
 src/AVMException.hpp src/OperandFactory.class.hpp src/Int8.hpp \
 src/Int16.hpp src/Int32.hpp src/Float.hpp src/AVM.hpp \
 src/Program.class.hpp src/Stack.class.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/Program.class.o: src/Program.class.cpp src/Program.class.hpp \
 src/IOperand.class.hpp src/AVMException.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/main.o: src/main.cpp src/AVM.hpp src/AVMException.hpp \
 src/Program.class.hpp src/IOperand.class.hpp src/Stack.class.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/OperandFactory.class.o: src/OperandFactory.class.cpp \
 src/OperandFactory.class.hpp src/IOperand.class.hpp src/Int8.hpp \
 src/AVMException.hpp src/Int16.hpp src/Int32.hpp src/Float.hpp \
 src/Double.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/Stack.class.o: src/Stack.class.cpp src/Stack.class.hpp \
 src/IOperand.class.hpp src/AVMException.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/Lexer.o: src/Lexer.cpp src/Lexer.hpp src/Program.class.hpp \
 src/IOperand.class.hpp src/AVMException.hpp src/Stack.class.hpp \
 src/AVM.hpp src/OperandFactory.class.hpp src/Int8.hpp src/Int16.hpp \
 src/Int32.hpp src/Float.hpp src/Double.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/AVM.o: src/AVM.cpp src/AVM.hpp src/AVMException.hpp src/Program.class.hpp \
 src/IOperand.class.hpp src/Stack.class.hpp src/OperandFactory.class.hpp \
 src/Int8.hpp src/Int16.hpp src/Int32.hpp src/Float.hpp src/Double.hpp \
 src/Lexer.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(DIROBJ)/AVMException.o: src/AVMException.cpp src/AVMException.hpp
	@echo $(TITLE)
	@mkdir -p $(DIROBJ)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
