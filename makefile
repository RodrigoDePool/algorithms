$(shell mkdir -p exe)

FLAGS := -no-pie -g
GRAPH_DIR := ./algorithms/graphs
GRAPH := dfs bfs

#UVA_DIR := ./algorithms/uva
#UVA := 


all: $(GRAPH)

%: $(GRAPH_DIR)/%.cpp
	g++ $(FLAGS) -o exe/$@ $^
	

clean:
	rm -f exe/*