#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-PROTEUS-VSM.mk)" "nbproject/Makefile-local-PROTEUS-VSM.mk"
include nbproject/Makefile-local-PROTEUS-VSM.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=PROTEUS-VSM
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/_GettingStarted.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/_GettingStarted.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=SRC/ConfigBits.c SRC/GettingStarted.c SRC/LCD-XC.c SRC/USART-XC.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/SRC/ConfigBits.o ${OBJECTDIR}/SRC/GettingStarted.o ${OBJECTDIR}/SRC/LCD-XC.o ${OBJECTDIR}/SRC/USART-XC.o
POSSIBLE_DEPFILES=${OBJECTDIR}/SRC/ConfigBits.o.d ${OBJECTDIR}/SRC/GettingStarted.o.d ${OBJECTDIR}/SRC/LCD-XC.o.d ${OBJECTDIR}/SRC/USART-XC.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/SRC/ConfigBits.o ${OBJECTDIR}/SRC/GettingStarted.o ${OBJECTDIR}/SRC/LCD-XC.o ${OBJECTDIR}/SRC/USART-XC.o

# Source Files
SOURCEFILES=SRC/ConfigBits.c SRC/GettingStarted.c SRC/LCD-XC.c SRC/USART-XC.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-PROTEUS-VSM.mk dist/${CND_CONF}/${IMAGE_TYPE}/_GettingStarted.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GA010
MP_LINKER_FILE_OPTION=,--script=p24FJ128GA010.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/SRC/ConfigBits.o: SRC/ConfigBits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SRC 
	@${RM} ${OBJECTDIR}/SRC/ConfigBits.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SRC/ConfigBits.c  -o ${OBJECTDIR}/SRC/ConfigBits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SRC/ConfigBits.o.d"      -g -D__DEBUG   -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SRC/ConfigBits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SRC/GettingStarted.o: SRC/GettingStarted.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SRC 
	@${RM} ${OBJECTDIR}/SRC/GettingStarted.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SRC/GettingStarted.c  -o ${OBJECTDIR}/SRC/GettingStarted.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SRC/GettingStarted.o.d"      -g -D__DEBUG   -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SRC/GettingStarted.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SRC/LCD-XC.o: SRC/LCD-XC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SRC 
	@${RM} ${OBJECTDIR}/SRC/LCD-XC.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SRC/LCD-XC.c  -o ${OBJECTDIR}/SRC/LCD-XC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SRC/LCD-XC.o.d"      -g -D__DEBUG   -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SRC/LCD-XC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SRC/USART-XC.o: SRC/USART-XC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SRC 
	@${RM} ${OBJECTDIR}/SRC/USART-XC.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SRC/USART-XC.c  -o ${OBJECTDIR}/SRC/USART-XC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SRC/USART-XC.o.d"      -g -D__DEBUG   -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SRC/USART-XC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/SRC/ConfigBits.o: SRC/ConfigBits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SRC 
	@${RM} ${OBJECTDIR}/SRC/ConfigBits.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SRC/ConfigBits.c  -o ${OBJECTDIR}/SRC/ConfigBits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SRC/ConfigBits.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SRC/ConfigBits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SRC/GettingStarted.o: SRC/GettingStarted.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SRC 
	@${RM} ${OBJECTDIR}/SRC/GettingStarted.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SRC/GettingStarted.c  -o ${OBJECTDIR}/SRC/GettingStarted.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SRC/GettingStarted.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SRC/GettingStarted.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SRC/LCD-XC.o: SRC/LCD-XC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SRC 
	@${RM} ${OBJECTDIR}/SRC/LCD-XC.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SRC/LCD-XC.c  -o ${OBJECTDIR}/SRC/LCD-XC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SRC/LCD-XC.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SRC/LCD-XC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/SRC/USART-XC.o: SRC/USART-XC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/SRC 
	@${RM} ${OBJECTDIR}/SRC/USART-XC.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SRC/USART-XC.c  -o ${OBJECTDIR}/SRC/USART-XC.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/SRC/USART-XC.o.d"      -g -omf=elf -O0 -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/SRC/USART-XC.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/_GettingStarted.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/_GettingStarted.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG   -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/_GettingStarted.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/_GettingStarted.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -Wl,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/_GettingStarted.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/PROTEUS-VSM
	${RM} -r dist/PROTEUS-VSM

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
