$(shell mkdir -p exe)

GRAPH_DIR := ./algorithms/graphs
GRAPH := dfs bfs

#UVA_DIR := ./algorithms/uva
#UVA := 


all: $(GRAPH)

%: $(GRAPH_DIR)/%.cpp
	g++ -no-pie -o exe/$@ $^
	

clean:
	rm -f exe/*