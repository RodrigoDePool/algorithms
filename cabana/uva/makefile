CC = g++
CFLAGS = -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE

%.exe: %.cpp
	$(CC) $(CFLAGS) -o $@ $<
	touch $@.input

%: %.exe
	./$< < $<.input > $<.output

.PHONY: clean cleanx cleanio
clean:
	rm -rf *.exe *.input *.output
cleanx:
	rm -rf *.exe
cleanio:
	rm -rf *.input *.output