FLAGS := -g -lm -lcrypt -std=c++11 -pipe -DONLINE_JUDGE

UVA_DIR := ./uva
ACEPTA_DIR := ./aceptaelreto

EXE := 325 11340 11577 375 10071 10055 108 10196 10142 10033 10137 10107 10347 524 482 673 10226 10194 459 127 793 254 247 252 11235 313 250 386 380 316 384 10911 290_rec 290_iter 10198 10359 502 507

all: $(EXE)

%: $(UVA_DIR)/%.cpp
	g++ $(FLAGS) -o $@ $^
	

%: $(ACEPTA_DIR)/%.cpp
	g++ $(FLAGS) -o $@ $^

clean:
	rm -f  $(EXE) input output
