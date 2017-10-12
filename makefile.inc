GCC = nvcc
WORKDIR = `git rev-parse --show-toplevel`
CFLAGS = -g --gpu-architecture=compute_60 --gpu-code=sm_61
OBJ_DIR = $(WORKDIR)/build

%.o: %.c
	@ $(GCC) $(CFLAGS) -c $^ -o $(OBJ_DIR)/$@

%.o: %.cu
	@ $(GCC) $(CFLAGS) -c $^ -o $(OBJ_DIR)/$@

$(SUBDIRS):
	@ $(MAKE) -C $@ all

.PHONY: $(SUBDIRS) all

all: $(OBS) $(SUBDIRS)
