#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 3
#define TCOUNT 10
#define COUNT_LIMIT 12

int count = 0;
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv;

void *inc_count(void *t) {
	int i;
	long my_id = (long)t;

	for (i = 0; i < TCOUNT; i++) {
		pthread_mutex_lock(&count_mutex);
		if (count == COUNT_LIMIT) {
			printf("inc_count(): thread%ld, count = %d Threshold value reached. ", my_id, count);
			pthread_cond_signal(&count_threshold_cv);
			printf("Just sent signal.\n");
		}
		printf("inc_count(): thread %ld, count = %d, unlocking mutex\n", my_id, count);
		pthread_mutex_unlock(&count_mutex);

		sleep(1);
	}
	pthread_exit(NULL);
}

void *watch_count(void *t) {
	long my_id = (long)t;
	printf("starting watch_count(): thread %ld\n", my_id);

	pthread_mutex_lock(&count_mutex);

	while (count < COUNT_LIMIT) {
		printf("watch_count(): thread %ld count = %d. going into wait...\n", my_id, count);
		pthread_cond_wait(&count_threshold_cv, &count_mutex);
		printf("watch_count(): thread %ld condition signal received. count = %d\n", my_id, count);
		printf("watch_count(): thread %ld updating thye value of count...\n", my_id, count);
		count += 125;
		printf("watch_count(): thread %ld count now = %d.\n", my_id, count);
	}
	printf("watch_count(): thread %ld unlocking mutex.\n", my_id);
	pthread_mutex_unlock(&count_mutex);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	int i, rc;
	long t1 = 1, t2 = 2, t3 = 3;
	pthread_t threads[3];
	pthread_attr_t attr;

	pthread_mutex_init(&count_mutex, NULL);
	pthread_cond_init(&count_thread_cv, NULL);
	
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	pthread_create(&threads[0], &attr, watch_count, (void *)t1);
	pthread_create(&threads[1], &attr, inc_count, (void *)t2);
	pthread_create(&threads[2], &attr, inc_count, (void *)t3);

	for (i = 0; i < NUM_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
	printf("Main(): waited and joined with %d threads. Final value of count = %d. Done.\n", NUM_THREADS, count);

	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_threshold_cv);
	pthread_exit(NULL);
}