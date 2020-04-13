#
#  There exist several targets which are by default empty and which can be 
#  used for execution of your targets. These targets are usually executed 
#  before and after some main targets. They are: 
#
#     .build-pre:              called before 'build' target
#     .build-post:             called after 'build' target
#     .clean-pre:              called before 'clean' target
#     .clean-post:             called after 'clean' target
#     .clobber-pre:            called before 'clobber' target
#     .clobber-post:           called after 'clobber' target
#     .all-pre:                called before 'all' target
#     .all-post:               called after 'all' target
#     .help-pre:               called before 'help' target
#     .help-post:              called after 'help' target
#
#  Targets beginning with '.' are not intended to be called on their own.
#
#  Main targets can be executed directly, and they are:
#  
#     build                    build a specific configuration
#     clean                    remove built files from a configuration
#     clobber                  remove all built files
#     all                      build all configurations
#     help                     print help mesage
#  
#  Targets .build-impl, .clean-impl, .clobber-impl, .all-impl, and
#  .help-impl are implemented in nbproject/makefile-impl.mk.
#
#  Available make variables:
#
#     CND_BASEDIR                base directory for relative paths
#     CND_DISTDIR                default top distribution directory (build artifacts)
#     CND_BUILDDIR               default top build directory (object files, ...)
#     CONF                       name of current configuration
#     CND_PLATFORM_${CONF}       platform name (current configuration)
#     CND_ARTIFACT_DIR_${CONF}   directory of build artifact (current configuration)
#     CND_ARTIFACT_NAME_${CONF}  name of build artifact (current configuration)
#     CND_ARTIFACT_PATH_${CONF}  path to build artifact (current configuration)
#     CND_PACKAGE_DIR_${CONF}    directory of package (current configuration)
#     CND_PACKAGE_NAME_${CONF}   name of package (current configuration)
#     CND_PACKAGE_PATH_${CONF}   path to package (current configuration)
#
# NOCDDL


# Environment 
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin


# build
build: .build-post

.build-pre:
# Add your pre 'build' code here...

.build-post: .build-impl main.o TextoConsultas.o TablaHash.o SeparacionPalabras.o ReposicionamientoNodos.o OrdenamientoSeleccion.o OperacionesSeleccion.o OperacionesInsercion.o NodoHash.o Nodo.o ListaTablas.o Graphviz.o FuncionesHash.o AVL.o
# Add your post 'build' code here...
	g++ main.o TextoConsultas.o TablaHash.o SeparacionPalabras.o ReposicionamientoNodos.o OrdenamientoSeleccion.o OperacionesSeleccion.o OperacionesInsercion.o NodoHash.o Nodo.o ListaTablas.o Graphviz.o FuncionesHash.o AVL.o -o Hash

main.o: main.cpp
	g++ -c main.cpp

TextoConsultas.o: TextoConsultas.cpp TextoConsultas.h
	g++ -c TextoConsultas.cpp

TablaHash.o: TablaHash.cpp TablaHash.h
	g++ -c TablaHash.cpp

SeparacionPalabras.o: SeparacionPalabras.cpp SeparacionPalabras.h
	g++ -c SeparacionPalabras.cpp

ReposicionamientoNodos.o: ReposicionamientoNodos.cpp ReposicionamientoNodos.h
	g++ -c ReposicionamientoNodos.cpp

OrdenamientoSeleccion.o: OrdenamientoSeleccion.cpp OrdenamientoSeleccion.h
	g++ -c OrdenamientoSeleccion.cpp

OperacionesSeleccion.o: OperacionesSeleccion.cpp OperacionesSeleccion.h
	g++ -c OperacionesSeleccion.cpp

OperacionesInsercion.o: OperacionesInsercion.cpp OperacionesInsercion.h
	g++ -c OperacionesInsercion.cpp

NodoHash.o: NodoHash.cpp NodoHash.h
	g++ -c NodoHash.cpp

Nodo.o: Nodo.cpp Nodo.h
	g++ -c Nodo.cpp

ListaTablas.o: ListaTablas.cpp ListaTablas.h
	g++ -c ListaTablas.cpp

Graphviz.o: Graphviz.cpp Graphviz.h
	g++ -c Graphviz.cpp

FuncionesHash.o: FuncionesHash.cpp FuncionesHash.h
	g++ -c FuncionesHash.cpp

AVL.o: AVL.cpp AVL.h
	g++ -c AVL.cpp


# clean
clean: .clean-post

.clean-pre:
# Add your pre 'clean' code here...

.clean-post: .clean-impl
# Add your post 'clean' code here...
	rm -rf *o Hash

# clobber
clobber: .clobber-post

.clobber-pre:
# Add your pre 'clobber' code here...

.clobber-post: .clobber-impl
# Add your post 'clobber' code here...


# all
all: .all-post

.all-pre:
# Add your pre 'all' code here...

.all-post: .all-impl
# Add your post 'all' code here...


# build tests
build-tests: .build-tests-post

.build-tests-pre:
# Add your pre 'build-tests' code here...

.build-tests-post: .build-tests-impl
# Add your post 'build-tests' code here...


# run tests
test: .test-post

.test-pre: build-tests
# Add your pre 'test' code here...

.test-post: .test-impl
# Add your post 'test' code here...


# help
help: .help-post

.help-pre:
# Add your pre 'help' code here...

.help-post: .help-impl
# Add your post 'help' code here...



# include project implementation makefile
include nbproject/Makefile-impl.mk

# include project make variables
include nbproject/Makefile-variables.mk
