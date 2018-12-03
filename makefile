GRAPH_DIR := ./algorithms/graphs
GRAPH := dfs bfs

#UVA_DIR := ./algorithms/uva
#UVA := 


all: $(GRAPH)

%: $(GRAPH_DIR)/%.cpp
	g++ -o exe/$@ $^
	

clean:
	rm -f exe/*
	