#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>

float get_rand() {
	float n = (float)rand();
	n/= RAND_MAX;
	return n;
}

typedef struct {
	float* data;
	int len;
} float_vector;

typedef struct neuron {
	char* activation;
	float_vector* weights;
	float bias;
	struct neuron* next;
} neuron;

float_vector* init_float_vec(void) {
	float_vector* vec = malloc(sizeof(float_vector)*1);
	vec->data = malloc(sizeof(float)*10);
	vec->len = 10;
	return vec;
}

float_vector* update_float_vec(float_vector* vec, int maxlen) {
	if (vec->len < maxlen) {
		vec->data = (float*)realloc(vec->data, sizeof(float)*maxlen);
		assert(vec->data != NULL);
		vec->len = maxlen;
	}
	return vec;
}

neuron* init_neuron(void) {
	neuron* n = malloc(sizeof(neuron)*1);
	
	char* activation = malloc(sizeof(char)*8);
	activation = "relu";

	float_vector* weights = init_float_vec();
	for (int i = 0; i < 10; i++) {
		weights->data[i] = get_rand();
	}
	float bias  = 0.5;

	n->activation = activation;
	n->weights = weights;
	n->bias = bias;
	n->next = NULL;
	return n;
}

float sum(float_vector* vec) {
	float result = 0;
	for (int i = 0; i < vec->len; i++) {
		result += vec->data[i];
	}
	return result;
}


int main(int argc, char** argv) {
	srand(time(NULL));
	neuron* N = init_neuron();
	N->weights = update_float_vec(N->weights, 20);
	N->weights->data[12] = 3.2;
	printf("%.3f\n", N->weights->data[12]);
	return 0;
}
