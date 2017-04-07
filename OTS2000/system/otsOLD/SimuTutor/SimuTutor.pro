######################################################################
# Automatically generated by qmake (2.01a) ??? ?? 3 09:19:31 2010
######################################################################

TEMPLATE = app
TARGET = SimuTutor
CONFIG += qaxcontainer
QT += 	network \
	sql
win32:RC_FILE = SimuTutor.rc
DEPENDPATH += .
INCLUDEPATH += .		\
		\home\ems\system\ots\ots_hdb\inc

# Input    
FORMS += ui/about.ui \
         ui/fault.ui \
         ui/faultadd.ui \
         ui/faultdata.ui \
         ui/faultdataadd.ui \
	 ui/groups.ui \
         ui/historyrec.ui \
	 ui/localopr.ui \
         ui/login.ui \
         ui/loginrec.ui \
         ui/loginstudent.ui \
         ui/model.ui \
         ui/modeladd.ui \
         ui/modelparam.ui \
         ui/modelparamadd.ui \
	 ui/pointname.ui \
	 ui/privilegemanager.ui \
         ui/revert.ui \
         ui/revertadd.ui \
	 ui/savescene.ui \
         ui/scene.ui \
         ui/sceneadd.ui \
         ui/scenedata.ui \
         ui/scenedataadd.ui \
	 ui/SceneReset.ui \
	 ui/scorerec.ui \
         ui/selecttask.ui \
         ui/sendmessage.ui \
         ui/SequenceEdit.ui \
         ui/SequenceList.ui \
	 ui/setpointmask.ui \
	 ui/setscenefault.ui \
         ui/settask.ui \
         ui/stationadd.ui \
         ui/stationconfig.ui \
	 ui/stndev.ui \
         ui/studentinfo.ui \
         ui/studentinfoadd.ui \
	 ui/subject_condition.ui \
	 ui/subject_edit.ui \
         ui/task.ui \
         ui/taskadd.ui \
         ui/SimuTutor.ui \
         ui/traininfo.ui \
         ui/traininfoadd.ui \
	 ui/trainmanager.ui   

HEADERS += src/about.h \
	   src/excelobject.h \
           src/fault.h \
	   src/faultdata.h \
	   src/historyrec.h \ 
	   src/Localopr.h \
           src/login.h \
	   src/loginrec.h \
           src/loginstudent.h \
	   src/model.h \
           src/modelparam.h \
	   src/pointname.h \
	   src/privilegemanager.h \
	   src/qcommon.h \
	   src/revert.h \
	   src/savescene.h \
           src/scene.h \
	   src/scenedata.h \
	   src/SceneReset.h \
	   src/scorerec.h \
           src/sendmessage.h \
	   src/Sequence.h \
	   src/setpointmask.h \
	   src/settask.h \
           src/stationconfig.h \
	   src/stndev.h \
           src/studentinfo.h \
	   src/subject.h \
	   src/task.h \   
           src/SimuTutor.h \
	   src/traininfo.h \
	   src/thread.h \
           /home/ems/system/ots/ots_hdb/inc/ots_hdb.h                                  
         
SOURCES += src/about.cpp \
	   src/excelobject.cpp \
           src/fault.cpp \
	   src/faultdata.cpp \
	   src/historyrec.cpp \ 
	   src/Localopr.cpp \
           src/login.cpp \
	   src/loginrec.cpp \
           src/loginstudent.cpp \
	   src/main.cpp \
	   src/model.cpp \
           src/modelparam.cpp \ 
	   src/pointname.cpp \
	   src/privilegemanager.cpp \
	   src/qcommon.cpp \
	   src/revert.cpp \
	   src/savescene.cpp \
           src/scene.cpp \
	   src/scenedata.cpp \
	   src/SceneReset.cpp \
	   src/scorerec.cpp \
           src/sendmessage.cpp \
	   src/Sequence.cpp \
	   src/setpointmask.cpp \
	   src/settask.cpp \
           src/stationconfig.cpp \
	   src/stndev.cpp \
           src/studentinfo.cpp \
	   src/subject.cpp \
	   src/task.cpp \   
           src/SimuTutor.cpp \
	   src/traininfo.cpp \
	   src/thread.cpp 

RESOURCES += SimuTutor.qrc

CONFIG(debug) {
	unix|win32: LIBS += odbc32.lib
	unix|win32: LIBS += odbccp32.lib
	unix|win32: LIBS += wsock32.lib
 	unix|win32: LIBS += \home\ems\system\dms\v4.0a\lib\dblib.lib
 	unix|win32: LIBS += \home\ems\system\lan\v4.0a\lib\lan.lib
	unix|win32: LIBS += \home\ems\system\dps\v4.0a\lib\ipclib.lib
	unix|win32: LIBS += \home\ems\system\ots\ots_hdb\lib\ots_hdbd.lib
	unix|win32: LIBS += \home\ems\system\ots\ots_hdb\lib\otsd.lib
} else {
	unix|win32: LIBS += odbc32.lib
	unix|win32: LIBS += odbccp32.lib
	unix|win32: LIBS += wsock32.lib
	unix|win32: LIBS += \home\ems\system\dms\v4.0a\lib\dblib.lib
 	unix|win32: LIBS += \home\ems\system\lan\v4.0a\lib\lan.lib
	unix|win32: LIBS += \home\ems\system\dps\v4.0a\lib\ipclib.lib
	unix|win32: LIBS += \home\ems\system\ots\ots_hdb\lib\ots_hdb.lib
	unix|win32: LIBS += \home\ems\system\ots\ots_hdb\lib\ots.lib
}


#Translation files
TRANSLATIONS += designer_zh_CN.ts \
		SimuTutor_zh_CN.ts \
		SimuTutor_en.ts