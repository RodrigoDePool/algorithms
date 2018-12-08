FLAGS := -g -lm -lcrypt  -pipe -DONLINE_JUDGE

GRAPH_DIR := ./algorithms/graphs
GRAPH := dfs bfs

UVA_DIR := ./algorithms/uva
UVA := 10196 10142 10033 10137


all: $(GRAPH) $(UVA)
	clear
	./10137 < data > salida
	diff salida salidaEsperada10137
	
%: $(GRAPH_DIR)/%.cpp
	g++ $(FLAGS) -o $@ $^
	


%: $(UVA_DIR)/%.cpp
	g++ $(FLAGS) -o $@ $^
	

clean:
	rm -f  $(GRAPH) $(UVA)