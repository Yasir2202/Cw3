CC = g++

CXXFLAGS = -std=c++11 -Wall

OUTPUT = filesystem

OBJDIR = obj

SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SOURCES))

all: $(OUTPUT)
	@echo "Clean compilation complete."

$(OUTPUT): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(OUTPUT)
	@rm -rf $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CC) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -f $(OUTPUT)
	@rm -rf $(OBJDIR)

.PHONY: all clean
