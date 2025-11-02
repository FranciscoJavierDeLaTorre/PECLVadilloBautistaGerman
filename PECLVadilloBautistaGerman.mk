##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PECLVadilloBautistaGerman
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :="C:/Estructura de Datos"
ProjectPath            :="C:/Estructura de Datos/GitHub/PECLVadilloBautistaGerman"
IntermediateDirectory  :=../../build-$(WorkspaceConfiguration)/GitHub/PECLVadilloBautistaGerman
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Francisco Javier
Date                   :=11/2/2025
CodeLitePath           :="C:/Users/Francisco Javier/Downloads/codelite-amd64-17.0.0/codelite"
MakeDirCommand         :=mkdir
LinkerName             :=C:/mingw64/mingw32/bin/g++.exe
SharedObjectLinkerName :=C:/mingw64/mingw32/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=C:/Estructura de Datos/build-$(WorkspaceConfiguration)/bin
OutputFile             :=..\..\build-$(WorkspaceConfiguration)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64/mingw32/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/mingw64/mingw32/bin/ar.exe -r
CXX      := C:/mingw64/mingw32/bin/g++.exe
CC       := C:/mingw64/mingw32/bin/gcc.exe
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw64/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Users\Francisco Javier\Downloads\codelite-amd64-17.0.0\codelite
Objects0=$(IntermediateDirectory)/Aficionado.cpp$(ObjectSuffix) $(IntermediateDirectory)/Pila.cpp$(ObjectSuffix) $(IntermediateDirectory)/Cola.cpp$(ObjectSuffix) $(IntermediateDirectory)/Lista.cpp$(ObjectSuffix) $(IntermediateDirectory)/NodoCola.cpp$(ObjectSuffix) $(IntermediateDirectory)/NodoLista.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Gestor.cpp$(ObjectSuffix) $(IntermediateDirectory)/NodoPila.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"
	@if not exist "$(OutputDirectory)" $(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@if not exist "$(IntermediateDirectory)" $(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Aficionado.cpp$(ObjectSuffix): Aficionado.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Estructura de Datos/GitHub/PECLVadilloBautistaGerman/Aficionado.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Aficionado.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Aficionado.cpp$(PreprocessSuffix): Aficionado.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Aficionado.cpp$(PreprocessSuffix) Aficionado.cpp

$(IntermediateDirectory)/Pila.cpp$(ObjectSuffix): Pila.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Estructura de Datos/GitHub/PECLVadilloBautistaGerman/Pila.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Pila.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Pila.cpp$(PreprocessSuffix): Pila.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Pila.cpp$(PreprocessSuffix) Pila.cpp

$(IntermediateDirectory)/Cola.cpp$(ObjectSuffix): Cola.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Estructura de Datos/GitHub/PECLVadilloBautistaGerman/Cola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Cola.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Cola.cpp$(PreprocessSuffix): Cola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Cola.cpp$(PreprocessSuffix) Cola.cpp

$(IntermediateDirectory)/Lista.cpp$(ObjectSuffix): Lista.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Estructura de Datos/GitHub/PECLVadilloBautistaGerman/Lista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Lista.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Lista.cpp$(PreprocessSuffix): Lista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Lista.cpp$(PreprocessSuffix) Lista.cpp

$(IntermediateDirectory)/NodoCola.cpp$(ObjectSuffix): NodoCola.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Estructura de Datos/GitHub/PECLVadilloBautistaGerman/NodoCola.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoCola.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NodoCola.cpp$(PreprocessSuffix): NodoCola.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NodoCola.cpp$(PreprocessSuffix) NodoCola.cpp

$(IntermediateDirectory)/NodoLista.cpp$(ObjectSuffix): NodoLista.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Estructura de Datos/GitHub/PECLVadilloBautistaGerman/NodoLista.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoLista.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NodoLista.cpp$(PreprocessSuffix): NodoLista.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NodoLista.cpp$(PreprocessSuffix) NodoLista.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Estructura de Datos/GitHub/PECLVadilloBautistaGerman/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Gestor.cpp$(ObjectSuffix): Gestor.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Estructura de Datos/GitHub/PECLVadilloBautistaGerman/Gestor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Gestor.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Gestor.cpp$(PreprocessSuffix): Gestor.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Gestor.cpp$(PreprocessSuffix) Gestor.cpp

$(IntermediateDirectory)/NodoPila.cpp$(ObjectSuffix): NodoPila.cpp 
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Estructura de Datos/GitHub/PECLVadilloBautistaGerman/NodoPila.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoPila.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NodoPila.cpp$(PreprocessSuffix): NodoPila.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NodoPila.cpp$(PreprocessSuffix) NodoPila.cpp

##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


