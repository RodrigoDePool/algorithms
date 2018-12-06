$(shell mkdir -p exe)

FLAGS := -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
GRAPH_DIR := ./algorithms/graphs
GRAPH := dfs bfs

UVA_DIR := ./algorithms/uva
UVA := 10196 10142


all: $(GRAPH) $(UVA)

%: $(GRAPH_DIR)/%.cpp
	g++ $(FLAGS) -o exe/$@ $^
	


%: $(UVA_DIR)/%.cpp
	g++ $(FLAGS) -o exe/$@ $^
	

clean:
	rm -f exe/*