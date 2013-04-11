#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Auto.o \
	${OBJECTDIR}/Darlehen.o \
	${OBJECTDIR}/Darlehensverwaltung.o \
	${OBJECTDIR}/GUI.o \
	${OBJECTDIR}/Haus.o \
	${OBJECTDIR}/Kunde.o \
	${OBJECTDIR}/Kundenverwaltung.o \
	${OBJECTDIR}/Sicherheit.o \
	${OBJECTDIR}/Sicherungsverwaltung.o \
	${OBJECTDIR}/Wertanlage.o \
	${OBJECTDIR}/Zahlungsverwaltung.o \
	${OBJECTDIR}/date.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ss13_darlehenssystem.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ss13_darlehenssystem.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ss13_darlehenssystem ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Auto.o: Auto.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Auto.o Auto.cpp

${OBJECTDIR}/Darlehen.o: Darlehen.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Darlehen.o Darlehen.cpp

${OBJECTDIR}/Darlehensverwaltung.o: Darlehensverwaltung.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Darlehensverwaltung.o Darlehensverwaltung.cpp

${OBJECTDIR}/GUI.o: GUI.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/GUI.o GUI.cpp

${OBJECTDIR}/Haus.o: Haus.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Haus.o Haus.cpp

${OBJECTDIR}/Kunde.o: Kunde.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Kunde.o Kunde.cpp

${OBJECTDIR}/Kundenverwaltung.o: Kundenverwaltung.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Kundenverwaltung.o Kundenverwaltung.cpp

${OBJECTDIR}/Sicherheit.o: Sicherheit.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sicherheit.o Sicherheit.cpp

${OBJECTDIR}/Sicherungsverwaltung.o: Sicherungsverwaltung.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sicherungsverwaltung.o Sicherungsverwaltung.cpp

${OBJECTDIR}/Wertanlage.o: Wertanlage.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Wertanlage.o Wertanlage.cpp

${OBJECTDIR}/Zahlungsverwaltung.o: Zahlungsverwaltung.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Zahlungsverwaltung.o Zahlungsverwaltung.cpp

${OBJECTDIR}/date.o: date.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/date.o date.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ss13_darlehenssystem.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
