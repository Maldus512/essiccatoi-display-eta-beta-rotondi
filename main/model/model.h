#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include "program.h"


#define USER_ACCESS_LEVEL       0
#define TECHNICIAN_ACCESS_LEVEL 1
#define PARMAC_SIZE             279
#define NUM_LOGOS               5


typedef enum {
    FIRMWARE_UPDATE_STATE_NONE = 0,
    FIRMWARE_UPDATE_STATE_AVAILABLE,
    FIRMWARE_UPDATE_STATE_UPDATING,
    FIRMWARE_UPDATE_STATE_SUCCESS,
    FIRMWARE_UPDATE_STATE_FAILURE,
} firmware_update_state_t;


typedef enum {
    TEMPERATURE_PROBE_INPUT = 0,
    TEMPERATURE_PROBE_OUTPUT,
    TEMPERATURE_PROBE_SHT,
} temperature_probe_t;


typedef enum {
    REMOVABLE_DRIVE_STATE_MISSING,
    REMOVABLE_DRIVE_STATE_MOUNTED,
    REMOVABLE_DRIVE_STATE_INVALID,
} removable_drive_state_t;


typedef enum {
    MACHINE_MODEL_TEST = 0,
    MACHINE_MODEL_EDS_RE_SELF_CA,
    MACHINE_MODEL_EDS_RE_LAB_CA,
    MACHINE_MODEL_EDS_RG_SELF_CA,
    MACHINE_MODEL_EDS_RG_LAB_CA,
    MACHINE_MODEL_EDS_RV_SELF_CA,
    MACHINE_MODEL_EDS_RV_LAB_CA,
    MACHINE_MODEL_EDS_RE_SELF_CC,
    MACHINE_MODEL_EDS_RV_SELF_CC,
    MACHINE_MODEL_EDS_RE_LAB_CC,
    MACHINE_MODEL_EDS_RV_LAB_CC,
    MACHINE_MODEL_EDS_RP_SELF_CA,
    MACHINE_MODEL_EDS_RP_LAB_CA,
    MACHINE_MODEL_EDS_RP_SELF_CC,
    MACHINE_MODEL_EDS_RP_LAB_CC,
    MACHINE_MODEL_EDS_RE_LAB_TH_CA,
    MACHINE_MODEL_EDS_RG_LAB_TH_CA,
    MACHINE_MODEL_EDS_RV_LAB_TH_CA,
    MACHINE_MODEL_EDS_RE_LAB_TH_CC,
    MACHINE_MODEL_EDS_RV_LAB_TH_CC,
#define MACHINE_MODELS_NUM 20
} machine_model_t;


typedef enum {
    DIGITAL_COIN_LINE_1 = 0,
    DIGITAL_COIN_LINE_2,
    DIGITAL_COIN_LINE_3,
    DIGITAL_COIN_LINE_4,
    DIGITAL_COIN_LINE_5,
#define DIGITAL_COIN_LINES_NUM 5
} digital_coin_line_t;


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
    ALARM_PORTHOLE = 0,
    ALARM_EMERGENCY,
    ALARM_FILTER,
    ALARM_AIR_FLOW,
    ALARM_BURNER,
    ALARM_SAFETY_TEMPERATURE,
    ALARM_TEMPERATURE_NOT_REACHED,
    ALARM_INVERTER,
#define ALARMS_NUM 8
} alarm_t;


typedef struct {
    name_t nome;

    uint16_t language;
    uint16_t max_user_language;
    uint16_t logo;
    uint16_t abilita_visualizzazione_temperatura;
    uint16_t abilita_tasto_menu;
    uint16_t display_cycles_statistics;
    uint16_t tempo_stop_automatico;
    uint16_t tempo_attesa_partenza_ciclo;
    uint16_t reset_page_time;
    uint16_t reset_language_time;
    uint16_t pause_button_time;
    uint16_t stop_button_time;
    uint16_t minimum_speed;
    uint16_t maximum_speed;
    uint16_t tempo_gettone;
    uint16_t velocita_antipiega;
    uint16_t tipo_pagamento;
    uint16_t access_level;
    uint16_t autostart;
    uint16_t residual_humidity_check;
    uint16_t max_input_temperature;                   // Maximum temperature to be set for the input probe
    uint16_t max_output_temperature;                  // Maximum temperature to be set for the output probe
    uint16_t minimum_coins;                           // Minimum number of coins to insert to start the drying cycle
    uint16_t time_per_coin;                           // Drying time to add for each credit unit
    uint16_t credit_request_type;                     // Message to show when requiring payment
    uint16_t number_of_cycles_before_maintenance;     // Number of cycles after which to show a maintenance request
    uint16_t maintenance_notice_delay;                // Time in between maintenance notices are shown
    uint16_t maintenance_notice_duration;             // Time for which maintenance notices are shown

    /* Parametri da inviare alla macchina */
    uint16_t tipo_sonda_temperatura;
    uint16_t posizione_sonda_temperatura;
    uint16_t safety_input_temperature;
    uint16_t safety_output_temperature;
    uint16_t tempo_allarme_temperatura;     // se non arriva in temperatura in quel tempo
    uint16_t temperature_probe;
    uint16_t allarme_inverter_off_on;
    uint16_t allarme_filtro_off_on;
    uint16_t emergency_alarm_nc_na;
    uint16_t air_flow_alarm_time;
    uint16_t tipo_macchina_occupata;
    uint16_t tipo_riscaldamento;
    uint16_t disabilita_allarmi;
    uint16_t heating_type;
    uint16_t gas_ignition_attempts;
    uint16_t stop_time_in_pause;
    uint16_t porthole_nc_na;
    uint16_t busy_signal_nc_na;
    uint16_t fan_with_open_porthole_time;
    uint16_t invert_fan_drum_pwm;
    uint16_t cycle_reset_time;
} parmac_t;


struct model {
    struct {
        uint16_t machine_model;
        uint8_t  commissioned;

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
                uint8_t  heating;
                int16_t  temperature_1_adc;
                int16_t  temperature_1;
                int16_t  temperature_2_adc;
                int16_t  temperature_2;
                int16_t  temperature_probe;
                uint16_t humidity_probe;
                int16_t  pressure_adc;
                int16_t  pressure;

                cycle_state_t cycle_state;
                int16_t       default_temperature;
                uint16_t      remaining_time_seconds;
                uint16_t      alarms;
                uint16_t      payment;
                uint16_t      coins[DIGITAL_COIN_LINES_NUM];
            } read;

            struct {
                uint8_t  test_mode;
                uint16_t test_outputs;
                uint8_t  test_pwm1;
                uint8_t  test_pwm2;
            } write;
        } minion;

        language_t              temporary_language;
        uint8_t                 temporary_access_level;
        uint8_t                 should_open_porthole;
        uint16_t                current_program_index;
        program_t               current_program;
        uint16_t                current_step_index;
        uint8_t                 test_enable_coin_reader;
        removable_drive_state_t removable_drive_state;
        firmware_update_state_t firmware_update_state;
    } run;
};


typedef const struct model model_t;
typedef struct model       mut_model_t;


void             model_init(mut_model_t *model);
void             model_clear_test_outputs(mut_model_t *model);
void             model_set_test_output(mut_model_t *model, uint16_t output_index);
uint8_t          model_get_bit_accesso(uint8_t al);
char            *model_new_unique_filename(model_t *model, char *filename, unsigned long seed);
const program_t *model_get_program(model_t *model, uint16_t program_index);
program_t       *model_get_mut_program(mut_model_t *model, uint16_t program_index);
void             model_reset_temporary_language(mut_model_t *model);
size_t           model_serialize_parmac(uint8_t *buffer, parmac_t *p);
size_t           model_deserialize_parmac(parmac_t *p, uint8_t *buffer);
program_step_t   model_get_current_step(model_t *model);
uint8_t          model_is_cycle_active(model_t *model);
uint8_t          model_is_cycle_paused(model_t *model);
uint8_t          model_is_cycle_stopped(model_t *model);
void             model_select_program(mut_model_t *model, uint16_t program_index);
void             model_select_step(mut_model_t *model, uint16_t step_index);
uint8_t          model_is_program_done(model_t *model);
int16_t          model_get_program_display_temperature(model_t *model, uint16_t program_index);
uint8_t          model_is_alarm_active(model_t *model, alarm_t alarm);
uint8_t          model_is_porthole_open(model_t *model);
uint8_t          model_is_cycle_running(model_t *model);
uint8_t          model_is_any_alarm_active(model_t *model);
uint8_t          model_should_enable_coin_reader(model_t *model);
uint8_t          model_swap_programs(mut_model_t *model, size_t first, size_t second);
void             model_init_default_programs(mut_model_t *model);
uint8_t          model_waiting_for_next_step(model_t *model);
void             model_move_to_next_step(mut_model_t *model);
int16_t          model_get_current_setpoint(model_t *model);
void             model_reset_program(mut_model_t *model);
uint8_t          model_is_step_endless(model_t *model);
uint16_t         model_get_maximum_temperature(model_t *model);
void             model_check_parameters(mut_model_t *model);
int16_t          model_get_current_temperature(model_t *model);
uint8_t          model_should_open_porthole(model_t *model);


#endif
