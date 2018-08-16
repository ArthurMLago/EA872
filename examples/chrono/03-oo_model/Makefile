

all: model
	./model

model: oo_model.cpp model_mainloop.cpp oo_model.hpp
	g++ -omodel model_mainloop.cpp oo_model.cpp

clean:
	rm model
