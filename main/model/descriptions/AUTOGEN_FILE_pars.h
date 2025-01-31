#ifndef AUTOGEN_FILE_PARS_H_INCLUDED
#define AUTOGEN_FILE_PARS_H_INCLUDED

typedef enum {
    PARS_DESCRIPTIONS_LINGUA = 0,
    PARS_DESCRIPTIONS_LIVELLO_ACCESSO,
    PARS_DESCRIPTIONS_VISUALIZZARE_TEMPERATURA,
    PARS_DESCRIPTIONS_TASTO_MENU,
    PARS_DESCRIPTIONS_TEMPO_TASTO_PAUSA,
    PARS_DESCRIPTIONS_TEMPO_TASTO_STOP,
    PARS_DESCRIPTIONS_TEMPO_STOP_AUTOMATICO,
    PARS_DESCRIPTIONS_DISABILITA_ALLARMI,
    PARS_DESCRIPTIONS_TEMPO_ALLARME_TEMPERATURA,
    PARS_DESCRIPTIONS_TEMPERATURA_DI_SICUREZZA,
    PARS_DESCRIPTIONS_TIPO_MACCHINA_OCCUPATA,
    PARS_DESCRIPTIONS_DIREZIONE_ALLARME_FILTRO,
    PARS_DESCRIPTIONS_DIREZIONE_ALLARME_INVERTER,
    PARS_DESCRIPTIONS_SONDA_TEMPERATURA,
    PARS_DESCRIPTIONS_TIPO_RISCALDAMENTO,
    PARS_DESCRIPTIONS_TENTATIVI_ACCENSIONE_GAS,
    PARS_DESCRIPTIONS_FERMA_TEMPO_IN_PAUSA,
    PARS_DESCRIPTIONS_DIREZIONE_CONTATTO_OBLO,
    PARS_DESCRIPTIONS_DIREZIONE_CONTATTO_MACCHINA_OCCUPATA,
    PARS_DESCRIPTIONS_DURATA,
    PARS_DESCRIPTIONS_TEMPO_DI_ROTAZIONE,
    PARS_DESCRIPTIONS_TEMPO_DI_PAUSA,
    PARS_DESCRIPTIONS_TEMPERATURA,
    PARS_DESCRIPTIONS_ISTERESI_RISCALDAMENTO,
    PARS_DESCRIPTIONS_ISTERESI_RAFFREDDAMENTO,
    PARS_DESCRIPTIONS_UMIDITA,
    PARS_DESCRIPTIONS_RISCALDAMENTO_PROGRESSIVO,
    PARS_DESCRIPTIONS_DURATA_MASSIMA,
    PARS_DESCRIPTIONS_CICLI_MASSIMI,
    PARS_DESCRIPTIONS_TEMPO_DI_RITARDO,
    PARS_DESCRIPTIONS_VELOCITA,
    PARS_DESCRIPTIONS_TIPO,
    PARS_DESCRIPTIONS_TEMPO_ALLARME_FLUSSO_ARIA,
    PARS_DESCRIPTIONS_TEMPO_VENTILAZIONE_OBLO_APERTO,
    PARS_DESCRIPTIONS_INVERSIONE_VENTOLA_E_CESTO,
    PARS_DESCRIPTIONS_ATTESA_TEMPERATURA,
    PARS_DESCRIPTIONS_ABILITA_INVERSIONE,
    PARS_DESCRIPTIONS_LINGUA_MASSIMA_UTENTE,
    PARS_DESCRIPTIONS_LOGO,
    PARS_DESCRIPTIONS_VELOCITA_MINIMA,
    PARS_DESCRIPTIONS_VELOCITA_MASSIMA,
    PARS_DESCRIPTIONS_TEMPERATURA_MASSIMA_IN_INGRESSO,
    PARS_DESCRIPTIONS_TEMPERATURA_MASSIMA_IN_USCITA,
    PARS_DESCRIPTIONS_TEMPERATURA_DI_SICUREZZA_IN_INGRESSO,
    PARS_DESCRIPTIONS_TEMPERATURA_DI_SICUREZZA_IN_USCITA,
    PARS_DESCRIPTIONS_TEMPO_DI_RITORNO_LINGUA_INIZIALE,
    PARS_DESCRIPTIONS_TEMPO_DI_RITORNO_PAGINA_INIZIALE,
    PARS_DESCRIPTIONS_CONTROLLO_UMIDITA_RESIDUA,
    PARS_DESCRIPTIONS_AUTOAVVIO,
    PARS_DESCRIPTIONS_DIREZIONE_ALLARME_EMERGENZA,
    PARS_DESCRIPTIONS_TEMPO_AZZERAMENTO_CICLO,
    PARS_DESCRIPTIONS_TEMPO_PER_GETTONE,
    PARS_DESCRIPTIONS_NUMERO_MINIMO_DI_GETTONI,
    PARS_DESCRIPTIONS_TIPO_DI_RICHIESTA_PAGAMENTO,
    PARS_DESCRIPTIONS_NUMERO_DI_CICLI_PRIMA_DELLA_MANUTENZIONE,
    PARS_DESCRIPTIONS_CADENZA_AVVISO_MANUTENZIONE,
    PARS_DESCRIPTIONS_DURATA_AVVISO_MANUTENZIONE,
} pars_descriptions_t;

extern const char *pars_descriptions[57][2];
typedef enum {
    PARS_NC_NA_NC = 0,
    PARS_NC_NA_NA,
} pars_nc_na_t;

extern const char *pars_nc_na[2][2];
typedef enum {
    PARS_MANUALE_AUTOMATICO_MANUALE = 0,
    PARS_MANUALE_AUTOMATICO_AUTOMATICO,
} pars_manuale_automatico_t;

extern const char *pars_manuale_automatico[2][2];
typedef enum {
    PARS_LINGUE_ITALIANO = 0,
    PARS_LINGUE_INGLESE,
    PARS_LINGUE_SPAGNOLO,
    PARS_LINGUE_FRANCESE,
    PARS_LINGUE_TEDESCO,
} pars_lingue_t;

extern const char *pars_lingue[5][5];
typedef enum {
    PARS_TIPO_RICHIESTA_PAGAMENTO_INSERIRE_GETTONE = 0,
    PARS_TIPO_RICHIESTA_PAGAMENTO_INSERIRE_MONETE,
    PARS_TIPO_RICHIESTA_PAGAMENTO_PAGARE_CASSA,
} pars_tipo_richiesta_pagamento_t;

extern const char *pars_tipo_richiesta_pagamento[3][2];
typedef enum {
    PARS_LIVELLO_ACCESSO_UTENTE = 0,
    PARS_LIVELLO_ACCESSO_TECNICO,
} pars_livello_accesso_t;

extern const char *pars_livello_accesso[2][2];
typedef enum {
    PARS_TIPO_MACCHINA_OCCUPATA_TIPO_0 = 0,
    PARS_TIPO_MACCHINA_OCCUPATA_TIPO_1,
    PARS_TIPO_MACCHINA_OCCUPATA_TIPO_2,
} pars_tipo_macchina_occupata_t;

extern const char *pars_tipo_macchina_occupata[3][2];
typedef enum {
    PARS_TIPO_RISCALDAMENTO_ELETTRICO = 0,
    PARS_TIPO_RISCALDAMENTO_GAS,
} pars_tipo_riscaldamento_t;

extern const char *pars_tipo_riscaldamento[2][2];
typedef enum {
    PARS_SONDA_TEMPERATURA_INGRESSO = 0,
    PARS_SONDA_TEMPERATURA_USCITA,
    PARS_SONDA_TEMPERATURA_TEMPERATURA_UMIDITA,
} pars_sonda_temperatura_t;

extern const char *pars_sonda_temperatura[3][2];
typedef enum {
    PARS_NOSI_NO = 0,
    PARS_NOSI_SI,
} pars_nosi_t;

extern const char *pars_nosi[2][2];
typedef enum {
    PARS_LOGHI_NESSUNO = 0,
    PARS_LOGHI_MSGROUP,
    PARS_LOGHI_ROTONDI,
    PARS_LOGHI_HOOVER,
    PARS_LOGHI_UNITYLAUNDRY,
} pars_loghi_t;

extern const char *pars_loghi[5][2];

#endif
