#ifndef BROKER_H_
#define BROKER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#include "config/broker_config.h"
#include "logger/broker_logger.h"
#include "../../shared-common/common/sockets.h"
#include "../../shared-common/common/utils.h"

int broker_socket;
int uid_subscribe = 0;

int broker_load();
void broker_server_init();
static void *handle_connection(void *arg);
void broker_exit();
void search_queue(t_subscribe *unSubscribe);
void initialize_queue();
void add_to(t_list *list, t_subscribe* sub);


t_list *get_queue,*appeared_queue,*new_queue,*caught_queue,*catch_queue,*localized_queue;

typedef struct {
	char* ip;
	uint32_t puerto;
	uint32_t id;
	int32_t endtime;
	uint32_t f_desc;
} t_subscribe_nodo;

t_subscribe_nodo* check_already_subscribed(char *ip,uint32_t puerto,t_list *list);

#endif /* BROKER_H_ */
