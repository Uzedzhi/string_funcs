INCLUDE_PATH = ..\string_funcs

WINDOWS_FLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline 		     \
-Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++     \
-Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body	     \
-Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers 			     \
-Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing    \
-Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE				 \
-I$(INCLUDE_PATH)

LINUX_FLAGS = -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations 		 \
-Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported   \
-Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security 			 \
-Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual   \
-Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo 				 \
-Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods 			 \
-Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef					 \
-Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix 							 \
-Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector 			 \
-fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging 				 \
-fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla 						 \
-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr \
-I$(INCLUDE_PATH:\=/)


ifeq ($(OS),Windows_NT)
	DETECTED_OS := Windows
else
	DETECTED_OS = $(shell uname -s)
endif

ifeq ($(DETECTED_OS),Windows)
	CXX = g++
	EXE = .exe
	RM = del
	FLAGS := $(WINDOWS_FLAGS)
else ifeq ($(DETECTED_OS), Linux)
	CXX = g++
	EXE = 
	RM = rm
	FLAGS := $(LINUX_FLAGS)
else ifeq ($(DETECTED_OS), Darwin)
	CXX = clang++
	EXE = 
	RM = rf
	FLAGS := $(LINUX_FLAGS)
else 
	$(error SYSTEM undefined: $(DETECTED_OS))
endif

FILES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)
OBJS := $(FILES:.cpp=.o)


main: $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $@


%.o: %.cpp $(HEADERS)
	$(CXX) $(FLAGS) -c $<

clean:
	$(RM) -rf *.o