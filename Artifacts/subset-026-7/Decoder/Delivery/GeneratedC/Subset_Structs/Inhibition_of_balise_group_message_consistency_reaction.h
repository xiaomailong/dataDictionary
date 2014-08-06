#ifndef NESTINGMARK_oETCS_Packet_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction
#define NESTINGMARK_oETCS_Packet_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction
/* =============================================================================
Formalization of Subset-026-7 (Chapter 7: ERTMS/ETCS language)

- Name: Subset-026-7 / TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction
- Description: UNISIG SUBSET-026-7, ISSUE : 3.3.0, 3.5 ERTMS/ETCS language) 
- Copyright (c) Siemens AG, 2014, All Rights Reserved
 	
- Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl )
- Gist URL: none
- Cryptography: No
- Author(s): SiemensRailAutomation

Disclaimer:

The use of this software is limited to NON-vital applications. 
It has NOT been developed for vital operation purposes and MUST NOT be used for applications 
which may cause harm to people, physical accidents or financial loss. 

THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OTHER KIND OF USE.  	
============================================================================= */
#include <stdint.h>
#include "opnETCS_Variables.h"

struct DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction {
  int vUsed_idx;                             // aktueller Fuellgrad von aPacket

  struct 
  {
          uint32_t v_TOccurence;            // Zeitpunkt des Empfangs
          uint64_t v_DOccurrence;           // Ort des Empfangs
          uint32_t vState;                  // Bearbeitungszustaende  
  } info;

  struct 
 { 
// TransmissionMedia=Balise
// Indication to on-board that the balise group message consistency reaction (service brake command) can be inhibited for this balise group message only, in case one or more balise telegram(s) of the group is/are missed or is/are detected but not decoded.
// Packet Number = 145

	uint32_t               NID_PACKET;            		// # 8	
	T_q_dir                Q_DIR                 ;		// # 2	
	uint32_t               L_PACKET              ;		// # 13	
} 


   aPacket[2];       // Instanz der Sturkur mit dem content
};

// struct -> type
typedef struct DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction T_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction;
// typ -> ptrtyp
typedef  T_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction* TP_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction;
// declaration of variable of ptrtyp
extern TP_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction  oETCS_Packet_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction;
// instatiate this ptrtype variable like this: (get memory and fill memory)
// TP_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction  oETCS_Packet_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction = new(T_DATA_oETCS_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction);
// and now fill in the content to start with ...
// Access variable like this: oETCS_Packet_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction->...
// maybe : memset(oETCS_Packet_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction, 0, sizeof(T_DATA_oETCS_Packet_TrackToTrain_Inhibition_of_balise_group_message_consistency_reaction));
// for complete 0 content.

#endif


