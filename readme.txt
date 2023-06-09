
emcc -O3 testThread.cpp -o testThread.js -s PTHREAD_POOL_SIZE_STRICT=0 -s USE_PTHREADS=1 -s EXPORTED_FUNCTIONS="['_testThread','_stop']" -s INITIAL_MEMORY=128MB  -s ENVIRONMENT=web,worker
