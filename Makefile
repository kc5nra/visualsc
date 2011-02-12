#############################################################################
# Makefile for building: visualsc
# Generated by qmake (2.01a) (Qt 4.7.0) on: Sat Feb 12 08:07:56 2011
# Project:  visualsc.pro
# Template: subdirs
# Command: c:/qt/2010.05/qt/bin/qmake.exe -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o Makefile visualsc.pro
#############################################################################

first: make_default
MAKEFILE      = Makefile
QMAKE         = c:/qt/2010.05/qt/bin/qmake.exe
DEL_FILE      = rm
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir
COPY          = cp
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = mv
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir
SUBTARGETS    =  \
		sub-scdatamodel \
		sub-sceditcontroller \
		sub-scgraphicsview \
		sub-app

scdatamodel/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) scdatamodel/ || $(MKDIR) scdatamodel/ 
	cd scdatamodel/ && $(QMAKE) c:/Users/David/Documents/QtProjects/visualsc/scdatamodel/scdatamodel.pro -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o $(MAKEFILE)
sub-scdatamodel-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) scdatamodel/ || $(MKDIR) scdatamodel/ 
	cd scdatamodel/ && $(QMAKE) c:/Users/David/Documents/QtProjects/visualsc/scdatamodel/scdatamodel.pro -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o $(MAKEFILE)
sub-scdatamodel: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE)
sub-scdatamodel-make_default-ordered: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) 
sub-scdatamodel-make_default: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) 
sub-scdatamodel-make_first-ordered: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) first
sub-scdatamodel-make_first: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) first
sub-scdatamodel-all-ordered: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) all
sub-scdatamodel-all: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) all
sub-scdatamodel-clean-ordered: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) clean
sub-scdatamodel-clean: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) clean
sub-scdatamodel-distclean-ordered: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) distclean
sub-scdatamodel-distclean: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) distclean
sub-scdatamodel-install_subtargets-ordered: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) install
sub-scdatamodel-install_subtargets: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) install
sub-scdatamodel-uninstall_subtargets-ordered: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-scdatamodel-uninstall_subtargets: scdatamodel/$(MAKEFILE) FORCE
	cd scdatamodel/ && $(MAKE) -f $(MAKEFILE) uninstall
sceditcontroller/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) sceditcontroller/ || $(MKDIR) sceditcontroller/ 
	cd sceditcontroller/ && $(QMAKE) c:/Users/David/Documents/QtProjects/visualsc/sceditcontroller/sceditcontroller.pro -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o $(MAKEFILE)
sub-sceditcontroller-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) sceditcontroller/ || $(MKDIR) sceditcontroller/ 
	cd sceditcontroller/ && $(QMAKE) c:/Users/David/Documents/QtProjects/visualsc/sceditcontroller/sceditcontroller.pro -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o $(MAKEFILE)
sub-sceditcontroller: sceditcontroller/$(MAKEFILE) FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE)
sub-sceditcontroller-make_default-ordered: sceditcontroller/$(MAKEFILE) sub-scdatamodel-make_default-ordered  FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) 
sub-sceditcontroller-make_default: sceditcontroller/$(MAKEFILE) FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) 
sub-sceditcontroller-make_first-ordered: sceditcontroller/$(MAKEFILE) sub-scdatamodel-make_first-ordered  FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) first
sub-sceditcontroller-make_first: sceditcontroller/$(MAKEFILE) FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) first
sub-sceditcontroller-all-ordered: sceditcontroller/$(MAKEFILE) sub-scdatamodel-all-ordered  FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) all
sub-sceditcontroller-all: sceditcontroller/$(MAKEFILE) FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) all
sub-sceditcontroller-clean-ordered: sceditcontroller/$(MAKEFILE) sub-scdatamodel-clean-ordered  FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) clean
sub-sceditcontroller-clean: sceditcontroller/$(MAKEFILE) FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) clean
sub-sceditcontroller-distclean-ordered: sceditcontroller/$(MAKEFILE) sub-scdatamodel-distclean-ordered  FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) distclean
sub-sceditcontroller-distclean: sceditcontroller/$(MAKEFILE) FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) distclean
sub-sceditcontroller-install_subtargets-ordered: sceditcontroller/$(MAKEFILE) sub-scdatamodel-install_subtargets-ordered  FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) install
sub-sceditcontroller-install_subtargets: sceditcontroller/$(MAKEFILE) FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) install
sub-sceditcontroller-uninstall_subtargets-ordered: sceditcontroller/$(MAKEFILE) sub-scdatamodel-uninstall_subtargets-ordered  FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-sceditcontroller-uninstall_subtargets: sceditcontroller/$(MAKEFILE) FORCE
	cd sceditcontroller/ && $(MAKE) -f $(MAKEFILE) uninstall
scgraphicsview/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) scgraphicsview/ || $(MKDIR) scgraphicsview/ 
	cd scgraphicsview/ && $(QMAKE) c:/Users/David/Documents/QtProjects/visualsc/scgraphicsview/scgraphicsview.pro -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o $(MAKEFILE)
sub-scgraphicsview-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) scgraphicsview/ || $(MKDIR) scgraphicsview/ 
	cd scgraphicsview/ && $(QMAKE) c:/Users/David/Documents/QtProjects/visualsc/scgraphicsview/scgraphicsview.pro -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o $(MAKEFILE)
sub-scgraphicsview: scgraphicsview/$(MAKEFILE) FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE)
sub-scgraphicsview-make_default-ordered: scgraphicsview/$(MAKEFILE) sub-sceditcontroller-make_default-ordered  FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) 
sub-scgraphicsview-make_default: scgraphicsview/$(MAKEFILE) FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) 
sub-scgraphicsview-make_first-ordered: scgraphicsview/$(MAKEFILE) sub-sceditcontroller-make_first-ordered  FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) first
sub-scgraphicsview-make_first: scgraphicsview/$(MAKEFILE) FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) first
sub-scgraphicsview-all-ordered: scgraphicsview/$(MAKEFILE) sub-sceditcontroller-all-ordered  FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) all
sub-scgraphicsview-all: scgraphicsview/$(MAKEFILE) FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) all
sub-scgraphicsview-clean-ordered: scgraphicsview/$(MAKEFILE) sub-sceditcontroller-clean-ordered  FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) clean
sub-scgraphicsview-clean: scgraphicsview/$(MAKEFILE) FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) clean
sub-scgraphicsview-distclean-ordered: scgraphicsview/$(MAKEFILE) sub-sceditcontroller-distclean-ordered  FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) distclean
sub-scgraphicsview-distclean: scgraphicsview/$(MAKEFILE) FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) distclean
sub-scgraphicsview-install_subtargets-ordered: scgraphicsview/$(MAKEFILE) sub-sceditcontroller-install_subtargets-ordered  FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) install
sub-scgraphicsview-install_subtargets: scgraphicsview/$(MAKEFILE) FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) install
sub-scgraphicsview-uninstall_subtargets-ordered: scgraphicsview/$(MAKEFILE) sub-sceditcontroller-uninstall_subtargets-ordered  FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-scgraphicsview-uninstall_subtargets: scgraphicsview/$(MAKEFILE) FORCE
	cd scgraphicsview/ && $(MAKE) -f $(MAKEFILE) uninstall
app/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) app/ || $(MKDIR) app/ 
	cd app/ && $(QMAKE) c:/Users/David/Documents/QtProjects/visualsc/app/app.pro -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o $(MAKEFILE)
sub-app-qmake_all:  FORCE
	@$(CHK_DIR_EXISTS) app/ || $(MKDIR) app/ 
	cd app/ && $(QMAKE) c:/Users/David/Documents/QtProjects/visualsc/app/app.pro -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o $(MAKEFILE)
sub-app: app/$(MAKEFILE) sub-scdatamodel \
		sub-scgraphicsview \
		sub-sceditcontroller FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE)
sub-app-make_default-ordered: app/$(MAKEFILE) sub-scgraphicsview-make_default-ordered  FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) 
sub-app-make_default: app/$(MAKEFILE) sub-scdatamodel-make_default sub-scgraphicsview-make_default sub-sceditcontroller-make_default FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) 
sub-app-make_first-ordered: app/$(MAKEFILE) sub-scgraphicsview-make_first-ordered  FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) first
sub-app-make_first: app/$(MAKEFILE) sub-scdatamodel-make_first sub-scgraphicsview-make_first sub-sceditcontroller-make_first FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) first
sub-app-all-ordered: app/$(MAKEFILE) sub-scgraphicsview-all-ordered  FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) all
sub-app-all: app/$(MAKEFILE) sub-scdatamodel-all sub-scgraphicsview-all sub-sceditcontroller-all FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) all
sub-app-clean-ordered: app/$(MAKEFILE) sub-scgraphicsview-clean-ordered  FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) clean
sub-app-clean: app/$(MAKEFILE) sub-scdatamodel-clean sub-scgraphicsview-clean sub-sceditcontroller-clean FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) clean
sub-app-distclean-ordered: app/$(MAKEFILE) sub-scgraphicsview-distclean-ordered  FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) distclean
sub-app-distclean: app/$(MAKEFILE) sub-scdatamodel-distclean sub-scgraphicsview-distclean sub-sceditcontroller-distclean FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) distclean
sub-app-install_subtargets-ordered: app/$(MAKEFILE) sub-scgraphicsview-install_subtargets-ordered  FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) install
sub-app-install_subtargets: app/$(MAKEFILE) sub-scdatamodel-install_subtargets sub-scgraphicsview-install_subtargets sub-sceditcontroller-install_subtargets FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) install
sub-app-uninstall_subtargets-ordered: app/$(MAKEFILE) sub-scgraphicsview-uninstall_subtargets-ordered  FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) uninstall
sub-app-uninstall_subtargets: app/$(MAKEFILE) sub-scdatamodel-uninstall_subtargets sub-scgraphicsview-uninstall_subtargets sub-sceditcontroller-uninstall_subtargets FORCE
	cd app/ && $(MAKE) -f $(MAKEFILE) uninstall

Makefile: visualsc.pro  c:/Qt/2010.05/qt/mkspecs/win32-g++/qmake.conf c:/Qt/2010.05/qt/mkspecs/qconfig.pri \
		c:/Qt/2010.05/qt/mkspecs/modules/qt_webkit_version.pri \
		c:/Qt/2010.05/qt/mkspecs/features/qt_functions.prf \
		c:/Qt/2010.05/qt/mkspecs/features/qt_config.prf \
		c:/Qt/2010.05/qt/mkspecs/features/exclusive_builds.prf \
		c:/Qt/2010.05/qt/mkspecs/features/default_pre.prf \
		c:/Qt/2010.05/qt/mkspecs/features/win32/default_pre.prf \
		visualsc.pri \
		c:/Qt/2010.05/qt/mkspecs/features/debug.prf \
		c:/Qt/2010.05/qt/mkspecs/features/debug_and_release.prf \
		c:/Qt/2010.05/qt/mkspecs/features/default_post.prf \
		c:/Qt/2010.05/qt/mkspecs/features/win32/default_post.prf \
		c:/Qt/2010.05/qt/mkspecs/features/win32/rtti.prf \
		c:/Qt/2010.05/qt/mkspecs/features/win32/exceptions.prf \
		c:/Qt/2010.05/qt/mkspecs/features/win32/stl.prf \
		c:/Qt/2010.05/qt/mkspecs/features/shared.prf \
		c:/Qt/2010.05/qt/mkspecs/features/warn_on.prf \
		c:/Qt/2010.05/qt/mkspecs/features/qt.prf \
		c:/Qt/2010.05/qt/mkspecs/features/win32/thread.prf \
		c:/Qt/2010.05/qt/mkspecs/features/moc.prf \
		c:/Qt/2010.05/qt/mkspecs/features/win32/windows.prf \
		c:/Qt/2010.05/qt/mkspecs/features/resources.prf \
		c:/Qt/2010.05/qt/mkspecs/features/uic.prf \
		c:/Qt/2010.05/qt/mkspecs/features/yacc.prf \
		c:/Qt/2010.05/qt/mkspecs/features/lex.prf
	$(QMAKE) -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o Makefile visualsc.pro
c:/Qt/2010.05/qt/mkspecs/qconfig.pri:
c:/Qt/2010.05/qt/mkspecs/modules/qt_webkit_version.pri:
c:/Qt/2010.05/qt/mkspecs/features/qt_functions.prf:
c:/Qt/2010.05/qt/mkspecs/features/qt_config.prf:
c:/Qt/2010.05/qt/mkspecs/features/exclusive_builds.prf:
c:/Qt/2010.05/qt/mkspecs/features/default_pre.prf:
c:/Qt/2010.05/qt/mkspecs/features/win32/default_pre.prf:
visualsc.pri:
c:/Qt/2010.05/qt/mkspecs/features/debug.prf:
c:/Qt/2010.05/qt/mkspecs/features/debug_and_release.prf:
c:/Qt/2010.05/qt/mkspecs/features/default_post.prf:
c:/Qt/2010.05/qt/mkspecs/features/win32/default_post.prf:
c:/Qt/2010.05/qt/mkspecs/features/win32/rtti.prf:
c:/Qt/2010.05/qt/mkspecs/features/win32/exceptions.prf:
c:/Qt/2010.05/qt/mkspecs/features/win32/stl.prf:
c:/Qt/2010.05/qt/mkspecs/features/shared.prf:
c:/Qt/2010.05/qt/mkspecs/features/warn_on.prf:
c:/Qt/2010.05/qt/mkspecs/features/qt.prf:
c:/Qt/2010.05/qt/mkspecs/features/win32/thread.prf:
c:/Qt/2010.05/qt/mkspecs/features/moc.prf:
c:/Qt/2010.05/qt/mkspecs/features/win32/windows.prf:
c:/Qt/2010.05/qt/mkspecs/features/resources.prf:
c:/Qt/2010.05/qt/mkspecs/features/uic.prf:
c:/Qt/2010.05/qt/mkspecs/features/yacc.prf:
c:/Qt/2010.05/qt/mkspecs/features/lex.prf:
qmake: qmake_all FORCE
	@$(QMAKE) -spec c:/Qt/2010.05/qt/mkspecs/win32-g++ -o Makefile visualsc.pro

qmake_all: sub-scdatamodel-qmake_all sub-sceditcontroller-qmake_all sub-scgraphicsview-qmake_all sub-app-qmake_all FORCE

make_default: sub-scdatamodel-make_default-ordered sub-sceditcontroller-make_default-ordered sub-scgraphicsview-make_default-ordered sub-app-make_default-ordered FORCE
make_first: sub-scdatamodel-make_first-ordered sub-sceditcontroller-make_first-ordered sub-scgraphicsview-make_first-ordered sub-app-make_first-ordered FORCE
all: sub-scdatamodel-all-ordered sub-sceditcontroller-all-ordered sub-scgraphicsview-all-ordered sub-app-all-ordered FORCE
clean: sub-scdatamodel-clean-ordered sub-sceditcontroller-clean-ordered sub-scgraphicsview-clean-ordered sub-app-clean-ordered FORCE
distclean: sub-scdatamodel-distclean-ordered sub-sceditcontroller-distclean-ordered sub-scgraphicsview-distclean-ordered sub-app-distclean-ordered FORCE
	-$(DEL_FILE) Makefile
install_subtargets: sub-scdatamodel-install_subtargets-ordered sub-sceditcontroller-install_subtargets-ordered sub-scgraphicsview-install_subtargets-ordered sub-app-install_subtargets-ordered FORCE
uninstall_subtargets: sub-scdatamodel-uninstall_subtargets-ordered sub-sceditcontroller-uninstall_subtargets-ordered sub-scgraphicsview-uninstall_subtargets-ordered sub-app-uninstall_subtargets-ordered FORCE

sub-scdatamodel-sub_Debug_ordered: scdatamodel/$(MAKEFILE)
	cd scdatamodel/ && $(MAKE) debug
sub-sceditcontroller-sub_Debug_ordered: sceditcontroller/$(MAKEFILE) sub-scdatamodel-sub_Debug_ordered 
	cd sceditcontroller/ && $(MAKE) debug
sub-scgraphicsview-sub_Debug_ordered: scgraphicsview/$(MAKEFILE) sub-sceditcontroller-sub_Debug_ordered 
	cd scgraphicsview/ && $(MAKE) debug
sub-app-sub_Debug_ordered: app/$(MAKEFILE) sub-scgraphicsview-sub_Debug_ordered 
	cd app/ && $(MAKE) debug
debug: sub-scdatamodel-sub_Debug_ordered sub-sceditcontroller-sub_Debug_ordered sub-scgraphicsview-sub_Debug_ordered sub-app-sub_Debug_ordered

sub-scdatamodel-sub_Release_ordered: scdatamodel/$(MAKEFILE)
	cd scdatamodel/ && $(MAKE) release
sub-sceditcontroller-sub_Release_ordered: sceditcontroller/$(MAKEFILE) sub-scdatamodel-sub_Release_ordered 
	cd sceditcontroller/ && $(MAKE) release
sub-scgraphicsview-sub_Release_ordered: scgraphicsview/$(MAKEFILE) sub-sceditcontroller-sub_Release_ordered 
	cd scgraphicsview/ && $(MAKE) release
sub-app-sub_Release_ordered: app/$(MAKEFILE) sub-scgraphicsview-sub_Release_ordered 
	cd app/ && $(MAKE) release
release: sub-scdatamodel-sub_Release_ordered sub-sceditcontroller-sub_Release_ordered sub-scgraphicsview-sub_Release_ordered sub-app-sub_Release_ordered

sub-scdatamodel-check_ordered: scdatamodel/$(MAKEFILE)
	cd scdatamodel/ && $(MAKE) check
sub-sceditcontroller-check_ordered: sceditcontroller/$(MAKEFILE) sub-scdatamodel-check_ordered 
	cd sceditcontroller/ && $(MAKE) check
sub-scgraphicsview-check_ordered: scgraphicsview/$(MAKEFILE) sub-sceditcontroller-check_ordered 
	cd scgraphicsview/ && $(MAKE) check
sub-app-check_ordered: app/$(MAKEFILE) sub-scgraphicsview-check_ordered 
	cd app/ && $(MAKE) check
check: sub-scdatamodel-check_ordered sub-sceditcontroller-check_ordered sub-scgraphicsview-check_ordered sub-app-check_ordered

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all
install: install_subtargets  FORCE

uninstall:  uninstall_subtargets FORCE

FORCE:

