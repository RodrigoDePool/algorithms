FLAGS := -g -lm -lcrypt  -pipe -DONLINE_JUDGE

GRAPH_DIR := ./algorithms/graphs
UVA_DIR := ./algorithms/uva

EXE := dfs bfs 10196 10142 10033 10137 10107


all: $(EXE)
	clear

%: $(GRAPH_DIR)/%.cpp
	g++ $(FLAGS) -o $@ $^
	


%: $(UVA_DIR)/%.cpp
	g++ $(FLAGS) -o $@ $^
	

clean:
	rm -f  $(EXE)