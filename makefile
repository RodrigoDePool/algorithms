$(shell mkdir -p exe)

FLAGS := -lm -lcrypt -O2 -pipe -DONLINE_JUDGE
GRAPH_DIR := ./algorithms/graphs
GRAPH := dfs bfs

UVA_DIR := ./algorithms/uva
UVA := 10196 10142 10033 10137


all: $(GRAPH) $(UVA)
	clear
	./exe/10196 < data

%: $(GRAPH_DIR)/%.cpp
	g++ $(FLAGS) -o exe/$@ $^
	


%: $(UVA_DIR)/%.cpp
	g++ $(FLAGS) -o exe/$@ $^
	

clean:
	rm -f exe/*