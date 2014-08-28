# Hasn't been tested on Unix machine.  May need to link to some other library
# make -f Makefile

LIBS        = -lm
INCLUDE     = 
CFLAGS      = -g 
CC          = g++

# ===============================================================

SOURCES     = \ 
			= group.cpp \
			= image.cpp \
			= main.cpp  \
			= matrix.cpp \ 
			= OrthographicCamera.cpp \ 
			= PerspectiveCamera.cpp \ 
			= PhongMaterial.cpp \
			= plane.cpp \ 
			= RayTracer.cpp \
			= scene_parser.cpp \
			= sphere.cpp \
			= transform.cpp \
			= triangle.cpp \
			= utils.cpp		
	
# ===============================================================

# variable for the object files 
OBJECTS = $(SOURCES:.cpp=.o)

# ===============================================================

# executable name 
EXECUTABLE = raytracer

# ===============================================================
all: $(EXECUTABLE) $(SOURCES) clean

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(OBJECTS) $(LIBS)
	
.cpp.o: 
	$(CC) $(CFLAGS) $(INCLUDE) $< -c -o $@

clean:
	rm -f *.o
	
# ===============================================================