#ifndef COMMON_PROTOCOLS_H_
#define COMMON_PROTOCOLS_H_

#include <commons/collections/list.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct {
	int size;
	void* stream;
} t_buffer;

typedef struct {
	int fd;
	int bool_val;
} t_handle_connection;

typedef struct {
	uint32_t pos_x;
	uint32_t pos_y;
} t_position;

typedef struct {
	uint32_t x;
	uint32_t y;
	uint32_t cant;
} t_position_aux;

typedef struct {

} t_empty;

typedef enum {
	HANDSHAKE,
	ACK,
	NEW_POKEMON,
	APPEARED_POKEMON,
	CATCH_POKEMON,
	CAUGHT_POKEMON,
	GET_POKEMON,
	LOCALIZED_POKEMON,
	SUBSCRIBE,
	NOOP
} t_protocol;

typedef enum {
	GAME_CARD,
	BROKER,
	GAME_BOY,
	TEAM
} t_proceso;

typedef enum {
	NEW_QUEUE,
	APPEARED_QUEUE,
	LOCALIZED_QUEUE,
	GET_QUEUE,
	CATCH_QUEUE,
	CAUGHT_QUEUE
} t_cola;

typedef struct {
	t_protocol operation_code;
	t_buffer* buffer;
} t_package;

typedef struct {
	uint32_t id_corr_msg;
	t_cola queue;
	char* sender_name;
	char* ip;
	uint32_t port;
} t_ack;

typedef struct {
	char *nombre_pokemon;
	uint32_t tamanio_nombre;
	uint32_t cantidad;
	uint32_t pos_x;
	uint32_t pos_y;
	uint32_t id_correlacional;
} t_new_pokemon;

typedef struct {
	char *nombre_pokemon;
	uint32_t tamanio_nombre;
	uint32_t pos_x;
	uint32_t pos_y;
	uint32_t id_correlacional;
} t_appeared_pokemon;

typedef struct {
	uint32_t id_correlacional;
	char* nombre_pokemon;
	uint32_t tamanio_nombre;
	uint32_t pos_x;
	uint32_t pos_y;
} t_catch_pokemon;

typedef struct {
	uint32_t id_correlacional;
	uint32_t result;
} t_caught_pokemon;

typedef struct {
	uint32_t id_correlacional;
	char* nombre_pokemon;
	uint32_t tamanio_nombre;
} t_get_pokemon;

typedef struct {
	char* ip;
	uint32_t puerto;
	t_proceso proceso;
	t_cola cola;
	uint32_t f_desc;
	int32_t seconds;
} t_subscribe;

typedef struct {
	uint32_t id_correlacional;
	char* nombre_pokemon;
	uint32_t tamanio_nombre;
	uint32_t cant_elem;
	t_list* posiciones;
} t_localized_pokemon;

typedef struct {
	uint32_t id;
	uint32_t pos;
	uint32_t len;
	t_cola tipo_cola;
	t_list suscriptores;
	uint32_t cant_ack;
	time_t timestamp;
} t_nodo_msj;

typedef struct {
	uint32_t id_subscriber;
	int ack_sent;
} t_suscriptor_msj;

#endif /* COMMON_PROTOCOLS_H_ */
