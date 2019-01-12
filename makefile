FLAGS := -g -lm -lcrypt -std=c++11 -pipe -DONLINE_JUDGE

GRAPH_DIR := ./algorithms/graphs
UVA_DIR := ./algorithms/uva
ACEPTA_DIR := ./algorithms/aceptaelreto

EXE := dfs 291 325 11340 11577 375 bfs 10071 10055 108 10196 10142 10033 10137 10107 10347 524 482 673 10226 10194 459 127 793 254 247 252

all: $(EXE)

%: $(GRAPH_DIR)/%.cpp
	g++ $(FLAGS) -o $@ $^
	


%: $(UVA_DIR)/%.cpp
	g++ $(FLAGS) -o $@ $^
	

%: $(ACEPTA_DIR)/%.cpp
	g++ $(FLAGS) -o $@ $^

clean:
	rm -f  $(EXE)
