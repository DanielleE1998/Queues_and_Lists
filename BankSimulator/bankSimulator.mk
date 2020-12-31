##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=bankSimulator
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/MomstroCity/codeLiteWorkSpace/DataStructs
ProjectPath            :=C:/Users/MomstroCity/codeLiteWorkSpace/DataStructs/bankSimulator
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=MomstroCity
Date                   :=16/07/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="bankSimulator.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/BankSimulation.cpp$(ObjectSuffix) $(IntermediateDirectory)/Customer.cpp$(ObjectSuffix) $(IntermediateDirectory)/PriorityQueue.cpp$(ObjectSuffix) $(IntermediateDirectory)/QueType.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/BankSimulation.cpp$(ObjectSuffix): BankSimulation.cpp $(IntermediateDirectory)/BankSimulation.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/MomstroCity/codeLiteWorkSpace/DataStructs/bankSimulator/BankSimulation.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BankSimulation.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BankSimulation.cpp$(DependSuffix): BankSimulation.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BankSimulation.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BankSimulation.cpp$(DependSuffix) -MM BankSimulation.cpp

$(IntermediateDirectory)/BankSimulation.cpp$(PreprocessSuffix): BankSimulation.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BankSimulation.cpp$(PreprocessSuffix) BankSimulation.cpp

$(IntermediateDirectory)/Customer.cpp$(ObjectSuffix): Customer.cpp $(IntermediateDirectory)/Customer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/MomstroCity/codeLiteWorkSpace/DataStructs/bankSimulator/Customer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Customer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Customer.cpp$(DependSuffix): Customer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Customer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Customer.cpp$(DependSuffix) -MM Customer.cpp

$(IntermediateDirectory)/Customer.cpp$(PreprocessSuffix): Customer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Customer.cpp$(PreprocessSuffix) Customer.cpp

$(IntermediateDirectory)/PriorityQueue.cpp$(ObjectSuffix): PriorityQueue.cpp $(IntermediateDirectory)/PriorityQueue.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/MomstroCity/codeLiteWorkSpace/DataStructs/bankSimulator/PriorityQueue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PriorityQueue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PriorityQueue.cpp$(DependSuffix): PriorityQueue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PriorityQueue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PriorityQueue.cpp$(DependSuffix) -MM PriorityQueue.cpp

$(IntermediateDirectory)/PriorityQueue.cpp$(PreprocessSuffix): PriorityQueue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PriorityQueue.cpp$(PreprocessSuffix) PriorityQueue.cpp

$(IntermediateDirectory)/QueType.cpp$(ObjectSuffix): QueType.cpp $(IntermediateDirectory)/QueType.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/MomstroCity/codeLiteWorkSpace/DataStructs/bankSimulator/QueType.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/QueType.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/QueType.cpp$(DependSuffix): QueType.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/QueType.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/QueType.cpp$(DependSuffix) -MM QueType.cpp

$(IntermediateDirectory)/QueType.cpp$(PreprocessSuffix): QueType.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/QueType.cpp$(PreprocessSuffix) QueType.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


