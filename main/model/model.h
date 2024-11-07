#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include "program.h"


#define USER_ACCESS_LEVEL       0
#define TECHNICIAN_ACCESS_LEVEL 1
#define PARMAC_SIZE             279


typedef enum {
    DRYER_PROGRAM_STEP_TYPE_DRYING = 0,
    DRYER_PROGRAM_STEP_TYPE_COOLING,
    DRYER_PROGRAM_STEP_TYPE_UNFOLDING,
#define DRYER_PROGRAM_STEP_TYPE_NUM 3,
} dryer_program_step_type_t;


typedef enum {
    BASE_PROGRAM_WOOL = 0,
    BASE_PROGRAM_COLD,
    BASE_PROGRAM_LUKEWARM,
    BASE_PROGRAM_WARM,
    BASE_PROGRAM_HOT,
#define BASE_PROGRAMS_NUM 5
} base_program_t;


typedef enum {
    LANGUAGE_ITALIANO = 0,
    LANGUAGE_ENGLISH,
#define LANGUAGES_NUM 2
} language_t;


typedef enum {
    CYCLE_STATE_STOPPED = 0,
    CYCLE_STATE_ACTIVE,
    CYCLE_STATE_WAIT_START,
    CYCLE_STATE_RUNNING,
    CYCLE_STATE_PAUSED,
} cycle_state_t;


typedef enum {
    ALARM_EMERGENCY = 0,
    ALARM_FILTER,
    ALARM_PORTHOLE,
#define ALARMS_NUM 3
} alarm_t;


typedef struct {
    name_t nome;

    uint16_t language;
    uint8_t  abilita_visualizzazione_temperatura;
    uint8_t  abilita_tasto_menu;
    uint16_t tempo_pressione_tasto_pausa;
    uint16_t tempo_pressione_tasto_stop;
    uint16_t tempo_stop_automatico;
    uint16_t stop_tempo_ciclo;
    uint16_t tempo_attesa_partenza_ciclo;

    uint8_t  abilita_espansione_rs485;
    uint8_t  abilita_gas;
    uint16_t velocita_minima;
    uint16_t velocita_massima;
    uint16_t tempo_gettone;
    uint16_t velocita_antipiega;
    uint16_t tipo_pagamento;
    uint16_t access_level;
    uint16_t max_programs;

    /* Parametri da inviare alla macchina */
    uint16_t tipo_sonda_temperatura;
    uint16_t posizione_sonda_temperatura;
    uint16_t temperatura_massima_ingresso;
    uint16_t temperatura_massima_uscita;
    uint16_t temperatura_sicurezza;
    uint16_t temperatura_sicurezza_out;
    uint16_t tempo_allarme_temperatura;     // se non arriva in temperatura in quel tempo
    uint16_t allarme_inverter_off_on;
    uint16_t allarme_filtro_off_on;
    uint16_t tipo_macchina_occupata;
    uint16_t tipo_riscaldamento;
    uint16_t autoavvio;
    uint16_t disabilita_allarmi;
} parmac_t;


struct model {
    struct {
        parmac_t parmac;

        uint16_t  num_programs;
        program_t programs[MAX_PROGRAMMI];
    } config;

    struct {
        struct {
            uint8_t communication_error;
            uint8_t communication_enabled;

            struct {
                uint8_t firmware_version_major;
                uint8_t firmware_version_minor;
                uint8_t firmware_version_patch;

                uint16_t inputs;
                int16_t  temperature_1_adc;
                int16_t  temperature_1;
                int16_t  temperature_2_adc;
                int16_t  temperature_2;
                int16_t  pressure_adc;
                int16_t  pressure;

                cycle_state_t             cycle_state;
                dryer_program_step_type_t step_type;
                int16_t                   default_temperature;
                uint16_t                  remaining_time_seconds;
                uint16_t                  alarms;
            } read;

            struct {
                uint8_t  test_mode;
                uint16_t test_outputs;
                uint8_t  test_pwm1;
                uint8_t  test_pwm2;
            } write;
        } minion;

        language_t temporary_language;
        uint8_t    temporary_access_level;
        uint16_t   current_program_index;
        program_t  current_program;
        uint16_t   current_step_index;
    } run;
};


typedef const struct model model_t;
typedef struct model       mut_model_t;


void                        model_init(mut_model_t *pmodel);
void                        model_clear_test_outputs(mut_model_t *model);
void                        model_set_test_output(mut_model_t *model, uint16_t output_index);
uint8_t                     model_get_bit_accesso(uint8_t al);
char                       *model_new_unique_filename(model_t *model, char *filename, unsigned long seed);
program_t                  *model_get_program(mut_model_t *pmodel);
void                        model_reset_temporary_language(mut_model_t *model);
size_t                      model_serialize_parmac(uint8_t *buffer, parmac_t *p);
size_t                      model_deserialize_parmac(parmac_t *p, uint8_t *buffer);
program_drying_parameters_t model_get_current_step(model_t *model);
uint8_t                     model_is_cycle_active(model_t *model);
uint8_t                     model_is_cycle_paused(model_t *model);
uint8_t                     model_is_cycle_stopped(model_t *model);
void                        model_select_program(mut_model_t *model, uint16_t program_index);
void                        model_select_step(mut_model_t *model, uint16_t step_index);
uint8_t                     model_is_drying(model_t *model);
uint8_t                     model_is_program_done(model_t *model);
int16_t                     model_get_program_display_temperature(model_t *model, uint16_t program_index);
uint8_t                     model_is_alarm_active(model_t *model, alarm_t alarm);
uint8_t                     model_is_porthole_open(model_t *model);
uint8_t                     model_is_cycle_running(model_t *model);
uint8_t                     model_is_any_alarm_active(model_t *model);
uint8_t                     model_swap_programs(mut_model_t *model, size_t first, size_t second);
void                        model_create_new_program(mut_model_t *model, uint16_t program_index);
void model_clone_program(mut_model_t *model, uint16_t source_program_index, uint16_t destination_program_index);
void model_delete_program(mut_model_t *model, uint16_t program_index);


#endif
