CPP = g++
F = -Wall -std=c++17
PLOT = 0 # plot or not
VPATH = ./lib/ #search directory
EXEC = search
OBJ = city.o dp.o
OBJDIR = ./obj/
EXECOBJ = $(addprefix $(OBJDIR), $(EXEC).o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))
OUTPUT = output.txt

all: clean dep link

dep: $(OBJDIR) $(OBJS)

link: $(EXECOBJ)
	$(CPP) $(F) $(EXECOBJ) $(OBJS) -o $(EXEC)

$(OBJDIR):
	mkdir obj

$(EXECOBJ): $(EXEC).cpp
	$(CPP) -DPLOT=$(PLOT) $(F) -c $< -o $@

$(OBJDIR)%.o: %.cpp
	$(CPP) $(F) -c $< -o $@
$(OUTPUT):
	make
	./search dp readfile.txt
plot: $(OUTPUT)
	gnuplot gnuplot/tsp11.p
plot_animation:
	make PLOT=1
	touch $(OUTPUT)
	gnuplot gnuplot/liveplot.gpi &
	./search dp readfile.txt
clean:
	rm -rf obj $(EXEC) tsp11-dp.eps output.txt
